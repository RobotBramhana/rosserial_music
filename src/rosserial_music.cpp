#include "rosserial_music/rosserial_music.hpp"
music_publisher::music_publisher():
    client(n.serviceClient<beginner_tutorials::AddTwoInts>("add_two_ints")),
    loop_rate(10)
{
tune={300,100,200,200,200,
                      200,200,200,200,100,
                      100,100,100,100,100,
                      100,100,100,100,400,
                      300,100,200,200,300,
                      100,200,200,300,100,
                      200,200,300,100,200,200};
}
void music_publisher::loop_function()
{
  if (client.call(srv))
  {
    ROS_INFO("Sum: %ld", (long int)srv.response.sum);
  }
  else
  {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }
  }