#define NEAT_STR_SHORT_NAMES
#include "../neat_str.h"

int main()
{
    String_View s     = str_view("hello, world");
    String_View hello = str_view(s, 0, 5);
    String_View world = str_view(s, 7);
    
    println(hello);
    println(world);
}
