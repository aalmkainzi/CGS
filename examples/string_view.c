#define FXS_SHORT_NAMES
#include "../fxs.h"

int main()
{
    StrView s     = strv("hello, world");
    StrView hello = strv(s, 0, 5);
    StrView world = strv(s, 7);
    
    println(hello);
    println(world);
}
