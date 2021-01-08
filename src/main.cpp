#include "rosserial_music/rosserial_music.hpp"

int main(int argc, char **argv)
{
    init(argc, argv, "node_class");
    while(ok())
    {
        spinOnce();
    }
    return 0;
}