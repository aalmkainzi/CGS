#define NEAT_STR_SHORT_NAMES
#include "../neat_str.h"

void replace_dash(Mut_String_Ref str)
{
    str_replace(str, "-", " ");
}

int main()
{
    String_Buffer sb = strbuf_init_from_cstr((char[]){"string-buffer"});
    
    char *cstr = calloc(128, sizeof(char));
    strcpy(cstr, "c-string");
    
    replace_dash(mutstr_ref(&sb));
    replace_dash(mutstr_ref(cstr));
    
    println(sb);
    println(cstr);
    
    free(cstr);
}
