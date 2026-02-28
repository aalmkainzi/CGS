#define CGS_SHORT_NAMES
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
    println(f); // can now use `struct FOO` variables in contexts that require a type with tostr
    
    println("hello", 123, "\n", nfmt(15.3, 'E', 2));
    
    char buf[64];
    sprint(buf, "hello-", f);
    
    println(buf);
    
    nfmt_t(int,'X') a = nfmt(10,'X');
    println(a);
}