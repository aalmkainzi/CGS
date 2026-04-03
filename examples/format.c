#define CGS_SHORT_NAMES
#include "cgs.h"

int main()
{
    char buf[64];
    
    cgs_format(buf, "% % %", 1, 2, 3);
    cgs_println(buf);
}