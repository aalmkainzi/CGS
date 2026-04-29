#include <stdio.h>
#include "../cgs.c"

int main()
{
    FILE *h = fopen("../cgs.h", "r");
    FILE *c = fopen("../cgs.c", "r");
    
    CGS_DStr amalgam = cgs_dstr_init();
    
    cgs_append(&amalgam, "// This file is generated from amalgamator.c\n");
    cgs_append_fread_until(&amalgam, h, EOF);
    cgs_append(&amalgam, "\n#if defined(CGS_IMPL)\n");
    cgs_append_fread_until(&amalgam, c, EOF);
    cgs_append(&amalgam, "\n#endif // CGS_IMPL\n");
    
    cgs_replace_first(&amalgam, "#include \"cgs.h\"", "");
    
    FILE *hh = fopen("cgs.h.h", "w");
    cgs_append(hh, amalgam);
    
    fclose(h);
    fclose(c);
    fclose(hh);
    cgs_dstr_deinit(&amalgam);
}
