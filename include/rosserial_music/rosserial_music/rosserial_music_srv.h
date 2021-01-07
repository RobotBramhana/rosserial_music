#ifndef _ROS_SERVICE_rosserial_music_srv_h
#define _ROS_SERVICE_rosserial_music_srv_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace rosserial_music
{

static const char ROSSERIAL_MUSIC_SRV[] = "rosserial_music/rosserial_music_srv";

  class rosserial_music_srvRequest : public ros::Msg
  {
    public:
      uint32_t notes_length;
      typedef uint32_t _notes_type;
      _notes_type st_notes;
      _notes_type * notes;
      uint32_t tune_length;
      typedef uint32_t _tune_type;
      _tune_type st_tune;
      _tune_type * tune;

    rosserial_music_srvRequest():
      notes_length(0), notes(NULL),
      tune_length(0), tune(NULL)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->notes_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->notes_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->notes_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->notes_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->notes_length);
      for( uint32_t i = 0; i < notes_length; i++){
      *(outbuffer + offset + 0) = (this->notes[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->notes[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->notes[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->notes[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->notes[i]);
      }
      *(outbuffer + offset + 0) = (this->tune_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tune_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tune_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tune_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tune_length);
      for( uint32_t i = 0; i < tune_length; i++){
      *(outbuffer + offset + 0) = (this->tune[i] >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->tune[i] >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->tune[i] >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->tune[i] >> (8 * 3)) & 0xFF;
      offset += sizeof(this->tune[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t notes_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      notes_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      notes_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      notes_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->notes_length);
      if(notes_lengthT > notes_length)
        this->notes = (uint32_t*)realloc(this->notes, notes_lengthT * sizeof(uint32_t));
      notes_length = notes_lengthT;
      for( uint32_t i = 0; i < notes_length; i++){
      this->st_notes =  ((uint32_t) (*(inbuffer + offset)));
      this->st_notes |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_notes |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_notes |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_notes);
        memcpy( &(this->notes[i]), &(this->st_notes), sizeof(uint32_t));
      }
      uint32_t tune_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      tune_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      tune_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      tune_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->tune_length);
      if(tune_lengthT > tune_length)
        this->tune = (uint32_t*)realloc(this->tune, tune_lengthT * sizeof(uint32_t));
      tune_length = tune_lengthT;
      for( uint32_t i = 0; i < tune_length; i++){
      this->st_tune =  ((uint32_t) (*(inbuffer + offset)));
      this->st_tune |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->st_tune |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->st_tune |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->st_tune);
        memcpy( &(this->tune[i]), &(this->st_tune), sizeof(uint32_t));
      }
     return offset;
    }

    const char * getType(){ return ROSSERIAL_MUSIC_SRV; };
    const char * getMD5(){ return "4c94a6aacf416a042d6e814c9b8e8730"; };

  };

  class rosserial_music_srvResponse : public ros::Msg
  {
    public:
      typedef bool _ack_type;
      _ack_type ack;

    rosserial_music_srvResponse():
      ack(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ack;
      u_ack.real = this->ack;
      *(outbuffer + offset + 0) = (u_ack.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->ack);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_ack;
      u_ack.base = 0;
      u_ack.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->ack = u_ack.real;
      offset += sizeof(this->ack);
     return offset;
    }

    const char * getType(){ return ROSSERIAL_MUSIC_SRV; };
    const char * getMD5(){ return "8f5729177853f34b146e2e57766d4dc2"; };

  };

  class rosserial_music_srv {
    public:
    typedef rosserial_music_srvRequest Request;
    typedef rosserial_music_srvResponse Response;
  };

}
#endif
