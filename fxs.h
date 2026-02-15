#ifndef FXS__STR_H_INCLUDED
#define FXS__STR_H_INCLUDED

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

struct FXS_Allocator;

typedef struct FXS_Allocation
{
    void *ptr;
    size_t n;
} FXS_Allocation;

typedef FXS_Allocation(*fxs_alloc_func)  (struct FXS_Allocator*, size_t alignment, size_t n);
typedef void           (*fxs_dealloc_func)(struct FXS_Allocator*, void *ptr, size_t n);
typedef FXS_Allocation(*fxs_realloc_func)(struct FXS_Allocator*, void *ptr, size_t alignment, size_t old_size, size_t new_size);

typedef struct FXS_Allocator
{
    fxs_alloc_func alloc;
    fxs_dealloc_func dealloc;
    fxs_realloc_func realloc;
} FXS_Allocator;

#if !defined(FXS_API)
    #define FXS_API
#endif

FXS_API FXS_Allocation fxs__allocator_invoke_alloc(FXS_Allocator *allocator, size_t alignment, size_t obj_size, size_t nb);
FXS_API void fxs__allocator_invoke_dealloc(FXS_Allocator *allocator, void *ptr, size_t obj_size, size_t nb);
FXS_API FXS_Allocation fxs__allocator_invoke_realloc(FXS_Allocator *allocator, void *ptr, size_t alignment, size_t obj_size, size_t old_nb, size_t new_nb);

FXS_API FXS_Allocator *fxs_get_default_allocator();

#define fxs_alloc(allocator, T, n) \
fxs__allocator_invoke_alloc(allocator, _Alignof(T), sizeof(T), (n))

#define fxs_dealloc(allocator, ptr, T, n) \
fxs__allocator_invoke_dealloc((allocator), (ptr), sizeof(T), (n))

#define fxs_realloc(allocator, ptr, T, old_n, new_n) \
fxs__allocator_invoke_realloc((allocator), (ptr), _Alignof(T), sizeof(T), (old_n), (new_n))

#define fxs_alloc_bytes(allocator, n) \
fxs__allocator_invoke_alloc((allocator), _Alignof(max_align_t), 1, (n))

#define fxs_dealloc_bytes(allocator, ptr, n) \
fxs__allocator_invoke_dealloc((allocator), (ptr), 1, (n))

#define fxs_realloc_bytes(allocator, ptr, old_n, new_n, actual) \
fxs__allocator_invoke_realloc((allocator), (ptr), _Alignof(max_align_t), 1, (old_n), (new_n))

#if __STDC_VERSION__ >= 202311L

    #define FXS__NODISCARD(...) [[nodiscard (__VA_ARGS__)]]

#elif defined(__GNUC__)

    #define FXS__NODISCARD(...) __attribute__((warn_unused_result))

#else

    #define FXS__NODISCARD(...)

#endif


#define fxs__static_assertx(exp, msg) \
((void)sizeof(struct { _Static_assert(exp, msg); int : 8; }))

#define fxs__has_type(exp, t) \
_Generic(exp, t: true, default: false)

#define fxs__is_array_of(exp, ty) \
fxs__has_type((__typeof__(exp)*){0}, __typeof__(ty)(*)[sizeof(exp)/sizeof(ty)])

#define FXS__CAT(a, ...) FXS__PRIMITIVE_CAT(a, __VA_ARGS__)
#define FXS__PRIMITIVE_CAT(a, ...) a ## __VA_ARGS__

#define fxs__coerce(exp, t) \
fxs__coerce_fallback(exp, t, (t){0})

#define fxs__coerce_fallback(exp, ty, fallback) \
_Generic(exp, \
    ty: (exp), \
    default: (fallback) \
)

#define fxs__coerce_string_type(exp, fallback) \
_Generic(exp,                                  \
    char*                     : exp,           \
    unsigned char*            : exp,           \
    FXS_DStr               : exp,           \
    FXS_DStr*              : exp,           \
    FXS_StrView           : exp,           \
    FXS_StrBuf         : exp,           \
    FXS_StrBuf*        : exp,           \
    FXS_MutStrRef        : exp,           \
    const char*               : exp,           \
    const unsigned char*      : exp,           \
    const FXS_DStr*        : exp,           \
    const FXS_StrBuf*  : exp,           \
    default                   : fallback       \
)

#define fxs__coerce_not(exp, not_ty, fallback_ty) \
_Generic(exp, \
    not_ty: (fallback_ty){0}, \
    default: exp \
)

#define FXS__CARR_LEN(carr) (sizeof(carr) / sizeof(carr[0]))

// IF_DEF and ARG_n stuff
#define FXS__COMMA()              ,
#define FXS__ARG1_( _1, ... )     _1
#define FXS__ARG1( ... )          FXS__ARG1_( __VA_ARGS__ )
#define FXS__ARG2_( _1, _2, ... ) _2
#define FXS__ARG2( ... )          FXS__ARG2_( __VA_ARGS__ )
#define FXS__INCL( ... )          __VA_ARGS__
#define FXS__OMIT( ... )
#define FXS__OMIT1(a, ...)        __VA_ARGS__
#define FXS__IF_DEF( macro )      FXS__ARG2( FXS__COMMA macro () FXS__INCL, FXS__OMIT, )
// IF_DEF and ARG_n stuff end

// FOREACH stuff
#define FXS__PARENS ()

#define FXS__EXPAND(...)  FXS__EXPAND4(FXS__EXPAND4(FXS__EXPAND4(FXS__EXPAND4(__VA_ARGS__))))
#define FXS__EXPAND4(...) FXS__EXPAND3(FXS__EXPAND3(FXS__EXPAND3(FXS__EXPAND3(__VA_ARGS__))))
#define FXS__EXPAND3(...) FXS__EXPAND2(FXS__EXPAND2(FXS__EXPAND2(FXS__EXPAND2(__VA_ARGS__))))
#define FXS__EXPAND2(...) FXS__EXPAND1(FXS__EXPAND1(FXS__EXPAND1(FXS__EXPAND1(__VA_ARGS__))))
#define FXS__EXPAND1(...) __VA_ARGS__

#define FXS__FOREACH(macro, ...)                                    \
__VA_OPT__(FXS__EXPAND(FXS__FOREACH_HELPER(macro, __VA_ARGS__)))
#define FXS__FOREACH_HELPER(macro, a1, ...)                         \
macro(a1)                                                     \
__VA_OPT__(FXS__FOREACH_REPEAT FXS__PARENS (macro, __VA_ARGS__))
#define FXS__FOREACH_REPEAT() FXS__FOREACH_HELPER
// FOREACH stuff end

#define FXS__VA_OR(otherwise, ...) \
__VA_ARGS__ FXS__IF_EMPTY(otherwise, __VA_ARGS__)

#define FXS__IF_EMPTY(then, ...) \
FXS__CAT(FXS__IF_EMPTY_, __VA_OPT__(0))(then)

#define FXS__IF_EMPTY_(then) then
#define FXS__IF_EMPTY_0(then)

#define FXS__IF_NEMPTY(then, ...) __VA_OPT__(then)

#define FXS__TYPEOF_ARG(arg) \
,__typeof__(arg)

#define FXS__TYPEOF_ARGS(...) \
__VA_OPT__( \
FXS__ARG1(__VA_ARGS__) FXS__FOREACH(FXS__TYPEOF_ARG, __VA_ARGS__) \
)

// Dynamic String
typedef struct FXS_DStr
{
    FXS_Allocator *allocator;
    unsigned int cap;
    unsigned int len;
    unsigned char *chars;
} FXS_DStr;

// Used as a general purpose non-dynamic string buffer
typedef struct FXS_StrBuf
{
    unsigned int cap;
    unsigned int len;
    unsigned char *chars;
} FXS_StrBuf;

// Used to view strings
typedef struct FXS_StrView
{
    unsigned int len;
    unsigned char *chars;
} FXS_StrView;

// An array of the above, returned by fxs_split
typedef struct FXS_StrViewArray
{
    unsigned int cap;
    unsigned int len;
    FXS_StrView *strs;
} FXS_StrViewArray;

// Used for passing `char[]` or `unsigned char[]`, such that it doesn't lose cap information
typedef struct FXS_Buffer
{
    unsigned char *ptr;
    unsigned int cap;
} FXS_Buffer;

enum FXS__MutStrType
{
    FXS__DSTR_TY = 1,
    FXS__STRBUF_TY,
    FXS__BUF_TY
};

// This is a tagged union for all mutable string types (i.e. all except String_View)
typedef struct FXS_MutStrRef
{
    union
    {
        FXS_DStr *dstr;
        FXS_StrBuf *strbuf;
        FXS_Buffer buf;
    } str;
    
    uint8_t ty; // enum FXS__MutStrType
} FXS_MutStrRef;

enum FXS__Error_Value
{
    FXS_OK = 0,
    FXS_DST_TOO_SMALL,
    FXS_ALLOC_ERR,
    FXS_INDEX_OUT_OF_BOUNDS,
    FXS_BAD_RANGE,
    FXS_NOT_FOUND,
    FXS_ALIASING_NOT_SUPPORTED,
    FXS_INCORRECT_TYPE,
    FXS_ENCODING_ERROR,
    FXS_CALLBACK_EXIT
};

typedef struct FXS_Error
{
    uint8_t ec;
} FXS_Error;

typedef struct FXS__FixedMutStrRef
{
    unsigned char *chars;
    unsigned int *len;
    unsigned int cap;
} FXS__FixedMutStrRef;

typedef struct FXS_ArrayFmt
{
    const void * const array;
    const size_t nb;
    const size_t elm_size;
    
    FXS_Error(* const elm_tostr)(FXS_MutStrRef dst, const void *obj);
    
    const FXS_StrView open;
    const FXS_StrView close;
    const FXS_StrView separator;
    const FXS_StrView trailing_separator;
} FXS_ArrayFmt;

typedef struct FXS__DStrAppendAllocator
{
    FXS_Allocator base;
    struct FXS_DStr *owner;
} FXS__DStrAppendAllocator;

typedef struct FXS_StrAppenderState
{
    FXS_DStr appender_dstr;
    FXS__DStrAppendAllocator dstr_append_allocator;
    FXS_StrBuf appender_buf;
} FXS_StrAppenderState;

typedef struct FXS_ReplaceResult
{
    unsigned int nb_replaced;
    FXS_Error err;
} FXS_ReplaceResult;

#define fxs__fmutstr_ref(s, ...) \
_Generic(&(__typeof__(s)){0}, \
    FXS_DStr**                          : fxs__dstr_ptr_as_fmutstr_ref(fxs__coerce(s, FXS_DStr*)), \
    FXS_Buffer*                            : fxs__buf_as_fmutstr_ref(fxs__coerce(s, FXS_Buffer), FXS__VA_OR(&(unsigned int){0}, __VA_ARGS__)), \
    FXS_StrBuf**                    : fxs__strbuf_ptr_as_fmutstr_ref(fxs__coerce(s, FXS_StrBuf*)), \
    char**                                  : fxs__buf_as_fmutstr_ref(fxs__buf_from_cstr(fxs__coerce(s, char*)), FXS__VA_OR(&(unsigned int){0}, __VA_ARGS__)), \
    unsigned char**                         : fxs__buf_as_fmutstr_ref(fxs__buf_from_ucstr(fxs__coerce(s, unsigned char*)), FXS__VA_OR(&(unsigned int){0}, __VA_ARGS__)), \
    char(*)[sizeof(__typeof__(s))]          : fxs__buf_as_fmutstr_ref(fxs__buf_from_carr(fxs__coerce(s, char*), sizeof(__typeof__(s))), FXS__VA_OR(&(unsigned int){0}, __VA_ARGS__)), \
    unsigned char(*)[sizeof(__typeof__(s))] : fxs__buf_as_fmutstr_ref(fxs__buf_from_ucarr(fxs__coerce(s, unsigned char*), sizeof(__typeof__(s))), FXS__VA_OR(&(unsigned int){0}, __VA_ARGS__)) \
)

