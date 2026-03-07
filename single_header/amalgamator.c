#include <stdio.h>
#define CGS_SHORT_NAMES
#include "../cgs.c"

int main()
{
    FILE *h = fopen("../cgs.h", "r");
    FILE *c = fopen("../cgs.c", "r");
    
    DStr amalgam = dstr_init();
    
    cgs_fread_until(&amalgam, h, EOF);
    cgs_append(&amalgam, "\n#if defined(CGS_IMPL)\n");
    cgs_append_fread_until(&amalgam, c, EOF);
    cgs_append(&amalgam, "\n#endif // CGS_IMPL\n");
    
    cgs_replace_first(&amalgam, "#include \"cgs.h\"", "");
    
    FILE *hh = fopen("cgs.h.h", "w");
    fprint(hh, amalgam);
    
    fclose(h);
    fclose(c);
    fclose(hh);
    dstr_deinit(&amalgam);
}
