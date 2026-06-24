#include "cgs.h"

int main()
{
    char buf[64];
    
    cgs_fmt(buf, "%? + %? = %?\n", 2, 3, 5);
    
    cgs_appendf(buf, "%[1] + %[0] = %[2]", 2, 3, 5);
    
    cgs_printfln("%?", buf);
    
    auto s = cgs_asprintf(cgs_get_default_allocator(), "no args %? %?", 1);
    cgs_writeln(s);
}
