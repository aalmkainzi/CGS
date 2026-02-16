#define FXS_SHORT_NAMES
#include "../fxs.h"

int main()
{
    DStr str = dstr_init();
    
    dstr_append(&str, "world");
    dstr_prepend(&str, "hello, ");
    
    println(str);
    
    dstr_deinit(&str);
}
