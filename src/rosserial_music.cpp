#include "rosserial_music/rosserial_music.hpp"

music_client::music_client() : client(nh.serviceClient<rosserial_music_srv>("request_music")),
                               loop_rate(10),
                               timer(nh.createWallTimer(WallDuration(20), &music_client::timer_callback, this,false, true))
{
  nh.getParam("tune", tune);
  nh.getParam("notes", notes);
}
void music_client::timer_callback(const WallTimerEvent&)
{
  if (client.call(music))
  {
    ROS_INFO("Service call successful");
    // music.request.notes.dim.push_back(rosserial_music_srv());
    // music.request.notes.layout.dim[0].size=notes.size();
    // music.request.notes.layout.dim[0].stride=1;
    //  music.request.notes.layout.dim[0].label = strings[typ+4];
    if (music.response.ack)
    {
      ROS_INFO("Music was played");
    }
    else
    {
      ROS_WARN("Music play failed");
    }
  }
  else
  {
    ROS_ERROR("Failed to call service");
  }
}