#define CGS_SHORT_NAMES
#include "cgs.h"

int main()
{
    DStr str = dstr_init();
    
    cgs_append(&str, "world");
    cgs_prepend(&str, "hello, ");
    
    println(str);
    
    dstr_deinit(&str);
}
