#include "cgs.h"

int main()
{
    // example 1
    char c[128] = {0};
    CGS_StrBuf mystr = cgs_strbuf_init_from_buf(c);
    
    cgs_sprint(&mystr, "hello, world", "\n", 123);
    
    cgs_append(&mystr, "456");
    
    cgs_println(mystr);
    // example 1 end
    
    // example 2
    char *cstr = malloc(64);
    strcpy(cstr, "hello, world");
    CGS_StrBuf mystr2 = cgs_strbuf_init_from_cstr(cstr, 64);
    
    cgs_replace(&mystr2, ", ", " -- ");
    
    cgs_println(mystr2);
    
    free(cstr);
    // example 2 end
}
