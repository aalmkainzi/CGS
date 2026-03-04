#define CGS_API static
#define CGS_SHORT_NAMES
#include "cgs.c"

int main()
{
    DStr dstr = dstr_init();
    cgs_append(&dstr, "hello world");
    println(dstr);
}