#ifndef SGS__H_INCLUDED
#define SGS__H_INCLUDED

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

struct SGS_Allocator;

typedef struct SGS_Allocation
{
    void *ptr;
    size_t n;
} SGS_Allocation;

typedef SGS_Allocation(*sgs_alloc_func)  (struct SGS_Allocator*, size_t alignment, size_t n);
typedef void          (*sgs_dealloc_func)(struct SGS_Allocator*, void *ptr, size_t n);
typedef SGS_Allocation(*sgs_realloc_func)(struct SGS_Allocator*, void *ptr, size_t alignment, size_t old_size, size_t new_size);

typedef struct SGS_Allocator
{
    sgs_alloc_func alloc;
    sgs_dealloc_func dealloc;
    sgs_realloc_func realloc;
} SGS_Allocator;

#if !defined(SGS_API)
    #define SGS_API
#endif

SGS_API SGS_Allocation sgs__allocator_invoke_alloc(SGS_Allocator *allocator, size_t alignment, size_t obj_size, size_t nb);
SGS_API void sgs__allocator_invoke_dealloc(SGS_Allocator *allocator, void *ptr, size_t obj_size, size_t nb);
SGS_API SGS_Allocation sgs__allocator_invoke_realloc(SGS_Allocator *allocator, void *ptr, size_t alignment, size_t obj_size, size_t old_nb, size_t new_nb);

SGS_API SGS_Allocator *sgs_get_default_allocator();

#define sgs_alloc(allocator, T, n) \
sgs__allocator_invoke_alloc(allocator, _Alignof(T), sizeof(T), (n))

#define sgs_dealloc(allocator, ptr, T, n) \
sgs__allocator_invoke_dealloc((allocator), (ptr), sizeof(T), (n))

#define sgs_realloc(allocator, ptr, T, old_n, new_n) \
sgs__allocator_invoke_realloc((allocator), (ptr), _Alignof(T), sizeof(T), (old_n), (new_n))

#define sgs_alloc_bytes(allocator, n) \
sgs__allocator_invoke_alloc((allocator), _Alignof(max_align_t), 1, (n))

#define sgs_dealloc_bytes(allocator, ptr, n) \
sgs__allocator_invoke_dealloc((allocator), (ptr), 1, (n))

#define sgs_realloc_bytes(allocator, ptr, old_n, new_n, actual) \
sgs__allocator_invoke_realloc((allocator), (ptr), _Alignof(max_align_t), 1, (old_n), (new_n))

#if __STDC_VERSION__ >= 202311L

    #define SGS__NODISCARD(...) [[nodiscard (__VA_ARGS__)]]

#elif defined(__GNUC__)

    #define SGS__NODISCARD(...) __attribute__((warn_unused_result))

#else

    #define SGS__NODISCARD(...)

#endif


#define sgs__static_assertx(exp, msg) \
((void)sizeof(struct { _Static_assert(exp, msg); int : 8; }))

#define sgs__has_type(exp, t) \
_Generic(exp, t: true, default: false)

#define sgs__is_array_of(exp, ty) \
sgs__has_type((__typeof__(exp)*){0}, __typeof__(ty)(*)[sizeof(exp)/sizeof(ty)])

#define SGS__CAT(a, ...) SGS__PRIMITIVE_CAT(a, __VA_ARGS__)
#define SGS__PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__

#define sgs__coerce(exp, t) \
sgs__coerce_fallback(exp, t, (t){0})

#define sgs__coerce_fallback(exp, ty, fallback) \
_Generic(exp, \
    ty: (exp), \
    default: (fallback) \
)

#define sgs__coerce_string_type(exp, fallback) \
_Generic(exp,                                  \
    char*                     : exp,           \
    unsigned char*            : exp,           \
    SGS_DStr                  : exp,           \
    SGS_DStr*                 : exp,           \
    SGS_StrView               : exp,           \
    SGS_StrBuf                : exp,           \
    SGS_StrBuf*               : exp,           \
    SGS_MutStrRef             : exp,           \
    const char*               : exp,           \
    const unsigned char*      : exp,           \
    const SGS_DStr*           : exp,           \
    const SGS_StrBuf*         : exp,           \
    default                   : fallback       \
)

#define sgs__coerce_not(exp, not_ty, fallback_ty) \
_Generic(exp, \
    not_ty: (fallback_ty){0}, \
    default: exp \
)

#define SGS__CARR_LEN(carr) (sizeof(carr) / sizeof(carr[0]))

// IF_DEF and ARG_n stuff
#define SGS__COMMA()              ,
#define SGS__ARG1_( _1, ... )     _1
#define SGS__ARG1( ... )          SGS__ARG1_( __VA_ARGS__ )
#define SGS__ARG2_( _1, _2, ... ) _2
#define SGS__ARG2( ... )          SGS__ARG2_( __VA_ARGS__ )
#define SGS__INCL( ... )          __VA_ARGS__
#define SGS__OMIT( ... )
#define SGS__OMIT1(a, ...)        __VA_ARGS__
#define SGS__IF_DEF( macro )      SGS__ARG2( SGS__COMMA macro () SGS__INCL, SGS__OMIT, )
// IF_DEF and ARG_n stuff end

// FOREACH stuff
#define SGS__PARENS ()

#define SGS__EXPAND(...)  SGS__EXPAND4(SGS__EXPAND4(SGS__EXPAND4(SGS__EXPAND4(__VA_ARGS__))))
#define SGS__EXPAND4(...) SGS__EXPAND3(SGS__EXPAND3(SGS__EXPAND3(SGS__EXPAND3(__VA_ARGS__))))
#define SGS__EXPAND3(...) SGS__EXPAND2(SGS__EXPAND2(SGS__EXPAND2(SGS__EXPAND2(__VA_ARGS__))))
#define SGS__EXPAND2(...) SGS__EXPAND1(SGS__EXPAND1(SGS__EXPAND1(SGS__EXPAND1(__VA_ARGS__))))
#define SGS__EXPAND1(...) __VA_ARGS__

#define SGS__FOREACH(macro, ...)                                    \
__VA_OPT__(SGS__EXPAND(SGS__FOREACH_HELPER(macro, __VA_ARGS__)))
#define SGS__FOREACH_HELPER(macro, a1, ...)                         \
macro(a1)                                                     \
__VA_OPT__(SGS__FOREACH_REPEAT SGS__PARENS (macro, __VA_ARGS__))
#define SGS__FOREACH_REPEAT() SGS__FOREACH_HELPER
// FOREACH stuff end

#define SGS__VA_OR(otherwise, ...) \
__VA_ARGS__ SGS__IF_EMPTY(otherwise, __VA_ARGS__)

#define SGS__IF_EMPTY(then, ...) \
SGS__CAT(SGS__IF_EMPTY_, __VA_OPT__(0))(then)

#define SGS__IF_EMPTY_(then) then
#define SGS__IF_EMPTY_0(then)

#define SGS__IF_NEMPTY(then, ...) __VA_OPT__(then)

#define SGS__TYPEOF_ARG(arg) \
,__typeof__(arg)

#define SGS__TYPEOF_ARGS(...) \
__VA_OPT__( \
SGS__ARG1(__VA_ARGS__) SGS__FOREACH(SGS__TYPEOF_ARG, __VA_ARGS__) \
)

// Dynamic String
typedef struct SGS_DStr
{
    SGS_Allocator *allocator;
    unsigned int cap;
    unsigned int len;
    unsigned char *chars;
} SGS_DStr;

// Used as a general purpose non-dynamic string buffer
typedef struct SGS_StrBuf
{
    unsigned int cap;
    unsigned int len;
    unsigned char *chars;
} SGS_StrBuf;

// Used to view strings
typedef struct SGS_StrView
{
    unsigned int len;
    unsigned char *chars;
} SGS_StrView;

// An array of the above, returned by sgs_split
typedef struct SGS_StrViewArray
{
    unsigned int cap;
    unsigned int len;
    SGS_StrView *strs;
} SGS_StrViewArray;

// Used for passing `char[]` or `unsigned char[]`, such that it doesn't lose cap information
typedef struct SGS_Buffer
{
    unsigned char *ptr;
    unsigned int cap;
} SGS_Buffer;

enum SGS__MutStrType
{
    SGS__DSTR_TY = 1,
    SGS__STRBUF_TY,
    SGS__BUF_TY
};

// This is a tagged union for all mutable string types (i.e. all except String_View)
typedef struct SGS_MutStrRef
{
    union
    {
        SGS_DStr *dstr;
        SGS_StrBuf *strbuf;
        SGS_Buffer buf;
    } str;
    
    uint8_t ty; // enum SGS__MutStrType
} SGS_MutStrRef;

enum SGS__Error_Value
{
    SGS_OK = 0,
    SGS_DST_TOO_SMALL,
    SGS_ALLOC_ERR,
    SGS_INDEX_OUT_OF_BOUNDS,
    SGS_BAD_RANGE,
    SGS_NOT_FOUND,
    SGS_ALIASING_NOT_SUPPORTED,
    SGS_INCORRECT_TYPE,
    SGS_ENCODING_ERROR,
    SGS_CALLBACK_EXIT
};

typedef struct SGS_Error
{
    uint8_t ec;
} SGS_Error;

typedef struct SGS__FixedMutStrRef
{
    unsigned char *chars;
    unsigned int *len;
    unsigned int cap;
} SGS__FixedMutStrRef;

typedef struct SGS_ArrayFmt
{
    const void * const array;
    const size_t nb;
    const size_t elm_size;
    
    SGS_Error(* const elm_tostr)(SGS_MutStrRef dst, const void *obj);
    
    const SGS_StrView open;
    const SGS_StrView close;
    const SGS_StrView separator;
    const SGS_StrView trailing_separator;
} SGS_ArrayFmt;

typedef struct SGS__DStrAppendAllocator
{
    SGS_Allocator base;
    struct SGS_DStr *owner;
} SGS__DStrAppendAllocator;

typedef struct SGS_StrAppenderState
{
    SGS_DStr appender_dstr;
    SGS__DStrAppendAllocator dstr_append_allocator;
    SGS_StrBuf appender_buf;
} SGS_StrAppenderState;

typedef struct SGS_ReplaceResult
{
    unsigned int nb_replaced;
    SGS_Error err;
} SGS_ReplaceResult;

#define sgs__fmutstr_ref(s, ...) \
_Generic(&(__typeof__(s)){0}, \
    SGS_DStr**                              : sgs__dstr_ptr_as_fmutstr_ref(sgs__coerce(s, SGS_DStr*)), \
    SGS_Buffer*                             : sgs__buf_as_fmutstr_ref(sgs__coerce(s, SGS_Buffer), SGS__VA_OR(&(unsigned int){0}, __VA_ARGS__)), \
    SGS_StrBuf**                            : sgs__strbuf_ptr_as_fmutstr_ref(sgs__coerce(s, SGS_StrBuf*)), \
    char**                                  : sgs__buf_as_fmutstr_ref(sgs__buf_from_cstr(sgs__coerce(s, char*)), SGS__VA_OR(&(unsigned int){0}, __VA_ARGS__)), \
    unsigned char**                         : sgs__buf_as_fmutstr_ref(sgs__buf_from_ucstr(sgs__coerce(s, unsigned char*)), SGS__VA_OR(&(unsigned int){0}, __VA_ARGS__)), \
    char(*)[sizeof(__typeof__(s))]          : sgs__buf_as_fmutstr_ref(sgs__buf_from_carr(sgs__coerce(s, char*), sizeof(__typeof__(s))), SGS__VA_OR(&(unsigned int){0}, __VA_ARGS__)), \
    unsigned char(*)[sizeof(__typeof__(s))] : sgs__buf_as_fmutstr_ref(sgs__buf_from_ucarr(sgs__coerce(s, unsigned char*), sizeof(__typeof__(s))), SGS__VA_OR(&(unsigned int){0}, __VA_ARGS__)) \
)

#define sgs_at(anystr, idx)                              \
_Generic(anystr,                                         \
    char*                     : sgs__cstr_char_at,       \
    unsigned char*            : sgs__ucstr_char_at,      \
    SGS_DStr                  : sgs__dstr_char_at,       \
    SGS_DStr*                 : sgs__dstr_ptr_char_at,   \
    SGS_StrView               : sgs__strv_char_at,       \
    SGS_StrBuf                : sgs__strbuf_char_at,     \
    SGS_StrBuf*               : sgs__strbuf_ptr_char_at, \
    SGS_MutStrRef             : sgs__mutstr_ref_char_at, \
    const char*               : sgs__cstr_char_at,       \
    const unsigned char*      : sgs__ucstr_char_at,      \
    const SGS_DStr*           : sgs__dstr_ptr_char_at,   \
    const SGS_StrBuf*         : sgs__strbuf_ptr_char_at  \
)((anystr), idx)

