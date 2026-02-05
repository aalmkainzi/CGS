#ifndef NEAT_STR_H
#define NEAT_STR_H

#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <inttypes.h>
#include <limits.h>

struct Neat_Allocator;

typedef struct Neat_Allocation
{
    void *ptr;
    size_t n;
} Neat_Allocation;

typedef Neat_Allocation(*neat_alloc_func)  (struct Neat_Allocator*, size_t alignment, size_t n);
typedef void           (*neat_dealloc_func)(struct Neat_Allocator*, void *ptr, size_t n);
typedef Neat_Allocation(*neat_realloc_func)(struct Neat_Allocator*, void *ptr, size_t alignment, size_t old_size, size_t new_size);

typedef struct Neat_Allocator
{
    neat_alloc_func alloc;
    neat_dealloc_func dealloc;
    neat_realloc_func realloc;
} Neat_Allocator;

Neat_Allocation neat__allocator_invoke_alloc(Neat_Allocator *allocator, size_t alignment, size_t obj_size, size_t nb);
void neat__allocator_invoke_dealloc(Neat_Allocator *allocator, void *ptr, size_t obj_size, size_t nb);
Neat_Allocation neat__allocator_invoke_realloc(Neat_Allocator *allocator, void *ptr, size_t alignment, size_t obj_size, size_t old_nb, size_t new_nb);

Neat_Allocator *neat_get_default_allocator();

#define neat_alloc(allocator, T, n) \
neat__allocator_invoke_alloc(allocator, _Alignof(T), sizeof(T), (n))

#define neat_dealloc(allocator, ptr, T, n) \
neat__allocator_invoke_dealloc((allocator), (ptr), sizeof(T), (n))

#define neat_realloc(allocator, ptr, T, old_n, new_n) \
neat__allocator_invoke_realloc((allocator), (ptr), _Alignof(T), sizeof(T), (old_n), (new_n))

#define neat_alloc_bytes(allocator, n) \
neat__allocator_invoke_alloc((allocator), _Alignof(max_align_t), 1, (n))

#define neat_dealloc_bytes(allocator, ptr, n) \
neat__allocator_invoke_dealloc((allocator), (ptr), 1, (n))

#define neat_realloc_bytes(allocator, ptr, old_n, new_n, actual) \
neat__allocator_invoke_realloc((allocator), (ptr), _Alignof(max_align_t), 1, (old_n), (new_n))

#if __STDC_VERSION__ >= 202311L

    #define NEAT__NODISCARD(...) [[nodiscard (__VA_ARGS__)]]

#elif defined(__GNUC__)

    #define NEAT__NODISCARD(...) __attribute__((warn_unused_result))

#else

    #define NEAT__NODISCARD(...)

#endif


#define neat__static_assertx(exp, msg) \
((void)sizeof(struct { _Static_assert(exp, msg); int : 8; }))

#define neat__has_type(exp, t) \
_Generic(exp, t: 1, default: 0)

#define neat__is_array_of(exp, ty) \
neat__has_type((__typeof__(exp)*){0}, __typeof__(ty)(*)[sizeof(exp)/sizeof(ty)])

#define NEAT__CAT(a, ...) NEAT__PRIMITIVE_CAT(a, __VA_ARGS__)
#define NEAT__PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__

#define neat__coerce(exp, t) \
neat__coerce_fallback(exp, t, (t){0})

#define neat__coerce_fallback(exp, ty, fallback) \
_Generic(exp, \
    ty: (exp), \
    default: (fallback) \
)

#define neat__coerce_string_type(exp, fallback) \
_Generic(exp,                                   \
    char*                     : exp,            \
    unsigned char*            : exp,            \
    Neat_DString              : exp,            \
    Neat_DString*             : exp,            \
    Neat_String_View          : exp,            \
    Neat_String_Buffer        : exp,            \
    Neat_String_Buffer*       : exp,            \
    Neat_Mut_String_Ref       : exp,            \
    const char*               : exp,            \
    const unsigned char*      : exp,            \
    const Neat_DString*       : exp,            \
    const Neat_String_Buffer* : exp,            \
    default                   : fallback        \
)

#define neat__coerce_not(exp, not_ty, fallback_ty) \
_Generic(exp, \
    not_ty: (fallback_ty){0}, \
    default: exp \
)

#define NEAT__CARR_LEN(carr) (sizeof(carr) / sizeof(carr[0]))

// IF_DEF and ARG_n stuff
#define NEAT__COMMA()              ,
#define NEAT__ARG1_( _1, ... )     _1
#define NEAT__ARG1( ... )          NEAT__ARG1_( __VA_ARGS__ )
#define NEAT__ARG2_( _1, _2, ... ) _2
#define NEAT__ARG2( ... )          NEAT__ARG2_( __VA_ARGS__ )
#define NEAT__INCL( ... )          __VA_ARGS__
#define NEAT__OMIT( ... )
#define NEAT__OMIT1(a, ...)        __VA_ARGS__
#define NEAT__IF_DEF( macro )      NEAT__ARG2( NEAT__COMMA macro () NEAT__INCL, NEAT__OMIT, )
// IF_DEF and ARG_n stuff end

// FOREACH stuff
#define NEAT__PARENS ()

#define NEAT__EXPAND(...)  NEAT__EXPAND4(NEAT__EXPAND4(NEAT__EXPAND4(NEAT__EXPAND4(__VA_ARGS__))))
#define NEAT__EXPAND4(...) NEAT__EXPAND3(NEAT__EXPAND3(NEAT__EXPAND3(NEAT__EXPAND3(__VA_ARGS__))))
#define NEAT__EXPAND3(...) NEAT__EXPAND2(NEAT__EXPAND2(NEAT__EXPAND2(NEAT__EXPAND2(__VA_ARGS__))))
#define NEAT__EXPAND2(...) NEAT__EXPAND1(NEAT__EXPAND1(NEAT__EXPAND1(NEAT__EXPAND1(__VA_ARGS__))))
#define NEAT__EXPAND1(...) __VA_ARGS__

#define NEAT__FOREACH(macro, ...)                                    \
__VA_OPT__(NEAT__EXPAND(NEAT__FOREACH_HELPER(macro, __VA_ARGS__)))
#define NEAT__FOREACH_HELPER(macro, a1, ...)                         \
macro(a1)                                                     \
__VA_OPT__(NEAT__FOREACH_REPEAT NEAT__PARENS (macro, __VA_ARGS__))
#define NEAT__FOREACH_REPEAT() NEAT__FOREACH_HELPER
// FOREACH stuff end

#define NEAT__VA_OR(otherwise, ...) \
__VA_ARGS__ NEAT__IF_EMPTY(otherwise, __VA_ARGS__)

#define NEAT__IF_EMPTY(then, ...) \
NEAT__CAT(NEAT__IF_EMPTY_, __VA_OPT__(0))(then)

#define NEAT__IF_EMPTY_(then) then
#define NEAT__IF_EMPTY_0(then)

#define NEAT__IF_NEMPTY(then, ...) __VA_OPT__(then)

#define NEAT__TYPEOF_ARG(arg) \
,__typeof__(arg)

#define NEAT__TYPEOF_ARGS(...) \
__VA_OPT__( \
NEAT__ARG1(__VA_ARGS__) NEAT__FOREACH(NEAT__TYPEOF_ARG, __VA_ARGS__) \
)

// Dynamic String
typedef struct Neat_DString
{
    Neat_Allocator *allocator;
    unsigned int cap;
    unsigned int len;
    unsigned char *chars;
} Neat_DString;

// Used as a general purpose non-dynamic string buffer
typedef struct Neat_String_Buffer
{
    unsigned int cap;
    unsigned int len;
    unsigned char *chars;
} Neat_String_Buffer;

// Used to view strings
typedef struct Neat_String_View
{
    unsigned int len;
    unsigned char *chars;
} Neat_String_View;

// An array of the above, returned by neat_str_split
typedef struct Neat_String_View_Array
{
    unsigned int cap;
    unsigned int len;
    Neat_String_View *strs;
} Neat_String_View_Array;

// Used for passing `char[]` or `unsigned char[]`, such that it doesn't lose cap information
typedef struct Neat_Buffer
{
    unsigned char *ptr;
    unsigned int cap;
} Neat_Buffer;

// This is a tagged union for all mutable string types (i.e. all except String_View)
typedef struct Neat_Mut_String_Ref
{
    const enum Neat_Mut_String_Ref_Type : signed char
    {
        NEAT__DSTR_TY = 1,
        NEAT__STRBUF_TY,
        NEAT__BUF_TY
    } ty;
    union
    {
        Neat_DString *dstr;
        Neat_String_Buffer *strbuf;
        Neat_Buffer buf;
    } str;
} Neat_Mut_String_Ref;

typedef struct Neat_Error
{
    enum Neat_Error_Value : signed char
    {
        NEAT_OK = 0,
        NEAT_DST_TOO_SMALL,
        NEAT_ALLOC_ERR,
        NEAT_INDEX_OUT_OF_BOUNDS,
        NEAT_BAD_RANGE,
        NEAT_NOT_FOUND,
        NEAT_UTF8_ERR,
        NEAT_ALIASING_NOT_SUPPORTED,
        NEAT_INCORRECT_TYPE,
        NEAT_ENCODING_ERROR,
        NEAT_CALLBACK_EXIT
    } ec;
} Neat_Error;

typedef struct Neat__Fixed_Mut_String_Ref
{
    unsigned char *chars;
    unsigned int *len;
    unsigned int cap;
} Neat__Fixed_Mut_String_Ref;

typedef struct Neat__Array_Fmt
{
    const void *array;
    const size_t nb;
    const size_t elm_size;
    
    const Neat_Error(*tostr_p)(Neat_Mut_String_Ref dst, const void *obj);
    
    const Neat_String_View open;
    const Neat_String_View close;
    const Neat_String_View separator;
    const enum {
        NEAT_NO_TRAILING_SEPERATOR = 0,
        NEAT_TRAILING_SEPERATOR,
        NEAT_TRAILING_SEPERATOR_NO_SPACE
    } trailing_separator;
} Neat__Array_Fmt;

#define neat__fmutstr_ref(s, ...) \
_Generic(&(__typeof__(s)){0}, \
    Neat_DString**                          : neat__dstr_ptr_as_fmutstr_ref(neat__coerce(s, Neat_DString*)), \
    Neat_Buffer*                            : neat__buf_as_fmutstr_ref(neat__coerce(s, Neat_Buffer), NEAT__VA_OR(&(unsigned int){0}, __VA_ARGS__)), \
    Neat_String_Buffer**                    : neat__strbuf_ptr_as_fmutstr_ref(neat__coerce(s, Neat_String_Buffer*)), \
    char**                                  : neat__buf_as_fmutstr_ref(neat__buf_from_cstr(neat__coerce(s, char*)), &(unsigned int){0}), \
    unsigned char**                         : neat__buf_as_fmutstr_ref(neat__buf_from_ucstr(neat__coerce(s, unsigned char*)), &(unsigned int){0}), \
    char(*)[sizeof(__typeof__(s))]          : neat__buf_as_fmutstr_ref(neat__buf_from_carr(neat__coerce(s, char*), sizeof(__typeof__(s))), &(unsigned int){0}), \
    unsigned char(*)[sizeof(__typeof__(s))] : neat__buf_as_fmutstr_ref(neat__buf_from_ucarr(neat__coerce(s, unsigned char*), sizeof(__typeof__(s))), &(unsigned int){0}) \
)

