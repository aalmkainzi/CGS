#include "cgs.h"

int main()
{
    char buf[64];
    
    cgs_interp(buf, "%? + %? = %?\n", 2, 3, 5);
    
    cgs_interp_append(buf, "%1 + %0 = %2", 2, 3, 5);
    
    cgs_println(buf);
}
