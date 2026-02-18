#define SGS_SHORT_NAMES
#include "../sgs.h"

int main()
{
    DStr str = dstr_init();
    
    dstr_append(&str, "world");
    dstr_prepend(&str, "hello, ");
    
    println(str);
    
    dstr_deinit(&str);
}
