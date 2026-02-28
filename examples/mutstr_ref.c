#define CGS_SHORT_NAMES
#include "cgs.h"

void replace_dash(MutStrRef str)
{
    cgs_replace(str, "-", " ");
}

int main()
{
    StrBuf sb = strbuf_init_from_cstr((char[]){"string-buffer"});
    
    char *cstr = calloc(128, sizeof(char));
    strcpy(cstr, "c-string");
    
    replace_dash(mutstr_ref(&sb));
    replace_dash(mutstr_ref(cstr));
    
    println(sb);
    println(cstr);
    
    free(cstr);
}
