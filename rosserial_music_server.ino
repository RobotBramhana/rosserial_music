/*
   ------------------------------------------------------------
   "THE COFFEEWARE LICENSE" (Revision 2):
   Sudhanva S wrote this code. As long as you retain this
   notice, you can do whatever you want with this stuff. If we
   meet someday, and you think this stuff is worth it, you can
   buy me a coffee in return.

   Also, you might consider following me on GitHub for any comments
   and/or questions you might have and if you'd like you can send
   me a donation at any time to support my work, ask me how!
   ------------------------------------------------------------

   @package bilahari_swarjithe
   @file bilahari_swarjithe.ino

   @mainpage Doxygen Arduino Music Project

   @section description Description
   A sketch when compiled and flashed on to Arduino by connecting
   a buzzer as shown in the circuit diagram, plays pallavi of
   bilahari swarjithe from Carnatic Music.

   @section note Note
   The declarations can also be made in *.h file.

   @section circuit Circuit
   - Buzzer connected to PIN 9.

   @section author Author
   - Created by Sudhanva S on 15/Sep/2020.

   @author Sudhanva S
*/

#include <ros.h>
#include <std_msgs/Int16MultiArray.h>
#include <rosserial_music/rosserial_music_srv.h>

using rosserial_music::rosserial_music_srv ;
using ros::NodeHandle;
using ros::ServiceServer;

NodeHandle nh;
rosserial_music_srv music;

/** @brief Tempo setting for the song. Higher values slows down the song. */
long tempo = 3500;

/** @brief Pause setting */
int pause = 1000;
int count = 100;

/** @brief Temporary variable with global scope. */
int notes_ = 0;

/** @brief Temporary variable with global scope. */
int tune = 0;
int duration  = 0;
/** @brief Pin number on Arduino */
int speakerOut = 2;

/** @brief Pointers to play music */
int *notes_ptr;
int *tune_ptr;
/** @brief Service declaration */
ServiceServer<rosserial_music_srv::Request, rosserial_music_srv::Response> server("test_srv", &callback);
/**
 * @brief callback function to play music based on service from ROS client
 * 
 * @param req Input; notes and tune.
 * @param res Output; acknowledgement that the music was played.
 */
void callback(const rosserial_music_srv::Request & req, rosserial_music_srv::Response & res) {
    res.ack = false;
  notes_ptr = (int*)malloc(req.notes_length * sizeof(int));
  tune_ptr = (int*)malloc(req.tune_length * sizeof(int));
  for (int i = 0; i < sizeof(notes_ptr); i++)
  {
    notes_ptr[i] = req.notes[i];
  }
  for (int i = 0; i < sizeof(tune_ptr); i++)
  {
    tune_ptr[i] = req.tune[i];
  }
  
  res.ack = play();

}

/**
 * @brief Performs PWM for the buzzer.
 */
void compose_music()
{
  long elapsed_time = 0;
  if (notes_ > 0)
  {
    while (elapsed_time < duration)
    {
      digitalWrite(speakerOut, HIGH);
      delayMicroseconds(notes_ / 2);

      digitalWrite(speakerOut, LOW);
      delayMicroseconds(notes_ / 2);

      elapsed_time += (notes_);
    }
  }
  else
  {
    for (int j = 0; j < count; j++)
    {
      delayMicroseconds(duration);
    }
  }
}
/**
 * @brief Play the music.
 * 
 * @return true if successful
 * @return false if unsuccessful
 */
bool play()
{
  for (int i = 0; i < sizeof(*notes_ptr) / 2; i++)
  {
    notes_ = notes_ptr[i];
    tune = notes_ptr[i];
    duration = tune * tempo;
    compose_music();
    delayMicroseconds(pause);
  }
  return true;
}
/**
 * @brief Setup Pins and Node
 * 
 */
void setup()
{
  pinMode(speakerOut, OUTPUT);
  nh.initNode();
  nh.advertiseService(server);
}
/**
 * @brief Execute ROS node in infinite loop
 * 
 */
void loop()
{
  nh.spinOnce();
  delay(10);
}