#define fxs_at(anystr, idx)                         \
_Generic(anystr,                                        \
    char*                     : fxs__cstr_char_at,      \
    unsigned char*            : fxs__ucstr_char_at,     \
    FXS_DStr              : fxs__dstr_char_at,       \
    FXS_DStr*             : fxs__dstr_ptr_char_at,   \
    FXS_StrView          : fxs__strv_char_at,       \
    FXS_StrBuf        : fxs__strbuf_char_at,     \
    FXS_StrBuf*       : fxs__strbuf_ptr_char_at, \
    FXS_MutStrRef       : fxs__mutstr_ref_char_at, \
    const char*               : fxs__cstr_char_at,      \
    const unsigned char*      : fxs__ucstr_char_at,     \
    const FXS_DStr*       : fxs__dstr_ptr_char_at,   \
    const FXS_StrBuf* : fxs__strbuf_ptr_char_at  \
)((anystr), idx)

#define fxs_len(anystr) \
_Generic(anystr, \
    char*                     : strlen(fxs__coerce_fallback(anystr, char*, "")), \
    unsigned char*            : strlen((char*) fxs__coerce_fallback(anystr, unsigned char*, "")), \
    FXS_DStr              : ((void)0, fxs__coerce(anystr, FXS_DStr).len), \
    FXS_DStr*             : ((void)0, fxs__coerce(anystr, FXS_DStr*)->len), \
    FXS_StrView          : ((void)0, fxs__coerce(anystr, FXS_StrView).len), \
    FXS_StrBuf        : ((void)0, fxs__coerce(anystr, FXS_StrBuf).len), \
    FXS_StrBuf*       : ((void)0, fxs__coerce(anystr, FXS_StrBuf*)->len), \
    FXS_MutStrRef       : ((void)0, fxs__mutstr_ref_len(fxs__coerce(anystr, FXS_MutStrRef))), \
    const char*               : strlen(fxs__coerce_fallback(anystr, const char*, "")), \
    const unsigned char*      : strlen((char*) fxs__coerce_fallback(anystr, const unsigned char*, "")), \
    const FXS_DStr*       : ((void)0, fxs__coerce(anystr, const FXS_DStr*)->len), \
    const FXS_StrBuf* : ((void)0, fxs__coerce(anystr, const FXS_StrBuf*)->len) \
)

static inline unsigned int fxs__return_32(unsigned int a)
{
    return a;
}

static inline unsigned int fxs__strlen_plus_one(const char *s)
{
    return strlen(s) + 1;
}

static inline unsigned int fxs__ustrlen_plus_one(const unsigned char *s)
{
    return strlen((const char*) s) + 1;
}

static inline unsigned int fxs__strv_len(const FXS_StrView sv)
{
    return sv.len;
}

#define fxs_cap(anystr)                                                   \
_Generic((__typeof__(anystr)*){0},                                            \
    char(*)[sizeof(__typeof__(anystr))]          : fxs__return_32,            \
    unsigned char(*)[sizeof(__typeof__(anystr))] : fxs__return_32,            \
    char**                                        : fxs__strlen_plus_one,     \
    unsigned char**                               : fxs__ustrlen_plus_one,    \
    FXS_StrView*                             : fxs__strv_len,             \
    FXS_DStr*                                 : fxs__dstr_cap,             \
    FXS_DStr**                                : fxs__dstr_ptr_cap,         \
    FXS_StrBuf*                           : fxs__strbuf_cap,           \
    FXS_StrBuf**                          : fxs__strbuf_ptr_cap,       \
    FXS_MutStrRef*                          : fxs__mutstr_ref_cap,       \
    const char**                                  : fxs__strlen_plus_one,     \
    const unsigned char**                         : fxs__ustrlen_plus_one,    \
    const FXS_DStr**                          : fxs__dstr_ptr_cap,         \
    const FXS_StrBuf**                    : fxs__strbuf_ptr_cap        \
)(_Generic((__typeof__(anystr)*){0},                                          \
    char(*)[sizeof(__typeof__(anystr))]: sizeof(__typeof__(anystr)),          \
    unsigned char(*)[sizeof(__typeof__(anystr))]: sizeof(__typeof__(anystr)), \
    default: (anystr)                                                         \
))

#define fxs_chars(any_str)                          \
_Generic(any_str,                                       \
    char*                     : fxs__cstr_as_cstr,      \
    unsigned char*            : fxs__ucstr_as_cstr,     \
    FXS_DStr              : fxs__dstr_as_cstr,       \
    FXS_DStr*             : fxs__dstr_ptr_as_cstr,   \
    FXS_StrView          : fxs__strv_as_cstr,       \
    FXS_StrBuf        : fxs__strbuf_as_cstr,     \
    FXS_StrBuf*       : fxs__strbuf_ptr_as_cstr, \
    FXS_MutStrRef       : fxs__mutstr_ref_as_cstr, \
    const char*               : fxs__cstr_as_cstr,      \
    const unsigned char*      : fxs__ucstr_as_cstr,     \
    const FXS_DStr*       : fxs__dstr_ptr_as_cstr,   \
    const FXS_StrBuf* : fxs__strbuf_ptr_as_cstr  \
)(any_str)

#define fxs_equal(anystr1, anystr2) \
fxs__strv_equal(fxs_str_view(anystr1), fxs_str_view(anystr2))

#define fxs_dup(anystr, ...) \
fxs__dstr_init_from(fxs_str_view(anystr), FXS__VA_OR(fxs_get_default_allocator(), __VA_ARGS__))

#define fxs_copy(mutstr_dst, anystr_src) \
_Generic(mutstr_dst, \
    FXS_MutStrRef : fxs__mutstr_ref_copy(fxs__coerce(mutstr_dst, FXS_MutStrRef), fxs_str_view(anystr_src)), \
    FXS_DStr*       : fxs__dstr_copy(fxs__coerce(mutstr_dst, FXS_DStr*), fxs_str_view(anystr_src)), \
    default             : fxs__fmutstr_ref_copy(fxs__fmutstr_ref(fxs__coerce_not(mutstr_dst, FXS_MutStrRef, FXS_StrBuf*)), fxs_str_view(anystr_src)) \
)

#define fxs_putc(mutstr_dst, c) \
_Generic(mutstr_dst, \
    FXS_MutStrRef : fxs__mutstr_ref_putc(fxs__coerce(mutstr_dst, FXS_MutStrRef), c), \
    FXS_DStr*       : fxs__dstr_putc(fxs__coerce(mutstr_dst, FXS_DStr*), c), \
    default             : fxs__fmutstr_ref_putc(fxs__fmutstr_ref(fxs__coerce_not(mutstr_dst, FXS_MutStrRef, FXS_StrBuf*)), c) \
)

#define fxs_append(mutstr_dst, anystr_src) \
_Generic(mutstr_dst, \
    FXS_MutStrRef : fxs__mutstr_ref_append(fxs__coerce(mutstr_dst, FXS_MutStrRef), fxs_str_view(anystr_src)), \
    FXS_DStr*       : fxs__dstr_append(fxs__coerce(mutstr_dst, FXS_DStr*), fxs_str_view(anystr_src)), \
    default             : fxs__fmutstr_ref_append(fxs__fmutstr_ref(fxs__coerce_not(mutstr_dst, FXS_MutStrRef, FXS_StrBuf*)), fxs_str_view(anystr_src)) \
)

#define fxs_insert(mutstr_dst, anystr_src, idx) \
_Generic(mutstr_dst, \
    FXS_MutStrRef : fxs__mutstr_ref_insert(fxs__coerce(mutstr_dst, FXS_MutStrRef), fxs_str_view(anystr_src), idx), \
    FXS_DStr*       : fxs__dstr_insert(fxs__coerce(mutstr_dst, FXS_DStr*), fxs_str_view(anystr_src), idx), \
    default             : fxs__fmutstr_ref_insert(fxs__fmutstr_ref(fxs__coerce_not(mutstr_dst, FXS_MutStrRef, FXS_StrBuf*)), fxs_str_view(anystr_src), idx) \
)

#define fxs_prepend(mutstr_dst, anystr_src) \
fxs_insert(mutstr_dst, anystr_src, 0)

#define fxs_find(anystr_hay, anystr_needle) \
fxs__strv_find(fxs_str_view(anystr_hay), fxs_str_view(anystr_needle))

#define fxs_count(anystr_hay, anystr_needle) \
fxs__strv_count(fxs_str_view(anystr_hay), fxs_str_view(anystr_needle))

#define fxs_clear(mutstr) \
_Generic(mutstr, \
    FXS_MutStrRef : fxs__mutstr_ref_clear(fxs__coerce(mutstr, FXS_MutStrRef)), \
    default             : fxs__fmutstr_ref_clear(fxs__fmutstr_ref(fxs__coerce_not(mutstr, FXS_MutStrRef, FXS_StrBuf*))) \
)

#define fxs_starts_with(anystr_hay, anystr_needle) \
fxs__strv_starts_with(fxs_str_view(anystr_hay), fxs_str_view(anystr_needle))

#define fxs_ends_with(anystr_hay, anystr_needle) \
fxs__strv_ends_with(fxs_str_view(anystr_hay), fxs_str_view(anystr_needle))

#define fxs_tolower(mutstr) \
fxs__chars_tolower(fxs_str_view(mutstr))

#define fxs_toupper(mutstr) \
fxs__chars_toupper(fxs_str_view(mutstr))

#define fxs_replace(mutstr_dst, anystr_target, anystr_replacement) \
_Generic(mutstr_dst, \
    MutStrRef : fxs__mutstr_ref_replace(fxs__coerce(mutstr_dst, FXS_MutStrRef), fxs_str_view(anystr_target), fxs_str_view(anystr_replacement)), \
    FXS_DStr*  : fxs__dstr_replace(fxs__coerce(mutstr_dst, FXS_DStr*), fxs_str_view(anystr_target), fxs_str_view(anystr_replacement)), \
    default        : fxs__fmutstr_ref_replace(fxs__fmutstr_ref(fxs__coerce_not(mutstr_dst, FXS_MutStrRef, FXS_StrBuf*)), fxs_str_view(anystr_target), fxs_str_view(anystr_replacement)) \
)

#define fxs_replace_first(mutstr_dst, anystr_target, anystr_replacement) \
_Generic(mutstr_dst, \
    FXS_MutStrRef : fxs__mutstr_ref_replace_first(fxs__coerce(mutstr_dst, FXS_MutStrRef), fxs_str_view(anystr_target), fxs_str_view(anystr_replacement)), \
    FXS_DStr*       : fxs__dstr_replace_first(fxs__coerce(mutstr_dst, FXS_DStr*), fxs_str_view(anystr_target), fxs_str_view(anystr_replacement)), \
    default             : fxs__fmutstr_ref_replace_first(fxs__fmutstr_ref(fxs__coerce_not(mutstr_dst, FXS_MutStrRef, FXS_StrBuf*)), fxs_str_view(anystr_target), fxs_str_view(anystr_replacement)) \
)

#define fxs_replace_range(mutstr_dst, begin, end, anystr_replacement) \
_Generic(mutstr_dst, \
    FXS_MutStrRef : fxs__mutstr_ref_replace_range(fxs__coerce(mutstr_dst, FXS_MutStrRef), begin, end, fxs_str_view(anystr_replacement)), \
    FXS_DStr*       : fxs__dstr_replace_range(fxs__coerce(mutstr_dst, FXS_DStr*), begin, end, fxs_str_view(anystr_replacement)), \
    default             : fxs__fmutstr_ref_replace_range(fxs__fmutstr_ref(fxs__coerce_not(mutstr_dst, FXS_MutStrRef, FXS_StrBuf*)), begin, end, fxs_str_view(anystr_replacement)) \
)

#define fxs_split(anystr, anystr_delim, ...) \
fxs__strv_split(fxs_str_view(anystr), fxs_str_view(anystr_delim), FXS__VA_OR(fxs_get_default_allocator(), __VA_ARGS__))

#define fxs_split_iter(anystr, anystr_delim, callback, ...) \
fxs__strv_split_iter(fxs_str_view(anystr), fxs_str_view(anystr_delim), callback, FXS__VA_OR(NULL, __VA_ARGS__));

