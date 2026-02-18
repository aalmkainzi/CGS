#define SGS_SHORT_NAMES
#include "../sgs.h"

int main()
{
    StrViewArray splitted = sgs_split("1 XX 2 XX 3 XX 4 XX 5 XX 6", " XX ");

    char c[128];
    StrBuf dst = strbuf_init_from_buf(c);
    sgs_join(&dst, splitted, ", ");

    println("the joined string: \n", dst);

    free(splitted.strs);
}
