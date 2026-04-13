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
    struct FOO f = {'a'};
    cgs_println(f); // can now use `struct FOO` variables in contexts that require a type with tostr
}