#define fxs_join(mutstr_dst, strv_arr, anystr_delim) \
_Generic(mutstr_dst, \
    FXS_MutStrRef : fxs__strv_arr_join(fxs__coerce(mutstr_dst, FXS_MutStrRef), strv_arr, fxs_str_view(anystr_delim)), \
    FXS_DStr*       : fxs__strv_arr_join_into_dstr(fxs__coerce(mutstr_dst, FXS_DStr*), strv_arr, fxs_str_view(anystr_delim)), \
    default             : fxs__strv_arr_join_into_fmutstr_ref(fxs__fmutstr_ref(fxs__coerce_not(mutstr_dst, FXS_MutStrRef, FXS_StrBuf*)), strv_arr, fxs_str_view(anystr_delim)) \
)

// DString branch can call fmutstr_ref version directly (its a shrink-only operation)
#define fxs_del(mutstr_dst, begin, end) \
_Generic(mutstr_dst, \
    FXS_MutStrRef : fxs__mutstr_ref_delete_range(fxs__coerce(mutstr_dst, FXS_MutStrRef), begin, end), \
    default             : fxs__fmutstr_ref_delete_range(fxs__fmutstr_ref(fxs__coerce_not(mutstr_dst, FXS_MutStrRef, FXS_StrBuf*)), begin, end) \
)

#define fxs_fread_line(mutstr_dst, stream) \
_Generic(mutstr_dst, \
    FXS_MutStrRef : fxs__mutstr_ref_fread_line(fxs__coerce(mutstr_dst, FXS_MutStrRef), stream), \
    FXS_DStr*       : fxs__dstr_fread_line(fxs__coerce(mutstr_dst, FXS_DStr*), stream), \
    default             : fxs__fmutstr_ref_fread_line(fxs__fmutstr_ref(fxs__coerce_not(mutstr_dst, FXS_MutStrRef, FXS_StrBuf*)), stream) \
)

#define fxs_append_fread_line(mutstr_dst, stream) \
_Generic(mutstr_dst, \
    FXS_MutStrRef : fxs__mutstr_ref_append_fread_line(fxs__coerce(mutstr_dst, FXS_MutStrRef), stream), \
    FXS_DStr*       : fxs__dstr_append_fread_line(fxs__coerce(mutstr_dst, FXS_DStr*), stream), \
    default             : fxs__fmutstr_ref_append_fread_line(fxs__fmutstr_ref(fxs__coerce_not(mutstr_dst, FXS_MutStrRef, FXS_StrBuf*)), stream) \
)

#define fxs_read_line(mutstr_dst) \
fxs_fread_line(mutstr_dst, stdin)

#define fxs_append_read_line(mutstr_dst) \
fxs_append_fread_line(mutstr_dst, stdin)

// helper macro
#define fxs__str_print_each(x) \
do \
{ \
    fxs__appender_mutstr_ref = fxs__make_appender_mutstr_ref( \
        fxs__as_mutstr_ref, \
        &fxs__appender_state \
    ); \
    fxs_tostr(fxs__appender_mutstr_ref, x); \
    fxs__mutstr_ref_commit_appender( \
        fxs__as_mutstr_ref, \
        fxs__appender_mutstr_ref \
    ); \
} while(0);

#define fxs__sprint_each_setup(...) \
__VA_OPT__( \
    FXS_StrAppenderState fxs__appender_state = {0}; \
    FXS_MutStrRef fxs__appender_mutstr_ref; \
    FXS__FOREACH(fxs__str_print_each, __VA_ARGS__); \
)

#define fxs_sprint_append(mutstr_dst, ...) \
do \
{ \
    FXS_MutStrRef fxs__as_mutstr_ref = fxs_mutstr_ref(mutstr_dst); \
    fxs__sprint_each_setup(__VA_ARGS__); \
} while(0)

#define fxs_sprint(mutstr_dst, ...) \
do \
{ \
    FXS_MutStrRef fxs__as_mutstr_ref = fxs_mutstr_ref(mutstr_dst); \
    fxs_clear(fxs__as_mutstr_ref); \
    fxs__sprint_each_setup(__VA_ARGS__); \
} while(0)

#define fxs_str_view_arr_from_carr(strv_carr, ...) \
fxs__strv_arr_from_carr(strv_carr, FXS__VA_OR(FXS__CARR_LEN(strv_carr), __VA_ARGS__))

#define FXS__STRV_COMMA(anystr) \
fxs_str_view(anystr),

#define fxs_str_view_arr(...)                                                                  \
(                                                                                              \
(FXS_StrViewArray) {                                                                      \
    .len  = FXS__CARR_LEN(((FXS_StrView[]){FXS__FOREACH(FXS__STRV_COMMA, __VA_ARGS__)})),  \
    .cap  = FXS__CARR_LEN(((FXS_StrView[]){FXS__FOREACH(FXS__STRV_COMMA, __VA_ARGS__)})),  \
    .strs = (FXS_StrView[]){FXS__FOREACH(FXS__STRV_COMMA, __VA_ARGS__)}                    \
}                                                                                              \
)

// Calls strlen on the cstr to determine its length
// if no capacity is passed, then:
// if char[] is passed, it uses the size of the array as capacity
// if char* is passed, the capacity is length+1
#define fxs_strbuf_init_from_cstr(cstr, ...) \
__VA_OPT__(fxs__strbuf_init_from_cstr_2(cstr, __VA_ARGS__)) \
FXS__IF_EMPTY(fxs__strbuf_init_from_cstr_(cstr), __VA_ARGS__)

#define fxs__strbuf_init_from_cstr_(cstr)                             \
fxs__strbuf_from_cstr(cstr,                                           \
_Generic(&(__typeof__(cstr)){0},                                      \
char(*)[sizeof(__typeof__(cstr))]         : sizeof(__typeof__(cstr)), \
unsigned char(*)[sizeof(__typeof__(cstr))]: sizeof(__typeof__(cstr)), \
char**                                    : strlen((char*) cstr) + 1, \
unsigned char**                           : strlen((char*) cstr) + 1  \
))

#define fxs__strbuf_init_from_cstr_2(cstr, cap) \
fxs__strbuf_from_cstr(cstr, cap)

// Does not call strlen on the buf
// Sets the first byte to '\0'
#define fxs_strbuf_init_from_buf(buf, ...) \
__VA_OPT__( fxs__strbuf_init_from_buf_2(buf, __VA_ARGS__) ) \
FXS__IF_EMPTY(fxs__strbuf_init_from_buf_(buf), __VA_ARGS__)

#define fxs__strbuf_init_from_buf_(buf) \
fxs__strbuf_from_buf( \
_Generic(&(__typeof__(buf)){0}, \
    char(*)[sizeof(__typeof__(buf))]: (FXS_Buffer){.ptr = (unsigned char*) (buf), .cap = sizeof(buf)}, \
    unsigned char(*)[sizeof(__typeof__(buf))]: (FXS_Buffer){.ptr = (unsigned char*) (buf), .cap = sizeof(buf)}, \
    FXS_Buffer*: buf \
))

#define fxs__strbuf_init_from_buf_2(buf, cap_) \
fxs__strbuf_from_buf((FXS_Buffer){.ptr = (unsigned char*) _Generic(buf,char*:buf,unsigned char*:buf,void*:buf), .cap = cap_})

#define fxs__cstr_to_buf(carr, ...) \
( \
FXS__IF_EMPTY( \
    _Generic((__typeof__(carr)*){0}, \
        char(*)[sizeof(__typeof__(carr))]: (FXS_Buffer){.ptr = (unsigned char*) (carr), .cap = sizeof(carr)}, \
        unsigned char(*)[sizeof(__typeof__(any_str))]: (FXS_Buffer){.ptr = (unsigned char*) (carr), .cap = sizeof(carr)} \
    ), \
    __VA_ARGS__ \
) \
__VA_OPT__(fxs__cstr_to_buf2((carr), __VA_ARGS__)) \
)

#define fxs__cstr_to_buf2(carr_or_ptr, cap_) \
((void)_Generic(carr_or_ptr, \
    char(*)[sizeof(__typeof__(carr_or_ptr))]: 0, \
    unsigned char(*)[sizeof(__typeof__(carr_or_ptr))]: 0, \
    char*: 0, \
    unsigned char*: 0 \
), \
(FXS_Buffer){.ptr = (unsigned char*) (carr_or_ptr), .cap = (cap_)})

#define fxs_mutstr_ref(mutstr, ...) \
FXS__CAT(fxs__mutstr_ref, __VA_OPT__(2))((mutstr) __VA_OPT__(,) __VA_ARGS__)

#define fxs__mutstr_ref(mutstr)                                               \
_Generic((__typeof__(mutstr)*){0},                                            \
char**                                       : fxs__cstr_as_mutstr_ref,       \
unsigned char**                              : fxs__ucstr_as_mutstr_ref,      \
FXS_DStr**                                : fxs__dstr_ptr_as_mutstr_ref,   \
FXS_StrBuf**                          : fxs__strbuf_ptr_as_mutstr_ref, \
FXS_MutStrRef*                                 : fxs__mutstr_ref_as_mutstr_ref, \
char(*)[sizeof(__typeof__(mutstr))]          : fxs__buf_as_mutstr_ref,        \
unsigned char(*)[sizeof(__typeof__(mutstr))] : fxs__buf_as_mutstr_ref         \
)(_Generic((__typeof__(mutstr)*){0},                                          \
    char(*)[sizeof(__typeof__(mutstr))]          : (FXS_Buffer){.ptr = (unsigned char*) fxs__coerce(mutstr, char*),          .cap = sizeof(__typeof__(mutstr))}, \
    unsigned char(*)[sizeof(__typeof__(mutstr))] : (FXS_Buffer){.ptr =                  fxs__coerce(mutstr, unsigned char*), .cap = sizeof(__typeof__(mutstr))}, \
    default: (mutstr) \
))

#define fxs__mutstr_ref2(carr_or_ptr, cap_) \
(FXS_MutStrRef){.ty = FXS__BUF_TY, .str.carr = fxs__cstr_to_buf(carr_or_ptr, cap_)} \

#define fxs_appender(mutstr_owner, appender_state) \
fxs__make_appender_mutstr_ref(fxs_mutstr_ref(mutstr_owner), (appender_state))

#define fxs_commit_appender(mutstr_owner, appender) \
fxs__mutstr_ref_commit_appender(fxs_mutstr_ref(mutstr_owner), appender)

#define fxs_str_view(any_str, ...) \
__VA_OPT__(fxs__strv2(any_str, __VA_ARGS__)) \
FXS__IF_EMPTY(fxs__strv1(any_str), __VA_ARGS__)

#define fxs__strv1(anystr)                             \
_Generic(anystr,                                       \
    char*                     : fxs__strv_cstr1,       \
    unsigned char*            : fxs__strv_ucstr1,      \
    FXS_DStr               : fxs__strv_dstr1,       \
    FXS_DStr*              : fxs__strv_dstr_ptr1,   \
    FXS_StrView                  : fxs__strv_strv1,       \
    FXS_StrBuf         : fxs__strv_strbuf1,     \
    FXS_StrBuf*        : fxs__strv_strbuf_ptr1, \
    FXS_MutStrRef               : fxs__strv_mutstr_ref1, \
    const char*               : fxs__strv_cstr1,       \
    const unsigned char*      : fxs__strv_ucstr1,      \
    const FXS_DStr*        : fxs__strv_dstr_ptr1,   \
    const FXS_StrBuf*  : fxs__strv_strbuf_ptr1  \
)(anystr)

#define fxs__strv2(anystr, begin, ...)                \
__VA_OPT__(fxs__strv3(anystr, begin, __VA_ARGS__))    \
FXS__IF_EMPTY(                                        \
_Generic(anystr,                                      \
    char*                    : fxs__strv_cstr2,       \
    unsigned char*           : fxs__strv_ucstr2,      \
    FXS_DStr              : fxs__strv_dstr2,       \
    FXS_DStr*             : fxs__strv_dstr_ptr2,   \
    FXS_StrView                 : fxs__strv_strv2,       \
    FXS_StrBuf        : fxs__strv_strbuf2,     \
    FXS_StrBuf*       : fxs__strv_strbuf_ptr2, \
    FXS_MutStrRef              : fxs__strv_mutstr_ref2, \
    const char*              : fxs__strv_cstr2,       \
    const unsigned char*     : fxs__strv_ucstr2,      \
    const FXS_DStr*       : fxs__strv_dstr_ptr2,   \
    const FXS_StrBuf* : fxs__strv_strbuf_ptr2  \
)(anystr, begin), __VA_ARGS__)