#define sgs_len(anystr) \
_Generic(anystr, \
    char*                : strlen(sgs__coerce_fallback(anystr, char*, "")), \
    unsigned char*       : strlen((char*) sgs__coerce_fallback(anystr, unsigned char*, "")), \
    SGS_DStr             : ((void)0, sgs__coerce(anystr, SGS_DStr).len), \
    SGS_DStr*            : ((void)0, sgs__coerce(anystr, SGS_DStr*)->len), \
    SGS_StrView          : ((void)0, sgs__coerce(anystr, SGS_StrView).len), \
    SGS_StrBuf           : ((void)0, sgs__coerce(anystr, SGS_StrBuf).len), \
    SGS_StrBuf*          : ((void)0, sgs__coerce(anystr, SGS_StrBuf*)->len), \
    SGS_MutStrRef        : ((void)0, sgs__mutstr_ref_len(sgs__coerce(anystr, SGS_MutStrRef))), \
    const char*          : strlen(sgs__coerce_fallback(anystr, const char*, "")), \
    const unsigned char* : strlen((char*) sgs__coerce_fallback(anystr, const unsigned char*, "")), \
    const SGS_DStr*      : ((void)0, sgs__coerce(anystr, const SGS_DStr*)->len), \
    const SGS_StrBuf*    : ((void)0, sgs__coerce(anystr, const SGS_StrBuf*)->len) \
)

static inline unsigned int sgs__return_32(unsigned int a)
{
    return a;
}

static inline unsigned int sgs__strlen_plus_one(const char *s)
{
    return strlen(s) + 1;
}

static inline unsigned int sgs__ustrlen_plus_one(const unsigned char *s)
{
    return strlen((const char*) s) + 1;
}

static inline unsigned int sgs__strv_len(const SGS_StrView sv)
{
    return sv.len;
}

#define sgs_cap(anystr)                                                       \
_Generic((__typeof__(anystr)*){0},                                            \
    char(*)[sizeof(__typeof__(anystr))]           : sgs__return_32,           \
    unsigned char(*)[sizeof(__typeof__(anystr))]  : sgs__return_32,           \
    char**                                        : sgs__strlen_plus_one,     \
    unsigned char**                               : sgs__ustrlen_plus_one,    \
    SGS_StrView*                                  : sgs__strv_len,            \
    SGS_DStr*                                     : sgs__dstr_cap,            \
    SGS_DStr**                                    : sgs__dstr_ptr_cap,        \
    SGS_StrBuf*                                   : sgs__strbuf_cap,          \
    SGS_StrBuf**                                  : sgs__strbuf_ptr_cap,      \
    SGS_MutStrRef*                                : sgs__mutstr_ref_cap,      \
    const char**                                  : sgs__strlen_plus_one,     \
    const unsigned char**                         : sgs__ustrlen_plus_one,    \
    const SGS_DStr**                              : sgs__dstr_ptr_cap,        \
    const SGS_StrBuf**                            : sgs__strbuf_ptr_cap       \
)(_Generic((__typeof__(anystr)*){0},                                          \
    char(*)[sizeof(__typeof__(anystr))]: sizeof(__typeof__(anystr)),          \
    unsigned char(*)[sizeof(__typeof__(anystr))]: sizeof(__typeof__(anystr)), \
    default: (anystr)                                                         \
))

#define sgs_chars(any_str)                           \
_Generic(any_str,                                    \
    char*                 : sgs__cstr_as_cstr,       \
    unsigned char*        : sgs__ucstr_as_cstr,      \
    SGS_DStr              : sgs__dstr_as_cstr,       \
    SGS_DStr*             : sgs__dstr_ptr_as_cstr,   \
    SGS_StrView           : sgs__strv_as_cstr,       \
    SGS_StrBuf            : sgs__strbuf_as_cstr,     \
    SGS_StrBuf*           : sgs__strbuf_ptr_as_cstr, \
    SGS_MutStrRef         : sgs__mutstr_ref_as_cstr, \
    const char*           : sgs__cstr_as_cstr,       \
    const unsigned char*  : sgs__ucstr_as_cstr,      \
    const SGS_DStr*       : sgs__dstr_ptr_as_cstr,   \
    const SGS_StrBuf*     : sgs__strbuf_ptr_as_cstr  \
)(any_str)

#define sgs_equal(anystr1, anystr2) \
sgs__strv_equal(sgs_strv(anystr1), sgs_strv(anystr2))

#define sgs_dup(anystr, ...) \
sgs__dstr_init_from(sgs_strv(anystr), SGS__VA_OR(sgs_get_default_allocator(), __VA_ARGS__))

#define sgs_copy(mutstr_dst, anystr_src) \
_Generic(mutstr_dst, \
    SGS_MutStrRef : sgs__mutstr_ref_copy(sgs__coerce(mutstr_dst, SGS_MutStrRef), sgs_strv(anystr_src)), \
    SGS_DStr*     : sgs__dstr_copy(sgs__coerce(mutstr_dst, SGS_DStr*), sgs_strv(anystr_src)), \
    default       : sgs__fmutstr_ref_copy(sgs__fmutstr_ref(sgs__coerce_not(mutstr_dst, SGS_MutStrRef, SGS_StrBuf*)), sgs_strv(anystr_src)) \
)

#define sgs_putc(mutstr_dst, c) \
_Generic(mutstr_dst, \
    SGS_MutStrRef : sgs__mutstr_ref_putc(sgs__coerce(mutstr_dst, SGS_MutStrRef), c), \
    SGS_DStr*     : sgs__dstr_putc(sgs__coerce(mutstr_dst, SGS_DStr*), c), \
    default       : sgs__fmutstr_ref_putc(sgs__fmutstr_ref(sgs__coerce_not(mutstr_dst, SGS_MutStrRef, SGS_StrBuf*)), c) \
)

#define sgs_append(mutstr_dst, anystr_src) \
_Generic(mutstr_dst, \
    SGS_MutStrRef : sgs__mutstr_ref_append(sgs__coerce(mutstr_dst, SGS_MutStrRef), sgs_strv(anystr_src)), \
    SGS_DStr*     : sgs__dstr_append(sgs__coerce(mutstr_dst, SGS_DStr*), sgs_strv(anystr_src)), \
    default       : sgs__fmutstr_ref_append(sgs__fmutstr_ref(sgs__coerce_not(mutstr_dst, SGS_MutStrRef, SGS_StrBuf*)), sgs_strv(anystr_src)) \
)

#define sgs_insert(mutstr_dst, anystr_src, idx) \
_Generic(mutstr_dst, \
    SGS_MutStrRef : sgs__mutstr_ref_insert(sgs__coerce(mutstr_dst, SGS_MutStrRef), sgs_strv(anystr_src), idx), \
    SGS_DStr*     : sgs__dstr_insert(sgs__coerce(mutstr_dst, SGS_DStr*), sgs_strv(anystr_src), idx), \
    default       : sgs__fmutstr_ref_insert(sgs__fmutstr_ref(sgs__coerce_not(mutstr_dst, SGS_MutStrRef, SGS_StrBuf*)), sgs_strv(anystr_src), idx) \
)

#define sgs_prepend(mutstr_dst, anystr_src) \
sgs_insert(mutstr_dst, anystr_src, 0)

#define sgs_find(anystr_hay, anystr_needle) \
sgs__strv_find(sgs_strv(anystr_hay), sgs_strv(anystr_needle))

#define sgs_count(anystr_hay, anystr_needle) \
sgs__strv_count(sgs_strv(anystr_hay), sgs_strv(anystr_needle))

#define sgs_clear(mutstr) \
_Generic(mutstr, \
    SGS_MutStrRef : sgs__mutstr_ref_clear(sgs__coerce(mutstr, SGS_MutStrRef)), \
    default       : sgs__fmutstr_ref_clear(sgs__fmutstr_ref(sgs__coerce_not(mutstr, SGS_MutStrRef, SGS_StrBuf*))) \
)

#define sgs_starts_with(anystr_hay, anystr_needle) \
sgs__strv_starts_with(sgs_strv(anystr_hay), sgs_strv(anystr_needle))

#define sgs_ends_with(anystr_hay, anystr_needle) \
sgs__strv_ends_with(sgs_strv(anystr_hay), sgs_strv(anystr_needle))

#define sgs_tolower(mutstr) \
sgs__chars_tolower(sgs_strv(mutstr))

#define sgs_toupper(mutstr) \
sgs__chars_toupper(sgs_strv(mutstr))

#define sgs_replace(mutstr_dst, anystr_target, anystr_replacement) \
_Generic(mutstr_dst, \
    MutStrRef : sgs__mutstr_ref_replace(sgs__coerce(mutstr_dst, SGS_MutStrRef), sgs_strv(anystr_target), sgs_strv(anystr_replacement)), \
    SGS_DStr* : sgs__dstr_replace(sgs__coerce(mutstr_dst, SGS_DStr*), sgs_strv(anystr_target), sgs_strv(anystr_replacement)), \
    default   : sgs__fmutstr_ref_replace(sgs__fmutstr_ref(sgs__coerce_not(mutstr_dst, SGS_MutStrRef, SGS_StrBuf*)), sgs_strv(anystr_target), sgs_strv(anystr_replacement)) \
)

#define sgs_replace_first(mutstr_dst, anystr_target, anystr_replacement) \
_Generic(mutstr_dst, \
    SGS_MutStrRef : sgs__mutstr_ref_replace_first(sgs__coerce(mutstr_dst, SGS_MutStrRef), sgs_strv(anystr_target), sgs_strv(anystr_replacement)), \
    SGS_DStr*     : sgs__dstr_replace_first(sgs__coerce(mutstr_dst, SGS_DStr*), sgs_strv(anystr_target), sgs_strv(anystr_replacement)), \
    default       : sgs__fmutstr_ref_replace_first(sgs__fmutstr_ref(sgs__coerce_not(mutstr_dst, SGS_MutStrRef, SGS_StrBuf*)), sgs_strv(anystr_target), sgs_strv(anystr_replacement)) \
)

#define sgs_replace_range(mutstr_dst, begin, end, anystr_replacement) \
_Generic(mutstr_dst, \
    SGS_MutStrRef : sgs__mutstr_ref_replace_range(sgs__coerce(mutstr_dst, SGS_MutStrRef), begin, end, sgs_strv(anystr_replacement)), \
    SGS_DStr*     : sgs__dstr_replace_range(sgs__coerce(mutstr_dst, SGS_DStr*), begin, end, sgs_strv(anystr_replacement)), \
    default       : sgs__fmutstr_ref_replace_range(sgs__fmutstr_ref(sgs__coerce_not(mutstr_dst, SGS_MutStrRef, SGS_StrBuf*)), begin, end, sgs_strv(anystr_replacement)) \
)

#define sgs_split(anystr, anystr_delim, ...) \
sgs__strv_split(sgs_strv(anystr), sgs_strv(anystr_delim), SGS__VA_OR(sgs_get_default_allocator(), __VA_ARGS__))

#define sgs_split_iter(anystr, anystr_delim, callback, ...) \
sgs__strv_split_iter(sgs_strv(anystr), sgs_strv(anystr_delim), callback, SGS__VA_OR(NULL, __VA_ARGS__));

#define sgs_join(mutstr_dst, strv_arr, anystr_delim) \
_Generic(mutstr_dst, \
    SGS_MutStrRef : sgs__strv_arr_join(sgs__coerce(mutstr_dst, SGS_MutStrRef), strv_arr, sgs_strv(anystr_delim)), \
    SGS_DStr*     : sgs__strv_arr_join_into_dstr(sgs__coerce(mutstr_dst, SGS_DStr*), strv_arr, sgs_strv(anystr_delim)), \
    default       : sgs__strv_arr_join_into_fmutstr_ref(sgs__fmutstr_ref(sgs__coerce_not(mutstr_dst, SGS_MutStrRef, SGS_StrBuf*)), strv_arr, sgs_strv(anystr_delim)) \
)

// DString branch can call fmutstr_ref version directly (its a shrink-only operation)
#define sgs_del(mutstr_dst, begin, end) \
_Generic(mutstr_dst, \
    SGS_MutStrRef : sgs__mutstr_ref_delete_range(sgs__coerce(mutstr_dst, SGS_MutStrRef), begin, end), \
    default       : sgs__fmutstr_ref_delete_range(sgs__fmutstr_ref(sgs__coerce_not(mutstr_dst, SGS_MutStrRef, SGS_StrBuf*)), begin, end) \
)

