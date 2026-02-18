#define SGS_SHORT_NAMES
#include "../sgs.h"

int main()
{
    // example 1
    char c[128] = {0};
    StrBuf mystr = strbuf_init_from_buf(c);
    
    sgs_sprint(&mystr, "hello, world", "\n", 123);
    
    sgs_append(&mystr, "456");
    
    println(mystr);
    // example 1 end
    
    // example 2
    char *cstr = malloc(64);
    strcpy(cstr, "hello, world");
    StrBuf mystr2 = strbuf_init_from_cstr(cstr, 64);
    
    sgs_replace(&mystr2, ", ", " -- ");
    
    println(mystr2);
    
    free(cstr);
    // example 2 end
}
