#include "cgs.h"

int main()
{
    CGS_StrViewArray splitted = cgs_split("1 XX 2 XX 3 XX 4 XX 5 XX 6", " XX ");

    char c[128];
    CGS_StrBuf dst = cgs_strbuf_init_from_buf(c);
    cgs_join(&dst, splitted, ", ");

    cgs_println("the joined string: \n", dst);

    free(splitted.strs);
}
