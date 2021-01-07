#include <ros/ros.h>
#include <ros/String.h>



/** @brief Note sa, one of the Saptha Swaras. Frequency at 261 Hz  */
#define  s     3830    
/** @brief Note ri, one of the Saptha Swaras. Frequency at 294 Hz  */
#define  r     3400    
/** @brief Note ga, one of the Saptha Swaras. Frequency at 329 Hz  */  
#define  g     3038    
/** @brief Note ma, one of the Saptha Swaras. Frequency at 349 Hz  */
#define  m     2864    
/** @brief Note pa, one of the Saptha Swaras. Frequency at 392 Hz  */
#define  p     2550    
/** @brief Note da, one of the Saptha Swaras. Frequency at 440 Hz  */
#define  d     2272    
/** @brief Note ni, one of the Saptha Swaras. Frequency at 493 Hz  */
#define  n     2028    
/** @brief Note sa, one of the Saptha Swaras. But, on the next pitch. Frequency at 523 Hz  */
#define  S     1912    
/** @brief Note sa, one of the Saptha Swaras. But, on the next pitch.  */ 
#define  R     1686    
/** @brief To reset notes. Named it Z for 0 Hz  */
#define  Z     0       

using namespace ros;



class music_publisher
{
public:
    music_publisher();
    void loop_function();
private:
    NodeHandle nh_;
    ServiceClient client;
    rosserial_music::rosserial_music music;
    Rate loop_rate;
    vector<int> notes;
    vector<int> tune;
};