#define sgs_fread_line(mutstr_dst, stream) \
_Generic(mutstr_dst, \
    SGS_MutStrRef : sgs__mutstr_ref_fread_line(sgs__coerce(mutstr_dst, SGS_MutStrRef), stream), \
    SGS_DStr*     : sgs__dstr_fread_line(sgs__coerce(mutstr_dst, SGS_DStr*), stream), \
    default       : sgs__fmutstr_ref_fread_line(sgs__fmutstr_ref(sgs__coerce_not(mutstr_dst, SGS_MutStrRef, SGS_StrBuf*)), stream) \
)

#define sgs_append_fread_line(mutstr_dst, stream) \
_Generic(mutstr_dst, \
    SGS_MutStrRef : sgs__mutstr_ref_append_fread_line(sgs__coerce(mutstr_dst, SGS_MutStrRef), stream), \
    SGS_DStr*     : sgs__dstr_append_fread_line(sgs__coerce(mutstr_dst, SGS_DStr*), stream), \
    default       : sgs__fmutstr_ref_append_fread_line(sgs__fmutstr_ref(sgs__coerce_not(mutstr_dst, SGS_MutStrRef, SGS_StrBuf*)), stream) \
)

#define sgs_read_line(mutstr_dst) \
sgs_fread_line(mutstr_dst, stdin)

#define sgs_append_read_line(mutstr_dst) \
sgs_append_fread_line(mutstr_dst, stdin)

// helper macro
#define sgs__str_print_each(x) \
do \
{ \
    sgs__appender_mutstr_ref = sgs__make_appender_mutstr_ref( \
        sgs__as_mutstr_ref, \
        &sgs__appender_state \
    ); \
    sgs_tostr(sgs__appender_mutstr_ref, x); \
    sgs__mutstr_ref_commit_appender( \
        sgs__as_mutstr_ref, \
        sgs__appender_mutstr_ref \
    ); \
} while(0);

#define sgs__sprint_each_setup(...) \
__VA_OPT__( \
    SGS_StrAppenderState sgs__appender_state = {0}; \
    SGS_MutStrRef sgs__appender_mutstr_ref; \
    SGS__FOREACH(sgs__str_print_each, __VA_ARGS__); \
)

#define sgs_sprint_append(mutstr_dst, ...) \
do \
{ \
    SGS_MutStrRef sgs__as_mutstr_ref = sgs_mutstr_ref(mutstr_dst); \
    sgs__sprint_each_setup(__VA_ARGS__); \
} while(0)

#define sgs_sprint(mutstr_dst, ...) \
do \
{ \
    SGS_MutStrRef sgs__as_mutstr_ref = sgs_mutstr_ref(mutstr_dst); \
    sgs_clear(sgs__as_mutstr_ref); \
    sgs__sprint_each_setup(__VA_ARGS__); \
} while(0)

#define sgs_strv_arr_from_carr(strv_carr, ...) \
sgs__strv_arr_from_carr(strv_carr, SGS__VA_OR(SGS__CARR_LEN(strv_carr), __VA_ARGS__))

#define SGS__STRV_COMMA(anystr) \
sgs_strv(anystr),

#define sgs_strv_arr(...)                                                                  \
(                                                                                          \
(SGS_StrViewArray) {                                                                       \
    .len  = SGS__CARR_LEN(((SGS_StrView[]){SGS__FOREACH(SGS__STRV_COMMA, __VA_ARGS__)})),  \
    .cap  = SGS__CARR_LEN(((SGS_StrView[]){SGS__FOREACH(SGS__STRV_COMMA, __VA_ARGS__)})),  \
    .strs = (SGS_StrView[]){SGS__FOREACH(SGS__STRV_COMMA, __VA_ARGS__)}                    \
}                                                                                          \
)

// Calls strlen on the cstr to determine its length
// if no capacity is passed, then:
// if char[] is passed, it uses the size of the array as capacity
// if char* is passed, the capacity is length+1
#define sgs_strbuf_init_from_cstr(cstr, ...) \
__VA_OPT__(sgs__strbuf_init_from_cstr_2(cstr, __VA_ARGS__)) \
SGS__IF_EMPTY(sgs__strbuf_init_from_cstr_(cstr), __VA_ARGS__)

#define sgs__strbuf_init_from_cstr_(cstr)                             \
sgs__strbuf_from_cstr(cstr,                                           \
_Generic(&(__typeof__(cstr)){0},                                      \
char(*)[sizeof(__typeof__(cstr))]         : sizeof(__typeof__(cstr)), \
unsigned char(*)[sizeof(__typeof__(cstr))]: sizeof(__typeof__(cstr)), \
char**                                    : strlen((char*) cstr) + 1, \
unsigned char**                           : strlen((char*) cstr) + 1  \
))

#define sgs__strbuf_init_from_cstr_2(cstr, cap) \
sgs__strbuf_from_cstr(cstr, cap)

// Does not call strlen on the buf
// Sets the first byte to '\0'
#define sgs_strbuf_init_from_buf(buf, ...) \
__VA_OPT__( sgs__strbuf_init_from_buf_2(buf, __VA_ARGS__) ) \
SGS__IF_EMPTY(sgs__strbuf_init_from_buf_(buf), __VA_ARGS__)

#define sgs__strbuf_init_from_buf_(buf) \
sgs__strbuf_from_buf( \
_Generic(&(__typeof__(buf)){0}, \
    char(*)[sizeof(__typeof__(buf))]: (SGS_Buffer){.ptr = (unsigned char*) (buf), .cap = sizeof(buf)}, \
    unsigned char(*)[sizeof(__typeof__(buf))]: (SGS_Buffer){.ptr = (unsigned char*) (buf), .cap = sizeof(buf)}, \
    SGS_Buffer*: buf \
))

#define sgs__strbuf_init_from_buf_2(buf, cap_) \
sgs__strbuf_from_buf((SGS_Buffer){.ptr = (unsigned char*) _Generic(buf,char*:buf,unsigned char*:buf,void*:buf), .cap = cap_})

#define sgs__cstr_to_buf(carr, ...) \
( \
SGS__IF_EMPTY( \
    _Generic((__typeof__(carr)*){0}, \
        char(*)[sizeof(__typeof__(carr))]: (SGS_Buffer){.ptr = (unsigned char*) (carr), .cap = sizeof(carr)}, \
        unsigned char(*)[sizeof(__typeof__(any_str))]: (SGS_Buffer){.ptr = (unsigned char*) (carr), .cap = sizeof(carr)} \
    ), \
    __VA_ARGS__ \
) \
__VA_OPT__(sgs__cstr_to_buf2((carr), __VA_ARGS__)) \
)

#define sgs__cstr_to_buf2(carr_or_ptr, cap_) \
((void)_Generic(carr_or_ptr, \
    char(*)[sizeof(__typeof__(carr_or_ptr))]: 0, \
    unsigned char(*)[sizeof(__typeof__(carr_or_ptr))]: 0, \
    char*: 0, \
    unsigned char*: 0 \
), \
(SGS_Buffer){.ptr = (unsigned char*) (carr_or_ptr), .cap = (cap_)})

#define sgs_mutstr_ref(mutstr, ...) \
SGS__CAT(sgs__mutstr_ref, __VA_OPT__(2))((mutstr) __VA_OPT__(,) __VA_ARGS__)

#define sgs__mutstr_ref(mutstr)                                               \
_Generic((__typeof__(mutstr)*){0},                                            \
char**                                       : sgs__cstr_as_mutstr_ref,       \
unsigned char**                              : sgs__ucstr_as_mutstr_ref,      \
SGS_DStr**                                   : sgs__dstr_ptr_as_mutstr_ref,   \
SGS_StrBuf**                                 : sgs__strbuf_ptr_as_mutstr_ref, \
SGS_MutStrRef*                               : sgs__mutstr_ref_as_mutstr_ref, \
char(*)[sizeof(__typeof__(mutstr))]          : sgs__buf_as_mutstr_ref,        \
unsigned char(*)[sizeof(__typeof__(mutstr))] : sgs__buf_as_mutstr_ref         \
)(_Generic((__typeof__(mutstr)*){0},                                          \
    char(*)[sizeof(__typeof__(mutstr))]          : (SGS_Buffer){.ptr = (unsigned char*) sgs__coerce(mutstr, char*),          .cap = sizeof(__typeof__(mutstr))}, \
    unsigned char(*)[sizeof(__typeof__(mutstr))] : (SGS_Buffer){.ptr =                  sgs__coerce(mutstr, unsigned char*), .cap = sizeof(__typeof__(mutstr))}, \
    default: (mutstr) \
))

#define sgs__mutstr_ref2(carr_or_ptr, cap_) \
(SGS_MutStrRef){.ty = SGS__BUF_TY, .str.carr = sgs__cstr_to_buf(carr_or_ptr, cap_)} \

#define sgs_appender(mutstr_owner, appender_state) \
sgs__make_appender_mutstr_ref(sgs_mutstr_ref(mutstr_owner), (appender_state))

#define sgs_commit_appender(mutstr_owner, appender) \
sgs__mutstr_ref_commit_appender(sgs_mutstr_ref(mutstr_owner), appender)

#define sgs_strv(any_str, ...) \
__VA_OPT__(sgs__strv2(any_str, __VA_ARGS__)) \
SGS__IF_EMPTY(sgs__strv1(any_str), __VA_ARGS__)

#define sgs__strv1(anystr)                        \
_Generic(anystr,                                  \
    char*                : sgs__strv_cstr1,       \
    unsigned char*       : sgs__strv_ucstr1,      \
    SGS_DStr             : sgs__strv_dstr1,       \
    SGS_DStr*            : sgs__strv_dstr_ptr1,   \
    SGS_StrView          : sgs__strv_strv1,       \
    SGS_StrBuf           : sgs__strv_strbuf1,     \
    SGS_StrBuf*          : sgs__strv_strbuf_ptr1, \
    SGS_MutStrRef        : sgs__strv_mutstr_ref1, \
    const char*          : sgs__strv_cstr1,       \
    const unsigned char* : sgs__strv_ucstr1,      \
    const SGS_DStr*      : sgs__strv_dstr_ptr1,   \
    const SGS_StrBuf*    : sgs__strv_strbuf_ptr1  \
)(anystr)

#define sgs__strv2(anystr, begin, ...)             \
__VA_OPT__(sgs__strv3(anystr, begin, __VA_ARGS__)) \
SGS__IF_EMPTY(                                     \
_Generic(anystr,                                   \
    char*                : sgs__strv_cstr2,        \
    unsigned char*       : sgs__strv_ucstr2,       \
    SGS_DStr             : sgs__strv_dstr2,        \
    SGS_DStr*            : sgs__strv_dstr_ptr2,    \
    SGS_StrView          : sgs__strv_strv2,        \
    SGS_StrBuf           : sgs__strv_strbuf2,      \
    SGS_StrBuf*          : sgs__strv_strbuf_ptr2,  \
    SGS_MutStrRef        : sgs__strv_mutstr_ref2,  \
    const char*          : sgs__strv_cstr2,        \
    const unsigned char* : sgs__strv_ucstr2,       \
    const SGS_DStr*      : sgs__strv_dstr_ptr2,    \
    const SGS_StrBuf*    : sgs__strv_strbuf_ptr2   \
)(anystr, begin), __VA_ARGS__)

#define sgs__strv3(anystr, begin, end)            \
_Generic(anystr,                                  \
    char*                : sgs__strv_cstr3,       \
    unsigned char*       : sgs__strv_ucstr3,      \
    SGS_DStr             : sgs__strv_dstr3,       \
    SGS_DStr*            : sgs__strv_dstr_ptr3,   \
    SGS_StrView          : sgs__strv_strv3,       \
    SGS_StrBuf           : sgs__strv_strbuf3,     \
    SGS_StrBuf*          : sgs__strv_strbuf_ptr3, \
    SGS_MutStrRef        : sgs__strv_mutstr_ref3, \
    const char*          : sgs__strv_cstr3,       \
    const unsigned char* : sgs__strv_ucstr3,      \
    const SGS_DStr*      : sgs__strv_dstr_ptr3,   \
    const SGS_StrBuf*    : sgs__strv_strbuf_ptr3  \
)(anystr, begin, end)

#define sgs_dstr_init(...) \
SGS__CAT(sgs__dstr_init0, __VA_OPT__(1))(__VA_ARGS__)

#define sgs__dstr_init0() \
sgs__dstr_init(1, sgs_get_default_allocator())

