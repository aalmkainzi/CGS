#include "cgs.h"

int main()
{
    cgs_printfln("%? %? %? %? %? %?", 1, 2, 3, 4, cgs_alignfmt(125, CENTER, 10, '_'), cgs_nfmt(10.5, 'e', 3));
    // cgs_printf("%?", cgs_alignfmt(125, CENTER, 10, '_'));
}
