#define FXS_SHORT_NAMES
#include "../fxs.h"

void replace_dash(MutStrRef str)
{
    fxs_replace(str, "-", " ");
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
