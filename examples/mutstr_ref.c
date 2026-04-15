#include "cgs.h"

void replace_dash(CGS_MutStrRef str)
{
    cgs_replace(str, "-", " ");
}

int main()
{
    CGS_StrBuf sb = cgs_strbuf_init_from_cstr((char[]){"string-buffer"});
    
    char *cstr = calloc(128, sizeof(char));
    strcpy(cstr, "c-string");
    
    replace_dash(cgs_mutstr_ref(&sb));
    replace_dash(cgs_mutstr_ref(cstr));
    
    cgs_println(sb);
    cgs_println(cstr);
    
    free(cstr);
}
