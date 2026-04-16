#include "cgs.h"

int main()
{
    cgs_nfmt_t(int, 'x', '-') a = {21};
    
    cgs_println(a);
}