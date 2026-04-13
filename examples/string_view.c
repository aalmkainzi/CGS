#include "cgs.h"

int main()
{
    CGS_StrView s     = cgs_strv("hello, world");
    CGS_StrView hello = cgs_strv(s, 0, 5);
    CGS_StrView world = cgs_strv(s, 7);
    
    cgs_println(hello);
    cgs_println(world);
}
