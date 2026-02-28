# CGS - C Generic Strings
A Generic String library to make string handling more intuitive in C.

## Quick Examples
```C
#define CGS_SHORT_NAMES
#include "cgs.h"

int main()
{
    StrView s     = strv("hello, world");
    StrView hello = strv(s, 0, 5);
    StrView world = strv(s, 7);
    
    println(hello);
    println(world);
}

```
```C
#define CGS_SHORT_NAMES
#include "cgs.h"

int main()
{
    DStr str = dstr_init();
    
    cgs_append(&str, "world");
    cgs_prepend(&str, "hello, ");
    
    println(str);
    
    dstr_deinit(&str);
}

```

## Short names
if you define the macro `CGS_SHORT_NAMES` before including the `cgs.h` header, unprefixed variants of the following identifiers will be `#define`d:
```C
CGS_Allocator
CGS_DStr
CGS_StrBuf
CGS_StrView
CGS_StrViewArray
CGS_MutStrRef
CGS_ReplaceResult
CGS_AppenderState
CGS_ArrayFmt

cgs_strv
cgs_strv_arr
cgs_strv_arr_from_carr

cgs_strbuf_init_from_cstr
cgs_strbuf_init_from_buf

cgs_dstr_init
cgs_dstr_init_from
cgs_dstr_deinit
cgs_dstr_ensure_cap
cgs_dstr_shrink_to_fit

cgs_mutstr_ref

cgs_tostr
cgs_tostr_p
cgs_has_tostr

cgs_print
cgs_println
cgs_fprint
cgs_fprintln

cgs_sprint
cgs_sprint_append

cgs_nfmt
cgs_nfmt_t
cgs_arrfmt
```