#define neat_str_at(any_str, idx)                   \
_Generic(any_str,                                   \
    char*               : neat__cstr_char_at,       \
    unsigned char*      : neat__ucstr_char_at,      \
    Neat_DString        : neat__dstr_char_at,       \
    Neat_DString*       : neat__dstr_ptr_char_at,   \
    Neat_String_View    : neat__strv_char_at,       \
    Neat_String_Buffer  : neat__strbuf_char_at,     \
    Neat_String_Buffer* : neat__strbuf_ptr_char_at, \
    Neat_Mut_String_Ref : neat__mutstr_ref_char_at  \
)((any_str), idx)

#define neat_str_len(any_str) \
_Generic(any_str, \
    char*                     : strlen(neat__coerce_fallback(any_str, char*, "")), \
    unsigned char*            : strlen((char*) neat__coerce_fallback(any_str, unsigned char*, "")), \
    Neat_DString              : ((void)0, neat__coerce(any_str, Neat_DString).len), \
    Neat_DString*             : ((void)0, neat__coerce(any_str, Neat_DString*)->len), \
    Neat_String_View          : ((void)0, neat__coerce(any_str, Neat_String_View).len), \
    Neat_String_Buffer        : ((void)0, neat__coerce(any_str, Neat_String_Buffer).len), \
    Neat_String_Buffer*       : ((void)0, neat__coerce(any_str, Neat_String_Buffer*)->len), \
    Neat_Mut_String_Ref       : ((void)0, neat__mutstr_ref_len(neat__coerce(any_str, Neat_Mut_String_Ref))), \
    const char*               : strlen(neat__coerce_fallback(any_str, const char*, "")), \
    const unsigned char*      : strlen((char*) neat__coerce_fallback(any_str, const unsigned char*, "")), \
    const Neat_DString*       : ((void)0, neat__coerce(any_str, const Neat_DString*)->len), \
    const Neat_String_Buffer* : ((void)0, neat__coerce(any_str, const Neat_String_Buffer*)->len) \
)

static inline uint32_t neat__return_32(unsigned int a)
{
    return a;
}

#define neat_str_cap(any_str)                                             \
_Generic((__typeof__(any_str)*){0},                                       \
    char(*)[sizeof(__typeof__(any_str))]          : neat__return_32,      \
    unsigned char(*)[sizeof(__typeof__(any_str))] : neat__return_32,      \
    Neat_DString*                                 : neat__dstr_cap,       \
    Neat_DString**                                : neat__dstr_ptr_cap,   \
    Neat_String_Buffer*                           : neat__strbuf_cap,     \
    Neat_String_Buffer**                          : neat__strbuf_ptr_cap, \
    Neat_Mut_String_Ref*                          : neat__mutstr_ref_cap  \
)(_Generic((__typeof__(any_str)*){0},                                     \
    char(*)[sizeof(__typeof__(any_str))]: sizeof(any_str),                \
    unsigned char(*)[sizeof(__typeof__(any_str))]: sizeof(any_str), \
    default: (any_str) \
))

#define neat_str_chars(any_str)                     \
_Generic(any_str,                                   \
    char*               : neat__cstr_as_cstr,       \
    unsigned char*      : neat__ucstr_as_cstr,      \
    Neat_DString        : neat__dstr_as_cstr,       \
    Neat_DString*       : neat__dstr_ptr_as_cstr,   \
    Neat_String_View    : neat__strv_as_cstr,       \
    Neat_String_Buffer  : neat__strbuf_as_cstr,     \
    Neat_String_Buffer* : neat__strbuf_ptr_as_cstr, \
    Neat_Mut_String_Ref : neat__mutstr_ref_as_cstr  \
)(any_str)

#define neat_str_equal(any_str1, any_str2) \
neat__strv_equal(neat_str_view(any_str1), neat_str_view(any_str2))

#define neat_str_dup(any_str, ...) \
neat__dstr_init_from(neat_str_view(any_str), NEAT__VA_OR(neat_get_default_allocator(), __VA_ARGS__))

#define neat_str_copy(any_str_dst, any_str_src) \
_Generic(any_str_dst, \
    Neat_Mut_String_Ref : neat__mutstr_ref_copy(neat__coerce(any_str_dst, Neat_Mut_String_Ref), neat_str_view(any_str_src)), \
    Neat_DString*       : neat__mutstr_ref_copy(neat__dstr_ptr_as_mutstr_ref(neat__coerce(any_str_dst, Neat_DString*)), neat_str_view(any_str_src)), \
    default             : neat__fmutstr_ref_copy(neat__fmutstr_ref(neat__coerce_not(any_str_dst, Neat_Mut_String_Ref, Neat_String_Buffer*)), neat_str_view(any_str_src)) \
)

#define neat_str_putc(any_str_dst, c) \
_Generic(any_str_dst, \
    Neat_Mut_String_Ref : neat__mutstr_ref_putc(neat__coerce(any_str_dst, Neat_Mut_String_Ref), c), \
    Neat_DString*       : neat__mutstr_ref_putc(neat__dstr_ptr_as_mutstr_ref(neat__coerce(any_str_dst, Neat_DString*)), c), \
    default             : neat__fmutstr_ref_putc(neat__fmutstr_ref(neat__coerce_not(any_str_dst, Neat_Mut_String_Ref, Neat_String_Buffer*)), c) \
)

#define neat_str_append(any_str_dst, any_str_src) \
_Generic(any_str_dst, \
    Neat_Mut_String_Ref : neat__mutstr_ref_append(neat__coerce(any_str_dst, Neat_Mut_String_Ref), neat_str_view(any_str_src)), \
    Neat_DString*       : neat__dstr_append_strv(neat__coerce(any_str_dst, Neat_DString*), neat_str_view(any_str_src)), \
    default             : neat__fmutstr_ref_append_strv(neat__fmutstr_ref(neat__coerce_not(any_str_dst, Neat_Mut_String_Ref, Neat_String_Buffer*)), neat_str_view(any_str_src)) \
)

#define neat_str_insert(any_str_dst, any_str_src, idx) \
_Generic(any_str_dst, \
    Neat_Mut_String_Ref : neat__mutstr_ref_insert(neat__coerce(any_str_dst, Neat_Mut_String_Ref), neat_str_view(any_str_src), idx), \
    Neat_DString*       : neat__dstr_insert_strv(neat__coerce(any_str_dst, Neat_DString*), neat_str_view(any_str_src), idx), \
    default             : neat__fmutstr_ref_insert(neat__fmutstr_ref(neat__coerce_not(any_str_dst, Neat_Mut_String_Ref, Neat_String_Buffer*)), neat_str_view(any_str_src), idx) \
)

#define neat_str_prepend(neat_str_dst, neat_str_src) \
neat_str_insert(neat_str_dst, neat_str_src, 0)

#define neat_str_find(any_str_hay, any_str_needle) \
neat__strv_find(neat_str_view(any_str_hay), neat_str_view(any_str_needle))

#define neat_str_count(any_str_hay, any_str_needle) \
neat__strv_count(neat_str_view(any_str_hay), neat_str_view(any_str_needle))

#define neat_str_clear(any_str) \
neat__mutstr_ref_clear(neat__mutstr_ref(any_str))

#define neat_str_starts_with(any_str_hay, any_str_needle) \
neat__strv_starts_with(neat_str_view(any_str_hay), neat_str_view(any_str_needle))

#define neat_str_ends_with(any_str_hay, any_str_needle) \
neat__strv_ends_with(neat_str_view(any_str_hay), neat_str_view(any_str_needle))

#define neat_str_tolower(any_str) \
neat__mutstr_ref_tolower(neat_mutstr_ref(any_str))

#define neat_str_toupper(any_str) \
neat__mutstr_ref_toupper(neat_mutstr_ref(any_str))

#define neat_str_replace(any_str, any_str_target, any_str_replacement) \
_Generic(any_str, \
    Mut_String_Ref : neat__mutstr_ref_replace(neat__coerce(any_str, Neat_Mut_String_Ref), neat_str_view(any_str_target), neat_str_view(any_str_replacement)), \
    Neat_DString*  : neat__mutstr_ref_replace(neat__mutstr_ref(any_str), neat_str_view(any_str_target), neat_str_view(any_str_replacement)), \
    default        : neat__fmutstr_ref_replace(neat__fmutstr_ref(neat__coerce_not(any_str, Neat_Mut_String_Ref, Neat_String_Buffer*)), neat_str_view(any_str_target), neat_str_view(any_str_replacement)) \
)

#define neat_str_replace_first(any_str, any_str_target, any_str_replacement) \
_Generic(any_str, \
    Neat_Mut_String_Ref : neat__mutstr_ref_replace_first(neat__coerce(any_str, Neat_Mut_String_Ref), neat_str_view(any_str_target), neat_str_view(any_str_replacement)), \
    Neat_DString*       : neat__mutstr_ref_replace_first(neat__mutstr_ref(any_str), neat_str_view(any_str_target), neat_str_view(any_str_replacement)), \
    default             : neat__fmutstr_ref_replace_first(neat__fmutstr_ref(neat__coerce_not(any_str, Neat_Mut_String_Ref, Neat_String_Buffer*)), neat_str_view(any_str_target), neat_str_view(any_str_replacement)) \
)

#define neat_str_replace_range(any_str, begin, end, any_str_replacement) \
_Generic(any_str, \
    Neat_Mut_String_Ref : neat__mutstr_ref_replace_range(neat__coerce(any_str, Neat_Mut_String_Ref), begin, end, neat_str_view(any_str_replacement)), \
    Neat_DString*       : neat__mutstr_ref_replace_range(neat_mutstr_ref(any_str), begin, end, neat_str_view(any_str_replacement)) \
    default              : neat__fmutstr_ref_replace_range(neat__fmutstr_ref(neat__coerce_not(any_str, Neat_Mut_String_Ref, Neat_String_Buffer*), begin, end, neat_str_view(any_str_replacement))) \
)

#define neat_str_split(any_str, any_str_delim, ...) \
neat__strv_split(neat_str_view(any_str), neat_str_view(any_str_delim), NEAT__VA_OR(neat_get_default_allocator(), __VA_ARGS__))

#define neat_str_split_iter(any_str, any_str_delim, callback, ...) \
neat__strv_split_iter(neat_str_view(any_str), neat_str_view(any_str_delim), callback, NEAT__VA_OR(NULL, __VA_ARGS__));

#define neat_str_join(any_str_dst, strv_arr, any_str_delim) \
neat__strv_arr_join(neat_mutstr_ref(any_str_dst), strv_arr, neat_str_view(any_str_delim))

#define neat_str_del(any_str, begin, end) \
_Generic(any_str, \
    Neat_Mut_String_Ref : neat__mutstr_ref_delete_range(neat__coerce(any_str, Neat_Mut_String_Ref), begin, end), \
    Neat_DString*       : neat__mutstr_ref_delete_range(neat__dstr_ptr_as_mutstr_ref(neat__coerce(any_str, Neat_DString*)), begin, end), \
    default             : neat__fmutstr_ref_delete_range(neat__fmutstr_ref(neat__coerce_not(any_str, Neat_Mut_String_Ref, Neat_String_Buffer*)), begin, end) \
)

#define neat_str_fread_line(any_str, stream) \
_Generic(any_str, \
    Neat_Mut_String_Ref : neat__mutstr_ref_fread_line(neat__coerce(any_str, Neat_Mut_String_Ref), stream), \
    Neat_DString*       : neat__dstr_fread_line(neat__coerce(any_str, Neat_DString*), stream), \
    default             : neat__fmutstr_ref_fread_line(neat__fmutstr_ref(neat__coerce_not(any_str, Neat_Mut_String_Ref, Neat_String_Buffer*)), stream) \
)

