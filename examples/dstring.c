#define NEAT_STR_SHORT_NAMES
#include "../neat_str.h"

int main()
{
    DString str = dstr_init();
    
    dstr_append(&str, "world");
    dstr_prepend(&str, "hello, ");
    
    println(str);
    
    dstr_deinit(&str);
}
