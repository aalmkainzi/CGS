#include "cgs.h"

struct FOO {
    char n;
};

CGS_Error foo_to_str(CGS_Writer dst, struct FOO foo)
{
    CGS_Error err = cgs_putc(dst, foo.n);
    return err;
}

#define ADD_TOSTR \
(struct FOO, foo_to_str)

#include "cgs.h"

int main()
{
    char *dst = (char[]){"ab"};
    cgs_tostr_many(dst, 1, 2, 3);
    cgs_writeln(dst);
}
