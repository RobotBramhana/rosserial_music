#include "rosserial_music/rosserial_music.hpp"

int main(int argc, char **argv)
{
    init(argc, argv, "node_class");
    node_class this_node;
    while(ok())
    {
        this_node.loop_function();
        spinOnce();
    }
    return 0;
}