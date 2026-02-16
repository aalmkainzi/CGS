#define FXS_SHORT_NAMES
#include "../fxs.h"

int main()
{
    StrViewArray splitted = fxs_split("1 XX 2 XX 3 XX 4 XX 5 XX 6", " XX ");

    char c[128];
    StrBuf dst = strbuf_init_from_buf(c);
    fxs_join(&dst, splitted, ", ");

    println("the joined string: \n", dst);

    free(splitted.strs);
}