#define neat_str_append_fread_line(any_str, stream) \
_Generic(any_str, \
    Neat_Mut_String_Ref : neat__mutstr_ref_append_fread_line(neat__coerce(any_str, Neat_Mut_String_Ref), stream), \
    Neat_DString*       : neat__dstr_append_fread_line(neat__coerce(any_str, Neat_DString*), stream), \
    default             : neat__fmutstr_ref_append_fread_line(neat__fmutstr_ref(neat__coerce_not(any_str, Neat_Mut_String_Ref, Neat_String_Buffer*)), stream) \
)

#define neat_str_read_line(any_str) \
neat_str_fread_line(any_str, stdin)

#define neat_str_append_read_line(any_str) \
neat_str_append_fread_line(any_str, stdin)

// helper macro
#define neat__str_print_each(x) \
do \
{ \
    Neat_Mut_String_Ref neat__appender_mutstr_ref = neat__make_appender_mutstr_ref( \
        neat__as_mutstr_ref, \
        &neat__appender_dstr_opt, \
        &neat__appender_dstr_allocator_opt, \
        &neat__appender_strbuf_opt \
    ); \
    neat_tostr(neat__appender_mutstr_ref, x); \
    neat__mutstr_ref_commit_appender( \
        neat__as_mutstr_ref, \
        neat__appender_mutstr_ref \
    ); \
} while(0);

#define neat__str_print_each_setup(...) \
__VA_OPT__( \
    Neat_DString neat__appender_dstr_opt = {0}; \
    Neat__DString_Append_Allocator neat__appender_dstr_allocator_opt = {0}; \
    Neat_String_Buffer neat__appender_strbuf_opt = {0}; \
    NEAT__FOREACH(neat__str_print_each, __VA_ARGS__); \
)

#define neat__str_print_append(...) \
__VA_OPT__( \
do \
{ \
    typedef struct Neat__DString_Append_Allocator \
    { \
        Neat_Allocator funcs; \
        struct Neat_DString *owner; \
    } Neat__DString_Append_Allocator; \
    \
    Neat_Mut_String_Ref neat__make_appender_mutstr_ref(Neat_Mut_String_Ref owner, Neat_DString *appender_dstr_opt, void *dstr_appender_allocator, Neat_String_Buffer *appender_strbuf_opt); \
    Neat_Error neat__mutstr_ref_commit_appender(Neat_Mut_String_Ref owner, Neat_Mut_String_Ref appender); \
    \
    neat__str_print_each_setup(__VA_ARGS__); \
} while(0) \
)

#define neat_str_print_append(any_str_dst, ...) \
do \
{ \
    Neat_Mut_String_Ref neat__as_mutstr_ref = neat_mutstr_ref(any_str_dst); \
    neat__str_print_append(__VA_ARGS__); \
} while(0)

#define neat_str_print(any_str_dst, ...) \
do \
{ \
    Neat_Mut_String_Ref neat__as_mutstr_ref = neat_mutstr_ref(any_str_dst); \
    neat_str_clear(neat__as_mutstr_ref); \
    neat__str_print_append(__VA_ARGS__); \
} while(0)

#define neat_str_view_arr_from_carr(strv_carr, ...) \
neat__strv_arr_from_carr(strv_carr, NEAT__VA_OR(NEAT__CARR_LEN(strv_carr), __VA_ARGS__))

#define NEAT__STRV_COMMA(any_str) \
neat_str_view(any_str),

#define neat_str_view_arr(...)                                                                    \
(                                                                                                 \
(Neat_String_View_Array) {                                                                        \
    .len  = NEAT__CARR_LEN(((Neat_String_View[]){NEAT__FOREACH(NEAT__STRV_COMMA, __VA_ARGS__)})), \
    .cap  = NEAT__CARR_LEN(((Neat_String_View[]){NEAT__FOREACH(NEAT__STRV_COMMA, __VA_ARGS__)})), \
    .strs = (Neat_String_View[]){NEAT__FOREACH(NEAT__STRV_COMMA, __VA_ARGS__)}                    \
}                                                                                                 \
)

// Calls strlen on the cstr to determine its length
// if no capacity is passed, then:
// if char[] is passed, it uses the size of the array as capacity
// if char* is passed, the capacity is length+1
#define neat_strbuf_init_from_cstr(cstr, ...) \
__VA_OPT__(neat__strbuf_init_from_cstr_2(cstr, __VA_ARGS__)) \
NEAT__IF_EMPTY(neat__strbuf_init_from_cstr_(cstr), __VA_ARGS__)

#define neat__strbuf_init_from_cstr_(cstr) \
neat__strbuf_from_cstr(cstr,                                          \
_Generic(&(__typeof__(cstr)){0},                                      \
char(*)[sizeof(__typeof__(cstr))]         : sizeof(__typeof__(cstr)), \
unsigned char(*)[sizeof(__typeof__(cstr))]: sizeof(__typeof__(cstr)), \
char**                                    : strlen((char*) cstr) + 1, \
unsigned char**                           : strlen((char*) cstr) + 1  \
))

#define neat__strbuf_init_from_cstr_2(cstr, cap) \
neat__strbuf_from_cstr(cstr, cap)

// Does not call strlen on the buf
// Sets the first byte to '\0'
#define neat_strbuf_init_from_buf(buf, ...) \
__VA_OPT__( neat__strbuf_init_from_buf_2(buf, __VA_ARGS__) ) \
NEAT__IF_EMPTY(neat__strbuf_init_from_buf_(buf), __VA_ARGS__)

#define neat__strbuf_init_from_buf_(buf) \
neat__strbuf_from_buf( \
_Generic(&(__typeof__(buf)){0}, \
    char(*)[sizeof(__typeof__(buf))]: (Neat_Buffer){.ptr = (unsigned char*) (buf), .cap = sizeof(buf)}, \
    unsigned char(*)[sizeof(__typeof__(buf))]: (Neat_Buffer){.ptr = (unsigned char*) (buf), .cap = sizeof(buf)}, \
    Neat_Buffer*: buf \
))

#define neat__strbuf_init_from_buf_2(buf, cap_) \
neat__strbuf_from_buf((Neat_Buffer){.ptr = buf, .cap = cap_})

#define neat__cstr_to_buf(carr, ...) \
( \
NEAT__IF_EMPTY( \
    _Generic((__typeof__(carr)*){0}, \
        char(*)[sizeof(__typeof__(carr))]: (Neat_Buffer){.ptr = (unsigned char*) (carr), .cap = sizeof(carr)}, \
        unsigned char(*)[sizeof(__typeof__(any_str))]: (Neat_Buffer){.ptr = (unsigned char*) (carr), .cap = sizeof(carr)} \
    ), \
    __VA_ARGS__ \
) \
__VA_OPT__(neat__cstr_to_buf2((carr), __VA_ARGS__)) \
)

#define neat__cstr_to_buf2(carr_or_ptr, cap_) \
((void)_Generic(carr_or_ptr, \
    char(*)[sizeof(__typeof__(carr_or_ptr))]: 0, \
    unsigned char(*)[sizeof(__typeof__(carr_or_ptr))]: 0, \
    char*: 0, \
    unsigned char*: 0 \
), \
(Neat_Buffer){.ptr = (unsigned char*) (carr_or_ptr), .cap = (cap_)})

#define neat_mutstr_ref(any_str, ...) \
NEAT__CAT(neat__mutstr_ref, __VA_OPT__(2))((any_str) __VA_OPT__(,) __VA_ARGS__)

#define neat__mutstr_ref(any_str)                                              \
_Generic((__typeof__(any_str)*){0},                                            \
char**                                       : neat__cstr_as_mutstr_ref,       \
unsigned char**                              : neat__ucstr_as_mutstr_ref,      \
Neat_DString**                               : neat__dstr_ptr_as_mutstr_ref,   \
Neat_String_Buffer**                         : neat__strbuf_ptr_as_mutstr_ref, \
Neat_Mut_String_Ref*                         : neat__mutstr_ref_as_mutstr_ref, \
char(*)[sizeof(__typeof__(any_str))]         : neat__buf_as_mutstr_ref,        \
unsigned char(*)[sizeof(__typeof__(any_str))]: neat__buf_as_mutstr_ref         \
)(_Generic((__typeof__(any_str)*){0},                                          \
    char(*)[sizeof(__typeof__(any_str))]: (Neat_Buffer){.ptr = (unsigned char*) neat__coerce(any_str, char*), .cap = sizeof(__typeof__(any_str))}, \
    unsigned char(*)[sizeof(__typeof__(any_str))]: (Neat_Buffer){.ptr = neat__coerce(any_str, unsigned char*), .cap = sizeof(__typeof__(any_str))}, \
    default: (any_str) \
))

#define neat__mutstr_ref2(carr_or_ptr, cap_) \
(Neat_Mut_String_Ref){.ty = NEAT__BUF_TY, .str.carr = neat__cstr_to_buf(carr_or_ptr, cap_)} \

#define neat_str_view(any_str, ...) \
__VA_OPT__(neat__strv2(any_str, __VA_ARGS__)) \
NEAT__IF_EMPTY(neat__strv1(any_str), __VA_ARGS__)

#define neat__strv1(any_str) \
_Generic(any_str,                                       \
    char*                     : neat__strv_cstr1,       \
    unsigned char*            : neat__strv_ucstr1,      \
    Neat_DString              : neat__strv_dstr1,       \
    Neat_DString*             : neat__strv_dstr_ptr1,   \
    Neat_String_View          : neat__strv_strv1,       \
    Neat_String_Buffer        : neat__strv_strbuf1,     \
    Neat_String_Buffer*       : neat__strv_strbuf_ptr1, \
    Neat_Mut_String_Ref       : neat__strv_mutstr_ref1, \
    const char*               : neat__strv_cstr1,       \
    const unsigned char*      : neat__strv_ucstr1,      \
    const Neat_DString*       : neat__strv_dstr_ptr1,   \
    const Neat_String_Buffer* : neat__strv_strbuf_ptr1  \
)(any_str)

#define neat__strv2(any_str, begin, ...)                \
__VA_OPT__(neat__strv3(any_str, begin, __VA_ARGS__))    \
NEAT__IF_EMPTY(                                         \
_Generic(any_str,                                       \
    char*               : neat__strv_cstr2,             \
    unsigned char*      : neat__strv_ucstr2,            \
    Neat_DString        : neat__strv_dstr2,             \
    Neat_DString*       : neat__strv_dstr_ptr2,         \
    Neat_String_View    : neat__strv_strv2,             \
    Neat_String_Buffer  : neat__strv_strbuf2,           \
    Neat_String_Buffer* : neat__strv_strbuf_ptr2,       \
    Neat_Mut_String_Ref : neat__strv_mutstr_ref2,       \
    const char*               : neat__strv_cstr2,       \
    const unsigned char*      : neat__strv_ucstr2,      \
    const Neat_DString*       : neat__strv_dstr_ptr2,   \
    const Neat_String_Buffer* : neat__strv_strbuf_ptr2  \
)(any_str, begin), __VA_ARGS__)

#define neat__strv3(any_str, begin, end)                \
_Generic(any_str,                                       \
    char*               : neat__strv_cstr3,             \
    unsigned char*      : neat__strv_ucstr3,            \
    Neat_DString        : neat__strv_dstr3,             \
    Neat_DString*       : neat__strv_dstr_ptr3,         \
    Neat_String_View    : neat__strv_strv3,             \
    Neat_String_Buffer  : neat__strv_strbuf3,           \
    Neat_String_Buffer* : neat__strv_strbuf_ptr3,       \
    Neat_Mut_String_Ref : neat__strv_mutstr_ref3,       \
    const char*               : neat__strv_cstr3,       \
    const unsigned char*      : neat__strv_ucstr3,      \
    const Neat_DString*       : neat__strv_dstr_ptr3,   \
    const Neat_String_Buffer* : neat__strv_strbuf_ptr3  \
)(any_str, begin, end)

