#include "cgs.h"

int main()
{
    char buf[64];
    
    cgs_format(buf, "%? + %? = %?", 2, 3, 5);
    cgs_println(buf);
    
    cgs_format(buf, "%1 + %0 = %2", 2, 3, 5);
    cgs_println(buf);
}
