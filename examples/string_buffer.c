#define NEAT_STR_SHORT_NAMES
#include "../neat_str.h"

int main()
{
    // example 1
    char c[128] = {0};
    String_Buffer mystr = strbuf_init_from_buf(c);
    
    str_print(&mystr, "hello, world", "\n", 123);
    
    str_append(&mystr, "456");
    
    println(mystr);
    // example 1 end
    
    // example 2
    char *cstr = malloc(64);
    strcpy(cstr, "hello, world");
    String_Buffer mystr2 = strbuf_init_from_cstr(cstr, 64);
    
    str_replace(&mystr2, ", ", " -- ");
    
    println(mystr2);
    
    free(cstr);
    // example 2 end
}