#define neat_dstr_init(...) \
NEAT__CAT(neat__dstr_init0, __VA_OPT__(1))(__VA_ARGS__)

#define neat__dstr_init0() \
neat__dstr_init(0, neat_get_default_allocator())

#define neat__dstr_init01(cap, ...)              \
__VA_OPT__(neat__dstr_init2((cap), __VA_ARGS__)) \
NEAT__IF_EMPTY(                                  \
    neat__dstr_init(                            \
        (cap),                                  \
        neat_get_default_allocator()            \
    )                                           \
, __VA_ARGS__                                   \
)

#define neat__dstr_init2(cap, allocator) \
neat__dstr_init((cap), (allocator))

#define neat_dstr_init_from(str, ...) \
neat__dstr_init_from(neat_str_view(str), NEAT__VA_OR(neat_get_default_allocator(), __VA_ARGS__))

#define neat_dstr_deinit(dstr) \
neat__dstr_deinit(dstr)

#define neat_dstr_append(dstr, any_str) \
neat__dstr_append_strv(dstr, neat_str_view(any_str))

#define neat_dstr_prepend(dstr, any_str) \
neat__dstr_prepend_strv(dstr, neat_str_view(any_str))

#define neat_dstr_insert(dstr, any_str, idx) \
neat__dstr_insert_strv(dstr, neat_str_view(any_str), idx)

#define neat_dstr_fread_line(dstr, stream) \
neat__dstr_fread_line(dstr, stream)

#define neat_dstr_read_line(dstr) \
neat__dstr_fread_line(dstr, stdin)

#define neat_dstr_append_fread_line(dstr, stream) \
neat__dstr_append_fread_line(dstr, stream)

#define neat_dstr_append_read_line(dstr) \
neat__dstr_append_fread_line(dstr, stdin)

#define neat_dstr_shrink_to_fit(dstr) \
neat__dstr_shrink_to_fit(dstr)

#define neat_dstr_ensure_cap(dstr, new_cap) \
neat__dstr_ensure_cap(dstr, new_cap)

#define neat_fprint(f, ...)                        \
do                                                 \
{                                                  \
    FILE *neat__file_stream = f;                   \
    (void) neat__file_stream;                      \
    extern _Thread_local Neat_DString neat__fprint_tostr_dynamic_buffer; \
    NEAT__FOREACH(neat__fprint_each, __VA_ARGS__); \
} while(0)

#define neat__fprint_each(x)                                \
do                                                          \
{                                                           \
    neat__fprint_strv(neat__file_stream, _Generic(x,        \
        char*                     : neat__strv_cstr1,       \
        unsigned char*            : neat__strv_ucstr1,      \
        Neat_DString              : neat__strv_dstr1,       \
        Neat_DString*             : neat__strv_dstr_ptr1,   \
        Neat_String_View          : neat__strv_strv1,       \
        Neat_String_Buffer        : neat__strv_strbuf1,     \
        Neat_String_Buffer*       : neat__strv_strbuf_ptr1, \
        Neat_Mut_String_Ref       : neat__strv_mutstr_ref1, \
        const char*               : neat__strv_cstr1,       \
        const unsigned char*      : neat__strv_ucstr1,      \
        const Neat_DString*       : neat__strv_dstr_ptr1,   \
        const Neat_String_Buffer* : neat__strv_strbuf_ptr1, \
        default                   : neat__strv_dstr1        \
    )(neat__coerce_string_type(x, (neat_tostr(&neat__fprint_tostr_dynamic_buffer, x), neat__fprint_tostr_dynamic_buffer)))); \
    neat__fprint_tostr_dynamic_buffer.len = 0;              \
} while(0);

#define neat_print(...) \
neat_fprint(stdout, __VA_ARGS__)

#define neat_fprintln(f, ...)                 \
do                                            \
{                                             \
    FILE *neat__tmp_file = f;                 \
    (void) neat__tmp_file;                    \
    neat_fprint(neat__tmp_file, __VA_ARGS__); \
    fputc('\n', neat__tmp_file);              \
} while(0)

#define neat_println(...) \
neat_fprintln(stdout, __VA_ARGS__)

typedef char neat__c;
typedef signed char neat__sc;
typedef unsigned char neat__uc;
typedef short neat__s;
typedef unsigned short neat__us;
typedef int neat__i;
typedef unsigned int neat__ui;
typedef long neat__l;
typedef unsigned long neat__ul;
typedef long long neat__ll;
typedef unsigned long long neat__ull;

#define NEAT__MCALL(macro, arglist) macro arglist

#define NEAT__INTEGER_TYPES(NEAT__X, extra, ...) \
NEAT__X(neat__c, extra)  \
NEAT__X(neat__sc, extra) \
NEAT__X(neat__uc, extra) \
NEAT__X(neat__s, extra)  \
NEAT__X(neat__us, extra) \
NEAT__X(neat__i, extra)  \
NEAT__X(neat__ui, extra) \
NEAT__X(neat__l, extra)  \
NEAT__X(neat__ul, extra) \
NEAT__X(neat__ll, extra) \
NEAT__MCALL(NEAT__VA_OR(NEAT__X, __VA_ARGS__), (neat__ull, extra))

#define NEAT__FLOATING_TYPES(NEAT__X, extra, last_call) \
NEAT__X(float, extra) \
last_call(double, extra)

#define NEAT__X(ty, extra) \
typedef struct Neat__Integer_d_Fmt_##ty \
{ \
    ty obj; \
} Neat__Integer_d_Fmt_##ty; \
typedef struct Neat__Integer_x_Fmt_##ty \
{ \
    ty obj; \
} Neat__Integer_x_Fmt_##ty; \
typedef struct Neat__Integer_o_Fmt_##ty \
{ \
    ty obj; \
} Neat__Integer_o_Fmt_##ty; \
typedef struct Neat__Integer_b_Fmt_##ty \
{ \
    ty obj; \
} Neat__Integer_b_Fmt_##ty;

NEAT__INTEGER_TYPES(NEAT__X, ignore)

#undef NEAT__X

#define NEAT__X(ty, extra) \
typedef struct Neat__Floating_f_Fmt_##ty \
{ \
    ty obj; \
    int precision; \
} Neat__Floating_f_Fmt_##ty; \
typedef struct Neat__Floating_g_Fmt_##ty \
{ \
    ty obj; \
    int precision; \
} Neat__Floating_g_Fmt_##ty; \
typedef struct Neat__Floating_e_Fmt_##ty \
{ \
    ty obj; \
    int precision; \
} Neat__Floating_e_Fmt_##ty; \
typedef struct Neat__Floating_a_Fmt_##ty \
{ \
    ty obj; \
    int precision; \
} Neat__Floating_a_Fmt_##ty; \

NEAT__FLOATING_TYPES(NEAT__X, ignore, NEAT__X)

#undef NEAT__X

#define NEAT__X_IS_TY(ty, extra) \
ty: 1,

#define NEAT__IS_FLOATING(obj) \
_Generic(obj, \
NEAT__FLOATING_TYPES(NEAT__X_IS_TY, ignore, NEAT__X_IS_TY) \
default: 0)

#define NEAT__IS_INTEGER(obj) \
_Generic(obj, \
NEAT__INTEGER_TYPES(NEAT__X_IS_TY, ignore) \
default: 0)

