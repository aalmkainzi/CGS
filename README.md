# CGS - C Generic Strings

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
- anystr_t: any of (`char*`, `unsigned char*`, `char[]`, `unsigned char[]`, `StrView`, `DStr`, `DStr*`, `StrBuf`, `StrBuf*`, `MutStrRef`)
- mutstr_t: any of (`char*`, `unsigned char*`, `char[]`, `unsigned char[]`, `DStr*`, `StrBuf*`, `MutStrRef`)
- writer_t: mutstr_t, `CGS_Writer`

This is a list of all the utility macros CGS provides:
```C
StrView                        strv(anystr_t str, unsigned int from = 0, unsigned int to_exclusive = cgs_len(str));
                               
StrBuf                         strbuf_init_from_cstr([unsigned] char *cstr, unsigned int cap = strlen(cstr) + 1);
StrBuf                         strbuf_init_from_cstr([unsigned] char cstr[], unsigned int cap = sizeof(cstr));
StrBuf                         strbuf_init_from_buf([unsigned] char *buf, unsigned int cap);
StrBuf                         strbuf_init_from_buf([unsigned] char buf[], unsigned int cap = sizeof(buf));
                               
DStr                           dstr_init(unsigned int initial_cap = 0, Allocator *allocator = cgs_get_default_allocator());
DStr                           dstr_init_from(anystr_t src, Allocator *allocator = cgs_get_default_allocator());
void                           dstr_deinit(DStr *dstr);
CGS_Error                      dstr_shrink_to_fit(DStr *dstr);
CGS_Error                      dstr_ensure_cap(DStr *dstr, unsigned int at_least);
                               
MutStrRef                      mutstr_ref(mutstr_t str);
                               
CGS_Writer                     cgs_writer(writer_t);
CGS_Writer                     cgs_writer(FILE*);
                               
StrViewArray                   strv_arr(...anystr_t);
StrViewArray                   strv_arr_from_carr(StrView strs[N]);
StrViewArray                   strv_arr_from_carr(StrView *strs, unsigned int len);
                               
unsigned int                   cgs_len(anystr_t);
unsigned int                   cgs_cap(anystr_t);
bool                           cgs_equal(anystr_t a, anystr_t b);
char*                          cgs_chars(anystr_t);
StrView                        cgs_find(anystr_t hay, anystr_t needle);
unsigned int                   cgs_count(anystr_t hay, anystr_t needle);
CGS_Error                      cgs_clear(mutstr_t);
bool                           cgs_starts_with(anystr_t hay, anystr_t needle);
bool                           cgs_ends_with(anystr_t hay, anystr_t needle);
CGS_Error                      cgs_map_chars(mutstr_t, bool(*map_func)(char *c, void *arg), void *arg = NULL);
void                           cgs_tolower(mutstr_t);
void                           cgs_toupper(mutstr_t);
CGS_Error                      cgs_copy(mutstr_t dst, anystr_t src);
CGS_Error                      cgs_putc(writer_t dst, char c);
DStr                           cgs_dup(anystr_t src, Allocator *allocator = cgs_get_default_allocator());
CGS_Error                      cgs_append(writer_t dst, anystr_t src);
CGS_Error                      cgs_insert(mutstr_t dst, anystr_t src, unsigned int pos);
CGS_Error                      cgs_prepend(mutstr_t dst, anystr_t src);
CGS_Error                      cgs_del(mutstr_t, unsigned int from, unsigned int to_exclusive);
ReplaceResult                  cgs_replace(mutstr_t dst, anystr_t target, anystr_t replacement);
CGS_Error                      cgs_replace_first(mutstr_t dst, anystr_t target, anystr_t replacement);
CGS_Error                      cgs_replace_range(mutstr_t dst, unsigned int from, unsigned int to_exclusive, anystr_t replacement);
StrViewArray                   cgs_split(anystr_t str, anystr_t delim, Allocator *allocator = cgs_get_default_allocator());
CGS_Error                      cgs_split_iter(anystr_t str, anystr_t delim, bool(*callback)(StrView found, void *arg), void *arg = NULL);
CGS_Error                      cgs_join(mutstr_t dst, StrViewArray arr, anystr_t delim);
CGS_Error                      cgs_fread_line(mutstr_t dst, FILE *stream);
CGS_Error                      cgs_append_fread_line(mutstr_t dst, FILE *stream);
CGS_Error                      cgs_read_line(mutstr_t dst);
CGS_Error                      cgs_append_read_line(mutstr_t dst);
MutStrRef                      cgs_appender(mutstr_t owner, AppenderState *state);
CGS_Error                      cgs_commit_appender(mutstr_t owner, MutStrRef appender);
CGS_Error                      tostr(mutstr_t dst, T val);
CGS_Error                      tostr_append(writer_t dst, T val);
CGS_Error                      tostr_p(mutstr_t dst, T *val);
bool                           has_tostr(T);
                               print(...args with tostr);
                               println(...args with tostr);
                               fprint(FILE *stream, ...args with tostr);
                               fprintln(FILE *stream, ...args with tostr);
                               sprint(mutstr_t dst, ...args with tostr);
                               sprint_append(writer_t dst, ...args with tostr);
nfmt_t(integer_T, fmt_char)    nfmt(integer_T value, int fmt_char);
nfmt_t(float/double, fmt_char) nfmt(float/double value, int fmt_char, int precision = (fmt_char == 'a' ? -1 : 6));
ArrayFmt                       arrfmt(T *array, size_t len);
ArrayFmt                       arrfmt(T *array, size_t len, anystr_t open, anystr_t close, anystr_t delim, anystr_t trailing_delim = "");
```

## DStr

Dynamic String.

Constructed with:
```C
DStr dstr_init(unsigned int initial_cap = 0, Allocator *allocator = cgs_get_default_allocator());
DStr dstr_init_from(anystr_t src, Allocator *allocator = cgs_get_default_allocator());
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
StrView strv(anystr_t, unsigned int from = 0, unsigned int to_exclusive = cgs_len(str));
```

## MutStrRef

This type can be used as a reference to any mutable string type (all string types except `StrView`).

to initialize:
```C
MutStrRef mutstr_ref(mutstr_t);
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
CGS_Error tostr(mutstr_t dst, T val);
CGS_Error tostr_append(writer_t dst, T val);
```
e.g.
```C
int main()
{
    DStr num = dstr_init();
    tostr(&num, 10);
}
```

You can add your own tostr functions for types by defining `ADD_TOSTR (Ty, Ty2str)` and re-including the `cgs.h` header:
```C
#define CGS_SHORT_NAMES
#include "cgs.h"

struct FOO {
    char n;
};

CGS_Error foo_to_str(CGS_Writer dst, struct FOO *f )
{
    CGS_Error err = cgs_putc(dst, f->n);
    return err;
}

#define ADD_TOSTR \
(struct FOO, foo_to_str)

#include "cgs.h"

int main()
{
    struct FOO f = {'a'};
    println(f); // can now use `struct FOO` in contexts that require a type with tostr
}
```

## fprint and sprint

Types that have a `tostr` defined can use `fprint`/`sprint` and their variants:

```C
fprint(FILE *stream, ...args with tostr);
fprintln(FILE *stream, ...args with tostr);
print(...args with tostr);
println(...args with tostr);

sprint(mutstr_t dst, ...args with tostr);
sprint_append(writer_t dst, ...args with tostr);
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