#define fxs__strv3(anystr, begin, end)                \
_Generic(anystr,                                      \
    char*                    : fxs__strv_cstr3,       \
    unsigned char*           : fxs__strv_ucstr3,      \
    FXS_DStr              : fxs__strv_dstr3,       \
    FXS_DStr*             : fxs__strv_dstr_ptr3,   \
    FXS_StrView                 : fxs__strv_strv3,       \
    FXS_StrBuf        : fxs__strv_strbuf3,     \
    FXS_StrBuf*       : fxs__strv_strbuf_ptr3, \
    FXS_MutStrRef              : fxs__strv_mutstr_ref3, \
    const char*              : fxs__strv_cstr3,       \
    const unsigned char*     : fxs__strv_ucstr3,      \
    const FXS_DStr*       : fxs__strv_dstr_ptr3,   \
    const FXS_StrBuf* : fxs__strv_strbuf_ptr3  \
)(anystr, begin, end)

#define fxs_dstr_init(...) \
FXS__CAT(fxs__dstr_init0, __VA_OPT__(1))(__VA_ARGS__)

#define fxs__dstr_init0() \
fxs__dstr_init(1, fxs_get_default_allocator())

#define fxs__dstr_init01(cap, ...)               \
__VA_OPT__(fxs__dstr_init2((cap), __VA_ARGS__)) \
FXS__IF_EMPTY(                                  \
    fxs__dstr_init(                             \
        (cap),                                  \
        fxs_get_default_allocator()             \
    )                                           \
, __VA_ARGS__                                   \
)

#define fxs__dstr_init2(cap, allocator) \
fxs__dstr_init((cap), (allocator))

#define fxs_dstr_init_from(anystr_src, ...) \
fxs__dstr_init_from(fxs_str_view(anystr_src), FXS__VA_OR(fxs_get_default_allocator(), __VA_ARGS__))

#define fxs_dstr_deinit(dstr) \
fxs__dstr_deinit(dstr)

#define fxs_dstr_append(dstr, anystr_src) \
fxs__dstr_append(dstr, fxs_str_view(anystr_src))

#define fxs_dstr_prepend(dstr, anystr_src) \
fxs__dstr_prepend_strv(dstr, fxs_str_view(anystr_src))

#define fxs_dstr_insert(dstr, anystr_src, idx) \
fxs__dstr_insert(dstr, fxs_str_view(anystr_src), idx)

#define fxs_dstr_fread_line(dstr, stream) \
fxs__dstr_fread_line(dstr, stream)

#define fxs_dstr_read_line(dstr) \
fxs__dstr_fread_line(dstr, stdin)

#define fxs_dstr_append_fread_line(dstr, stream) \
fxs__dstr_append_fread_line(dstr, stream)

#define fxs_dstr_append_read_line(dstr) \
fxs__dstr_append_fread_line(dstr, stdin)

#define fxs_dstr_shrink_to_fit(dstr) \
fxs__dstr_shrink_to_fit(dstr)

#define fxs_dstr_ensure_cap(dstr, new_cap) \
fxs__dstr_ensure_cap(dstr, new_cap)

#define fxs_fprint(f, ...)                       \
do                                               \
{                                                \
    FILE *fxs__file_stream = f;                  \
    (void) fxs__file_stream;                     \
    extern _Thread_local FXS_DStr fxs__fprint_tostr_dynamic_buffer; \
    FXS__FOREACH(fxs__fprint_each, __VA_ARGS__); \
} while(0)

#define fxs__fprint_each(x)                                 \
do                                                          \
{                                                           \
    __typeof__(((void)0,x)) fxs__x_tmp = x;                 \
    fxs__fprint_strv(fxs__file_stream, _Generic(fxs__x_tmp, \
        char*                     : fxs__strv_cstr1,        \
        unsigned char*            : fxs__strv_ucstr1,       \
        FXS_DStr              : fxs__strv_dstr1,         \
        FXS_DStr*             : fxs__strv_dstr_ptr1,     \
        FXS_StrView          : fxs__strv_strv1,         \
        FXS_StrBuf        : fxs__strv_strbuf1,       \
        FXS_StrBuf*       : fxs__strv_strbuf_ptr1,   \
        FXS_MutStrRef       : fxs__strv_mutstr_ref1,   \
        const char*               : fxs__strv_cstr1,        \
        const unsigned char*      : fxs__strv_ucstr1,       \
        const FXS_DStr*       : fxs__strv_dstr_ptr1,     \
        const FXS_StrBuf* : fxs__strv_strbuf_ptr1,   \
        default                   : fxs__strv_dstr1         \
    )(fxs__coerce_string_type(fxs__x_tmp, (fxs_tostr(&fxs__fprint_tostr_dynamic_buffer, fxs__x_tmp), fxs__fprint_tostr_dynamic_buffer)))); \
    fxs__fprint_tostr_dynamic_buffer.len = 0;               \
} while(0);

#define fxs_print(...) \
fxs_fprint(stdout, __VA_ARGS__)

#define fxs_fprintln(f, ...)                \
do                                          \
{                                           \
    FILE *fxs__tmp_file = f;                \
    (void) fxs__tmp_file;                   \
    fxs_fprint(fxs__tmp_file, __VA_ARGS__); \
    fputc('\n', fxs__tmp_file);             \
} while(0)

#define fxs_println(...) \
fxs_fprintln(stdout, __VA_ARGS__)

typedef char fxs__c;
typedef signed char fxs__sc;
typedef unsigned char fxs__uc;
typedef short fxs__s;
typedef unsigned short fxs__us;
typedef int fxs__i;
typedef unsigned int fxs__ui;
typedef long fxs__l;
typedef unsigned long fxs__ul;
typedef long long fxs__ll;
typedef unsigned long long fxs__ull;

#define FXS__MCALL(macro, arglist) macro arglist

#define FXS__INTEGER_TYPES(FXS__X, extra, ...) \
FXS__X(fxs__c, extra)  \
FXS__X(fxs__sc, extra) \
FXS__X(fxs__uc, extra) \
FXS__X(fxs__s, extra)  \
FXS__X(fxs__us, extra) \
FXS__X(fxs__i, extra)  \
FXS__X(fxs__ui, extra) \
FXS__X(fxs__l, extra)  \
FXS__X(fxs__ul, extra) \
FXS__X(fxs__ll, extra) \
FXS__MCALL(FXS__VA_OR(FXS__X, __VA_ARGS__), (fxs__ull, extra))

#define FXS__FLOATING_TYPES(FXS__X, extra, last_call) \
FXS__X(float, extra) \
last_call(double, extra)

#define FXS__X(ty, extra) \
typedef struct FXS__Integer_d_Fmt_##ty \
{ \
    ty obj; \
} FXS__Integer_d_Fmt_##ty; \
typedef struct FXS__Integer_x_Fmt_##ty \
{ \
    ty obj; \
} FXS__Integer_x_Fmt_##ty; \
typedef struct FXS__Integer_o_Fmt_##ty \
{ \
    ty obj; \
} FXS__Integer_o_Fmt_##ty; \
typedef struct FXS__Integer_b_Fmt_##ty \
{ \
    ty obj; \
} FXS__Integer_b_Fmt_##ty;

FXS__INTEGER_TYPES(FXS__X, ignore)

#undef FXS__X

#define FXS__X(ty, extra) \
typedef struct FXS__Floating_f_Fmt_##ty \
{ \
    ty obj; \
    int precision; \
} FXS__Floating_f_Fmt_##ty; \
typedef struct FXS__Floating_g_Fmt_##ty \
{ \
    ty obj; \
    int precision; \
} FXS__Floating_g_Fmt_##ty; \
typedef struct FXS__Floating_e_Fmt_##ty \
{ \
    ty obj; \
    int precision; \
} FXS__Floating_e_Fmt_##ty; \
typedef struct FXS__Floating_a_Fmt_##ty \
{ \
    ty obj; \
    int precision; \
} FXS__Floating_a_Fmt_##ty; \

FXS__FLOATING_TYPES(FXS__X, ignore, FXS__X)

#undef FXS__X

#define FXS__X_IS_TY(ty, extra) \
ty: 1,

#define FXS__IS_FLOATING(obj) \
_Generic(obj, \
FXS__FLOATING_TYPES(FXS__X_IS_TY, ignore, FXS__X_IS_TY) \
default: 0)

#define FXS__IS_INTEGER(obj) \
_Generic(obj, \
FXS__INTEGER_TYPES(FXS__X_IS_TY, ignore) \
default: 0)