#define sgs__dstr_init01(cap, ...)               \
__VA_OPT__(sgs__dstr_init2((cap), __VA_ARGS__)) \
SGS__IF_EMPTY(                                  \
    sgs__dstr_init(                             \
        (cap),                                  \
        sgs_get_default_allocator()             \
    )                                           \
, __VA_ARGS__                                   \
)

#define sgs__dstr_init2(cap, allocator) \
sgs__dstr_init((cap), (allocator))

#define sgs_dstr_init_from(anystr_src, ...) \
sgs__dstr_init_from(sgs_strv(anystr_src), SGS__VA_OR(sgs_get_default_allocator(), __VA_ARGS__))

#define sgs_dstr_deinit(dstr) \
sgs__dstr_deinit(dstr)

#define sgs_dstr_shrink_to_fit(dstr) \
sgs__dstr_shrink_to_fit(dstr)

#define sgs_dstr_ensure_cap(dstr, new_cap) \
sgs__dstr_ensure_cap(dstr, new_cap)

#define sgs_fprint(f, ...)                       \
do                                               \
{                                                \
    FILE *sgs__file_stream = f;                  \
    (void) sgs__file_stream;                     \
    extern _Thread_local SGS_DStr sgs__fprint_tostr_dynamic_buffer; \
    SGS__FOREACH(sgs__fprint_each, __VA_ARGS__); \
} while(0)

#define sgs__fprint_each(x)                                 \
do                                                          \
{                                                           \
    __typeof__(((void)0,x)) sgs__x_tmp = x;                 \
    sgs__fprint_strv(sgs__file_stream, _Generic(sgs__x_tmp, \
        char*                     : sgs__strv_cstr1,        \
        unsigned char*            : sgs__strv_ucstr1,       \
        SGS_DStr                  : sgs__strv_dstr1,        \
        SGS_DStr*                 : sgs__strv_dstr_ptr1,    \
        SGS_StrView               : sgs__strv_strv1,        \
        SGS_StrBuf                : sgs__strv_strbuf1,      \
        SGS_StrBuf*               : sgs__strv_strbuf_ptr1,  \
        SGS_MutStrRef             : sgs__strv_mutstr_ref1,  \
        const char*               : sgs__strv_cstr1,        \
        const unsigned char*      : sgs__strv_ucstr1,       \
        const SGS_DStr*           : sgs__strv_dstr_ptr1,    \
        const SGS_StrBuf*         : sgs__strv_strbuf_ptr1,  \
        default                   : sgs__strv_dstr1         \
    )(sgs__coerce_string_type(sgs__x_tmp, (sgs_tostr(&sgs__fprint_tostr_dynamic_buffer, sgs__x_tmp), sgs__fprint_tostr_dynamic_buffer)))); \
    sgs__fprint_tostr_dynamic_buffer.len = 0;               \
} while(0);

#define sgs_print(...) \
sgs_fprint(stdout, __VA_ARGS__)

#define sgs_fprintln(f, ...)                \
do                                          \
{                                           \
    FILE *sgs__tmp_file = f;                \
    (void) sgs__tmp_file;                   \
    sgs_fprint(sgs__tmp_file, __VA_ARGS__); \
    fputc('\n', sgs__tmp_file);             \
} while(0)

#define sgs_println(...) \
sgs_fprintln(stdout, __VA_ARGS__)

typedef char sgs__c;
typedef signed char sgs__sc;
typedef unsigned char sgs__uc;
typedef short sgs__s;
typedef unsigned short sgs__us;
typedef int sgs__i;
typedef unsigned int sgs__ui;
typedef long sgs__l;
typedef unsigned long sgs__ul;
typedef long long sgs__ll;
typedef unsigned long long sgs__ull;

#define SGS__MCALL(macro, arglist) macro arglist

#define SGS__INTEGER_TYPES(SGS__X, extra, ...) \
SGS__X(sgs__c, extra)  \
SGS__X(sgs__sc, extra) \
SGS__X(sgs__uc, extra) \
SGS__X(sgs__s, extra)  \
SGS__X(sgs__us, extra) \
SGS__X(sgs__i, extra)  \
SGS__X(sgs__ui, extra) \
SGS__X(sgs__l, extra)  \
SGS__X(sgs__ul, extra) \
SGS__X(sgs__ll, extra) \
SGS__MCALL(SGS__VA_OR(SGS__X, __VA_ARGS__), (sgs__ull, extra))

#define SGS__FLOATING_TYPES(SGS__X, extra, last_call) \
SGS__X(float, extra) \
last_call(double, extra)

#define SGS__X(ty, extra) \
typedef struct SGS__Integer_d_Fmt_##ty \
{ \
    ty obj; \
} SGS__Integer_d_Fmt_##ty; \
typedef struct SGS__Integer_x_Fmt_##ty \
{ \
    ty obj; \
} SGS__Integer_x_Fmt_##ty; \
typedef struct SGS__Integer_o_Fmt_##ty \
{ \
    ty obj; \
} SGS__Integer_o_Fmt_##ty; \
typedef struct SGS__Integer_b_Fmt_##ty \
{ \
    ty obj; \
} SGS__Integer_b_Fmt_##ty; \
typedef struct SGS__Integer_X_Fmt_##ty \
{ \
    ty obj; \
} SGS__Integer_X_Fmt_##ty;

SGS__INTEGER_TYPES(SGS__X, ignore)

#undef SGS__X

#define SGS__X(ty, extra) \
typedef struct SGS__Floating_f_Fmt_##ty \
{ \
    ty obj; \
    int precision; \
} SGS__Floating_f_Fmt_##ty; \
typedef struct SGS__Floating_g_Fmt_##ty \
{ \
    ty obj; \
    int precision; \
} SGS__Floating_g_Fmt_##ty; \
typedef struct SGS__Floating_e_Fmt_##ty \
{ \
    ty obj; \
    int precision; \
} SGS__Floating_e_Fmt_##ty; \
typedef struct SGS__Floating_a_Fmt_##ty \
{ \
    ty obj; \
    int precision; \
} SGS__Floating_a_Fmt_##ty; \
typedef struct SGS__Floating_F_Fmt_##ty \
{ \
    ty obj; \
    int precision; \
} SGS__Floating_F_Fmt_##ty; \
typedef struct SGS__Floating_G_Fmt_##ty \
{ \
    ty obj; \
    int precision; \
} SGS__Floating_G_Fmt_##ty; \
typedef struct SGS__Floating_E_Fmt_##ty \
{ \
    ty obj; \
    int precision; \
} SGS__Floating_E_Fmt_##ty; \
typedef struct SGS__Floating_A_Fmt_##ty \
{ \
    ty obj; \
    int precision; \
} SGS__Floating_A_Fmt_##ty;

SGS__FLOATING_TYPES(SGS__X, ignore, SGS__X)

#undef SGS__X

#define SGS__X_IS_TY(ty, extra) \
ty: 1,

#define SGS__IS_FLOATING(obj) \
_Generic(obj, \
SGS__FLOATING_TYPES(SGS__X_IS_TY, ignore, SGS__X_IS_TY) \
default: 0)

#define SGS__IS_INTEGER(obj) \
_Generic(obj, \
SGS__INTEGER_TYPES(SGS__X_IS_TY, ignore) \
default: 0)