#define NEAT__INTEGER_FMT_GENERIC_BRANCHES(ty, extra) \
ty: \
_Generic((char(*)[NEAT__ARG2 extra]){0}, \
char(*)['d']: (Neat__Integer_d_Fmt_##ty){neat__coerce(NEAT__ARG1 extra, ty)},  \
char(*)['x']: (Neat__Integer_x_Fmt_##ty)    {neat__coerce(NEAT__ARG1 extra, ty)},  \
char(*)['o']: (Neat__Integer_o_Fmt_##ty)  {neat__coerce(NEAT__ARG1 extra, ty)},  \
char(*)['b']: (Neat__Integer_b_Fmt_##ty) {neat__coerce(NEAT__ARG1 extra, ty)},  \
default: 0),

#define NEAT__3_VA_OR(otherwise, a,b, ...) \
NEAT__VA_OR(otherwise, __VA_ARGS__)

#define NEAT__FLOATING_FMT_LAST_GENERIC_BRANCH(ty, extra) \
ty: \
_Generic((char(*)[NEAT__ARG2 extra]){0}, \
char(*)['f']: (Neat__Floating_f_Fmt_##ty){neat__coerce(NEAT__ARG1 extra, ty), NEAT__MCALL(NEAT__3_VA_OR, (6, NEAT__EXPAND1 extra))},   \
char(*)['g']: (Neat__Floating_g_Fmt_##ty){neat__coerce(NEAT__ARG1 extra, ty), NEAT__MCALL(NEAT__3_VA_OR, (6, NEAT__EXPAND1 extra))},   \
char(*)['e']: (Neat__Floating_e_Fmt_##ty){neat__coerce(NEAT__ARG1 extra, ty), NEAT__MCALL(NEAT__3_VA_OR, (6, NEAT__EXPAND1 extra))},   \
char(*)['a']: (Neat__Floating_a_Fmt_##ty){neat__coerce(NEAT__ARG1 extra, ty), NEAT__MCALL(NEAT__3_VA_OR, (-1, NEAT__EXPAND1 extra))},  \
default: 0)

#define NEAT__FLOATING_FMT_GENERIC_BRANCH(ty, extra) \
NEAT__FLOATING_FMT_LAST_GENERIC_BRANCH(ty, extra),

#define neat_tsfmt(x, fmt_chr, ...) \
( \
    neat__static_assertx( (NEAT__IS_FLOATING(x) && (fmt_chr == 'f' || fmt_chr == 'g' || fmt_chr == 'e' || fmt_chr == 'a')  ) || (NEAT__IS_INTEGER(x) && (fmt_chr == 'd' || fmt_chr == 'x' || fmt_chr == 'o' || fmt_chr == 'b')), "Incorrect formatting char for the type"), \
    neat__static_assertx((NEAT__IS_FLOATING(x) || (1 __VA_OPT__(-1))), "tsfmt Integers dont take a third parameter"), \
    _Generic(x, \
        NEAT__INTEGER_TYPES(NEAT__INTEGER_FMT_GENERIC_BRANCHES, (x, fmt_chr)) \
        NEAT__FLOATING_TYPES(NEAT__FLOATING_FMT_GENERIC_BRANCH, (x, fmt_chr __VA_OPT__(,) __VA_ARGS__), NEAT__FLOATING_FMT_LAST_GENERIC_BRANCH) \
    ) \
)

#undef NEAT__X

#define neat_arrfmt(array_, nb_, open_, close_, seperator_, ...) \
((Neat__Array_Fmt){ \
    .array = (array_), \
    .nb = (nb_), \
    .elm_size = sizeof((array_)[0]), \
    .tostr_p = (void*) neat__get_tostr_p_func(__typeof__((array_)[0])), \
    .open = neat_str_view(open_), \
    .close = neat_str_view(close_), \
    .separator = neat_str_view(seperator_), \
    .trailing_separator = __VA_ARGS__ +0 \
})

#define NEAT__INTEGER_TOSTR_GENERIC_CASE(ty, extra) \
Neat__Integer_d_Fmt_##ty : neat__Integer_d_Fmt_##ty##_tostr, \
Neat__Integer_x_Fmt_##ty : neat__Integer_x_Fmt_##ty##_tostr, \
Neat__Integer_o_Fmt_##ty : neat__Integer_o_Fmt_##ty##_tostr, \
Neat__Integer_b_Fmt_##ty : neat__Integer_b_Fmt_##ty##_tostr, \

#define NEAT__FLOATING_TOSTR_LAST_GENERIC_CASE(ty, extra) \
Neat__Floating_f_Fmt_##ty : neat__Floating_f_Fmt_##ty##_tostr, \
Neat__Floating_g_Fmt_##ty : neat__Floating_g_Fmt_##ty##_tostr, \
Neat__Floating_e_Fmt_##ty : neat__Floating_e_Fmt_##ty##_tostr, \
Neat__Floating_a_Fmt_##ty : neat__Floating_a_Fmt_##ty##_tostr

#define NEAT__INTEGER_TOSTR_P_GENERIC_CASE(ty, extra) \
Neat__Integer_d_Fmt_##ty : neat__Integer_d_Fmt_##ty##_tostr_p, \
Neat__Integer_x_Fmt_##ty : neat__Integer_x_Fmt_##ty##_tostr_p, \
Neat__Integer_o_Fmt_##ty : neat__Integer_o_Fmt_##ty##_tostr_p, \
Neat__Integer_b_Fmt_##ty : neat__Integer_b_Fmt_##ty##_tostr_p, \

#define NEAT__FLOATING_TOSTR_P_LAST_GENERIC_CASE(ty, extra) \
Neat__Floating_f_Fmt_##ty : neat__Floating_f_Fmt_##ty##_tostr_p, \
Neat__Floating_g_Fmt_##ty : neat__Floating_g_Fmt_##ty##_tostr_p, \
Neat__Floating_e_Fmt_##ty : neat__Floating_e_Fmt_##ty##_tostr_p, \
Neat__Floating_a_Fmt_##ty : neat__Floating_a_Fmt_##ty##_tostr_p

#define NEAT__FLOATING_TOSTR_GENERIC_CASE(ty, extra) \
NEAT__FLOATING_TOSTR_LAST_GENERIC_CASE(ty, extra),

#define NEAT__FLOATING_TOSTR_P_GENERIC_CASE(ty, extra) \
NEAT__FLOATING_TOSTR_P_LAST_GENERIC_CASE(ty, extra),

#define NEAT__DEFAULT_TOSTR_GENERIC_BRANCHES                  \
bool                      : neat__bool_tostr,                 \
char*                     : neat__cstr_tostr,                 \
unsigned char*            : neat__ucstr_tostr,                \
char                      : neat__char_tostr,                 \
signed char               : neat__schar_tostr,                \
unsigned char             : neat__uchar_tostr,                \
short                     : neat__short_tostr,                \
unsigned short            : neat__ushort_tostr,               \
int                       : neat__int_tostr,                  \
unsigned int              : neat__uint_tostr,                 \
long                      : neat__long_tostr,                 \
unsigned long             : neat__ulong_tostr,                \
long long                 : neat__llong_tostr,                \
unsigned long long        : neat__ullong_tostr,               \
float                     : neat__float_tostr,                \
double                    : neat__double_tostr,               \
Neat_DString              : neat__dstr_tostr,                 \
Neat_DString*             : neat__dstr_ptr_tostr,             \
Neat_String_View          : neat__strv_tostr,                 \
Neat_String_Buffer        : neat__strbuf_tostr,               \
Neat_String_Buffer*       : neat__strbuf_ptr_tostr,           \
Neat_Mut_String_Ref       : neat__mutstr_ref_tostr,           \
const char*               : neat__cstr_tostr,                 \
const unsigned char*      : neat__ucstr_tostr,                \
const Neat_DString*       : neat__dstr_ptr_tostr,             \
const Neat_String_Buffer* : neat__strbuf_ptr_tostr,           \
Neat_Error                : neat__error_tostr,                \
Neat__Array_Fmt           : neat__array_fmt_tostr,            \
NEAT__INTEGER_TYPES(NEAT__INTEGER_TOSTR_GENERIC_CASE, ignore) \
NEAT__FLOATING_TYPES(NEAT__FLOATING_TOSTR_GENERIC_CASE, ignore, NEAT__FLOATING_TOSTR_LAST_GENERIC_CASE)

#define NEAT__DEFAULT_TOSTR_P_GENERIC_BRANCHES                  \
bool                      : neat__bool_tostr_p,                 \
char*                     : neat__cstr_tostr_p,                 \
unsigned char*            : neat__ucstr_tostr_p,                \
char                      : neat__char_tostr_p,                 \
signed char               : neat__schar_tostr_p,                \
unsigned char             : neat__uchar_tostr_p,                \
short                     : neat__short_tostr_p,                \
unsigned short            : neat__ushort_tostr_p,               \
int                       : neat__int_tostr_p,                  \
unsigned int              : neat__uint_tostr_p,                 \
long                      : neat__long_tostr_p,                 \
unsigned long             : neat__ulong_tostr_p,                \
long long                 : neat__llong_tostr_p,                \
unsigned long long        : neat__ullong_tostr_p,               \
float                     : neat__float_tostr_p,                \
double                    : neat__double_tostr_p,               \
Neat_DString              : neat__dstr_tostr_p,                 \
Neat_DString*             : neat__dstr_ptr_tostr_p,             \
Neat_String_View          : neat__strv_tostr_p,                 \
Neat_String_Buffer        : neat__strbuf_tostr_p,               \
Neat_String_Buffer*       : neat__strbuf_ptr_tostr_p,           \
Neat_Mut_String_Ref       : neat__mutstr_ref_tostr_p,           \
const char*               : neat__cstr_tostr_p,                 \
const unsigned char*      : neat__ucstr_tostr_p,                \
const Neat_DString*       : neat__dstr_ptr_tostr_p,             \
const Neat_String_Buffer* : neat__strbuf_ptr_tostr_p,           \
Neat_Error                : neat__error_tostr_p,                \
NEAT__INTEGER_TYPES(NEAT__INTEGER_TOSTR_P_GENERIC_CASE, ignore) \
NEAT__FLOATING_TYPES(NEAT__FLOATING_TOSTR_P_GENERIC_CASE, ignore, NEAT__FLOATING_TOSTR_P_LAST_GENERIC_CASE)

#define NEAT__TOSTR_FUNCS_GENERIC_BRANCHES                             \
NEAT__IF_DEF(NEAT__TOSTR1) (neat__tostr_type_1 : neat__tostr_func_1,)  \
NEAT__IF_DEF(NEAT__TOSTR2) (neat__tostr_type_2 : neat__tostr_func_2,)  \
NEAT__IF_DEF(NEAT__TOSTR3) (neat__tostr_type_3 : neat__tostr_func_3,)  \
NEAT__IF_DEF(NEAT__TOSTR4) (neat__tostr_type_4 : neat__tostr_func_4,)  \
NEAT__IF_DEF(NEAT__TOSTR5) (neat__tostr_type_5 : neat__tostr_func_5,)  \
NEAT__IF_DEF(NEAT__TOSTR6) (neat__tostr_type_6 : neat__tostr_func_6,)  \
NEAT__IF_DEF(NEAT__TOSTR7) (neat__tostr_type_7 : neat__tostr_func_7,)  \
NEAT__IF_DEF(NEAT__TOSTR8) (neat__tostr_type_8 : neat__tostr_func_8,)  \
NEAT__IF_DEF(NEAT__TOSTR9) (neat__tostr_type_9 : neat__tostr_func_9,)  \
NEAT__IF_DEF(NEAT__TOSTR10)(neat__tostr_type_10: neat__tostr_func_10,) \
NEAT__IF_DEF(NEAT__TOSTR11)(neat__tostr_type_11: neat__tostr_func_11,) \
NEAT__IF_DEF(NEAT__TOSTR12)(neat__tostr_type_12: neat__tostr_func_12,) \
NEAT__IF_DEF(NEAT__TOSTR13)(neat__tostr_type_13: neat__tostr_func_13,) \
NEAT__IF_DEF(NEAT__TOSTR14)(neat__tostr_type_14: neat__tostr_func_14,) \
NEAT__IF_DEF(NEAT__TOSTR15)(neat__tostr_type_15: neat__tostr_func_15,) \
NEAT__IF_DEF(NEAT__TOSTR16)(neat__tostr_type_16: neat__tostr_func_16,) \
NEAT__IF_DEF(NEAT__TOSTR17)(neat__tostr_type_17: neat__tostr_func_17,) \
NEAT__IF_DEF(NEAT__TOSTR18)(neat__tostr_type_18: neat__tostr_func_18,) \
NEAT__IF_DEF(NEAT__TOSTR19)(neat__tostr_type_19: neat__tostr_func_19,) \
NEAT__IF_DEF(NEAT__TOSTR20)(neat__tostr_type_20: neat__tostr_func_20,) \
NEAT__IF_DEF(NEAT__TOSTR21)(neat__tostr_type_21: neat__tostr_func_21,) \
NEAT__IF_DEF(NEAT__TOSTR22)(neat__tostr_type_22: neat__tostr_func_22,) \
NEAT__IF_DEF(NEAT__TOSTR23)(neat__tostr_type_23: neat__tostr_func_23,) \
NEAT__IF_DEF(NEAT__TOSTR24)(neat__tostr_type_24: neat__tostr_func_24,) \
NEAT__IF_DEF(NEAT__TOSTR25)(neat__tostr_type_25: neat__tostr_func_25,) \
NEAT__IF_DEF(NEAT__TOSTR26)(neat__tostr_type_26: neat__tostr_func_26,) \
NEAT__IF_DEF(NEAT__TOSTR27)(neat__tostr_type_27: neat__tostr_func_27,) \
NEAT__IF_DEF(NEAT__TOSTR28)(neat__tostr_type_28: neat__tostr_func_28,) \
NEAT__IF_DEF(NEAT__TOSTR29)(neat__tostr_type_29: neat__tostr_func_29,) \
NEAT__IF_DEF(NEAT__TOSTR30)(neat__tostr_type_30: neat__tostr_func_30,) \
NEAT__IF_DEF(NEAT__TOSTR31)(neat__tostr_type_31: neat__tostr_func_31,) \
NEAT__IF_DEF(NEAT__TOSTR32)(neat__tostr_type_32: neat__tostr_func_32,) \
NEAT__DEFAULT_TOSTR_GENERIC_BRANCHES

#define NEAT__TOSTR_P_FUNCS_GENERIC_BRANCHES                             \
NEAT__IF_DEF(NEAT__TOSTR1) (neat__tostr_type_1 : neat__tostr_p_func_1,)  \
NEAT__IF_DEF(NEAT__TOSTR2) (neat__tostr_type_2 : neat__tostr_p_func_2,)  \
NEAT__IF_DEF(NEAT__TOSTR3) (neat__tostr_type_3 : neat__tostr_p_func_3,)  \
NEAT__IF_DEF(NEAT__TOSTR4) (neat__tostr_type_4 : neat__tostr_p_func_4,)  \
NEAT__IF_DEF(NEAT__TOSTR5) (neat__tostr_type_5 : neat__tostr_p_func_5,)  \
NEAT__IF_DEF(NEAT__TOSTR6) (neat__tostr_type_6 : neat__tostr_p_func_6,)  \
NEAT__IF_DEF(NEAT__TOSTR7) (neat__tostr_type_7 : neat__tostr_p_func_7,)  \
NEAT__IF_DEF(NEAT__TOSTR8) (neat__tostr_type_8 : neat__tostr_p_func_8,)  \
NEAT__IF_DEF(NEAT__TOSTR9) (neat__tostr_type_9 : neat__tostr_p_func_9,)  \
NEAT__IF_DEF(NEAT__TOSTR10)(neat__tostr_type_10: neat__tostr_p_func_10,) \
NEAT__IF_DEF(NEAT__TOSTR11)(neat__tostr_type_11: neat__tostr_p_func_11,) \
NEAT__IF_DEF(NEAT__TOSTR12)(neat__tostr_type_12: neat__tostr_p_func_12,) \
NEAT__IF_DEF(NEAT__TOSTR13)(neat__tostr_type_13: neat__tostr_p_func_13,) \
NEAT__IF_DEF(NEAT__TOSTR14)(neat__tostr_type_14: neat__tostr_p_func_14,) \
NEAT__IF_DEF(NEAT__TOSTR15)(neat__tostr_type_15: neat__tostr_p_func_15,) \
NEAT__IF_DEF(NEAT__TOSTR16)(neat__tostr_type_16: neat__tostr_p_func_16,) \
NEAT__IF_DEF(NEAT__TOSTR17)(neat__tostr_type_17: neat__tostr_p_func_17,) \
NEAT__IF_DEF(NEAT__TOSTR18)(neat__tostr_type_18: neat__tostr_p_func_18,) \
NEAT__IF_DEF(NEAT__TOSTR19)(neat__tostr_type_19: neat__tostr_p_func_19,) \
NEAT__IF_DEF(NEAT__TOSTR20)(neat__tostr_type_20: neat__tostr_p_func_20,) \
NEAT__IF_DEF(NEAT__TOSTR21)(neat__tostr_type_21: neat__tostr_p_func_21,) \
NEAT__IF_DEF(NEAT__TOSTR22)(neat__tostr_type_22: neat__tostr_p_func_22,) \
NEAT__IF_DEF(NEAT__TOSTR23)(neat__tostr_type_23: neat__tostr_p_func_23,) \
NEAT__IF_DEF(NEAT__TOSTR24)(neat__tostr_type_24: neat__tostr_p_func_24,) \
NEAT__IF_DEF(NEAT__TOSTR25)(neat__tostr_type_25: neat__tostr_p_func_25,) \
NEAT__IF_DEF(NEAT__TOSTR26)(neat__tostr_type_26: neat__tostr_p_func_26,) \
NEAT__IF_DEF(NEAT__TOSTR27)(neat__tostr_type_27: neat__tostr_p_func_27,) \
NEAT__IF_DEF(NEAT__TOSTR28)(neat__tostr_type_28: neat__tostr_p_func_28,) \
NEAT__IF_DEF(NEAT__TOSTR29)(neat__tostr_type_29: neat__tostr_p_func_29,) \
NEAT__IF_DEF(NEAT__TOSTR30)(neat__tostr_type_30: neat__tostr_p_func_30,) \
NEAT__IF_DEF(NEAT__TOSTR31)(neat__tostr_type_31: neat__tostr_p_func_31,) \
NEAT__IF_DEF(NEAT__TOSTR32)(neat__tostr_type_32: neat__tostr_p_func_32,) \
NEAT__DEFAULT_TOSTR_P_GENERIC_BRANCHES

struct neat__fail_type { int dummy; };
typedef void(*neat__tostr_fail)(struct neat__fail_type*);

#define neat__get_tostr_func(ty) \
_Generic((ty){0}, \
    NEAT__TOSTR_FUNCS_GENERIC_BRANCHES \
)

#define neat__get_tostr_func_ft(ty) \
_Generic((ty){0}, \
    NEAT__TOSTR_FUNCS_GENERIC_BRANCHES, \
    default: (neat__tostr_fail){0} \
)

#define neat__get_tostr_p_func(ty) \
_Generic((ty){0}, \
    NEAT__TOSTR_P_FUNCS_GENERIC_BRANCHES \
)

#define neat_tostr(dst, src) \
neat__get_tostr_func(__typeof__(src))(neat_mutstr_ref(dst), (src))

#define neat_has_tostr(ty) \
(!neat__has_type(neat__get_tostr_func_ft(ty), neat__tostr_fail))

#define neat_tostr_p(dst, src) \
neat__get_tostr_p_func(__typeof__(*(src)))(neat_mutstr_ref(dst), (src))

#define NEAT__DECL_TOSTR_FUNC(n) \
typedef __typeof__(NEAT__MCALL(NEAT__ARG1, ADD_TOSTR)) neat__tostr_type_##n; \
static inline Neat_Error neat__tostr_func_##n (Neat_Mut_String_Ref dst, neat__tostr_type_##n obj) \
{ \
    _Static_assert(neat__has_type(NEAT__MCALL(NEAT__ARG2, ADD_TOSTR), __typeof__(Neat_Error(*)(Neat_Mut_String_Ref, neat__tostr_type_##n))), "tostr functions must have signature `Neat_Error(Neat_Mut_String_Ref dst, T src)`"); \
    neat__mutstr_ref_clear(dst); \
    return NEAT__MCALL(NEAT__ARG2, ADD_TOSTR) (dst, obj); \
} \
static inline Neat_Error neat__tostr_p_func_##n (Neat_Mut_String_Ref dst, const neat__tostr_type_##n *obj) \
{ \
    return neat__tostr_func_##n(dst, *obj); \
}

Neat_String_View neat__strv_cstr1(const char *str);
Neat_String_View neat__strv_ucstr1(const unsigned char *str);
Neat_String_View neat__strv_dstr1(const Neat_DString str);
Neat_String_View neat__strv_dstr_ptr1(const Neat_DString *str);
Neat_String_View neat__strv_strv1(const Neat_String_View str);
Neat_String_View neat__strv_strbuf1(const Neat_String_Buffer str);
Neat_String_View neat__strv_strbuf_ptr1(const Neat_String_Buffer *str);
Neat_String_View neat__strv_mutstr_ref1(const Neat_Mut_String_Ref str);

Neat_String_View neat__strv_cstr2(const char *str, unsigned int begin);
Neat_String_View neat__strv_ucstr2(const unsigned char *str, unsigned int begin);
Neat_String_View neat__strv_dstr2(const Neat_DString str, unsigned int begin);
Neat_String_View neat__strv_dstr_ptr2(const Neat_DString *str, unsigned int begin);
Neat_String_View neat__strv_strv2(const Neat_String_View str, unsigned int begin);
Neat_String_View neat__strv_strbuf2(const Neat_String_Buffer str, unsigned int begin);
Neat_String_View neat__strv_strbuf_ptr2(const Neat_String_Buffer *str, unsigned int begin);
Neat_String_View neat__strv_mutstr_ref2(const Neat_Mut_String_Ref str, unsigned int begin);

Neat_String_View neat__strv_cstr3(const char *str, unsigned int begin, unsigned int end);
Neat_String_View neat__strv_ucstr3(const unsigned char *str, unsigned int begin, unsigned int end);
Neat_String_View neat__strv_dstr3(const Neat_DString str, unsigned int begin, unsigned int end);
Neat_String_View neat__strv_dstr_ptr3(const Neat_DString *str, unsigned int begin, unsigned int end);
Neat_String_View neat__strv_strv3(const Neat_String_View str, unsigned int begin, unsigned int end);
Neat_String_View neat__strv_strbuf3(const Neat_String_Buffer str, unsigned int begin, unsigned int end);
Neat_String_View neat__strv_strbuf_ptr3(const Neat_String_Buffer *str, unsigned int begin, unsigned int end);
Neat_String_View neat__strv_mutstr_ref3(const Neat_Mut_String_Ref str, unsigned int begin, unsigned int end);

Neat_String_Buffer neat__strbuf_from_cstr(const char *ptr, unsigned int cap);
Neat_String_Buffer neat__strbuf_from_buf(const Neat_Buffer buf);

Neat_Buffer neat__buf_from_cstr(const char *str);
Neat_Buffer neat__buf_from_ucstr(const unsigned char *str);
Neat_Buffer neat__buf_from_carr(const char *str, size_t cap);
Neat_Buffer neat__buf_from_ucarr(const unsigned char *str, size_t cap);

Neat_Mut_String_Ref neat__cstr_as_mutstr_ref(const char *str);
Neat_Mut_String_Ref neat__ucstr_as_mutstr_ref(const unsigned char *str);
Neat_Mut_String_Ref neat__buf_as_mutstr_ref(const Neat_Buffer str);
Neat_Mut_String_Ref neat__dstr_ptr_as_mutstr_ref(const Neat_DString *str);
Neat_Mut_String_Ref neat__strbuf_ptr_as_mutstr_ref(const Neat_String_Buffer *str);
Neat_Mut_String_Ref neat__mutstr_ref_as_mutstr_ref(const Neat_Mut_String_Ref str);

Neat__Fixed_Mut_String_Ref neat__buf_as_fmutstr_ref(Neat_Buffer buf, unsigned int *len_ptr);
Neat__Fixed_Mut_String_Ref neat__strbuf_ptr_as_fmutstr_ref(Neat_String_Buffer *strbuf);
Neat__Fixed_Mut_String_Ref neat__dstr_ptr_as_fmutstr_ref(Neat_DString *dstr);

char *neat__cstr_as_cstr(const char *str);
char *neat__ucstr_as_cstr(const unsigned char *str);
char *neat__dstr_as_cstr(const Neat_DString str);
char *neat__dstr_ptr_as_cstr(const Neat_DString *str);
char *neat__strv_as_cstr(const Neat_String_View str);
char *neat__strbuf_as_cstr(const Neat_String_Buffer str);
char *neat__strbuf_ptr_as_cstr(const Neat_String_Buffer *str);
char *neat__mutstr_ref_as_cstr(const Neat_Mut_String_Ref str);

unsigned int neat__dstr_cap(const Neat_DString str);
unsigned int neat__dstr_ptr_cap(const Neat_DString *str);
unsigned int neat__strbuf_cap(const Neat_String_Buffer str);
unsigned int neat__strbuf_ptr_cap(const Neat_String_Buffer *str);
unsigned int neat__buf_cap(const Neat_Buffer buf);
unsigned int neat__mutstr_ref_cap(const Neat_Mut_String_Ref str);
unsigned int neat__mutstr_ref_len(const Neat_Mut_String_Ref str);

unsigned char neat__cstr_char_at(const char *str, unsigned int idx);
unsigned char neat__ucstr_char_at(const unsigned char *str, unsigned int idx);
unsigned char neat__dstr_char_at(const Neat_DString str, unsigned int idx);
unsigned char neat__dstr_ptr_char_at(const Neat_DString *str, unsigned int idx);
unsigned char neat__strv_char_at(const Neat_String_View str, unsigned int idx);
unsigned char neat__strbuf_char_at(const Neat_String_Buffer str, unsigned int idx);
unsigned char neat__strbuf_ptr_char_at(const Neat_String_Buffer *str, unsigned int idx);
unsigned char neat__mutstr_ref_char_at(const Neat_Mut_String_Ref str, unsigned int idx);

bool neat__is_strv_within(Neat_String_View base, Neat_String_View sub);

NEAT__NODISCARD("discarding a new DString may cause a memory leak")
Neat_DString neat__dstr_init(unsigned int cap, Neat_Allocator *allocator);
NEAT__NODISCARD("discarding a new DString may cause a memory leak")
Neat_DString neat__dstr_init_from(Neat_String_View from, Neat_Allocator *allocator);
void neat__dstr_deinit(Neat_DString *dstr);
Neat_Error neat__dstr_append_strv(Neat_DString *dstr, const Neat_String_View str);
Neat_Error neat__dstr_prepend_strv(Neat_DString *dstr, const Neat_String_View str);
Neat_Error neat__dstr_insert_strv(Neat_DString *dstr, const Neat_String_View str, unsigned int idx);
Neat_Error neat__dstr_fread_line(Neat_DString *dstr, FILE *stream);
Neat_Error neat__dstr_append_fread_line(Neat_DString *dstr, FILE *stream);
void neat__dstr_shrink_to_fit(Neat_DString *dstr);
Neat_Error neat__dstr_ensure_cap(Neat_DString *dstr, unsigned int at_least);

Neat_Error neat__mutstr_ref_putc(Neat_Mut_String_Ref dst, unsigned char c);
Neat_Error neat__mutstr_ref_copy(Neat_Mut_String_Ref dst, const Neat_String_View src);
Neat_Error neat__mutstr_ref_append(Neat_Mut_String_Ref dst, const Neat_String_View src);
Neat_Error neat__mutstr_ref_delete_range(Neat_Mut_String_Ref str, unsigned int begin, unsigned int end);
Neat_Error neat__mutstr_ref_insert(Neat_Mut_String_Ref dst, const Neat_String_View src, unsigned int idx);
Neat_Error neat__mutstr_ref_replace(Neat_Mut_String_Ref str, const Neat_String_View target, const Neat_String_View replacement);
Neat_Error neat__mutstr_ref_replace_first(Neat_Mut_String_Ref str, const Neat_String_View target, const Neat_String_View replacement);
Neat_Error neat__mutstr_ref_replace_range(Neat_Mut_String_Ref str, unsigned int begin, unsigned int end, const Neat_String_View replacement);
Neat_Error neat__mutstr_ref_clear(Neat_Mut_String_Ref str);

Neat_Error neat__fmutstr_ref_putc(Neat__Fixed_Mut_String_Ref dst, unsigned char c);
Neat_Error neat__fmutstr_ref_copy(Neat__Fixed_Mut_String_Ref dst, const Neat_String_View src);
Neat_Error neat__fmutstr_ref_append_strv(Neat__Fixed_Mut_String_Ref dst, const Neat_String_View src);
Neat_Error neat__fmutstr_ref_delete_range(Neat__Fixed_Mut_String_Ref str, unsigned int begin, unsigned int end);
Neat_Error neat__fmutstr_ref_insert(Neat__Fixed_Mut_String_Ref dst, const Neat_String_View src, unsigned int idx);
Neat_Error neat__fmutstr_ref_replace(Neat__Fixed_Mut_String_Ref str, const Neat_String_View target, const Neat_String_View replacement);
Neat_Error neat__fmutstr_ref_replace_first(Neat__Fixed_Mut_String_Ref str, const Neat_String_View target, const Neat_String_View replacement);
Neat_Error neat__fmutstr_ref_replace_range(Neat__Fixed_Mut_String_Ref str, unsigned int begin, unsigned int end, const Neat_String_View replacement);

Neat_Error neat__dstr_copy(Neat_DString *dstr, const Neat_String_View src);

NEAT__NODISCARD("str_split returns new String_View_Array")
Neat_String_View_Array neat__strv_split(const Neat_String_View str, const Neat_String_View delim, Neat_Allocator* allocator);
Neat_Error neat__strv_split_iter(const Neat_String_View str, const Neat_String_View delim, bool(*cb)(Neat_String_View found, void *ctx), void *ctx);
Neat_Error neat__strv_arr_join(Neat_Mut_String_Ref dst, Neat_String_View_Array strs, Neat_String_View delim);

Neat_String_View_Array neat__strv_arr_from_carr(const Neat_String_View *carr, unsigned int nb);

bool neat__strv_equal(const Neat_String_View str1, const Neat_String_View str2);
Neat_String_View neat__strv_find(const Neat_String_View hay, const Neat_String_View needle);
unsigned int neat__strv_count(const Neat_String_View hay, const Neat_String_View needle);
bool neat__strv_starts_with(const Neat_String_View hay, const Neat_String_View needle);
bool neat__strv_ends_with(const Neat_String_View hay, const Neat_String_View needle);

Neat_Error neat__mutstr_ref_tolower(Neat_Mut_String_Ref str);
Neat_Error neat__mutstr_ref_toupper(Neat_Mut_String_Ref str);

Neat_Error neat__mutstr_ref_fread_line(Neat_Mut_String_Ref dst, FILE *stream);
Neat_Error neat__mutstr_ref_append_fread_line(Neat_Mut_String_Ref dst, FILE *stream);

Neat_Error neat__fmutstr_ref_fread_line(Neat__Fixed_Mut_String_Ref dst, FILE *stream);
Neat_Error neat__fmutstr_ref_append_fread_line(Neat__Fixed_Mut_String_Ref dst, FILE *stream);

unsigned int neat__fprint_strv(FILE *stream, const Neat_String_View str);
unsigned int neat__fprintln_strv(FILE *stream, const Neat_String_View str);

Neat_Error neat__bool_tostr(Neat_Mut_String_Ref dst, bool obj);
Neat_Error neat__cstr_tostr(Neat_Mut_String_Ref dst, const char *obj);
Neat_Error neat__ucstr_tostr(Neat_Mut_String_Ref dst, const unsigned char *obj);
Neat_Error neat__char_tostr(Neat_Mut_String_Ref dst, char obj);
Neat_Error neat__schar_tostr(Neat_Mut_String_Ref dst, signed char obj);
Neat_Error neat__uchar_tostr(Neat_Mut_String_Ref dst, unsigned char obj);
Neat_Error neat__short_tostr(Neat_Mut_String_Ref dst, short obj);
Neat_Error neat__ushort_tostr(Neat_Mut_String_Ref dst, unsigned short obj);
Neat_Error neat__int_tostr(Neat_Mut_String_Ref dst, int obj);
Neat_Error neat__uint_tostr(Neat_Mut_String_Ref dst, unsigned int obj);
Neat_Error neat__long_tostr(Neat_Mut_String_Ref dst, long obj);
Neat_Error neat__ulong_tostr(Neat_Mut_String_Ref dst, unsigned long obj);
Neat_Error neat__llong_tostr(Neat_Mut_String_Ref dst, long long obj);
Neat_Error neat__ullong_tostr(Neat_Mut_String_Ref dst, unsigned long long obj);
Neat_Error neat__float_tostr(Neat_Mut_String_Ref dst, float obj);
Neat_Error neat__double_tostr(Neat_Mut_String_Ref dst, double obj);

Neat_Error neat__dstr_tostr(Neat_Mut_String_Ref dst, const Neat_DString obj);
Neat_Error neat__dstr_ptr_tostr(Neat_Mut_String_Ref dst, const Neat_DString *obj);
Neat_Error neat__strv_tostr(Neat_Mut_String_Ref dst, const Neat_String_View obj);
Neat_Error neat__strbuf_tostr(Neat_Mut_String_Ref dst, const Neat_String_Buffer obj);
Neat_Error neat__strbuf_ptr_tostr(Neat_Mut_String_Ref dst, const Neat_String_Buffer *obj);
Neat_Error neat__mutstr_ref_tostr(Neat_Mut_String_Ref dst, const Neat_Mut_String_Ref obj);

Neat_Error neat__error_tostr(Neat_Mut_String_Ref dst, Neat_Error obj);
Neat_Error neat__array_fmt_tostr(Neat_Mut_String_Ref dst, Neat__Array_Fmt obj);

Neat_Error neat__bool_tostr_p(Neat_Mut_String_Ref dst, bool *obj);
Neat_Error neat__cstr_tostr_p(Neat_Mut_String_Ref dst, const char **obj);
Neat_Error neat__ucstr_tostr_p(Neat_Mut_String_Ref dst, const unsigned char **obj);
Neat_Error neat__char_tostr_p(Neat_Mut_String_Ref dst, char *obj);
Neat_Error neat__schar_tostr_p(Neat_Mut_String_Ref dst, signed char *obj);
Neat_Error neat__uchar_tostr_p(Neat_Mut_String_Ref dst, unsigned char *obj);
Neat_Error neat__short_tostr_p(Neat_Mut_String_Ref dst, short *obj);
Neat_Error neat__ushort_tostr_p(Neat_Mut_String_Ref dst, unsigned short *obj);
Neat_Error neat__int_tostr_p(Neat_Mut_String_Ref dst, int *obj);
Neat_Error neat__uint_tostr_p(Neat_Mut_String_Ref dst, unsigned int *obj);
Neat_Error neat__long_tostr_p(Neat_Mut_String_Ref dst, long *obj);
Neat_Error neat__ulong_tostr_p(Neat_Mut_String_Ref dst, unsigned long *obj);
Neat_Error neat__llong_tostr_p(Neat_Mut_String_Ref dst, long long *obj);
Neat_Error neat__ullong_tostr_p(Neat_Mut_String_Ref dst, unsigned long long *obj);
Neat_Error neat__float_tostr_p(Neat_Mut_String_Ref dst, float *obj);
Neat_Error neat__double_tostr_p(Neat_Mut_String_Ref dst, double *obj);

Neat_Error neat__dstr_tostr_p(Neat_Mut_String_Ref dst, const Neat_DString *obj);
Neat_Error neat__dstr_ptr_tostr_p(Neat_Mut_String_Ref dst, const Neat_DString **obj);
Neat_Error neat__strv_tostr_p(Neat_Mut_String_Ref dst, const Neat_String_View *obj);
Neat_Error neat__strbuf_tostr_p(Neat_Mut_String_Ref dst, const Neat_String_Buffer *obj);
Neat_Error neat__strbuf_ptr_tostr_p(Neat_Mut_String_Ref dst, const Neat_String_Buffer **obj);
Neat_Error neat__mutstr_ref_tostr_p(Neat_Mut_String_Ref dst, const Neat_Mut_String_Ref *obj);

Neat_Error neat__error_tostr_p(Neat_Mut_String_Ref dst, Neat_Error *obj);

#define NEAT__X(ty, extra) \
Neat_Error neat__Integer_d_Fmt_##ty##_tostr(Neat_Mut_String_Ref dst, Neat__Integer_d_Fmt_##ty obj);    \
Neat_Error neat__Integer_x_Fmt_##ty##_tostr(Neat_Mut_String_Ref dst, Neat__Integer_x_Fmt_##ty obj);    \
Neat_Error neat__Integer_o_Fmt_##ty##_tostr(Neat_Mut_String_Ref dst, Neat__Integer_o_Fmt_##ty obj);    \
Neat_Error neat__Integer_b_Fmt_##ty##_tostr(Neat_Mut_String_Ref dst, Neat__Integer_b_Fmt_##ty obj);    \
                                                                                                       \
Neat_Error neat__Integer_d_Fmt_##ty##_tostr_p(Neat_Mut_String_Ref dst, Neat__Integer_d_Fmt_##ty *obj); \
Neat_Error neat__Integer_x_Fmt_##ty##_tostr_p(Neat_Mut_String_Ref dst, Neat__Integer_x_Fmt_##ty *obj); \
Neat_Error neat__Integer_o_Fmt_##ty##_tostr_p(Neat_Mut_String_Ref dst, Neat__Integer_o_Fmt_##ty *obj); \
Neat_Error neat__Integer_b_Fmt_##ty##_tostr_p(Neat_Mut_String_Ref dst, Neat__Integer_b_Fmt_##ty *obj);

NEAT__INTEGER_TYPES(NEAT__X, ignore)

#undef NEAT__X

#define NEAT__X(ty, extra) \
Neat_Error neat__Floating_f_Fmt_##ty##_tostr(Neat_Mut_String_Ref dst, Neat__Floating_f_Fmt_##ty obj);    \
Neat_Error neat__Floating_g_Fmt_##ty##_tostr(Neat_Mut_String_Ref dst, Neat__Floating_g_Fmt_##ty obj);    \
Neat_Error neat__Floating_e_Fmt_##ty##_tostr(Neat_Mut_String_Ref dst, Neat__Floating_e_Fmt_##ty obj);    \
Neat_Error neat__Floating_a_Fmt_##ty##_tostr(Neat_Mut_String_Ref dst, Neat__Floating_a_Fmt_##ty obj);    \
                                                                                                         \
Neat_Error neat__Floating_f_Fmt_##ty##_tostr_p(Neat_Mut_String_Ref dst, Neat__Floating_f_Fmt_##ty *obj); \
Neat_Error neat__Floating_g_Fmt_##ty##_tostr_p(Neat_Mut_String_Ref dst, Neat__Floating_g_Fmt_##ty *obj); \
Neat_Error neat__Floating_e_Fmt_##ty##_tostr_p(Neat_Mut_String_Ref dst, Neat__Floating_e_Fmt_##ty *obj); \
Neat_Error neat__Floating_a_Fmt_##ty##_tostr_p(Neat_Mut_String_Ref dst, Neat__Floating_a_Fmt_##ty *obj);

NEAT__FLOATING_TYPES(NEAT__X, ignore, NEAT__X)

#undef NEAT__X

#endif /* NEAT_STR_H */

#ifdef NEAT_STR_SHORT_NAMES

typedef Neat_Allocator          Allocator;
typedef Neat_DString            DString;
typedef Neat_String_Buffer      String_Buffer;
typedef Neat_String_View        String_View;
typedef Neat_String_View_Array  String_View_Array;
typedef Neat_Mut_String_Ref     Mut_String_Ref;

#define str_at(any_str, idx) neat_str_at(any_str, idx)
#define str_len(any_str) neat_str_len(any_str)
#define str_cap(any_str) neat_str_cap(any_str)
#define str_equal(any_str1, any_str2) neat_str_equal(any_str1, any_str2)
#define str_chars(any_str) neat_str_chars(any_str)
#define str_find(any_str_hay, any_str_needle) neat_str_find(any_str_hay, any_str_needle)
#define str_count(any_str_hay, any_str_needle) neat_str_count(any_str_hay, any_str_needle)
#define str_clear(any_str) neat_str_clear(any_str)
#define str_starts_with(any_str_hay, any_str_needle) neat_str_starts_with(any_str_hay, any_str_needle)
#define str_ends_with(any_str_hay, any_str_needle) neat_str_ends_with(any_str_hay, any_str_needle)
#define str_tolower(any_str) neat_str_tolower(any_str)
#define str_toupper(any_str) neat_str_toupper(any_str)
#define str_copy(any_str_dst, any_str_src) neat_str_copy(any_str_dst, any_str_src)
#define str_putc(any_str_dst, c) neat_str_putc(any_str_dst, c)
#define str_dup(any_str_src) neat_str_dup(any_str_src)
#define str_append(cap_str_dst, any_str_src) neat_str_append(cap_str_dst, any_str_src)
#define str_insert(any_str_dst, any_str_src, idx) neat_str_insert(any_str_dst, any_str_src, idx)
#define str_prepend(neat_str_dst, neat_str_src) neat_str_prepend(neat_str_dst, neat_str_src)
#define str_del(any_str, begin, end) neat_str_del(any_str, begin, end)
#define str_replace(mut_str, any_str_target, any_str_replacement) neat_str_replace(mut_str, any_str_target, any_str_replacement)
#define str_replace_first(any_str, any_str_target, any_str_replacement) neat_str_replace_first(any_str, any_str_target, any_str_replacement)
#define str_replace_range(any_str, begin, end, any_str_replacement) neat_str_replace_range(any_str, begin, end, any_str_replacement)
#define str_split(any_str, any_str_delim, ...) neat_str_split(any_str, any_str_delim __VA_OPT__(,) __VA_ARGS__)
#define str_split_iter(any_str, any_str_delim, callback, ...) neat_str_split_iter(any_str, any_str_delim, callback __VA_OPT__(,) __VA_ARGS__)
#define str_join(mut_str_dst, strv_arr, any_str_delim) neat_str_join(mut_str_dst, strv_arr, any_str_delim)
#define str_fread_line(any_str, stream) neat_str_fread_line(any_str, stream)
#define str_append_fread_line(any_str, stream) neat_str_append_fread_line(any_str, stream)
#define str_read_line(any_str) neat_str_read_line(any_str)
#define str_read_line_new(...) neat_str_read_line_new(__VA_ARGS__)
#define str_fread_line_new(stream, ...) neat_str_fread_line_new(stream __VA_OPT__(,) __VA_ARGS__)
#define str_append_read_line(any_str) neat_str_append_read_line(any_str)
#define str_print(any_str, ...) neat_str_print(any_str __VA_OPT__(,) __VA_ARGS__)
#define str_print_append(any_str, ...) neat_str_print_append(any_str, __VA_ARGS__)

#define dstr_init(...) neat_dstr_init(__VA_ARGS__)
#define dstr_init_from(anystr, ...) neat_dstr_init_from(anystr __VA_OPT__(,) __VA_ARGS__)
#define dstr_deinit(dstr) neat_dstr_deinit(dstr);

#define dstr_append(dstr, any_str) neat_dstr_append(dstr, any_str)
#define dstr_prepend(dstr, any_str) neat_dstr_prepend(dstr, any_str)
#define dstr_insert(dstr, any_str, idx) neat_dstr_insert(dstr, any_str, idx)
#define dstr_fread_line(dstr, stream) neat_dstr_fread_line(dstr, stream)
#define dstr_read_line(dstr) neat_dstr_read_line(dstr)
#define dstr_append_fread_line(dstr, stream) neat_dstr_append_fread_line(dstr, stream)
#define dstr_append_read_line(dstr) neat_dstr_append_read_line(dstr)
#define dstr_shrink_to_fit(dstr) neat_dstr_shrink_to_fit(dstr)
#define dstr_ensure_cap(dstr, new_cap) neat_dstr_ensure_cap(dstr, new_cap)

#define strbuf_init_from_cstr(cstr, ...) neat_strbuf_init_from_cstr(cstr __VA_OPT__(,) __VA_ARGS__)
#define strbuf_init_from_buf(buf, ...) neat_strbuf_init_from_buf(buf __VA_OPT__(,) __VA_ARGS__)
#define str_view(...) neat_str_view(__VA_ARGS__)
#define mutstr_ref(any_str, ...) neat_mutstr_ref(any_str __VA_OPT__(,) __VA_ARGS__)
#define str_view_arr(...) neat_str_view_arr(__VA_ARGS__)
#define str_view_arr_from_carr(strv_carr, ...) neat_str_view_arr_from_carr(strv_carr __VA_OPT__(,) __VA_ARGS__)

#define tostr(dst, src) neat_tostr(dst, src)
#define has_tostr(T) neat_has_tostr(T)

#define print(...) neat_print(__VA_ARGS__)
#define println(...) neat_println(__VA_ARGS__)
#define fprint(stream, ...) neat_fprint(stream, __VA_ARGS__)
#define fprintln(stream, ...) neat_fprintln(stream, __VA_ARGS__)

#define tsfmt(exp, fmt_char, ...) neat_tsfmt(exp, fmt_char __VA_OPT__(,) __VA_ARGS__)
#define arrfmt(arr, n, open, close, delim, ...) neat_arrfmt(arr, n, open, close, delim __VA_OPT__(,) __VA_ARGS__)

#endif

#if defined(ADD_TOSTR)

#if !defined(NEAT__TOSTR1)
#define NEAT__TOSTR1
NEAT__DECL_TOSTR_FUNC(1)
#elif !defined(NEAT__TOSTR2)
#define NEAT__TOSTR2
NEAT__DECL_TOSTR_FUNC(2)
#elif !defined(NEAT__TOSTR3)
#define NEAT__TOSTR3
NEAT__DECL_TOSTR_FUNC(3)
#elif !defined(NEAT__TOSTR4)
#define NEAT__TOSTR4
NEAT__DECL_TOSTR_FUNC(4)
#elif !defined(NEAT__TOSTR5)
#define NEAT__TOSTR5
NEAT__DECL_TOSTR_FUNC(5)
#elif !defined(NEAT__TOSTR6)
#define NEAT__TOSTR6
NEAT__DECL_TOSTR_FUNC(6)
#elif !defined(NEAT__TOSTR7)
#define NEAT__TOSTR7
NEAT__DECL_TOSTR_FUNC(7)
#elif !defined(NEAT__TOSTR8)
#define NEAT__TOSTR8
NEAT__DECL_TOSTR_FUNC(8)
#elif !defined(NEAT__TOSTR9)
#define NEAT__TOSTR9
NEAT__DECL_TOSTR_FUNC(9)
#elif !defined(NEAT__TOSTR10)
#define NEAT__TOSTR10
NEAT__DECL_TOSTR_FUNC(10)
#elif !defined(NEAT__TOSTR11)
#define NEAT__TOSTR11
NEAT__DECL_TOSTR_FUNC(11)
#elif !defined(NEAT__TOSTR12)
#define NEAT__TOSTR12
NEAT__DECL_TOSTR_FUNC(12)
#elif !defined(NEAT__TOSTR13)
#define NEAT__TOSTR13
NEAT__DECL_TOSTR_FUNC(13)
#elif !defined(NEAT__TOSTR14)
#define NEAT__TOSTR14
NEAT__DECL_TOSTR_FUNC(14)
#elif !defined(NEAT__TOSTR15)
#define NEAT__TOSTR15
NEAT__DECL_TOSTR_FUNC(15)
#elif !defined(NEAT__TOSTR16)
#define NEAT__TOSTR16
NEAT__DECL_TOSTR_FUNC(16)
#elif !defined(NEAT__TOSTR17)
#define NEAT__TOSTR17
NEAT__DECL_TOSTR_FUNC(17)
#elif !defined(NEAT__TOSTR18)
#define NEAT__TOSTR18
NEAT__DECL_TOSTR_FUNC(18)
#elif !defined(NEAT__TOSTR19)
#define NEAT__TOSTR19
NEAT__DECL_TOSTR_FUNC(19)
#elif !defined(NEAT__TOSTR20)
#define NEAT__TOSTR20
NEAT__DECL_TOSTR_FUNC(20)
#elif !defined(NEAT__TOSTR21)
#define NEAT__TOSTR21
NEAT__DECL_TOSTR_FUNC(21)
#elif !defined(NEAT__TOSTR22)
#define NEAT__TOSTR22
NEAT__DECL_TOSTR_FUNC(22)
#elif !defined(NEAT__TOSTR23)
#define NEAT__TOSTR23
NEAT__DECL_TOSTR_FUNC(23)
#elif !defined(NEAT__TOSTR24)
#define NEAT__TOSTR24
NEAT__DECL_TOSTR_FUNC(24)
#elif !defined(NEAT__TOSTR25)
#define NEAT__TOSTR25
NEAT__DECL_TOSTR_FUNC(25)
#elif !defined(NEAT__TOSTR26)
#define NEAT__TOSTR26
NEAT__DECL_TOSTR_FUNC(26)
#elif !defined(NEAT__TOSTR27)
#define NEAT__TOSTR27
NEAT__DECL_TOSTR_FUNC(27)
#elif !defined(NEAT__TOSTR28)
#define NEAT__TOSTR28
NEAT__DECL_TOSTR_FUNC(28)
#elif !defined(NEAT__TOSTR29)
#define NEAT__TOSTR29
NEAT__DECL_TOSTR_FUNC(29)
#elif !defined(NEAT__TOSTR30)
#define NEAT__TOSTR30
NEAT__DECL_TOSTR_FUNC(30)
#elif !defined(NEAT__TOSTR31)
#define NEAT__TOSTR31
NEAT__DECL_TOSTR_FUNC(31)
#elif !defined(NEAT__TOSTR32)
#define NEAT__TOSTR32
NEAT__DECL_TOSTR_FUNC(32)
#else
#error "Maximum number of tostr functions is 32"
#endif

#undef ADD_TOSTR

#endif