#define FXS__INTEGER_FMT_GENERIC_BRANCHES(ty, extra) \
ty: \
_Generic((char(*)[FXS__ARG2 extra]){0}, \
char(*)['d']: (FXS__Integer_d_Fmt_##ty){fxs__coerce(FXS__ARG1 extra, ty)},  \
char(*)['x']: (FXS__Integer_x_Fmt_##ty){fxs__coerce(FXS__ARG1 extra, ty)},  \
char(*)['o']: (FXS__Integer_o_Fmt_##ty){fxs__coerce(FXS__ARG1 extra, ty)},  \
char(*)['b']: (FXS__Integer_b_Fmt_##ty){fxs__coerce(FXS__ARG1 extra, ty)},  \
default: 0),

#define FXS__3_VA_OR(otherwise, a,b, ...) \
FXS__VA_OR(otherwise, __VA_ARGS__)

#define FXS__FLOATING_FMT_LAST_GENERIC_BRANCH(ty, extra) \
ty: \
_Generic((char(*)[FXS__ARG2 extra]){0}, \
char(*)['f']: (FXS__Floating_f_Fmt_##ty){fxs__coerce(FXS__ARG1 extra, ty), FXS__MCALL(FXS__3_VA_OR, (6, FXS__EXPAND1 extra))},   \
char(*)['g']: (FXS__Floating_g_Fmt_##ty){fxs__coerce(FXS__ARG1 extra, ty), FXS__MCALL(FXS__3_VA_OR, (6, FXS__EXPAND1 extra))},   \
char(*)['e']: (FXS__Floating_e_Fmt_##ty){fxs__coerce(FXS__ARG1 extra, ty), FXS__MCALL(FXS__3_VA_OR, (6, FXS__EXPAND1 extra))},   \
char(*)['a']: (FXS__Floating_a_Fmt_##ty){fxs__coerce(FXS__ARG1 extra, ty), FXS__MCALL(FXS__3_VA_OR, (-1, FXS__EXPAND1 extra))},  \
default: 0)

#define FXS__FLOATING_FMT_GENERIC_BRANCH(ty, extra) \
FXS__FLOATING_FMT_LAST_GENERIC_BRANCH(ty, extra),

#define fxs_tsfmt(x, fmt_chr, ...) \
( \
    fxs__static_assertx( (FXS__IS_FLOATING(x) && (fmt_chr == 'f' || fmt_chr == 'g' || fmt_chr == 'e' || fmt_chr == 'a')  ) || (FXS__IS_INTEGER(x) && (fmt_chr == 'd' || fmt_chr == 'x' || fmt_chr == 'o' || fmt_chr == 'b')), "Incorrect formatting char for the type"), \
    fxs__static_assertx((FXS__IS_FLOATING(x) || (1 __VA_OPT__(-1))), "tsfmt Integers dont take a third parameter"), \
    _Generic(x, \
        FXS__INTEGER_TYPES(FXS__INTEGER_FMT_GENERIC_BRANCHES, (x, fmt_chr)) \
        FXS__FLOATING_TYPES(FXS__FLOATING_FMT_GENERIC_BRANCH, (x, fmt_chr __VA_OPT__(,) __VA_ARGS__), FXS__FLOATING_FMT_LAST_GENERIC_BRANCH) \
    ) \
)

#define fxs_tsfmt_t(ty, fmt_chr, ...) \
__typeof__(fxs_tsfmt((ty)0, fmt_chr __VA_OPT__(,) __VA_ARGS__))

#define fxs_arrfmt(array, nb, ...) \
FXS__IF_EMPTY(fxs__arrfmt_, __VA_ARGS__) \
__VA_OPT__(fxs__arrfmt_2) \
(array, nb __VA_OPT__(,) __VA_ARGS__)

#define fxs__arrfmt_(array_, nb_) \
((FXS_ArrayFmt){ \
    .array = (array_), \
    .nb = (nb_), \
    .elm_size = sizeof((array_)[0]), \
    .elm_tostr = (void*) fxs__get_tostr_p_func(__typeof__((array_)[0])), \
    .open = fxs_str_view("{"), \
    .close = fxs_str_view("}"), \
    .separator = fxs_str_view(", "), \
    .trailing_separator = fxs_str_view("") \
})

#define fxs__arrfmt_2(array_, nb_, open_, close_, seperator_, ...) \
((FXS_ArrayFmt){ \
    .array = (array_), \
    .nb = (nb_), \
    .elm_size = sizeof((array_)[0]), \
    .elm_tostr = (void*) fxs__get_tostr_p_func(__typeof__((array_)[0])), \
    .open = fxs_str_view(open_), \
    .close = fxs_str_view(close_), \
    .separator = fxs_str_view(seperator_), \
    .trailing_separator = fxs_str_view(FXS__VA_OR("", __VA_ARGS__)) \
})

#define FXS__INTEGER_TOSTR_GENERIC_CASE(ty, extra) \
FXS__Integer_d_Fmt_##ty : fxs__Integer_d_Fmt_##ty##_tostr, \
FXS__Integer_x_Fmt_##ty : fxs__Integer_x_Fmt_##ty##_tostr, \
FXS__Integer_o_Fmt_##ty : fxs__Integer_o_Fmt_##ty##_tostr, \
FXS__Integer_b_Fmt_##ty : fxs__Integer_b_Fmt_##ty##_tostr, \

#define FXS__FLOATING_TOSTR_LAST_GENERIC_CASE(ty, extra) \
FXS__Floating_f_Fmt_##ty : fxs__Floating_f_Fmt_##ty##_tostr, \
FXS__Floating_g_Fmt_##ty : fxs__Floating_g_Fmt_##ty##_tostr, \
FXS__Floating_e_Fmt_##ty : fxs__Floating_e_Fmt_##ty##_tostr, \
FXS__Floating_a_Fmt_##ty : fxs__Floating_a_Fmt_##ty##_tostr

#define FXS__INTEGER_TOSTR_P_GENERIC_CASE(ty, extra) \
FXS__Integer_d_Fmt_##ty : fxs__Integer_d_Fmt_##ty##_tostr_p, \
FXS__Integer_x_Fmt_##ty : fxs__Integer_x_Fmt_##ty##_tostr_p, \
FXS__Integer_o_Fmt_##ty : fxs__Integer_o_Fmt_##ty##_tostr_p, \
FXS__Integer_b_Fmt_##ty : fxs__Integer_b_Fmt_##ty##_tostr_p, \

#define FXS__FLOATING_TOSTR_P_LAST_GENERIC_CASE(ty, extra) \
FXS__Floating_f_Fmt_##ty : fxs__Floating_f_Fmt_##ty##_tostr_p, \
FXS__Floating_g_Fmt_##ty : fxs__Floating_g_Fmt_##ty##_tostr_p, \
FXS__Floating_e_Fmt_##ty : fxs__Floating_e_Fmt_##ty##_tostr_p, \
FXS__Floating_a_Fmt_##ty : fxs__Floating_a_Fmt_##ty##_tostr_p

#define FXS__FLOATING_TOSTR_GENERIC_CASE(ty, extra) \
FXS__FLOATING_TOSTR_LAST_GENERIC_CASE(ty, extra),

#define FXS__FLOATING_TOSTR_P_GENERIC_CASE(ty, extra) \
FXS__FLOATING_TOSTR_P_LAST_GENERIC_CASE(ty, extra),

#define FXS__DEFAULT_TOSTR_GENERIC_BRANCHES                 \
bool                      : fxs__bool_tostr,                \
char*                     : fxs__cstr_tostr,                \
unsigned char*            : fxs__ucstr_tostr,               \
char                      : fxs__char_tostr,                \
signed char               : fxs__schar_tostr,               \
unsigned char             : fxs__uchar_tostr,               \
short                     : fxs__short_tostr,               \
unsigned short            : fxs__ushort_tostr,              \
int                       : fxs__int_tostr,                 \
unsigned int              : fxs__uint_tostr,                \
long                      : fxs__long_tostr,                \
unsigned long             : fxs__ulong_tostr,               \
long long                 : fxs__llong_tostr,               \
unsigned long long        : fxs__ullong_tostr,              \
float                     : fxs__float_tostr,               \
double                    : fxs__double_tostr,              \
FXS_DStr              : fxs__dstr_tostr,                 \
FXS_DStr*             : fxs__dstr_ptr_tostr,             \
FXS_StrView          : fxs__strv_tostr,                 \
FXS_StrBuf        : fxs__strbuf_tostr,               \
FXS_StrBuf*       : fxs__strbuf_ptr_tostr,           \
FXS_MutStrRef       : fxs__mutstr_ref_tostr,           \
const char*               : fxs__cstr_tostr,                \
const unsigned char*      : fxs__ucstr_tostr,               \
const FXS_DStr*       : fxs__dstr_ptr_tostr,             \
const FXS_StrBuf* : fxs__strbuf_ptr_tostr,           \
FXS_Error                : fxs__error_tostr,                \
FXS_ArrayFmt            : fxs__array_fmt_tostr,            \
FXS__INTEGER_TYPES(FXS__INTEGER_TOSTR_GENERIC_CASE, ignore) \
FXS__FLOATING_TYPES(FXS__FLOATING_TOSTR_GENERIC_CASE, ignore, FXS__FLOATING_TOSTR_LAST_GENERIC_CASE)

#define FXS__DEFAULT_TOSTR_P_GENERIC_BRANCHES                 \
bool                      : fxs__bool_tostr_p,                \
char*                     : fxs__cstr_tostr_p,                \
unsigned char*            : fxs__ucstr_tostr_p,               \
char                      : fxs__char_tostr_p,                \
signed char               : fxs__schar_tostr_p,               \
unsigned char             : fxs__uchar_tostr_p,               \
short                     : fxs__short_tostr_p,               \
unsigned short            : fxs__ushort_tostr_p,              \
int                       : fxs__int_tostr_p,                 \
unsigned int              : fxs__uint_tostr_p,                \
long                      : fxs__long_tostr_p,                \
unsigned long             : fxs__ulong_tostr_p,               \
long long                 : fxs__llong_tostr_p,               \
unsigned long long        : fxs__ullong_tostr_p,              \
float                     : fxs__float_tostr_p,               \
double                    : fxs__double_tostr_p,              \
FXS_DStr              : fxs__dstr_tostr_p,                 \
FXS_DStr*             : fxs__dstr_ptr_tostr_p,             \
FXS_StrView          : fxs__strv_tostr_p,                 \
FXS_StrBuf        : fxs__strbuf_tostr_p,               \
FXS_StrBuf*       : fxs__strbuf_ptr_tostr_p,           \
FXS_MutStrRef       : fxs__mutstr_ref_tostr_p,           \
const char*               : fxs__cstr_tostr_p,                \
const unsigned char*      : fxs__ucstr_tostr_p,               \
const FXS_DStr*       : fxs__dstr_ptr_tostr_p,             \
const FXS_StrBuf* : fxs__strbuf_ptr_tostr_p,           \
FXS_Error                : fxs__error_tostr_p,                \
FXS_ArrayFmt*           : fxs__array_fmt_tostr_p,            \
FXS__INTEGER_TYPES(FXS__INTEGER_TOSTR_P_GENERIC_CASE, ignore) \
FXS__FLOATING_TYPES(FXS__FLOATING_TOSTR_P_GENERIC_CASE, ignore, FXS__FLOATING_TOSTR_P_LAST_GENERIC_CASE)

#define FXS__TOSTR_FUNCS_GENERIC_BRANCHES                          \
FXS__IF_DEF(FXS__TOSTR1) (fxs__tostr_type_1 : fxs__tostr_func_1,)  \
FXS__IF_DEF(FXS__TOSTR2) (fxs__tostr_type_2 : fxs__tostr_func_2,)  \
FXS__IF_DEF(FXS__TOSTR3) (fxs__tostr_type_3 : fxs__tostr_func_3,)  \
FXS__IF_DEF(FXS__TOSTR4) (fxs__tostr_type_4 : fxs__tostr_func_4,)  \
FXS__IF_DEF(FXS__TOSTR5) (fxs__tostr_type_5 : fxs__tostr_func_5,)  \
FXS__IF_DEF(FXS__TOSTR6) (fxs__tostr_type_6 : fxs__tostr_func_6,)  \
FXS__IF_DEF(FXS__TOSTR7) (fxs__tostr_type_7 : fxs__tostr_func_7,)  \
FXS__IF_DEF(FXS__TOSTR8) (fxs__tostr_type_8 : fxs__tostr_func_8,)  \
FXS__IF_DEF(FXS__TOSTR9) (fxs__tostr_type_9 : fxs__tostr_func_9,)  \
FXS__IF_DEF(FXS__TOSTR10)(fxs__tostr_type_10: fxs__tostr_func_10,) \
FXS__IF_DEF(FXS__TOSTR11)(fxs__tostr_type_11: fxs__tostr_func_11,) \
FXS__IF_DEF(FXS__TOSTR12)(fxs__tostr_type_12: fxs__tostr_func_12,) \
FXS__IF_DEF(FXS__TOSTR13)(fxs__tostr_type_13: fxs__tostr_func_13,) \
FXS__IF_DEF(FXS__TOSTR14)(fxs__tostr_type_14: fxs__tostr_func_14,) \
FXS__IF_DEF(FXS__TOSTR15)(fxs__tostr_type_15: fxs__tostr_func_15,) \
FXS__IF_DEF(FXS__TOSTR16)(fxs__tostr_type_16: fxs__tostr_func_16,) \
FXS__IF_DEF(FXS__TOSTR17)(fxs__tostr_type_17: fxs__tostr_func_17,) \
FXS__IF_DEF(FXS__TOSTR18)(fxs__tostr_type_18: fxs__tostr_func_18,) \
FXS__IF_DEF(FXS__TOSTR19)(fxs__tostr_type_19: fxs__tostr_func_19,) \
FXS__IF_DEF(FXS__TOSTR20)(fxs__tostr_type_20: fxs__tostr_func_20,) \
FXS__IF_DEF(FXS__TOSTR21)(fxs__tostr_type_21: fxs__tostr_func_21,) \
FXS__IF_DEF(FXS__TOSTR22)(fxs__tostr_type_22: fxs__tostr_func_22,) \
FXS__IF_DEF(FXS__TOSTR23)(fxs__tostr_type_23: fxs__tostr_func_23,) \
FXS__IF_DEF(FXS__TOSTR24)(fxs__tostr_type_24: fxs__tostr_func_24,) \
FXS__IF_DEF(FXS__TOSTR25)(fxs__tostr_type_25: fxs__tostr_func_25,) \
FXS__IF_DEF(FXS__TOSTR26)(fxs__tostr_type_26: fxs__tostr_func_26,) \
FXS__IF_DEF(FXS__TOSTR27)(fxs__tostr_type_27: fxs__tostr_func_27,) \
FXS__IF_DEF(FXS__TOSTR28)(fxs__tostr_type_28: fxs__tostr_func_28,) \
FXS__IF_DEF(FXS__TOSTR29)(fxs__tostr_type_29: fxs__tostr_func_29,) \
FXS__IF_DEF(FXS__TOSTR30)(fxs__tostr_type_30: fxs__tostr_func_30,) \
FXS__IF_DEF(FXS__TOSTR31)(fxs__tostr_type_31: fxs__tostr_func_31,) \
FXS__IF_DEF(FXS__TOSTR32)(fxs__tostr_type_32: fxs__tostr_func_32,) \
FXS__DEFAULT_TOSTR_GENERIC_BRANCHES

#define FXS__TOSTR_P_FUNCS_GENERIC_BRANCHES                          \
FXS__IF_DEF(FXS__TOSTR1) (fxs__tostr_type_1 : fxs__tostr_p_func_1,)  \
FXS__IF_DEF(FXS__TOSTR2) (fxs__tostr_type_2 : fxs__tostr_p_func_2,)  \
FXS__IF_DEF(FXS__TOSTR3) (fxs__tostr_type_3 : fxs__tostr_p_func_3,)  \
FXS__IF_DEF(FXS__TOSTR4) (fxs__tostr_type_4 : fxs__tostr_p_func_4,)  \
FXS__IF_DEF(FXS__TOSTR5) (fxs__tostr_type_5 : fxs__tostr_p_func_5,)  \
FXS__IF_DEF(FXS__TOSTR6) (fxs__tostr_type_6 : fxs__tostr_p_func_6,)  \
FXS__IF_DEF(FXS__TOSTR7) (fxs__tostr_type_7 : fxs__tostr_p_func_7,)  \
FXS__IF_DEF(FXS__TOSTR8) (fxs__tostr_type_8 : fxs__tostr_p_func_8,)  \
FXS__IF_DEF(FXS__TOSTR9) (fxs__tostr_type_9 : fxs__tostr_p_func_9,)  \
FXS__IF_DEF(FXS__TOSTR10)(fxs__tostr_type_10: fxs__tostr_p_func_10,) \
FXS__IF_DEF(FXS__TOSTR11)(fxs__tostr_type_11: fxs__tostr_p_func_11,) \
FXS__IF_DEF(FXS__TOSTR12)(fxs__tostr_type_12: fxs__tostr_p_func_12,) \
FXS__IF_DEF(FXS__TOSTR13)(fxs__tostr_type_13: fxs__tostr_p_func_13,) \
FXS__IF_DEF(FXS__TOSTR14)(fxs__tostr_type_14: fxs__tostr_p_func_14,) \
FXS__IF_DEF(FXS__TOSTR15)(fxs__tostr_type_15: fxs__tostr_p_func_15,) \
FXS__IF_DEF(FXS__TOSTR16)(fxs__tostr_type_16: fxs__tostr_p_func_16,) \
FXS__IF_DEF(FXS__TOSTR17)(fxs__tostr_type_17: fxs__tostr_p_func_17,) \
FXS__IF_DEF(FXS__TOSTR18)(fxs__tostr_type_18: fxs__tostr_p_func_18,) \
FXS__IF_DEF(FXS__TOSTR19)(fxs__tostr_type_19: fxs__tostr_p_func_19,) \
FXS__IF_DEF(FXS__TOSTR20)(fxs__tostr_type_20: fxs__tostr_p_func_20,) \
FXS__IF_DEF(FXS__TOSTR21)(fxs__tostr_type_21: fxs__tostr_p_func_21,) \
FXS__IF_DEF(FXS__TOSTR22)(fxs__tostr_type_22: fxs__tostr_p_func_22,) \
FXS__IF_DEF(FXS__TOSTR23)(fxs__tostr_type_23: fxs__tostr_p_func_23,) \
FXS__IF_DEF(FXS__TOSTR24)(fxs__tostr_type_24: fxs__tostr_p_func_24,) \
FXS__IF_DEF(FXS__TOSTR25)(fxs__tostr_type_25: fxs__tostr_p_func_25,) \
FXS__IF_DEF(FXS__TOSTR26)(fxs__tostr_type_26: fxs__tostr_p_func_26,) \
FXS__IF_DEF(FXS__TOSTR27)(fxs__tostr_type_27: fxs__tostr_p_func_27,) \
FXS__IF_DEF(FXS__TOSTR28)(fxs__tostr_type_28: fxs__tostr_p_func_28,) \
FXS__IF_DEF(FXS__TOSTR29)(fxs__tostr_type_29: fxs__tostr_p_func_29,) \
FXS__IF_DEF(FXS__TOSTR30)(fxs__tostr_type_30: fxs__tostr_p_func_30,) \
FXS__IF_DEF(FXS__TOSTR31)(fxs__tostr_type_31: fxs__tostr_p_func_31,) \
FXS__IF_DEF(FXS__TOSTR32)(fxs__tostr_type_32: fxs__tostr_p_func_32,) \
FXS__DEFAULT_TOSTR_P_GENERIC_BRANCHES

struct fxs__fail_type { int dummy; };
typedef void(*fxs__tostr_fail)(struct fxs__fail_type*);

#define fxs__get_tostr_func(ty) \
_Generic((ty){0}, \
    FXS__TOSTR_FUNCS_GENERIC_BRANCHES \
)

#define fxs__get_tostr_func_ft(ty) \
_Generic((ty){0}, \
    FXS__TOSTR_FUNCS_GENERIC_BRANCHES, \
    default: (fxs__tostr_fail){0} \
)

#define fxs__get_tostr_p_func(ty) \
_Generic((ty){0}, \
    FXS__TOSTR_P_FUNCS_GENERIC_BRANCHES \
)

#define fxs_tostr(dst, src) \
fxs__get_tostr_func(__typeof__(src))(fxs_mutstr_ref(dst), (src))

#define fxs_has_tostr(ty) \
(!fxs__has_type(fxs__get_tostr_func_ft(ty), fxs__tostr_fail))

#define fxs_tostr_p(dst, src) \
fxs__get_tostr_p_func(__typeof__(*(src)))(fxs_mutstr_ref(dst), (src))

#define FXS__DECL_TOSTR_FUNC(n) \
typedef __typeof__(FXS__MCALL(FXS__ARG1, ADD_TOSTR)) fxs__tostr_type_##n; \
static inline FXS_Error fxs__tostr_func_##n (FXS_MutStrRef dst, fxs__tostr_type_##n obj) \
{ \
    _Static_assert(fxs__has_type(FXS__MCALL(FXS__ARG2, ADD_TOSTR), __typeof__(FXS_Error(*)(FXS_MutStrRef, fxs__tostr_type_##n))), "tostr functions must have signature `FXS_Error(FXS_MutStrRef dst, T src)`"); \
    fxs__mutstr_ref_clear(dst); \
    return FXS__MCALL(FXS__ARG2, ADD_TOSTR) (dst, obj); \
} \
static inline FXS_Error fxs__tostr_p_func_##n (FXS_MutStrRef dst, const fxs__tostr_type_##n *obj) \
{ \
    return fxs__tostr_func_##n(dst, *obj); \
}

FXS_API FXS_StrView fxs__strv_cstr1(const char *str);
FXS_API FXS_StrView fxs__strv_ucstr1(const unsigned char *str);
FXS_API FXS_StrView fxs__strv_dstr1(const FXS_DStr str);
FXS_API FXS_StrView fxs__strv_dstr_ptr1(const FXS_DStr *str);
FXS_API FXS_StrView fxs__strv_strv1(const FXS_StrView str);
FXS_API FXS_StrView fxs__strv_strbuf1(const FXS_StrBuf str);
FXS_API FXS_StrView fxs__strv_strbuf_ptr1(const FXS_StrBuf *str);
FXS_API FXS_StrView fxs__strv_mutstr_ref1(const FXS_MutStrRef str);

FXS_API FXS_StrView fxs__strv_cstr2(const char *str, unsigned int begin);
FXS_API FXS_StrView fxs__strv_ucstr2(const unsigned char *str, unsigned int begin);
FXS_API FXS_StrView fxs__strv_dstr2(const FXS_DStr str, unsigned int begin);
FXS_API FXS_StrView fxs__strv_dstr_ptr2(const FXS_DStr *str, unsigned int begin);
FXS_API FXS_StrView fxs__strv_strv2(const FXS_StrView str, unsigned int begin);
FXS_API FXS_StrView fxs__strv_strbuf2(const FXS_StrBuf str, unsigned int begin);
FXS_API FXS_StrView fxs__strv_strbuf_ptr2(const FXS_StrBuf *str, unsigned int begin);
FXS_API FXS_StrView fxs__strv_mutstr_ref2(const FXS_MutStrRef str, unsigned int begin);

FXS_API FXS_StrView fxs__strv_cstr3(const char *str, unsigned int begin, unsigned int end);
FXS_API FXS_StrView fxs__strv_ucstr3(const unsigned char *str, unsigned int begin, unsigned int end);
FXS_API FXS_StrView fxs__strv_dstr3(const FXS_DStr str, unsigned int begin, unsigned int end);
FXS_API FXS_StrView fxs__strv_dstr_ptr3(const FXS_DStr *str, unsigned int begin, unsigned int end);
FXS_API FXS_StrView fxs__strv_strv3(const FXS_StrView str, unsigned int begin, unsigned int end);
FXS_API FXS_StrView fxs__strv_strbuf3(const FXS_StrBuf str, unsigned int begin, unsigned int end);
FXS_API FXS_StrView fxs__strv_strbuf_ptr3(const FXS_StrBuf *str, unsigned int begin, unsigned int end);
FXS_API FXS_StrView fxs__strv_mutstr_ref3(const FXS_MutStrRef str, unsigned int begin, unsigned int end);

FXS_API FXS_StrBuf fxs__strbuf_from_cstr(const char *ptr, unsigned int cap);
FXS_API FXS_StrBuf fxs__strbuf_from_buf(const FXS_Buffer buf);

FXS_API FXS_Buffer fxs__buf_from_cstr(const char *str);
FXS_API FXS_Buffer fxs__buf_from_ucstr(const unsigned char *str);
FXS_API FXS_Buffer fxs__buf_from_carr(const char *str, size_t cap);
FXS_API FXS_Buffer fxs__buf_from_ucarr(const unsigned char *str, size_t cap);

FXS_API FXS_MutStrRef fxs__cstr_as_mutstr_ref(const char *str);
FXS_API FXS_MutStrRef fxs__ucstr_as_mutstr_ref(const unsigned char *str);
FXS_API FXS_MutStrRef fxs__buf_as_mutstr_ref(const FXS_Buffer str);
FXS_API FXS_MutStrRef fxs__dstr_ptr_as_mutstr_ref(const FXS_DStr *str);
FXS_API FXS_MutStrRef fxs__strbuf_ptr_as_mutstr_ref(const FXS_StrBuf *str);
FXS_API FXS_MutStrRef fxs__mutstr_ref_as_mutstr_ref(const FXS_MutStrRef str);

FXS_API FXS__FixedMutStrRef fxs__buf_as_fmutstr_ref(FXS_Buffer buf, unsigned int *len_ptr);
FXS_API FXS__FixedMutStrRef fxs__strbuf_ptr_as_fmutstr_ref(FXS_StrBuf *strbuf);
FXS_API FXS__FixedMutStrRef fxs__dstr_ptr_as_fmutstr_ref(FXS_DStr *dstr);

FXS_API FXS_MutStrRef fxs__make_appender_mutstr_ref(FXS_MutStrRef owner, FXS_StrAppenderState *state);
FXS_API FXS_Error fxs__mutstr_ref_commit_appender(FXS_MutStrRef owner, FXS_MutStrRef appender);

FXS_API char *fxs__cstr_as_cstr(const char *str);
FXS_API char *fxs__ucstr_as_cstr(const unsigned char *str);
FXS_API char *fxs__dstr_as_cstr(const FXS_DStr str);
FXS_API char *fxs__dstr_ptr_as_cstr(const FXS_DStr *str);
FXS_API char *fxs__strv_as_cstr(const FXS_StrView str);
FXS_API char *fxs__strbuf_as_cstr(const FXS_StrBuf str);
FXS_API char *fxs__strbuf_ptr_as_cstr(const FXS_StrBuf *str);
FXS_API char *fxs__mutstr_ref_as_cstr(const FXS_MutStrRef str);

FXS_API unsigned int fxs__dstr_cap(const FXS_DStr str);
FXS_API unsigned int fxs__dstr_ptr_cap(const FXS_DStr *str);
FXS_API unsigned int fxs__strbuf_cap(const FXS_StrBuf str);
FXS_API unsigned int fxs__strbuf_ptr_cap(const FXS_StrBuf *str);
FXS_API unsigned int fxs__buf_cap(const FXS_Buffer buf);
FXS_API unsigned int fxs__mutstr_ref_cap(const FXS_MutStrRef str);
FXS_API unsigned int fxs__mutstr_ref_len(const FXS_MutStrRef str);

FXS_API unsigned char fxs__cstr_char_at(const char *str, unsigned int idx);
FXS_API unsigned char fxs__ucstr_char_at(const unsigned char *str, unsigned int idx);
FXS_API unsigned char fxs__dstr_char_at(const FXS_DStr str, unsigned int idx);
FXS_API unsigned char fxs__dstr_ptr_char_at(const FXS_DStr *str, unsigned int idx);
FXS_API unsigned char fxs__strv_char_at(const FXS_StrView str, unsigned int idx);
FXS_API unsigned char fxs__strbuf_char_at(const FXS_StrBuf str, unsigned int idx);
FXS_API unsigned char fxs__strbuf_ptr_char_at(const FXS_StrBuf *str, unsigned int idx);
FXS_API unsigned char fxs__mutstr_ref_char_at(const FXS_MutStrRef str, unsigned int idx);

FXS_API bool fxs__is_strv_within(FXS_StrView base, FXS_StrView sub);

FXS__NODISCARD("discarding a new DString may cause a memory leak")
FXS_API FXS_DStr fxs__dstr_init(unsigned int cap, FXS_Allocator *allocator);
FXS__NODISCARD("discarding a new DString may cause a memory leak")
FXS_API FXS_DStr fxs__dstr_init_from(FXS_StrView from, FXS_Allocator *allocator);
FXS_API void fxs__dstr_deinit(FXS_DStr *dstr);
FXS_API FXS_Error fxs__dstr_append(FXS_DStr *dstr, const FXS_StrView str);
FXS_API FXS_Error fxs__dstr_prepend_strv(FXS_DStr *dstr, const FXS_StrView str);
FXS_API FXS_Error fxs__dstr_insert(FXS_DStr *dstr, const FXS_StrView str, unsigned int idx);
FXS_API FXS_Error fxs__dstr_fread_line(FXS_DStr *dstr, FILE *stream);
FXS_API FXS_Error fxs__dstr_append_fread_line(FXS_DStr *dstr, FILE *stream);
FXS_API FXS_Error fxs__dstr_shrink_to_fit(FXS_DStr *dstr);
FXS_API FXS_Error fxs__dstr_ensure_cap(FXS_DStr *dstr, unsigned int at_least);

FXS_API FXS_Error fxs__mutstr_ref_putc(FXS_MutStrRef dst, unsigned char c);
FXS_API FXS_Error fxs__mutstr_ref_copy(FXS_MutStrRef dst, const FXS_StrView src);
FXS_API FXS_Error fxs__mutstr_ref_append(FXS_MutStrRef dst, const FXS_StrView src);
FXS_API FXS_Error fxs__mutstr_ref_delete_range(FXS_MutStrRef str, unsigned int begin, unsigned int end);
FXS_API FXS_Error fxs__mutstr_ref_insert(FXS_MutStrRef dst, const FXS_StrView src, unsigned int idx);
FXS_API FXS_ReplaceResult fxs__mutstr_ref_replace(FXS_MutStrRef str, const FXS_StrView target, const FXS_StrView replacement);
FXS_API FXS_Error fxs__mutstr_ref_replace_first(FXS_MutStrRef str, const FXS_StrView target, const FXS_StrView replacement);
FXS_API FXS_Error fxs__mutstr_ref_replace_range(FXS_MutStrRef str, unsigned int begin, unsigned int end, const FXS_StrView replacement);
FXS_API FXS_Error fxs__mutstr_ref_clear(FXS_MutStrRef str);
FXS_API FXS_Error fxs__strv_arr_join(FXS_MutStrRef dst, FXS_StrViewArray strs, FXS_StrView delim);

FXS_API FXS_Error fxs__fmutstr_ref_putc(FXS__FixedMutStrRef dst, unsigned char c);
FXS_API FXS_Error fxs__fmutstr_ref_copy(FXS__FixedMutStrRef dst, const FXS_StrView src);
FXS_API FXS_Error fxs__fmutstr_ref_append(FXS__FixedMutStrRef dst, const FXS_StrView src);
FXS_API FXS_Error fxs__fmutstr_ref_delete_range(FXS__FixedMutStrRef str, unsigned int begin, unsigned int end);
FXS_API FXS_Error fxs__fmutstr_ref_insert(FXS__FixedMutStrRef dst, const FXS_StrView src, unsigned int idx);
FXS_API FXS_ReplaceResult fxs__fmutstr_ref_replace(FXS__FixedMutStrRef str, const FXS_StrView target, const FXS_StrView replacement);
FXS_API FXS_Error fxs__fmutstr_ref_replace_first(FXS__FixedMutStrRef str, const FXS_StrView target, const FXS_StrView replacement);
FXS_API FXS_Error fxs__fmutstr_ref_replace_range(FXS__FixedMutStrRef str, unsigned int begin, unsigned int end, const FXS_StrView replacement);
FXS_API FXS_Error fxs__fmutstr_ref_clear(FXS__FixedMutStrRef str);
FXS_API FXS_Error fxs__strv_arr_join_into_fmutstr_ref(FXS__FixedMutStrRef dst, const FXS_StrViewArray strs, const FXS_StrView delim);

FXS_API FXS_Error fxs__dstr_putc(FXS_DStr *dst, unsigned char c);
FXS_API FXS_Error fxs__dstr_copy(FXS_DStr *dstr, const FXS_StrView src);
FXS_API FXS_ReplaceResult fxs__dstr_replace(FXS_DStr *dstr, const FXS_StrView target, const FXS_StrView replacement);
FXS_API FXS_Error fxs__dstr_replace_first(FXS_DStr *dstr, const FXS_StrView target, const FXS_StrView replacement);
FXS_API FXS_Error fxs__dstr_replace_range(FXS_DStr *dstr, unsigned int begin, unsigned int end, const FXS_StrView replacement);
FXS_API FXS_Error fxs__strv_arr_join_into_dstr(FXS_DStr *dstr, const FXS_StrViewArray strs, const FXS_StrView delim);

FXS__NODISCARD("str_split returns a heap allocated array")
FXS_API FXS_StrViewArray fxs__strv_split(const FXS_StrView str, const FXS_StrView delim, FXS_Allocator* allocator);
FXS_API FXS_Error fxs__strv_split_iter(const FXS_StrView str, const FXS_StrView delim, bool(*cb)(FXS_StrView found, void *ctx), void *ctx);

FXS_API FXS_StrViewArray fxs__strv_arr_from_carr(const FXS_StrView *carr, unsigned int nb);

FXS_API bool fxs__strv_equal(const FXS_StrView str1, const FXS_StrView str2);
FXS_API FXS_StrView fxs__strv_find(const FXS_StrView hay, const FXS_StrView needle);
FXS_API unsigned int fxs__strv_count(const FXS_StrView hay, const FXS_StrView needle);
FXS_API bool fxs__strv_starts_with(const FXS_StrView hay, const FXS_StrView needle);
FXS_API bool fxs__strv_ends_with(const FXS_StrView hay, const FXS_StrView needle);

FXS_API void fxs__chars_tolower(FXS_StrView str);
FXS_API void fxs__chars_toupper(FXS_StrView str);

FXS_API FXS_Error fxs__mutstr_ref_fread_line(FXS_MutStrRef dst, FILE *stream);
FXS_API FXS_Error fxs__mutstr_ref_append_fread_line(FXS_MutStrRef dst, FILE *stream);

FXS_API FXS_Error fxs__fmutstr_ref_fread_line(FXS__FixedMutStrRef dst, FILE *stream);
FXS_API FXS_Error fxs__fmutstr_ref_append_fread_line(FXS__FixedMutStrRef dst, FILE *stream);

FXS_API unsigned int fxs__fprint_strv(FILE *stream, const FXS_StrView str);
FXS_API unsigned int fxs__fprintln_strv(FILE *stream, const FXS_StrView str);

FXS_API FXS_Error fxs__bool_tostr(FXS_MutStrRef dst, bool obj);
FXS_API FXS_Error fxs__cstr_tostr(FXS_MutStrRef dst, const char *obj);
FXS_API FXS_Error fxs__ucstr_tostr(FXS_MutStrRef dst, const unsigned char *obj);
FXS_API FXS_Error fxs__char_tostr(FXS_MutStrRef dst, char obj);
FXS_API FXS_Error fxs__schar_tostr(FXS_MutStrRef dst, signed char obj);
FXS_API FXS_Error fxs__uchar_tostr(FXS_MutStrRef dst, unsigned char obj);
FXS_API FXS_Error fxs__short_tostr(FXS_MutStrRef dst, short obj);
FXS_API FXS_Error fxs__ushort_tostr(FXS_MutStrRef dst, unsigned short obj);
FXS_API FXS_Error fxs__int_tostr(FXS_MutStrRef dst, int obj);
FXS_API FXS_Error fxs__uint_tostr(FXS_MutStrRef dst, unsigned int obj);
FXS_API FXS_Error fxs__long_tostr(FXS_MutStrRef dst, long obj);
FXS_API FXS_Error fxs__ulong_tostr(FXS_MutStrRef dst, unsigned long obj);
FXS_API FXS_Error fxs__llong_tostr(FXS_MutStrRef dst, long long obj);
FXS_API FXS_Error fxs__ullong_tostr(FXS_MutStrRef dst, unsigned long long obj);
FXS_API FXS_Error fxs__float_tostr(FXS_MutStrRef dst, float obj);
FXS_API FXS_Error fxs__double_tostr(FXS_MutStrRef dst, double obj);

FXS_API FXS_Error fxs__dstr_tostr(FXS_MutStrRef dst, const FXS_DStr obj);
FXS_API FXS_Error fxs__dstr_ptr_tostr(FXS_MutStrRef dst, const FXS_DStr *obj);
FXS_API FXS_Error fxs__strv_tostr(FXS_MutStrRef dst, const FXS_StrView obj);
FXS_API FXS_Error fxs__strbuf_tostr(FXS_MutStrRef dst, const FXS_StrBuf obj);
FXS_API FXS_Error fxs__strbuf_ptr_tostr(FXS_MutStrRef dst, const FXS_StrBuf *obj);
FXS_API FXS_Error fxs__mutstr_ref_tostr(FXS_MutStrRef dst, const FXS_MutStrRef obj);

FXS_API FXS_Error fxs__error_tostr(FXS_MutStrRef dst, FXS_Error obj);
FXS_API FXS_Error fxs__array_fmt_tostr(FXS_MutStrRef dst, FXS_ArrayFmt obj);

FXS_API FXS_Error fxs__bool_tostr_p(FXS_MutStrRef dst, bool *obj);
FXS_API FXS_Error fxs__cstr_tostr_p(FXS_MutStrRef dst, const char **obj);
FXS_API FXS_Error fxs__ucstr_tostr_p(FXS_MutStrRef dst, const unsigned char **obj);
FXS_API FXS_Error fxs__char_tostr_p(FXS_MutStrRef dst, char *obj);
FXS_API FXS_Error fxs__schar_tostr_p(FXS_MutStrRef dst, signed char *obj);
FXS_API FXS_Error fxs__uchar_tostr_p(FXS_MutStrRef dst, unsigned char *obj);
FXS_API FXS_Error fxs__short_tostr_p(FXS_MutStrRef dst, short *obj);
FXS_API FXS_Error fxs__ushort_tostr_p(FXS_MutStrRef dst, unsigned short *obj);
FXS_API FXS_Error fxs__int_tostr_p(FXS_MutStrRef dst, int *obj);
FXS_API FXS_Error fxs__uint_tostr_p(FXS_MutStrRef dst, unsigned int *obj);
FXS_API FXS_Error fxs__long_tostr_p(FXS_MutStrRef dst, long *obj);
FXS_API FXS_Error fxs__ulong_tostr_p(FXS_MutStrRef dst, unsigned long *obj);
FXS_API FXS_Error fxs__llong_tostr_p(FXS_MutStrRef dst, long long *obj);
FXS_API FXS_Error fxs__ullong_tostr_p(FXS_MutStrRef dst, unsigned long long *obj);
FXS_API FXS_Error fxs__float_tostr_p(FXS_MutStrRef dst, float *obj);
FXS_API FXS_Error fxs__double_tostr_p(FXS_MutStrRef dst, double *obj);

FXS_API FXS_Error fxs__dstr_tostr_p(FXS_MutStrRef dst, const FXS_DStr *obj);
FXS_API FXS_Error fxs__dstr_ptr_tostr_p(FXS_MutStrRef dst, const FXS_DStr **obj);
FXS_API FXS_Error fxs__strv_tostr_p(FXS_MutStrRef dst, const FXS_StrView *obj);
FXS_API FXS_Error fxs__strbuf_tostr_p(FXS_MutStrRef dst, const FXS_StrBuf *obj);
FXS_API FXS_Error fxs__strbuf_ptr_tostr_p(FXS_MutStrRef dst, const FXS_StrBuf **obj);
FXS_API FXS_Error fxs__mutstr_ref_tostr_p(FXS_MutStrRef dst, const FXS_MutStrRef *obj);

FXS_API FXS_Error fxs__error_tostr_p(FXS_MutStrRef dst, FXS_Error *obj);
FXS_API FXS_Error fxs__array_fmt_tostr_p(FXS_MutStrRef dst, FXS_ArrayFmt *obj);

#define FXS__X(ty, extra) \
FXS_API FXS_Error fxs__Integer_d_Fmt_##ty##_tostr(FXS_MutStrRef dst, FXS__Integer_d_Fmt_##ty obj);    \
FXS_API FXS_Error fxs__Integer_x_Fmt_##ty##_tostr(FXS_MutStrRef dst, FXS__Integer_x_Fmt_##ty obj);    \
FXS_API FXS_Error fxs__Integer_o_Fmt_##ty##_tostr(FXS_MutStrRef dst, FXS__Integer_o_Fmt_##ty obj);    \
FXS_API FXS_Error fxs__Integer_b_Fmt_##ty##_tostr(FXS_MutStrRef dst, FXS__Integer_b_Fmt_##ty obj);    \
                                                                                                           \
FXS_API FXS_Error fxs__Integer_d_Fmt_##ty##_tostr_p(FXS_MutStrRef dst, FXS__Integer_d_Fmt_##ty *obj); \
FXS_API FXS_Error fxs__Integer_x_Fmt_##ty##_tostr_p(FXS_MutStrRef dst, FXS__Integer_x_Fmt_##ty *obj); \
FXS_API FXS_Error fxs__Integer_o_Fmt_##ty##_tostr_p(FXS_MutStrRef dst, FXS__Integer_o_Fmt_##ty *obj); \
FXS_API FXS_Error fxs__Integer_b_Fmt_##ty##_tostr_p(FXS_MutStrRef dst, FXS__Integer_b_Fmt_##ty *obj);

FXS__INTEGER_TYPES(FXS__X, ignore)

#undef FXS__X

#define FXS__X(ty, extra) \
FXS_API FXS_Error fxs__Floating_f_Fmt_##ty##_tostr(FXS_MutStrRef dst, FXS__Floating_f_Fmt_##ty obj);    \
FXS_API FXS_Error fxs__Floating_g_Fmt_##ty##_tostr(FXS_MutStrRef dst, FXS__Floating_g_Fmt_##ty obj);    \
FXS_API FXS_Error fxs__Floating_e_Fmt_##ty##_tostr(FXS_MutStrRef dst, FXS__Floating_e_Fmt_##ty obj);    \
FXS_API FXS_Error fxs__Floating_a_Fmt_##ty##_tostr(FXS_MutStrRef dst, FXS__Floating_a_Fmt_##ty obj);    \
                                                                                                        \
FXS_API FXS_Error fxs__Floating_f_Fmt_##ty##_tostr_p(FXS_MutStrRef dst, FXS__Floating_f_Fmt_##ty *obj); \
FXS_API FXS_Error fxs__Floating_g_Fmt_##ty##_tostr_p(FXS_MutStrRef dst, FXS__Floating_g_Fmt_##ty *obj); \
FXS_API FXS_Error fxs__Floating_e_Fmt_##ty##_tostr_p(FXS_MutStrRef dst, FXS__Floating_e_Fmt_##ty *obj); \
FXS_API FXS_Error fxs__Floating_a_Fmt_##ty##_tostr_p(FXS_MutStrRef dst, FXS__Floating_a_Fmt_##ty *obj);

FXS__FLOATING_TYPES(FXS__X, ignore, FXS__X)

#undef FXS__X

#endif /* FXS__STR_H_INCLUDED */

#ifdef FXS_SHORT_NAMES

typedef FXS_Allocator             Allocator;
typedef FXS_DStr                  DStr;
typedef FXS_StrBuf                StrBuf;
typedef FXS_StrView               StrView;
typedef FXS_StrViewArray          StrViewArray;
typedef FXS_MutStrRef             MutStrRef;
typedef FXS_ReplaceResult         ReplaceResult;
typedef FXS_StrAppenderState      StrAppenderState;
typedef FXS_ArrayFmt              ArrayFmt;

#define str_view(anystr, ...) fxs_str_view(anystr __VA_OPT__(,) __VA_ARGS__)
#define str_view_arr(...) fxs_str_view_arr(__VA_ARGS__)
#define str_view_arr_from_carr(...) fxs_str_view_arr_from_carr(arr __VA_OPT__(,) __VA_ARGS__)

#define strbuf_init_from_cstr(cstr, ...) fxs_strbuf_init_from_cstr(cstr __VA_OPT__(,) __VA_ARGS__)
#define strbuf_init_from_buf(buf, ...) fxs_strbuf_init_from_buf(buf __VA_OPT__(,) __VA_ARGS__)

#define dstr_init(...) fxs_dstr_init(__VA_ARGS__)
#define dstr_init_from(anystr, ...) fxs_dstr_init_from(anystr __VA_OPT__(,) __VA_ARGS__)
#define dstr_deinit(dstr) fxs_dstr_deinit(dstr);

#define mutstr_ref(mutstr, ...) fxs_mutstr_ref(mutstr __VA_OPT__(,) __VA_ARGS__)

#define dstr_append(dstr, anystr) fxs_dstr_append(dstr, anystr)
#define dstr_prepend(dstr, anystr) fxs_dstr_prepend(dstr, anystr)
#define dstr_insert(dstr, anystr, idx) fxs_dstr_insert(dstr, anystr, idx)
#define dstr_fread_line(dstr, stream) fxs_dstr_fread_line(dstr, stream)
#define dstr_read_line(dstr) fxs_dstr_read_line(dstr)
#define dstr_append_fread_line(dstr, stream) fxs_dstr_append_fread_line(dstr, stream)
#define dstr_append_read_line(dstr) fxs_dstr_append_read_line(dstr)
#define dstr_shrink_to_fit(dstr) fxs_dstr_shrink_to_fit(dstr)
#define dstr_ensure_cap(dstr, new_cap) fxs_dstr_ensure_cap(dstr, new_cap)


#define tostr(dst, src) fxs_tostr(dst, src)
#define tostr_p(dst, srcp) fxs_tostr_p(dst, srcp)
#define has_tostr(T) fxs_has_tostr(T)

#define print(...) fxs_print(__VA_ARGS__)
#define println(...) fxs_println(__VA_ARGS__)
#define fprint(stream, ...) fxs_fprint(stream, __VA_ARGS__)
#define fprintln(stream, ...) fxs_fprintln(stream, __VA_ARGS__)

#define tsfmt(exp, fmt_char, ...) fxs_tsfmt(exp, fmt_char __VA_OPT__(,) __VA_ARGS__)
#define tsfmt_t(T, fmt_char, ...) fxs_tsfmt_t(T, fmt_char __VA_OPT__(,) __VA_ARGS__)
#define arrfmt(arr, n, ...) fxs_arrfmt(arr, n, __VA_ARGS__)

#endif

#if defined(ADD_TOSTR)

_Static_assert( fxs__has_type(fxs__get_tostr_func_ft(FXS__ARG1 ADD_TOSTR), fxs__tostr_fail), "Type already has a tostr" );

#if !defined(FXS__TOSTR1)
#define FXS__TOSTR1
FXS__DECL_TOSTR_FUNC(1)
#elif !defined(FXS__TOSTR2)
#define FXS__TOSTR2
FXS__DECL_TOSTR_FUNC(2)
#elif !defined(FXS__TOSTR3)
#define FXS__TOSTR3
FXS__DECL_TOSTR_FUNC(3)
#elif !defined(FXS__TOSTR4)
#define FXS__TOSTR4
FXS__DECL_TOSTR_FUNC(4)
#elif !defined(FXS__TOSTR5)
#define FXS__TOSTR5
FXS__DECL_TOSTR_FUNC(5)
#elif !defined(FXS__TOSTR6)
#define FXS__TOSTR6
FXS__DECL_TOSTR_FUNC(6)
#elif !defined(FXS__TOSTR7)
#define FXS__TOSTR7
FXS__DECL_TOSTR_FUNC(7)
#elif !defined(FXS__TOSTR8)
#define FXS__TOSTR8
FXS__DECL_TOSTR_FUNC(8)
#elif !defined(FXS__TOSTR9)
#define FXS__TOSTR9
FXS__DECL_TOSTR_FUNC(9)
#elif !defined(FXS__TOSTR10)
#define FXS__TOSTR10
FXS__DECL_TOSTR_FUNC(10)
#elif !defined(FXS__TOSTR11)
#define FXS__TOSTR11
FXS__DECL_TOSTR_FUNC(11)
#elif !defined(FXS__TOSTR12)
#define FXS__TOSTR12
FXS__DECL_TOSTR_FUNC(12)
#elif !defined(FXS__TOSTR13)
#define FXS__TOSTR13
FXS__DECL_TOSTR_FUNC(13)
#elif !defined(FXS__TOSTR14)
#define FXS__TOSTR14
FXS__DECL_TOSTR_FUNC(14)
#elif !defined(FXS__TOSTR15)
#define FXS__TOSTR15
FXS__DECL_TOSTR_FUNC(15)
#elif !defined(FXS__TOSTR16)
#define FXS__TOSTR16
FXS__DECL_TOSTR_FUNC(16)
#elif !defined(FXS__TOSTR17)
#define FXS__TOSTR17
FXS__DECL_TOSTR_FUNC(17)
#elif !defined(FXS__TOSTR18)
#define FXS__TOSTR18
FXS__DECL_TOSTR_FUNC(18)
#elif !defined(FXS__TOSTR19)
#define FXS__TOSTR19
FXS__DECL_TOSTR_FUNC(19)
#elif !defined(FXS__TOSTR20)
#define FXS__TOSTR20
FXS__DECL_TOSTR_FUNC(20)
#elif !defined(FXS__TOSTR21)
#define FXS__TOSTR21
FXS__DECL_TOSTR_FUNC(21)
#elif !defined(FXS__TOSTR22)
#define FXS__TOSTR22
FXS__DECL_TOSTR_FUNC(22)
#elif !defined(FXS__TOSTR23)
#define FXS__TOSTR23
FXS__DECL_TOSTR_FUNC(23)
#elif !defined(FXS__TOSTR24)
#define FXS__TOSTR24
FXS__DECL_TOSTR_FUNC(24)
#elif !defined(FXS__TOSTR25)
#define FXS__TOSTR25
FXS__DECL_TOSTR_FUNC(25)
#elif !defined(FXS__TOSTR26)
#define FXS__TOSTR26
FXS__DECL_TOSTR_FUNC(26)
#elif !defined(FXS__TOSTR27)
#define FXS__TOSTR27
FXS__DECL_TOSTR_FUNC(27)
#elif !defined(FXS__TOSTR28)
#define FXS__TOSTR28
FXS__DECL_TOSTR_FUNC(28)
#elif !defined(FXS__TOSTR29)
#define FXS__TOSTR29
FXS__DECL_TOSTR_FUNC(29)
#elif !defined(FXS__TOSTR30)
#define FXS__TOSTR30
FXS__DECL_TOSTR_FUNC(30)
#elif !defined(FXS__TOSTR31)
#define FXS__TOSTR31
FXS__DECL_TOSTR_FUNC(31)
#elif !defined(FXS__TOSTR32)
#define FXS__TOSTR32
FXS__DECL_TOSTR_FUNC(32)
#else
#error "Maximum number of tostr functions is 32"
#endif

#undef ADD_TOSTR

#endif