#define SGS__INTEGER_FMT_GENERIC_BRANCHES(ty, extra) \
ty: \
_Generic((char(*)[SGS__ARG2 extra]){0}, \
char(*)['d']: (SGS__Integer_d_Fmt_##ty){sgs__coerce(SGS__ARG1 extra, ty)},  \
char(*)['x']: (SGS__Integer_x_Fmt_##ty){sgs__coerce(SGS__ARG1 extra, ty)},  \
char(*)['o']: (SGS__Integer_o_Fmt_##ty){sgs__coerce(SGS__ARG1 extra, ty)},  \
char(*)['b']: (SGS__Integer_b_Fmt_##ty){sgs__coerce(SGS__ARG1 extra, ty)},  \
char(*)['X']: (SGS__Integer_X_Fmt_##ty){sgs__coerce(SGS__ARG1 extra, ty)},  \
default: 0),

#define SGS__3_VA_OR(otherwise, a,b, ...) \
SGS__VA_OR(otherwise, __VA_ARGS__)

#define SGS__FLOATING_FMT_LAST_GENERIC_BRANCH(ty, extra) \
ty: \
_Generic((char(*)[SGS__ARG2 extra]){0}, \
char(*)['f']: (SGS__Floating_f_Fmt_##ty){sgs__coerce(SGS__ARG1 extra, ty), SGS__MCALL(SGS__3_VA_OR, (6 , SGS__EXPAND1 extra))}, \
char(*)['g']: (SGS__Floating_g_Fmt_##ty){sgs__coerce(SGS__ARG1 extra, ty), SGS__MCALL(SGS__3_VA_OR, (6 , SGS__EXPAND1 extra))}, \
char(*)['e']: (SGS__Floating_e_Fmt_##ty){sgs__coerce(SGS__ARG1 extra, ty), SGS__MCALL(SGS__3_VA_OR, (6 , SGS__EXPAND1 extra))}, \
char(*)['a']: (SGS__Floating_a_Fmt_##ty){sgs__coerce(SGS__ARG1 extra, ty), SGS__MCALL(SGS__3_VA_OR, (-1, SGS__EXPAND1 extra))}, \
char(*)['F']: (SGS__Floating_F_Fmt_##ty){sgs__coerce(SGS__ARG1 extra, ty), SGS__MCALL(SGS__3_VA_OR, (6 , SGS__EXPAND1 extra))}, \
char(*)['G']: (SGS__Floating_G_Fmt_##ty){sgs__coerce(SGS__ARG1 extra, ty), SGS__MCALL(SGS__3_VA_OR, (6 , SGS__EXPAND1 extra))}, \
char(*)['E']: (SGS__Floating_E_Fmt_##ty){sgs__coerce(SGS__ARG1 extra, ty), SGS__MCALL(SGS__3_VA_OR, (6 , SGS__EXPAND1 extra))}, \
char(*)['A']: (SGS__Floating_A_Fmt_##ty){sgs__coerce(SGS__ARG1 extra, ty), SGS__MCALL(SGS__3_VA_OR, (-1, SGS__EXPAND1 extra))}, \
default: 0)

#define SGS__FLOATING_FMT_GENERIC_BRANCH(ty, extra) \
SGS__FLOATING_FMT_LAST_GENERIC_BRANCH(ty, extra),

#define sgs_tsfmt(x, fmt_chr, ...) \
( \
    sgs__static_assertx( (SGS__IS_FLOATING(x) && (fmt_chr == 'f' || fmt_chr == 'g' || fmt_chr == 'e' || fmt_chr == 'a' || fmt_chr == 'F' || fmt_chr == 'G' || fmt_chr == 'E' || fmt_chr == 'A')  ) || (SGS__IS_INTEGER(x) && (fmt_chr == 'd' || fmt_chr == 'x' || fmt_chr == 'o' || fmt_chr == 'b' || fmt_chr == 'X')), "Incorrect formatting char for the type"), \
    sgs__static_assertx((SGS__IS_FLOATING(x) || (1 __VA_OPT__(-1))), "tsfmt Integers dont take a third parameter"), \
    _Generic(x, \
        SGS__INTEGER_TYPES(SGS__INTEGER_FMT_GENERIC_BRANCHES, (x, fmt_chr)) \
        SGS__FLOATING_TYPES(SGS__FLOATING_FMT_GENERIC_BRANCH, (x, fmt_chr __VA_OPT__(,) __VA_ARGS__), SGS__FLOATING_FMT_LAST_GENERIC_BRANCH) \
    ) \
)

#define sgs_tsfmt_t(ty, fmt_chr) \
__typeof__(sgs_tsfmt((ty)0, fmt_chr))

#define sgs_arrfmt(array, nb, ...) \
SGS__IF_EMPTY(sgs__arrfmt_, __VA_ARGS__) \
__VA_OPT__(sgs__arrfmt_2) \
(array, nb __VA_OPT__(,) __VA_ARGS__)

#define sgs__arrfmt_(array_, nb_) \
((SGS_ArrayFmt){ \
    .array = (array_), \
    .nb = (nb_), \
    .elm_size = sizeof((array_)[0]), \
    .elm_tostr = (void*) sgs__get_tostr_p_func(__typeof__((array_)[0])), \
    .open = sgs_strv("{"), \
    .close = sgs_strv("}"), \
    .separator = sgs_strv(", "), \
    .trailing_separator = sgs_strv("") \
})

#define sgs__arrfmt_2(array_, nb_, open_, close_, seperator_, ...) \
((SGS_ArrayFmt){ \
    .array = (array_), \
    .nb = (nb_), \
    .elm_size = sizeof((array_)[0]), \
    .elm_tostr = (void*) sgs__get_tostr_p_func(__typeof__((array_)[0])), \
    .open = sgs_strv(open_), \
    .close = sgs_strv(close_), \
    .separator = sgs_strv(seperator_), \
    .trailing_separator = sgs_strv(SGS__VA_OR("", __VA_ARGS__)) \
})

#define SGS__INTEGER_TOSTR_GENERIC_CASE(ty, extra)         \
SGS__Integer_d_Fmt_##ty : sgs__Integer_d_Fmt_##ty##_tostr, \
SGS__Integer_x_Fmt_##ty : sgs__Integer_x_Fmt_##ty##_tostr, \
SGS__Integer_o_Fmt_##ty : sgs__Integer_o_Fmt_##ty##_tostr, \
SGS__Integer_b_Fmt_##ty : sgs__Integer_b_Fmt_##ty##_tostr, \
SGS__Integer_X_Fmt_##ty : sgs__Integer_X_Fmt_##ty##_tostr, \

#define SGS__FLOATING_TOSTR_LAST_GENERIC_CASE(ty, extra)     \
SGS__Floating_f_Fmt_##ty : sgs__Floating_f_Fmt_##ty##_tostr, \
SGS__Floating_g_Fmt_##ty : sgs__Floating_g_Fmt_##ty##_tostr, \
SGS__Floating_e_Fmt_##ty : sgs__Floating_e_Fmt_##ty##_tostr, \
SGS__Floating_a_Fmt_##ty : sgs__Floating_a_Fmt_##ty##_tostr, \
SGS__Floating_F_Fmt_##ty : sgs__Floating_F_Fmt_##ty##_tostr, \
SGS__Floating_G_Fmt_##ty : sgs__Floating_G_Fmt_##ty##_tostr, \
SGS__Floating_E_Fmt_##ty : sgs__Floating_E_Fmt_##ty##_tostr, \
SGS__Floating_A_Fmt_##ty : sgs__Floating_A_Fmt_##ty##_tostr

#define SGS__INTEGER_TOSTR_P_GENERIC_CASE(ty, extra)         \
SGS__Integer_d_Fmt_##ty : sgs__Integer_d_Fmt_##ty##_tostr_p, \
SGS__Integer_x_Fmt_##ty : sgs__Integer_x_Fmt_##ty##_tostr_p, \
SGS__Integer_o_Fmt_##ty : sgs__Integer_o_Fmt_##ty##_tostr_p, \
SGS__Integer_b_Fmt_##ty : sgs__Integer_b_Fmt_##ty##_tostr_p, \
SGS__Integer_X_Fmt_##ty : sgs__Integer_X_Fmt_##ty##_tostr_p,

#define SGS__FLOATING_TOSTR_P_LAST_GENERIC_CASE(ty, extra)     \
SGS__Floating_f_Fmt_##ty : sgs__Floating_f_Fmt_##ty##_tostr_p, \
SGS__Floating_g_Fmt_##ty : sgs__Floating_g_Fmt_##ty##_tostr_p, \
SGS__Floating_e_Fmt_##ty : sgs__Floating_e_Fmt_##ty##_tostr_p, \
SGS__Floating_a_Fmt_##ty : sgs__Floating_a_Fmt_##ty##_tostr_p, \
SGS__Floating_F_Fmt_##ty : sgs__Floating_F_Fmt_##ty##_tostr_p, \
SGS__Floating_G_Fmt_##ty : sgs__Floating_G_Fmt_##ty##_tostr_p, \
SGS__Floating_E_Fmt_##ty : sgs__Floating_E_Fmt_##ty##_tostr_p, \
SGS__Floating_A_Fmt_##ty : sgs__Floating_A_Fmt_##ty##_tostr_p

#define SGS__FLOATING_TOSTR_GENERIC_CASE(ty, extra) \
SGS__FLOATING_TOSTR_LAST_GENERIC_CASE(ty, extra),

#define SGS__FLOATING_TOSTR_P_GENERIC_CASE(ty, extra) \
SGS__FLOATING_TOSTR_P_LAST_GENERIC_CASE(ty, extra),

#define SGS__DEFAULT_TOSTR_GENERIC_BRANCHES                 \
bool                      : sgs__bool_tostr,                \
char*                     : sgs__cstr_tostr,                \
unsigned char*            : sgs__ucstr_tostr,               \
char                      : sgs__char_tostr,                \
signed char               : sgs__schar_tostr,               \
unsigned char             : sgs__uchar_tostr,               \
short                     : sgs__short_tostr,               \
unsigned short            : sgs__ushort_tostr,              \
int                       : sgs__int_tostr,                 \
unsigned int              : sgs__uint_tostr,                \
long                      : sgs__long_tostr,                \
unsigned long             : sgs__ulong_tostr,               \
long long                 : sgs__llong_tostr,               \
unsigned long long        : sgs__ullong_tostr,              \
float                     : sgs__float_tostr,               \
double                    : sgs__double_tostr,              \
SGS_DStr                  : sgs__dstr_tostr,                \
SGS_DStr*                 : sgs__dstr_ptr_tostr,            \
SGS_StrView               : sgs__strv_tostr,                \
SGS_StrBuf                : sgs__strbuf_tostr,              \
SGS_StrBuf*               : sgs__strbuf_ptr_tostr,          \
SGS_MutStrRef             : sgs__mutstr_ref_tostr,          \
const char*               : sgs__cstr_tostr,                \
const unsigned char*      : sgs__ucstr_tostr,               \
const SGS_DStr*           : sgs__dstr_ptr_tostr,            \
const SGS_StrBuf*         : sgs__strbuf_ptr_tostr,          \
SGS_Error                 : sgs__error_tostr,               \
SGS_ArrayFmt              : sgs__array_fmt_tostr,           \
SGS__INTEGER_TYPES(SGS__INTEGER_TOSTR_GENERIC_CASE, ignore) \
SGS__FLOATING_TYPES(SGS__FLOATING_TOSTR_GENERIC_CASE, ignore, SGS__FLOATING_TOSTR_LAST_GENERIC_CASE)

#define SGS__DEFAULT_TOSTR_P_GENERIC_BRANCHES                 \
bool                      : sgs__bool_tostr_p,                \
char*                     : sgs__cstr_tostr_p,                \
unsigned char*            : sgs__ucstr_tostr_p,               \
char                      : sgs__char_tostr_p,                \
signed char               : sgs__schar_tostr_p,               \
unsigned char             : sgs__uchar_tostr_p,               \
short                     : sgs__short_tostr_p,               \
unsigned short            : sgs__ushort_tostr_p,              \
int                       : sgs__int_tostr_p,                 \
unsigned int              : sgs__uint_tostr_p,                \
long                      : sgs__long_tostr_p,                \
unsigned long             : sgs__ulong_tostr_p,               \
long long                 : sgs__llong_tostr_p,               \
unsigned long long        : sgs__ullong_tostr_p,              \
float                     : sgs__float_tostr_p,               \
double                    : sgs__double_tostr_p,              \
SGS_DStr                  : sgs__dstr_tostr_p,                \
SGS_DStr*                 : sgs__dstr_ptr_tostr_p,            \
SGS_StrView               : sgs__strv_tostr_p,                \
SGS_StrBuf                : sgs__strbuf_tostr_p,              \
SGS_StrBuf*               : sgs__strbuf_ptr_tostr_p,          \
SGS_MutStrRef             : sgs__mutstr_ref_tostr_p,          \
const char*               : sgs__cstr_tostr_p,                \
const unsigned char*      : sgs__ucstr_tostr_p,               \
const SGS_DStr*           : sgs__dstr_ptr_tostr_p,            \
const SGS_StrBuf*         : sgs__strbuf_ptr_tostr_p,          \
SGS_Error                 : sgs__error_tostr_p,               \
SGS_ArrayFmt*             : sgs__array_fmt_tostr_p,           \
SGS__INTEGER_TYPES(SGS__INTEGER_TOSTR_P_GENERIC_CASE, ignore) \
SGS__FLOATING_TYPES(SGS__FLOATING_TOSTR_P_GENERIC_CASE, ignore, SGS__FLOATING_TOSTR_P_LAST_GENERIC_CASE)

#define SGS__TOSTR_FUNCS_GENERIC_BRANCHES                          \
SGS__IF_DEF(SGS__TOSTR1) (sgs__tostr_type_1 : sgs__tostr_func_1,)  \
SGS__IF_DEF(SGS__TOSTR2) (sgs__tostr_type_2 : sgs__tostr_func_2,)  \
SGS__IF_DEF(SGS__TOSTR3) (sgs__tostr_type_3 : sgs__tostr_func_3,)  \
SGS__IF_DEF(SGS__TOSTR4) (sgs__tostr_type_4 : sgs__tostr_func_4,)  \
SGS__IF_DEF(SGS__TOSTR5) (sgs__tostr_type_5 : sgs__tostr_func_5,)  \
SGS__IF_DEF(SGS__TOSTR6) (sgs__tostr_type_6 : sgs__tostr_func_6,)  \
SGS__IF_DEF(SGS__TOSTR7) (sgs__tostr_type_7 : sgs__tostr_func_7,)  \
SGS__IF_DEF(SGS__TOSTR8) (sgs__tostr_type_8 : sgs__tostr_func_8,)  \
SGS__IF_DEF(SGS__TOSTR9) (sgs__tostr_type_9 : sgs__tostr_func_9,)  \
SGS__IF_DEF(SGS__TOSTR10)(sgs__tostr_type_10: sgs__tostr_func_10,) \
SGS__IF_DEF(SGS__TOSTR11)(sgs__tostr_type_11: sgs__tostr_func_11,) \
SGS__IF_DEF(SGS__TOSTR12)(sgs__tostr_type_12: sgs__tostr_func_12,) \
SGS__IF_DEF(SGS__TOSTR13)(sgs__tostr_type_13: sgs__tostr_func_13,) \
SGS__IF_DEF(SGS__TOSTR14)(sgs__tostr_type_14: sgs__tostr_func_14,) \
SGS__IF_DEF(SGS__TOSTR15)(sgs__tostr_type_15: sgs__tostr_func_15,) \
SGS__IF_DEF(SGS__TOSTR16)(sgs__tostr_type_16: sgs__tostr_func_16,) \
SGS__IF_DEF(SGS__TOSTR17)(sgs__tostr_type_17: sgs__tostr_func_17,) \
SGS__IF_DEF(SGS__TOSTR18)(sgs__tostr_type_18: sgs__tostr_func_18,) \
SGS__IF_DEF(SGS__TOSTR19)(sgs__tostr_type_19: sgs__tostr_func_19,) \
SGS__IF_DEF(SGS__TOSTR20)(sgs__tostr_type_20: sgs__tostr_func_20,) \
SGS__IF_DEF(SGS__TOSTR21)(sgs__tostr_type_21: sgs__tostr_func_21,) \
SGS__IF_DEF(SGS__TOSTR22)(sgs__tostr_type_22: sgs__tostr_func_22,) \
SGS__IF_DEF(SGS__TOSTR23)(sgs__tostr_type_23: sgs__tostr_func_23,) \
SGS__IF_DEF(SGS__TOSTR24)(sgs__tostr_type_24: sgs__tostr_func_24,) \
SGS__IF_DEF(SGS__TOSTR25)(sgs__tostr_type_25: sgs__tostr_func_25,) \
SGS__IF_DEF(SGS__TOSTR26)(sgs__tostr_type_26: sgs__tostr_func_26,) \
SGS__IF_DEF(SGS__TOSTR27)(sgs__tostr_type_27: sgs__tostr_func_27,) \
SGS__IF_DEF(SGS__TOSTR28)(sgs__tostr_type_28: sgs__tostr_func_28,) \
SGS__IF_DEF(SGS__TOSTR29)(sgs__tostr_type_29: sgs__tostr_func_29,) \
SGS__IF_DEF(SGS__TOSTR30)(sgs__tostr_type_30: sgs__tostr_func_30,) \
SGS__IF_DEF(SGS__TOSTR31)(sgs__tostr_type_31: sgs__tostr_func_31,) \
SGS__IF_DEF(SGS__TOSTR32)(sgs__tostr_type_32: sgs__tostr_func_32,) \
SGS__DEFAULT_TOSTR_GENERIC_BRANCHES

#define SGS__TOSTR_P_FUNCS_GENERIC_BRANCHES                          \
SGS__IF_DEF(SGS__TOSTR1) (sgs__tostr_type_1 : sgs__tostr_p_func_1,)  \
SGS__IF_DEF(SGS__TOSTR2) (sgs__tostr_type_2 : sgs__tostr_p_func_2,)  \
SGS__IF_DEF(SGS__TOSTR3) (sgs__tostr_type_3 : sgs__tostr_p_func_3,)  \
SGS__IF_DEF(SGS__TOSTR4) (sgs__tostr_type_4 : sgs__tostr_p_func_4,)  \
SGS__IF_DEF(SGS__TOSTR5) (sgs__tostr_type_5 : sgs__tostr_p_func_5,)  \
SGS__IF_DEF(SGS__TOSTR6) (sgs__tostr_type_6 : sgs__tostr_p_func_6,)  \
SGS__IF_DEF(SGS__TOSTR7) (sgs__tostr_type_7 : sgs__tostr_p_func_7,)  \
SGS__IF_DEF(SGS__TOSTR8) (sgs__tostr_type_8 : sgs__tostr_p_func_8,)  \
SGS__IF_DEF(SGS__TOSTR9) (sgs__tostr_type_9 : sgs__tostr_p_func_9,)  \
SGS__IF_DEF(SGS__TOSTR10)(sgs__tostr_type_10: sgs__tostr_p_func_10,) \
SGS__IF_DEF(SGS__TOSTR11)(sgs__tostr_type_11: sgs__tostr_p_func_11,) \
SGS__IF_DEF(SGS__TOSTR12)(sgs__tostr_type_12: sgs__tostr_p_func_12,) \
SGS__IF_DEF(SGS__TOSTR13)(sgs__tostr_type_13: sgs__tostr_p_func_13,) \
SGS__IF_DEF(SGS__TOSTR14)(sgs__tostr_type_14: sgs__tostr_p_func_14,) \
SGS__IF_DEF(SGS__TOSTR15)(sgs__tostr_type_15: sgs__tostr_p_func_15,) \
SGS__IF_DEF(SGS__TOSTR16)(sgs__tostr_type_16: sgs__tostr_p_func_16,) \
SGS__IF_DEF(SGS__TOSTR17)(sgs__tostr_type_17: sgs__tostr_p_func_17,) \
SGS__IF_DEF(SGS__TOSTR18)(sgs__tostr_type_18: sgs__tostr_p_func_18,) \
SGS__IF_DEF(SGS__TOSTR19)(sgs__tostr_type_19: sgs__tostr_p_func_19,) \
SGS__IF_DEF(SGS__TOSTR20)(sgs__tostr_type_20: sgs__tostr_p_func_20,) \
SGS__IF_DEF(SGS__TOSTR21)(sgs__tostr_type_21: sgs__tostr_p_func_21,) \
SGS__IF_DEF(SGS__TOSTR22)(sgs__tostr_type_22: sgs__tostr_p_func_22,) \
SGS__IF_DEF(SGS__TOSTR23)(sgs__tostr_type_23: sgs__tostr_p_func_23,) \
SGS__IF_DEF(SGS__TOSTR24)(sgs__tostr_type_24: sgs__tostr_p_func_24,) \
SGS__IF_DEF(SGS__TOSTR25)(sgs__tostr_type_25: sgs__tostr_p_func_25,) \
SGS__IF_DEF(SGS__TOSTR26)(sgs__tostr_type_26: sgs__tostr_p_func_26,) \
SGS__IF_DEF(SGS__TOSTR27)(sgs__tostr_type_27: sgs__tostr_p_func_27,) \
SGS__IF_DEF(SGS__TOSTR28)(sgs__tostr_type_28: sgs__tostr_p_func_28,) \
SGS__IF_DEF(SGS__TOSTR29)(sgs__tostr_type_29: sgs__tostr_p_func_29,) \
SGS__IF_DEF(SGS__TOSTR30)(sgs__tostr_type_30: sgs__tostr_p_func_30,) \
SGS__IF_DEF(SGS__TOSTR31)(sgs__tostr_type_31: sgs__tostr_p_func_31,) \
SGS__IF_DEF(SGS__TOSTR32)(sgs__tostr_type_32: sgs__tostr_p_func_32,) \
SGS__DEFAULT_TOSTR_P_GENERIC_BRANCHES

struct sgs__fail_type { int dummy; };
typedef void(*sgs__tostr_fail)(struct sgs__fail_type*);

#define sgs__get_tostr_func(ty) \
_Generic((ty){0}, \
    SGS__TOSTR_FUNCS_GENERIC_BRANCHES \
)

#define sgs__get_tostr_func_ft(ty) \
_Generic((ty){0}, \
    SGS__TOSTR_FUNCS_GENERIC_BRANCHES, \
    default: (sgs__tostr_fail){0} \
)

#define sgs__get_tostr_p_func(ty) \
_Generic((ty){0}, \
    SGS__TOSTR_P_FUNCS_GENERIC_BRANCHES \
)

#define sgs_tostr(dst, src) \
sgs__get_tostr_func(__typeof__(src))(sgs_mutstr_ref(dst), (src))

#define sgs_has_tostr(ty) \
(!sgs__has_type(sgs__get_tostr_func_ft(ty), sgs__tostr_fail))

#define sgs_tostr_p(dst, src) \
sgs__get_tostr_p_func(__typeof__(*(src)))(sgs_mutstr_ref(dst), (src))

#define SGS__DECL_TOSTR_FUNC(n) \
typedef __typeof__(SGS__MCALL(SGS__ARG1, ADD_TOSTR)) sgs__tostr_type_##n; \
static inline SGS_Error sgs__tostr_func_##n (SGS_MutStrRef dst, sgs__tostr_type_##n obj) \
{ \
    _Static_assert(sgs__has_type(SGS__MCALL(SGS__ARG2, ADD_TOSTR), __typeof__(SGS_Error(*)(SGS_MutStrRef, sgs__tostr_type_##n))), "tostr functions must have signature `SGS_Error(SGS_MutStrRef dst, T src)`"); \
    sgs__mutstr_ref_clear(dst); \
    return SGS__MCALL(SGS__ARG2, ADD_TOSTR) (dst, obj); \
} \
static inline SGS_Error sgs__tostr_p_func_##n (SGS_MutStrRef dst, const sgs__tostr_type_##n *obj) \
{ \
    return sgs__tostr_func_##n(dst, *obj); \
}

SGS_API SGS_StrView sgs__strv_cstr1(const char *str);
SGS_API SGS_StrView sgs__strv_ucstr1(const unsigned char *str);
SGS_API SGS_StrView sgs__strv_dstr1(const SGS_DStr str);
SGS_API SGS_StrView sgs__strv_dstr_ptr1(const SGS_DStr *str);
SGS_API SGS_StrView sgs__strv_strv1(const SGS_StrView str);
SGS_API SGS_StrView sgs__strv_strbuf1(const SGS_StrBuf str);
SGS_API SGS_StrView sgs__strv_strbuf_ptr1(const SGS_StrBuf *str);
SGS_API SGS_StrView sgs__strv_mutstr_ref1(const SGS_MutStrRef str);

SGS_API SGS_StrView sgs__strv_cstr2(const char *str, unsigned int begin);
SGS_API SGS_StrView sgs__strv_ucstr2(const unsigned char *str, unsigned int begin);
SGS_API SGS_StrView sgs__strv_dstr2(const SGS_DStr str, unsigned int begin);
SGS_API SGS_StrView sgs__strv_dstr_ptr2(const SGS_DStr *str, unsigned int begin);
SGS_API SGS_StrView sgs__strv_strv2(const SGS_StrView str, unsigned int begin);
SGS_API SGS_StrView sgs__strv_strbuf2(const SGS_StrBuf str, unsigned int begin);
SGS_API SGS_StrView sgs__strv_strbuf_ptr2(const SGS_StrBuf *str, unsigned int begin);
SGS_API SGS_StrView sgs__strv_mutstr_ref2(const SGS_MutStrRef str, unsigned int begin);

SGS_API SGS_StrView sgs__strv_cstr3(const char *str, unsigned int begin, unsigned int end);
SGS_API SGS_StrView sgs__strv_ucstr3(const unsigned char *str, unsigned int begin, unsigned int end);
SGS_API SGS_StrView sgs__strv_dstr3(const SGS_DStr str, unsigned int begin, unsigned int end);
SGS_API SGS_StrView sgs__strv_dstr_ptr3(const SGS_DStr *str, unsigned int begin, unsigned int end);
SGS_API SGS_StrView sgs__strv_strv3(const SGS_StrView str, unsigned int begin, unsigned int end);
SGS_API SGS_StrView sgs__strv_strbuf3(const SGS_StrBuf str, unsigned int begin, unsigned int end);
SGS_API SGS_StrView sgs__strv_strbuf_ptr3(const SGS_StrBuf *str, unsigned int begin, unsigned int end);
SGS_API SGS_StrView sgs__strv_mutstr_ref3(const SGS_MutStrRef str, unsigned int begin, unsigned int end);

SGS_API SGS_StrBuf sgs__strbuf_from_cstr(const char *ptr, unsigned int cap);
SGS_API SGS_StrBuf sgs__strbuf_from_buf(const SGS_Buffer buf);

SGS_API SGS_Buffer sgs__buf_from_cstr(const char *str);
SGS_API SGS_Buffer sgs__buf_from_ucstr(const unsigned char *str);
SGS_API SGS_Buffer sgs__buf_from_carr(const char *str, size_t cap);
SGS_API SGS_Buffer sgs__buf_from_ucarr(const unsigned char *str, size_t cap);

SGS_API SGS_MutStrRef sgs__cstr_as_mutstr_ref(const char *str);
SGS_API SGS_MutStrRef sgs__ucstr_as_mutstr_ref(const unsigned char *str);
SGS_API SGS_MutStrRef sgs__buf_as_mutstr_ref(const SGS_Buffer str);
SGS_API SGS_MutStrRef sgs__dstr_ptr_as_mutstr_ref(const SGS_DStr *str);
SGS_API SGS_MutStrRef sgs__strbuf_ptr_as_mutstr_ref(const SGS_StrBuf *str);
SGS_API SGS_MutStrRef sgs__mutstr_ref_as_mutstr_ref(const SGS_MutStrRef str);

SGS_API SGS__FixedMutStrRef sgs__buf_as_fmutstr_ref(SGS_Buffer buf, unsigned int *len_ptr);
SGS_API SGS__FixedMutStrRef sgs__strbuf_ptr_as_fmutstr_ref(SGS_StrBuf *strbuf);
SGS_API SGS__FixedMutStrRef sgs__dstr_ptr_as_fmutstr_ref(SGS_DStr *dstr);

SGS_API SGS_MutStrRef sgs__make_appender_mutstr_ref(SGS_MutStrRef owner, SGS_StrAppenderState *state);
SGS_API SGS_Error sgs__mutstr_ref_commit_appender(SGS_MutStrRef owner, SGS_MutStrRef appender);

SGS_API char *sgs__cstr_as_cstr(const char *str);
SGS_API char *sgs__ucstr_as_cstr(const unsigned char *str);
SGS_API char *sgs__dstr_as_cstr(const SGS_DStr str);
SGS_API char *sgs__dstr_ptr_as_cstr(const SGS_DStr *str);
SGS_API char *sgs__strv_as_cstr(const SGS_StrView str);
SGS_API char *sgs__strbuf_as_cstr(const SGS_StrBuf str);
SGS_API char *sgs__strbuf_ptr_as_cstr(const SGS_StrBuf *str);
SGS_API char *sgs__mutstr_ref_as_cstr(const SGS_MutStrRef str);

SGS_API unsigned int sgs__dstr_cap(const SGS_DStr str);
SGS_API unsigned int sgs__dstr_ptr_cap(const SGS_DStr *str);
SGS_API unsigned int sgs__strbuf_cap(const SGS_StrBuf str);
SGS_API unsigned int sgs__strbuf_ptr_cap(const SGS_StrBuf *str);
SGS_API unsigned int sgs__buf_cap(const SGS_Buffer buf);
SGS_API unsigned int sgs__mutstr_ref_cap(const SGS_MutStrRef str);
SGS_API unsigned int sgs__mutstr_ref_len(const SGS_MutStrRef str);

SGS_API unsigned char sgs__cstr_char_at(const char *str, unsigned int idx);
SGS_API unsigned char sgs__ucstr_char_at(const unsigned char *str, unsigned int idx);
SGS_API unsigned char sgs__dstr_char_at(const SGS_DStr str, unsigned int idx);
SGS_API unsigned char sgs__dstr_ptr_char_at(const SGS_DStr *str, unsigned int idx);
SGS_API unsigned char sgs__strv_char_at(const SGS_StrView str, unsigned int idx);
SGS_API unsigned char sgs__strbuf_char_at(const SGS_StrBuf str, unsigned int idx);
SGS_API unsigned char sgs__strbuf_ptr_char_at(const SGS_StrBuf *str, unsigned int idx);
SGS_API unsigned char sgs__mutstr_ref_char_at(const SGS_MutStrRef str, unsigned int idx);

SGS_API bool sgs__is_strv_within(SGS_StrView base, SGS_StrView sub);

SGS__NODISCARD("discarding a new DString may cause a memory leak")
SGS_API SGS_DStr sgs__dstr_init(unsigned int cap, SGS_Allocator *allocator);
SGS__NODISCARD("discarding a new DString may cause a memory leak")
SGS_API SGS_DStr sgs__dstr_init_from(SGS_StrView from, SGS_Allocator *allocator);
SGS_API void sgs__dstr_deinit(SGS_DStr *dstr);
SGS_API SGS_Error sgs__dstr_append(SGS_DStr *dstr, const SGS_StrView str);
SGS_API SGS_Error sgs__dstr_prepend_strv(SGS_DStr *dstr, const SGS_StrView str);
SGS_API SGS_Error sgs__dstr_insert(SGS_DStr *dstr, const SGS_StrView str, unsigned int idx);
SGS_API SGS_Error sgs__dstr_fread_line(SGS_DStr *dstr, FILE *stream);
SGS_API SGS_Error sgs__dstr_append_fread_line(SGS_DStr *dstr, FILE *stream);
SGS_API SGS_Error sgs__dstr_shrink_to_fit(SGS_DStr *dstr);
SGS_API SGS_Error sgs__dstr_ensure_cap(SGS_DStr *dstr, unsigned int at_least);

SGS_API SGS_Error sgs__mutstr_ref_putc(SGS_MutStrRef dst, unsigned char c);
SGS_API SGS_Error sgs__mutstr_ref_copy(SGS_MutStrRef dst, const SGS_StrView src);
SGS_API SGS_Error sgs__mutstr_ref_append(SGS_MutStrRef dst, const SGS_StrView src);
SGS_API SGS_Error sgs__mutstr_ref_delete_range(SGS_MutStrRef str, unsigned int begin, unsigned int end);
SGS_API SGS_Error sgs__mutstr_ref_insert(SGS_MutStrRef dst, const SGS_StrView src, unsigned int idx);
SGS_API SGS_ReplaceResult sgs__mutstr_ref_replace(SGS_MutStrRef str, const SGS_StrView target, const SGS_StrView replacement);
SGS_API SGS_Error sgs__mutstr_ref_replace_first(SGS_MutStrRef str, const SGS_StrView target, const SGS_StrView replacement);
SGS_API SGS_Error sgs__mutstr_ref_replace_range(SGS_MutStrRef str, unsigned int begin, unsigned int end, const SGS_StrView replacement);
SGS_API SGS_Error sgs__mutstr_ref_clear(SGS_MutStrRef str);
SGS_API SGS_Error sgs__strv_arr_join(SGS_MutStrRef dst, SGS_StrViewArray strs, SGS_StrView delim);

SGS_API SGS_Error sgs__fmutstr_ref_putc(SGS__FixedMutStrRef dst, unsigned char c);
SGS_API SGS_Error sgs__fmutstr_ref_copy(SGS__FixedMutStrRef dst, const SGS_StrView src);
SGS_API SGS_Error sgs__fmutstr_ref_append(SGS__FixedMutStrRef dst, const SGS_StrView src);
SGS_API SGS_Error sgs__fmutstr_ref_delete_range(SGS__FixedMutStrRef str, unsigned int begin, unsigned int end);
SGS_API SGS_Error sgs__fmutstr_ref_insert(SGS__FixedMutStrRef dst, const SGS_StrView src, unsigned int idx);
SGS_API SGS_ReplaceResult sgs__fmutstr_ref_replace(SGS__FixedMutStrRef str, const SGS_StrView target, const SGS_StrView replacement);
SGS_API SGS_Error sgs__fmutstr_ref_replace_first(SGS__FixedMutStrRef str, const SGS_StrView target, const SGS_StrView replacement);
SGS_API SGS_Error sgs__fmutstr_ref_replace_range(SGS__FixedMutStrRef str, unsigned int begin, unsigned int end, const SGS_StrView replacement);
SGS_API SGS_Error sgs__fmutstr_ref_clear(SGS__FixedMutStrRef str);
SGS_API SGS_Error sgs__strv_arr_join_into_fmutstr_ref(SGS__FixedMutStrRef dst, const SGS_StrViewArray strs, const SGS_StrView delim);

SGS_API SGS_Error sgs__dstr_putc(SGS_DStr *dst, unsigned char c);
SGS_API SGS_Error sgs__dstr_copy(SGS_DStr *dstr, const SGS_StrView src);
SGS_API SGS_ReplaceResult sgs__dstr_replace(SGS_DStr *dstr, const SGS_StrView target, const SGS_StrView replacement);
SGS_API SGS_Error sgs__dstr_replace_first(SGS_DStr *dstr, const SGS_StrView target, const SGS_StrView replacement);
SGS_API SGS_Error sgs__dstr_replace_range(SGS_DStr *dstr, unsigned int begin, unsigned int end, const SGS_StrView replacement);
SGS_API SGS_Error sgs__strv_arr_join_into_dstr(SGS_DStr *dstr, const SGS_StrViewArray strs, const SGS_StrView delim);

SGS__NODISCARD("str_split returns a heap allocated array")
SGS_API SGS_StrViewArray sgs__strv_split(const SGS_StrView str, const SGS_StrView delim, SGS_Allocator* allocator);
SGS_API SGS_Error sgs__strv_split_iter(const SGS_StrView str, const SGS_StrView delim, bool(*cb)(SGS_StrView found, void *ctx), void *ctx);

SGS_API SGS_StrViewArray sgs__strv_arr_from_carr(const SGS_StrView *carr, unsigned int nb);

SGS_API bool sgs__strv_equal(const SGS_StrView str1, const SGS_StrView str2);
SGS_API SGS_StrView sgs__strv_find(const SGS_StrView hay, const SGS_StrView needle);
SGS_API unsigned int sgs__strv_count(const SGS_StrView hay, const SGS_StrView needle);
SGS_API bool sgs__strv_starts_with(const SGS_StrView hay, const SGS_StrView needle);
SGS_API bool sgs__strv_ends_with(const SGS_StrView hay, const SGS_StrView needle);

SGS_API void sgs__chars_tolower(SGS_StrView str);
SGS_API void sgs__chars_toupper(SGS_StrView str);

SGS_API SGS_Error sgs__mutstr_ref_fread_line(SGS_MutStrRef dst, FILE *stream);
SGS_API SGS_Error sgs__mutstr_ref_append_fread_line(SGS_MutStrRef dst, FILE *stream);

SGS_API SGS_Error sgs__fmutstr_ref_fread_line(SGS__FixedMutStrRef dst, FILE *stream);
SGS_API SGS_Error sgs__fmutstr_ref_append_fread_line(SGS__FixedMutStrRef dst, FILE *stream);

SGS_API unsigned int sgs__fprint_strv(FILE *stream, const SGS_StrView str);
SGS_API unsigned int sgs__fprintln_strv(FILE *stream, const SGS_StrView str);

SGS_API SGS_Error sgs__bool_tostr(SGS_MutStrRef dst, bool obj);
SGS_API SGS_Error sgs__cstr_tostr(SGS_MutStrRef dst, const char *obj);
SGS_API SGS_Error sgs__ucstr_tostr(SGS_MutStrRef dst, const unsigned char *obj);
SGS_API SGS_Error sgs__char_tostr(SGS_MutStrRef dst, char obj);
SGS_API SGS_Error sgs__schar_tostr(SGS_MutStrRef dst, signed char obj);
SGS_API SGS_Error sgs__uchar_tostr(SGS_MutStrRef dst, unsigned char obj);
SGS_API SGS_Error sgs__short_tostr(SGS_MutStrRef dst, short obj);
SGS_API SGS_Error sgs__ushort_tostr(SGS_MutStrRef dst, unsigned short obj);
SGS_API SGS_Error sgs__int_tostr(SGS_MutStrRef dst, int obj);
SGS_API SGS_Error sgs__uint_tostr(SGS_MutStrRef dst, unsigned int obj);
SGS_API SGS_Error sgs__long_tostr(SGS_MutStrRef dst, long obj);
SGS_API SGS_Error sgs__ulong_tostr(SGS_MutStrRef dst, unsigned long obj);
SGS_API SGS_Error sgs__llong_tostr(SGS_MutStrRef dst, long long obj);
SGS_API SGS_Error sgs__ullong_tostr(SGS_MutStrRef dst, unsigned long long obj);
SGS_API SGS_Error sgs__float_tostr(SGS_MutStrRef dst, float obj);
SGS_API SGS_Error sgs__double_tostr(SGS_MutStrRef dst, double obj);

SGS_API SGS_Error sgs__dstr_tostr(SGS_MutStrRef dst, const SGS_DStr obj);
SGS_API SGS_Error sgs__dstr_ptr_tostr(SGS_MutStrRef dst, const SGS_DStr *obj);
SGS_API SGS_Error sgs__strv_tostr(SGS_MutStrRef dst, const SGS_StrView obj);
SGS_API SGS_Error sgs__strbuf_tostr(SGS_MutStrRef dst, const SGS_StrBuf obj);
SGS_API SGS_Error sgs__strbuf_ptr_tostr(SGS_MutStrRef dst, const SGS_StrBuf *obj);
SGS_API SGS_Error sgs__mutstr_ref_tostr(SGS_MutStrRef dst, const SGS_MutStrRef obj);

SGS_API SGS_Error sgs__error_tostr(SGS_MutStrRef dst, SGS_Error obj);
SGS_API SGS_Error sgs__array_fmt_tostr(SGS_MutStrRef dst, SGS_ArrayFmt obj);

SGS_API SGS_Error sgs__bool_tostr_p(SGS_MutStrRef dst, bool *obj);
SGS_API SGS_Error sgs__cstr_tostr_p(SGS_MutStrRef dst, const char **obj);
SGS_API SGS_Error sgs__ucstr_tostr_p(SGS_MutStrRef dst, const unsigned char **obj);
SGS_API SGS_Error sgs__char_tostr_p(SGS_MutStrRef dst, char *obj);
SGS_API SGS_Error sgs__schar_tostr_p(SGS_MutStrRef dst, signed char *obj);
SGS_API SGS_Error sgs__uchar_tostr_p(SGS_MutStrRef dst, unsigned char *obj);
SGS_API SGS_Error sgs__short_tostr_p(SGS_MutStrRef dst, short *obj);
SGS_API SGS_Error sgs__ushort_tostr_p(SGS_MutStrRef dst, unsigned short *obj);
SGS_API SGS_Error sgs__int_tostr_p(SGS_MutStrRef dst, int *obj);
SGS_API SGS_Error sgs__uint_tostr_p(SGS_MutStrRef dst, unsigned int *obj);
SGS_API SGS_Error sgs__long_tostr_p(SGS_MutStrRef dst, long *obj);
SGS_API SGS_Error sgs__ulong_tostr_p(SGS_MutStrRef dst, unsigned long *obj);
SGS_API SGS_Error sgs__llong_tostr_p(SGS_MutStrRef dst, long long *obj);
SGS_API SGS_Error sgs__ullong_tostr_p(SGS_MutStrRef dst, unsigned long long *obj);
SGS_API SGS_Error sgs__float_tostr_p(SGS_MutStrRef dst, float *obj);
SGS_API SGS_Error sgs__double_tostr_p(SGS_MutStrRef dst, double *obj);

SGS_API SGS_Error sgs__dstr_tostr_p(SGS_MutStrRef dst, const SGS_DStr *obj);
SGS_API SGS_Error sgs__dstr_ptr_tostr_p(SGS_MutStrRef dst, const SGS_DStr **obj);
SGS_API SGS_Error sgs__strv_tostr_p(SGS_MutStrRef dst, const SGS_StrView *obj);
SGS_API SGS_Error sgs__strbuf_tostr_p(SGS_MutStrRef dst, const SGS_StrBuf *obj);
SGS_API SGS_Error sgs__strbuf_ptr_tostr_p(SGS_MutStrRef dst, const SGS_StrBuf **obj);
SGS_API SGS_Error sgs__mutstr_ref_tostr_p(SGS_MutStrRef dst, const SGS_MutStrRef *obj);

SGS_API SGS_Error sgs__error_tostr_p(SGS_MutStrRef dst, SGS_Error *obj);
SGS_API SGS_Error sgs__array_fmt_tostr_p(SGS_MutStrRef dst, SGS_ArrayFmt *obj);

#define SGS__X(ty, extra) \
SGS_API SGS_Error sgs__Integer_d_Fmt_##ty##_tostr(SGS_MutStrRef dst, SGS__Integer_d_Fmt_##ty obj);    \
SGS_API SGS_Error sgs__Integer_x_Fmt_##ty##_tostr(SGS_MutStrRef dst, SGS__Integer_x_Fmt_##ty obj);    \
SGS_API SGS_Error sgs__Integer_o_Fmt_##ty##_tostr(SGS_MutStrRef dst, SGS__Integer_o_Fmt_##ty obj);    \
SGS_API SGS_Error sgs__Integer_b_Fmt_##ty##_tostr(SGS_MutStrRef dst, SGS__Integer_b_Fmt_##ty obj);    \
SGS_API SGS_Error sgs__Integer_X_Fmt_##ty##_tostr(SGS_MutStrRef dst, SGS__Integer_X_Fmt_##ty obj);    \
                                                                                                      \
                                                                                                      \
SGS_API SGS_Error sgs__Integer_d_Fmt_##ty##_tostr_p(SGS_MutStrRef dst, SGS__Integer_d_Fmt_##ty *obj); \
SGS_API SGS_Error sgs__Integer_x_Fmt_##ty##_tostr_p(SGS_MutStrRef dst, SGS__Integer_x_Fmt_##ty *obj); \
SGS_API SGS_Error sgs__Integer_o_Fmt_##ty##_tostr_p(SGS_MutStrRef dst, SGS__Integer_o_Fmt_##ty *obj); \
SGS_API SGS_Error sgs__Integer_b_Fmt_##ty##_tostr_p(SGS_MutStrRef dst, SGS__Integer_b_Fmt_##ty *obj); \
SGS_API SGS_Error sgs__Integer_X_Fmt_##ty##_tostr_p(SGS_MutStrRef dst, SGS__Integer_X_Fmt_##ty *obj);

SGS__INTEGER_TYPES(SGS__X, ignore)

#undef SGS__X

#define SGS__X(ty, extra) \
SGS_API SGS_Error sgs__Floating_f_Fmt_##ty##_tostr(SGS_MutStrRef dst, SGS__Floating_f_Fmt_##ty obj);    \
SGS_API SGS_Error sgs__Floating_g_Fmt_##ty##_tostr(SGS_MutStrRef dst, SGS__Floating_g_Fmt_##ty obj);    \
SGS_API SGS_Error sgs__Floating_e_Fmt_##ty##_tostr(SGS_MutStrRef dst, SGS__Floating_e_Fmt_##ty obj);    \
SGS_API SGS_Error sgs__Floating_a_Fmt_##ty##_tostr(SGS_MutStrRef dst, SGS__Floating_a_Fmt_##ty obj);    \
SGS_API SGS_Error sgs__Floating_F_Fmt_##ty##_tostr(SGS_MutStrRef dst, SGS__Floating_F_Fmt_##ty obj);    \
SGS_API SGS_Error sgs__Floating_G_Fmt_##ty##_tostr(SGS_MutStrRef dst, SGS__Floating_G_Fmt_##ty obj);    \
SGS_API SGS_Error sgs__Floating_E_Fmt_##ty##_tostr(SGS_MutStrRef dst, SGS__Floating_E_Fmt_##ty obj);    \
SGS_API SGS_Error sgs__Floating_A_Fmt_##ty##_tostr(SGS_MutStrRef dst, SGS__Floating_A_Fmt_##ty obj);    \
                                                                                                        \
SGS_API SGS_Error sgs__Floating_f_Fmt_##ty##_tostr_p(SGS_MutStrRef dst, SGS__Floating_f_Fmt_##ty *obj); \
SGS_API SGS_Error sgs__Floating_g_Fmt_##ty##_tostr_p(SGS_MutStrRef dst, SGS__Floating_g_Fmt_##ty *obj); \
SGS_API SGS_Error sgs__Floating_e_Fmt_##ty##_tostr_p(SGS_MutStrRef dst, SGS__Floating_e_Fmt_##ty *obj); \
SGS_API SGS_Error sgs__Floating_a_Fmt_##ty##_tostr_p(SGS_MutStrRef dst, SGS__Floating_a_Fmt_##ty *obj); \
SGS_API SGS_Error sgs__Floating_F_Fmt_##ty##_tostr_p(SGS_MutStrRef dst, SGS__Floating_F_Fmt_##ty *obj); \
SGS_API SGS_Error sgs__Floating_G_Fmt_##ty##_tostr_p(SGS_MutStrRef dst, SGS__Floating_G_Fmt_##ty *obj); \
SGS_API SGS_Error sgs__Floating_E_Fmt_##ty##_tostr_p(SGS_MutStrRef dst, SGS__Floating_E_Fmt_##ty *obj); \
SGS_API SGS_Error sgs__Floating_A_Fmt_##ty##_tostr_p(SGS_MutStrRef dst, SGS__Floating_A_Fmt_##ty *obj);

SGS__FLOATING_TYPES(SGS__X, ignore, SGS__X)

#undef SGS__X

#endif /* SGS__H_INCLUDED */

#ifdef SGS_SHORT_NAMES

#define Allocator             SGS_Allocator
#define DStr                  SGS_DStr
#define StrBuf                SGS_StrBuf
#define StrView               SGS_StrView
#define StrViewArray          SGS_StrViewArray
#define MutStrRef             SGS_MutStrRef
#define ReplaceResult         SGS_ReplaceResult
#define StrAppenderState      SGS_StrAppenderState
#define ArrayFmt              SGS_ArrayFmt

#define strv(anystr, ...) sgs_strv(anystr __VA_OPT__(,) __VA_ARGS__)
#define strv_arr(...) sgs_strv_arr(__VA_ARGS__)
#define strv_arr_from_carr(arr, ...) sgs_strv_arr_from_carr(arr __VA_OPT__(,) __VA_ARGS__)

#define strbuf_init_from_cstr(cstr, ...) sgs_strbuf_init_from_cstr(cstr __VA_OPT__(,) __VA_ARGS__)
#define strbuf_init_from_buf(buf, ...) sgs_strbuf_init_from_buf(buf __VA_OPT__(,) __VA_ARGS__)

#define dstr_init(...) sgs_dstr_init(__VA_ARGS__)
#define dstr_init_from(anystr, ...) sgs_dstr_init_from(anystr __VA_OPT__(,) __VA_ARGS__)
#define dstr_deinit(dstr) sgs_dstr_deinit(dstr)
#define dstr_ensure_cap(dstr, new_cap) sgs_dstr_ensure_cap(dstr, new_cap)
#define dstr_shrink_to_fit(dstr) sgs_dstr_shrink_to_fit(dstr)

#define mutstr_ref(mutstr, ...) sgs_mutstr_ref(mutstr __VA_OPT__(,) __VA_ARGS__)

#define tostr(dst, src) sgs_tostr(dst, src)
#define tostr_p(dst, srcp) sgs_tostr_p(dst, srcp)
#define has_tostr(T) sgs_has_tostr(T)

#define print(...) sgs_print(__VA_ARGS__)
#define println(...) sgs_println(__VA_ARGS__)
#define fprint(stream, ...) sgs_fprint(stream, __VA_ARGS__)
#define fprintln(stream, ...) sgs_fprintln(stream, __VA_ARGS__)

#define tsfmt(exp, fmt_char, ...) sgs_tsfmt(exp, fmt_char __VA_OPT__(,) __VA_ARGS__)
#define tsfmt_t(T, fmt_char, ...) sgs_tsfmt_t(T, fmt_char __VA_OPT__(,) __VA_ARGS__)
#define arrfmt(arr, n, ...) sgs_arrfmt(arr, n, __VA_ARGS__)

#endif // SGS_SHORT_NAMES

#if defined(ADD_TOSTR)

_Static_assert( sgs__has_type(sgs__get_tostr_func_ft(SGS__ARG1 ADD_TOSTR), sgs__tostr_fail), "Type already has a tostr" );

#if !defined(SGS__TOSTR1)
#define SGS__TOSTR1
SGS__DECL_TOSTR_FUNC(1)
#elif !defined(SGS__TOSTR2)
#define SGS__TOSTR2
SGS__DECL_TOSTR_FUNC(2)
#elif !defined(SGS__TOSTR3)
#define SGS__TOSTR3
SGS__DECL_TOSTR_FUNC(3)
#elif !defined(SGS__TOSTR4)
#define SGS__TOSTR4
SGS__DECL_TOSTR_FUNC(4)
#elif !defined(SGS__TOSTR5)
#define SGS__TOSTR5
SGS__DECL_TOSTR_FUNC(5)
#elif !defined(SGS__TOSTR6)
#define SGS__TOSTR6
SGS__DECL_TOSTR_FUNC(6)
#elif !defined(SGS__TOSTR7)
#define SGS__TOSTR7
SGS__DECL_TOSTR_FUNC(7)
#elif !defined(SGS__TOSTR8)
#define SGS__TOSTR8
SGS__DECL_TOSTR_FUNC(8)
#elif !defined(SGS__TOSTR9)
#define SGS__TOSTR9
SGS__DECL_TOSTR_FUNC(9)
#elif !defined(SGS__TOSTR10)
#define SGS__TOSTR10
SGS__DECL_TOSTR_FUNC(10)
#elif !defined(SGS__TOSTR11)
#define SGS__TOSTR11
SGS__DECL_TOSTR_FUNC(11)
#elif !defined(SGS__TOSTR12)
#define SGS__TOSTR12
SGS__DECL_TOSTR_FUNC(12)
#elif !defined(SGS__TOSTR13)
#define SGS__TOSTR13
SGS__DECL_TOSTR_FUNC(13)
#elif !defined(SGS__TOSTR14)
#define SGS__TOSTR14
SGS__DECL_TOSTR_FUNC(14)
#elif !defined(SGS__TOSTR15)
#define SGS__TOSTR15
SGS__DECL_TOSTR_FUNC(15)
#elif !defined(SGS__TOSTR16)
#define SGS__TOSTR16
SGS__DECL_TOSTR_FUNC(16)
#elif !defined(SGS__TOSTR17)
#define SGS__TOSTR17
SGS__DECL_TOSTR_FUNC(17)
#elif !defined(SGS__TOSTR18)
#define SGS__TOSTR18
SGS__DECL_TOSTR_FUNC(18)
#elif !defined(SGS__TOSTR19)
#define SGS__TOSTR19
SGS__DECL_TOSTR_FUNC(19)
#elif !defined(SGS__TOSTR20)
#define SGS__TOSTR20
SGS__DECL_TOSTR_FUNC(20)
#elif !defined(SGS__TOSTR21)
#define SGS__TOSTR21
SGS__DECL_TOSTR_FUNC(21)
#elif !defined(SGS__TOSTR22)
#define SGS__TOSTR22
SGS__DECL_TOSTR_FUNC(22)
#elif !defined(SGS__TOSTR23)
#define SGS__TOSTR23
SGS__DECL_TOSTR_FUNC(23)
#elif !defined(SGS__TOSTR24)
#define SGS__TOSTR24
SGS__DECL_TOSTR_FUNC(24)
#elif !defined(SGS__TOSTR25)
#define SGS__TOSTR25
SGS__DECL_TOSTR_FUNC(25)
#elif !defined(SGS__TOSTR26)
#define SGS__TOSTR26
SGS__DECL_TOSTR_FUNC(26)
#elif !defined(SGS__TOSTR27)
#define SGS__TOSTR27
SGS__DECL_TOSTR_FUNC(27)
#elif !defined(SGS__TOSTR28)
#define SGS__TOSTR28
SGS__DECL_TOSTR_FUNC(28)
#elif !defined(SGS__TOSTR29)
#define SGS__TOSTR29
SGS__DECL_TOSTR_FUNC(29)
#elif !defined(SGS__TOSTR30)
#define SGS__TOSTR30
SGS__DECL_TOSTR_FUNC(30)
#elif !defined(SGS__TOSTR31)
#define SGS__TOSTR31
SGS__DECL_TOSTR_FUNC(31)
#elif !defined(SGS__TOSTR32)
#define SGS__TOSTR32
SGS__DECL_TOSTR_FUNC(32)
#else
#error "Maximum number of tostr functions is 32"
#endif

#undef ADD_TOSTR

#endif
