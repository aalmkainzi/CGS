#define CGS_API static
#include "cgs.c"

int main()
{
    CGS_DStr dstr = cgs_dstr_init();
    cgs_append(&dstr, "hello world");
    cgs_writeln(dstr);
}