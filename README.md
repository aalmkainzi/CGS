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
## Features
The library exposes multiple string types for different use cases:
- [DStr](#DStr)
- [StrBuf](#StrBuf)
- [StrView](#StrView)
- [MutStrRef](#MutStrRef)

All of which are null terminated, except for `StrView`.

There are three categories of string types:
- `anystr_t`: any of (`char*`, `unsigned char*`, `char[]`, `unsigned char[]`, `StrView`, `DStr`, `DStr*`, `StrBuf`, `StrBuf*`, `MutStrRef`)
- `mutstr_t`: any of (`char*`, `unsigned char*`, `char[]`, `unsigned char[]`, `DStr*`, `StrBuf*`, `MutStrRef`)
- `writer_t`: anything from `mutstr_t`, also `CGS_Writer` and `FILE*`

This is a list of all the utility macros CGS provides:
```C++
CGS_StrView       cgs_strv(anystr_t str, unsigned int from = 0, unsigned int to_exclusive = cgs_len(str));
                  
CGS_StrBuf        cgs_strbuf_init_from_cstr([unsigned] char *cstr, unsigned int cap = strlen(cstr) + 1);
CGS_StrBuf        cgs_strbuf_init_from_cstr([unsigned] char cstr[], unsigned int cap = sizeof(cstr));
CGS_StrBuf        cgs_strbuf_init_from_buf([unsigned] char *buf, unsigned int cap);
CGS_StrBuf        cgs_strbuf_init_from_buf([unsigned] char buf[], unsigned int cap = sizeof(buf));

CGS_DStr          cgs_dstr_init(unsigned int initial_cap = 0, CGS_Allocator *allocator = cgs_get_default_allocator());
CGS_DStr          cgs_dstr_init_from(anystr_t src, CGS_Allocator *allocator = cgs_get_default_allocator());
void              cgs_dstr_deinit(CGS_DStr *dstr);
CGS_Error         cgs_dstr_shrink_to_fit(CGS_DStr *dstr);
CGS_Error         cgs_dstr_ensure_cap(CGS_DStr *dstr, unsigned int at_least);

CGS_MutStrRef     cgs_mutstr_ref(mutstr_t str);
CGS_MutStrRef     cgs_mutstr_ref(cstr, cap);

CGS_Writer        cgs_writer(writer_t);

CGS_StrViewArray  cgs_strv_arr(...anystr_t);
CGS_StrViewArray  cgs_strv_arr_from_carr(CGS_StrView strs[N]);
CGS_StrViewArray  cgs_strv_arr_from_carr(CGS_StrView *strs, unsigned int len);

unsigned int      cgs_len(anystr_t);
unsigned int      cgs_cap(anystr_t);
bool              cgs_equal(anystr_t a, anystr_t b);
char*             cgs_chars(anystr_t);

CGS_StrView       cgs_find(anystr_t hay, anystr_t needle);
unsigned int      cgs_count(anystr_t hay, anystr_t needle);
CGS_Error         cgs_clear(mutstr_t);
bool              cgs_starts_with(anystr_t hay, anystr_t needle);
bool              cgs_ends_with(anystr_t hay, anystr_t needle);

CGS_StrView       cgs_trim_view(anystr_t str);
CGS_Error         cgs_trim(mutstr_t str);

CGS_StrView       cgs_spn(anystr_t src, anystr_t charset);
CGS_StrView       cgs_cspn(anystr_t src, anystr_t charset);

CGS_StrView       cgs_next_tok(CGS_StrView *base, anystr_t delim);
CGS_StrView       cgs_next_tok_any(CGS_StrView *base, anystr_t delim_set);

CGS_Error         cgs_map_chars(mutstr_t, bool(*map_func)(char *c, void *arg), void *arg = NULL);
void              cgs_tolower(mutstr_t);
void              cgs_toupper(mutstr_t);

CGS_Error         cgs_copy(mutstr_t dst, anystr_t src);
CGS_DStr          cgs_dup(anystr_t src, CGS_Allocator *allocator = cgs_get_default_allocator());

CGS_Error         cgs_putc(writer_t dst, char c);
CGS_Error         cgs_append(writer_t dst, anystr_t src);
CGS_Error         cgs_insert(mutstr_t dst, anystr_t src, unsigned int pos);
CGS_Error         cgs_prepend(mutstr_t dst, anystr_t src);
CGS_Error         cgs_del(mutstr_t, unsigned int from, unsigned int to_exclusive);

CGS_ReplaceResult cgs_replace(mutstr_t dst, anystr_t target, anystr_t replacement);
CGS_Error         cgs_replace_first(mutstr_t dst, anystr_t target, anystr_t replacement);
CGS_Error         cgs_replace_range(mutstr_t dst, unsigned int from, unsigned int to_exclusive, anystr_t replacement);

CGS_StrViewArray  cgs_split(anystr_t str, anystr_t delim, CGS_Allocator *allocator = cgs_get_default_allocator());
CGS_Error         cgs_split_iter(anystr_t str, anystr_t delim, bool(*callback)(CGS_StrView found, void *arg), void *arg = NULL);
CGS_Error         cgs_join(mutstr_t dst, CGS_StrViewArray arr, anystr_t delim);

CGS_Error         cgs_fread_line(mutstr_t dst, FILE *stream);
CGS_Error         cgs_append_fread_line(mutstr_t dst, FILE *stream);
CGS_Error         cgs_read_line(mutstr_t dst);
CGS_Error         cgs_append_read_line(mutstr_t dst);
CGS_Error         cgs_fread_until(mutstr_t dst, FILE *stream, int delim);
CGS_Error         cgs_append_fread_until(mutstr_t dst, FILE *stream, int delim);
CGS_Error         cgs_read_until(mutstr_t dst, int delim);
CGS_Error         cgs_append_read_until(mutstr_t dst, int delim);

CGS_MutStrRef     cgs_appender(mutstr_t owner, CGS_AppenderState *state);
CGS_Error         cgs_commit_appender(mutstr_t owner, CGS_MutStrRef appender);

CGS_Error         cgs_tostr(mutstr_t dst, T val);
CGS_Error         cgs_tostr_append(writer_t dst, T val);
CGS_Error         cgs_tostr_p(mutstr_t dst, T *val);
bool              cgs_has_tostr(T);
unsigned int      cgs_tostr_len(T val);
unsigned int      cgs_tostr_p_len(T *val);

CGS_Error         cgs_format(mutstr_t dst, const char *fmt, ...args with tostr);
CGS_Error         cgs_format_append(writer_t dst, const char *fmt, ...args with tostr);

                  cgs_print(...args with tostr);
                  cgs_println(...args with tostr);
                  cgs_fprint(FILE *stream, ...args with tostr);
                  cgs_fprintln(FILE *stream, ...args with tostr);
                  cgs_sprint(mutstr_t dst, ...args with tostr);
                  cgs_sprint_append(writer_t dst, ...args with tostr);

cgs_nfmt_t(integer_T, fmt_char)    cgs_nfmt(integer_T value, int fmt_char);
cgs_nfmt_t(float/double, fmt_char) cgs_nfmt(float/double value, int fmt_char, int precision = (fmt_char == 'a' ? -1 : 6));
CGS_ArrayFmt                       cgs_arrfmt(T *array, size_t len);
CGS_ArrayFmt                       cgs_arrfmt(T *array, size_t len, anystr_t open, anystr_t close, anystr_t delim, anystr_t trailing_delim = "");
```

## Short names
If you define the macro `CGS_SHORT_NAMES` before including the `cgs.h` header, unprefixed variants of the following identifiers will be `#define`d:
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
cgs_tostr_append
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

## DStr

Dynamic String.

Constructed with:
```C
CGS_DStr cgs_dstr_init(unsigned int initial_cap = 0, CGS_Allocator *allocator = cgs_get_default_allocator());
CGS_DStr cgs_dstr_init_from(anystr_t src, CGS_Allocator *allocator = cgs_get_default_allocator());
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

You can construct it by calling `strbuf_init_from_*` macros, or by constructing it yourself.

## StrView

Used to view into other strings.

To initialize:
```C
CGS_StrView cgs_strv(anystr_t str, unsigned int from = 0, unsigned int to_exclusive = cgs_len(str));
```

## MutStrRef

This type can be used as a reference to any `mutstr_t` type.

To initialize:
```C
CGS_MutStrRef cgs_mutstr_ref(mutstr_t);
CGS_MutStrRef cgs_mutstr_ref(cstr, cap);
```

For example:
```C
void set_to_bar(CGS_MutStrRef str)
{
    cgs_copy(str, "bar");
}

void f(CGS_DStr *s1, CGS_StrBuf *s2, char *s3)
{
    set_to_bar( cgs_mutstr_ref(s1) );
    set_to_bar( cgs_mutstr_ref(s2) );
    set_to_bar( cgs_mutstr_ref(s3) );
}
```

## tostr

Used to convert values to string:

```C
CGS_Error cgs_tostr(mutstr_t dst, T val);
CGS_Error cgs_tostr_append(writer_t dst, T val);
```
Example:
```C
#define CGS_SHORT_NAMES
#include "cgs.h"

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

```C++
cgs_fprint(FILE *stream, ...args with tostr);
cgs_fprintln(FILE *stream, ...args with tostr);
cgs_print(...args with tostr);
cgs_println(...args with tostr);

cgs_sprint(mutstr_t dst, ...args with tostr);
cgs_sprint_append(writer_t dst, ...args with tostr);
```

Example:
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
println( nfmt(15, 'X') ); // prints "F"
```

Note that `nfmt` is type-safe, you cannot use chars other than:
- For integers: `'d'`, `'x'`, `'o'`, `'b'`, `'X'`
- For float/double: `'f'`, `'g'`, `'e'`, `'a'`, `'F'`, `'G'`, `'E'`, `'A'`

## Including
If you want external linking, your options are:
- Add cgs.c to your build, and only include cgs.h
- Include cgs.c in only one file, and cgs.h in other files

You can also always include cgs.c, if you define `#define CGS_API static` before including:
```C
#define CGS_API static inline
#include "cgs.c"
```