## Features
The library exposes multiple string types for different use cases:
- [DStr](#DStr)
- [StrBuf](#StrBuf)
- [StrView](#StrView)
- [MutStrRef](#MutStrRef)

All of which are null terminated, except for `StrView`.

There are two categories of string types:
- anystr: any of (`char*`, `unsigned char*`, `char[]`, `unsigned char[]`, `StrView`, `DStr`, `DStr*`, `StrBuf`, `StrBuf*`, `MutStrRef`)
- mutstr: any of (`char*`, `unsigned char*`, `char[]`, `unsigned char[]`, `DStr*`, `StrBuf*`, `MutStrRef`)

This is a list of all the utility macros CGS provides:
```C
StrView                        strv(anystr str, unsigned int from = 0, unsigned int to_exclusive = cgs_len(str));
                               
StrBuf                         strbuf_init_from_cstr([unsigned] char *cstr, unsigned int cap = strlen(cstr) + 1);
StrBuf                         strbuf_init_from_cstr([unsigned] char cstr[], unsigned int cap = sizeof(cstr));
StrBuf                         strbuf_init_from_buf([unsigned] char *buf, unsigned int cap);
StrBuf                         strbuf_init_from_buf([unsigned] char buf[], unsigned int cap = sizeof(buf));
                               
DStr                           dstr_init(unsigned int initial_cap = 0, Allocator *allocator = cgs_get_default_allocator());
DStr                           dstr_init_from(anystr src, Allocator *allocator = cgs_get_default_allocator());
void                           dstr_deinit(DStr *dstr);
CGS_Error                      dstr_shrink_to_fit(DStr *dstr);
CGS_Error                      dstr_ensure_cap(DStr *dstr, unsigned int at_least);
                               
MutStrRef                      mutstr_ref(mutstr str);
                               
StrViewArray                   strv_arr(...anystr);
StrViewArray                   strv_arr_from_carr(StrView strs[N]);
StrViewArray                   strv_arr_from_carr(StrView *strs, unsigned int len);
                               
unsigned int                   cgs_len(anystr);
unsigned int                   cgs_cap(anystr);
bool                           cgs_equal(anystr a, anystr b);
char*                          cgs_chars(anystr);
StrView                        cgs_find(anystr hay, anystr needle);
unsigned int                   cgs_count(anystr hay, anystr needle);
CGS_Error                      cgs_clear(mutstr);
bool                           cgs_starts_with(anystr hay, anystr needle);
bool                           cgs_ends_with(anystr hay, anystr needle);
void                           cgs_tolower(mutstr);
void                           cgs_toupper(mutstr);
CGS_Error                      cgs_copy(mutstr dst, anystr src);
CGS_Error                      cgs_putc(mutstr dst, char c);
DStr                           cgs_dup(anystr src, Allocator *allocator = cgs_get_default_allocator());
CGS_Error                      cgs_append(mutstr dst, anystr src);
CGS_Error                      cgs_insert(mutstr dst, anystr src, unsigned int pos);
CGS_Error                      cgs_prepend(mutstr dst, anystr src);
CGS_Error                      cgs_del(mutstr, unsigned int from, unsigned int to_exclusive);
ReplaceResult                  cgs_replace(mutstr dst, anystr target, anystr replacement);
CGS_Error                      cgs_replace_first(mutstr dst, anystr target, anystr replacement);
CGS_Error                      cgs_replace_range(mutstr dst, unsigned int from, unsigned int to_exclusive, anystr replacement);
StrViewArray                   cgs_split(anystr str, anystr delim, Allocator *allocator = cgs_get_default_allocator());
CGS_Error                      cgs_split_iter(anystr str, anystr delim, bool(*callback)(StrView found, void *arg), void *arg = NULL);
CGS_Error                      cgs_join(mutstr dst, StrViewArray arr, anystr delim);
CGS_Error                      cgs_fread_line(mutstr dst, FILE *stream);
CGS_Error                      cgs_append_fread_line(mutstr dst, FILE *stream);
CGS_Error                      cgs_read_line(mutstr dst);
CGS_Error                      cgs_append_read_line(mutstr dst);
MutStrRef                      cgs_appender(mutstr owner, AppenderState *state);
CGS_Error                      cgs_commit_appender(mutstr owner, MutStrRef appender);
CGS_Error                      tostr(mutstr dst, T val);
CGS_Error                      tostr_p(mutstr dst, T *val);
bool                           has_tostr(T);
                               print(...args with tostr);
                               println(...args with tostr);
                               fprint(FILE *stream, ...args with tostr);
                               fprintln(FILE *stream, ...args with tostr);
                               sprint(mutstr dst, ...args with tostr);
                               sprint_append(mutstr dst, ...args with tostr);
nfmt_t(integer_T, fmt_char)    nfmt(integer_T value, int fmt_char);
nfmt_t(float/double, fmt_char) nfmt(float/double value, int fmt_char, int precision = (fmt_char == 'a' ? -1 : 6));
ArrayFmt                       arrfmt(T *array, size_t len);
ArrayFmt                       arrfmt(T *array, size_t len, anystr open, anystr close, anystr delim, anystr trailing_delim = "");
```

## DStr

Dynamic String.

Constructed with:
```C
DStr dstr_init(unsigned int initial_cap = 0, Allocator *allocator = cgs_get_default_allocator());
DStr dstr_init_from(anystr src, Allocator *allocator = cgs_get_default_allocator());
```

## StrBuf

Used as a general purpose string buffer, it's defined like this:
```C
typedef struct CGS_StrBuf
{
    char *chars;
    unsigned int cap; // including the nul
    unsigned int len;
} CGS_StrBuf;
```

You can construct by calling `strbuf_init_from_*` macros, or by constructing it yourself.

## StrView

Used to view into other strings.

to initialize:
```C
StrView strv(any_str, unsigned int from = 0, unsigned int to_exclusive = cgs_len(str));
```

## MutStrRef

This type can be used as a reference to any mutable string type (all string types except `String_View`).

to initialize:
```C
MutStrRef mutstr_ref(mutstr);
MutStrRef mutstr_ref(cstr, cap);
```

for example:
```C
void set_to_bar(MutStrRef str)
{
    cgs_copy(str, "bar");
}

void f(DStr *s1, StrBuf *s2, char *s3)
{
    set_to_bar( mutstr_ref(s1) );
    set_to_bar( mutstr_ref(s2) );
    set_to_bar( mutstr_ref(s3) );
}
```

## tostr

Used to convert values to string:

```C
CGS_Error tostr(mutstr dst, T val);
```
e.g.
```C
int main()
{
    DStr num = dstr_init();
    tostr(&num, 10);
}
```

You can add your own tostr functions for types by defining `ADD_TOSTR Ty, Ty2str` and re-including the `neat_str.h` header:
```C
#define CGS_SHORT_NAMES
#include "cgs.h"

struct FOO {
    char n;
};

CGS_Error foo_to_str(MutStrRef dst, struct FOO *f )
{
    DStr ret = dstr_init();
    CGS_Error err = cgs_putc(&ret, f->n);
    
    return err;
}

#define ADD_TOSTR \
(struct FOO, foo_to_str)

#include "cgs.h"

int main()
{
    struct FOO f = {'a'};
    println( f ); // can now use `struct FOO` variables in contexts that require a type with tostr
}
```

## fprint and sprint

Types that have a `tostr` defined can use `fprint`/`sprint` and their variants:

```C
fprint(FILE *stream, ...args with tostr);
fprintln(FILE *stream, ...args with tostr);
print(...args with tostr);
println(...args with tostr);

sprint(mutstr dst, ...args with tostr);
sprint_append(mutstr dst, ...args with tostr);
```

e.g:
```C
#define CGS_SHORT_NAMES
#include "cgs.h"

int main()
{
    println("hello", 123, "\n", 15.3);
    
    char buf[64];
    sprint(buf, "hello", 123);
}
```

## nfmt and arrfmt

These macros return a format object that has a `tostr`. For example:

```C
println( nfmt(10, 'X') ); // prints "A"
```

Note that `nfmt` is type-safe, you cannot use chars other than:
- For integers: `'d'`, `'x'`, `'o'`, `'b'`, `'X'`
- For float/double: `'f'`, `'g'`, `'e'`, `'a'`, `'F'`, `'G'`, `'E'`, `'A'`
