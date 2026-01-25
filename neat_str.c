#include <ctype.h>
#define NEAT_STR_PREFIX
#include "neat_str.h"

#define check_type(x, T, e, fallback) \
_Generic(x, T: e, default: fallback)

#define fmutstr_ref(s, ...)                                                                \
_Generic(s,                                                                                \
    Neat_DString*       : neat__dstr_as_fmutstr_ref(neat__coerce(s, Neat_DString*)),         \
    Neat_Buffer         : neat__buf_as_fmutstr_ref(neat__coerce(s, Neat_Buffer), NEAT__VA_OR(check_type(s, Neat_Buffer, (struct neat_fail_type){0}, 0), __VA_ARGS__)), \
    Neat_String_Buffer* : neat__strbuf_as_fmutstr_ref(neat__coerce(s, Neat_String_Buffer*)), \
    Neat_SString_Ref    : neat__sstr_ref_as_fmutstr_ref(neat__coerce(s, Neat_SString_Ref))   \
)

static const Neat_String_View error_to_string[] = {
    [NEAT_OK]                     = {.len = sizeof(u8"OK")                     - 1, .chars = u8"OK"},
    [NEAT_DST_TOO_SMALL]          = {.len = sizeof(u8"DST_TOO_SMALL")          - 1, .chars = u8"DST_TOO_SMALL"},
    [NEAT_ALLOC_ERR]              = {.len = sizeof(u8"ALLOC_ERR")              - 1, .chars = u8"ALLOC_ERR"},
    [NEAT_INDEX_OUT_OF_BOUNDS]    = {.len = sizeof(u8"INDEX_OUT_OF_BOUNDS")    - 1, .chars = u8"INDEX_OUT_OF_BOUNDS"},
    [NEAT_BAD_RANGE]              = {.len = sizeof(u8"BAD_RANGE")              - 1, .chars = u8"BAD_RANGE"},
    [NEAT_NOT_FOUND]              = {.len = sizeof(u8"NOT_FOUND")              - 1, .chars = u8"NOT_FOUND"},
    [NEAT_UTF8_ERR]               = {.len = sizeof(u8"UTF8_ERR")               - 1, .chars = u8"UTF8_ERR"},
    [NEAT_ALIASING_NOT_SUPPORTED] = {.len = sizeof(u8"ALIASING_NOT_SUPPORTED") - 1, .chars = u8"ALIASING_NOT_SUPPORTED"},
    [NEAT_INCORRECT_TYPE]         = {.len = sizeof(u8"INCORRECT_TYPE")         - 1, .chars = u8"INCORRECT_TYPE"},
};

static const long long ten_pows[] = {
    1,
    10,
    100,
    1000,
    10000,
    100000,
    1000000,
    10000000,
    100000000,
    1000000000,
    10000000000,
    100000000000,
    1000000000000,
    10000000000000,
    100000000000000,
    1000000000000000,
    10000000000000000,
    100000000000000000,
    1000000000000000000,
};

static const unsigned long long ten_pows_ull[] = {
    1ull,
    10ull,
    100ull,
    1000ull,
    10000ull,
    100000ull,
    1000000ull,
    10000000ull,
    100000000ull,
    1000000000ull,
    10000000000ull,
    100000000000ull,
    1000000000000ull,
    10000000000000ull,
    100000000000000ull,
    1000000000000000ull,
    10000000000000000ull,
    100000000000000000ull,
    1000000000000000000ull,
    10000000000000000000ull,
};

// TODO IDEA: for optimization reasons, maybe have this type in the header (but Neat__ prefix), and in the _Generic macros, turn non-DStrings into fmutstr_refs and call the fmutstr_ref functions
typedef struct Fixed_Mut_String_Ref
{
    unsigned char *chars;
    unsigned int *len;
    unsigned int cap;
} Fixed_Mut_String_Ref;

typedef struct Neat_DString_Append_Allocator
{
    Neat_Allocator funcs;
    struct Neat_DString *owner;
} Neat_DString_Append_Allocator;

const Neat_String_View neat_error_string(Neat_Error err)
{
    return error_to_string[err];
}

Fixed_Mut_String_Ref neat__buf_as_fmutstr_ref(Neat_Buffer buf, unsigned int *len_ptr)
{
    *len_ptr = strlen((char*) buf.ptr);
    Fixed_Mut_String_Ref ret = {
        .chars = buf.ptr,
        .cap = buf.cap,
        .len = len_ptr
    };
    return ret;
}

Fixed_Mut_String_Ref neat__sstr_ref_as_fmutstr_ref(Neat_SString_Ref sstr_ref)
{
    Fixed_Mut_String_Ref ret = {
        .chars = sstr_ref.sstr->chars,
        .cap = sstr_ref.cap,
        .len = &sstr_ref.sstr->len
    };
    return ret;
}

Fixed_Mut_String_Ref neat__strbuf_as_fmutstr_ref(Neat_String_Buffer *strbuf)
{
    Fixed_Mut_String_Ref ret = {
        .chars = strbuf->chars,
        .cap = strbuf->cap,
        .len = &strbuf->len
    };
    return ret;
}

Fixed_Mut_String_Ref neat__dstr_as_fmutstr_ref(Neat_DString *dstr)
{
    Fixed_Mut_String_Ref ret = {
        .chars = dstr->chars,
        .cap = dstr->cap,
        .len = &dstr->len
    };
    return ret;
}

Neat_Allocation neat__default_allocator_alloc(Neat_Allocator *ctx, size_t alignment, size_t n)
{
    (void) alignment;
    (void) ctx;
    void *mem = malloc(n);
    return (Neat_Allocation){
        .ptr = mem,
        .n = n
    };
}

void neat__default_allocator_dealloc(Neat_Allocator *ctx, void *ptr, size_t n)
{
    (void) ctx;
    (void) n;
    free(ptr);
}

Neat_Allocation neat__default_allocator_realloc(Neat_Allocator *ctx, void *ptr, size_t alignment, size_t old_size, size_t new_size)
{
    (void) ctx;
    (void) alignment;
    (void) old_size;
    void *mem = realloc(ptr, new_size);
    return (Neat_Allocation){
        .ptr = mem,
        .n = new_size
    };
}

Neat_Allocation neat__dstr_append_allocator_alloc(Neat_Allocator *allocator, size_t alignment, size_t n)
{
    assert(0); // this should never get called
    (void) allocator;
    (void) alignment;
    (void) n;
    return (Neat_Allocation){0};
}

void neat__dstr_append_allocator_dealloc(Neat_Allocator *allocator, void *ptr, size_t n)
{
    assert(0); // this should never get called
    (void) allocator;
    (void) ptr;
    (void) n;
}

Neat_Allocation neat__dstr_append_allocator_realloc(Neat_Allocator *allocator, void *ptr, size_t alignment, size_t old_size, size_t new_size)
{
    (void) alignment;
    
    Neat_DString_Append_Allocator *dstr_append_allocator = (typeof(dstr_append_allocator)) allocator;
    
    Neat_DString *owner = dstr_append_allocator->owner;
    
    assert(old_size == owner->cap - owner->len);
    assert(((unsigned char*)ptr - owner->chars) == owner->len);
    
    neat_dstr_ensure_cap(owner, owner->cap + (new_size - old_size));
    return (Neat_Allocation){
        .ptr = owner->chars + owner->len,
        .n = owner->cap - owner->len
    };
}

Neat_Allocation neat__allocator_invoke_alloc(Neat_Allocator *allocator, size_t alignment, size_t obj_size, size_t nb)
{
    return allocator->alloc(allocator, alignment, nb * obj_size);
}

void neat__allocator_invoke_dealloc(Neat_Allocator *allocator, void *ptr, size_t obj_size, size_t nb)
{
    allocator->dealloc(allocator, ptr, nb * obj_size);
}

Neat_Allocation neat__allocator_invoke_realloc(Neat_Allocator *allocator, void *ptr, size_t alignment, size_t obj_size, size_t old_nb, size_t new_nb)
{
    return allocator->realloc(allocator, ptr, alignment, old_nb * obj_size, new_nb * obj_size);
}

static Neat_Allocator default_allocator = {
    .alloc   = neat__default_allocator_alloc,
    .dealloc = neat__default_allocator_dealloc,
    .realloc = neat__default_allocator_realloc,
};

Neat_Allocator *neat_get_default_allocator()
{
    return &default_allocator;
}


void neat__make_dstr_append_allocator(Neat_DString *dstr, Neat_DString_Append_Allocator *out)
{
    *out = (Neat_DString_Append_Allocator){
        .funcs = {
            .alloc   = neat__dstr_append_allocator_alloc,
            .dealloc = neat__dstr_append_allocator_dealloc,
            .realloc = neat__dstr_append_allocator_realloc,
        },
        .owner = dstr
    };
}

static Neat_DString neat__make_appender_dstr(Neat_DString *owner, Neat_DString_Append_Allocator *allocator)
{
    neat__make_dstr_append_allocator(owner, allocator);
    return (Neat_DString){
        .allocator = (void*) allocator,
        .cap = owner->cap - owner->len,
        .len = 0,
        .chars = owner->chars + owner->len
    };
}

Neat_String_Buffer neat__make_appender_strbuf(Neat_Mut_String_Ref owner)
{
    return (Neat_String_Buffer){
        .cap = neat_str_cap(owner) - neat_str_len(owner),
        .len = 0,
        .chars = (unsigned char*)neat_str_chars(owner) + neat_str_len(owner)
    };
}

Neat_Mut_String_Ref neat__make_appender_mutstr_ref(Neat_Mut_String_Ref owner, Neat_DString *appender_dstr_opt, Neat_DString_Append_Allocator *appender_dstr_allocator_opt, Neat_String_Buffer *appender_strbuf_opt)
{
    switch(owner.ty)
    {
        case NEAT_DSTR_TY    :
            *appender_dstr_opt = neat__make_appender_dstr(owner.str.dstr, appender_dstr_allocator_opt);
            return neat_mutstr_ref(appender_dstr_opt);
        case NEAT_STRBUF_TY  :
        case NEAT_SSTR_REF_TY:
        case NEAT_CARR_TY    :
            Neat_Mut_String_Ref ret = {0};
            ret.ty = NEAT_STRBUF_TY;
            ret.str.strbuf = appender_strbuf_opt;
            *ret.str.strbuf = neat__make_appender_strbuf(owner);
            return ret;
        default              :
            unreachable();
    }
}

static inline unsigned int neat__uint_min(unsigned int a, unsigned int b)
{
    return a < b ? a : b;
}

static inline unsigned int neat__uint_max(unsigned int a, unsigned int b)
{
    return a > b ? a : b;
}

static unsigned int neat__chars_strlen(const char *chars, unsigned int cap)
{
    char *str_end = memchr(chars, '\0', cap);
    unsigned int len;
    
    if(str_end != NULL)
    {
        len = str_end - chars;
    }
    else
    {
        len = cap - 1;
    }
    
    return len;
}

bool neat__is_strv_within(Neat_String_View base, Neat_String_View sub)
{
    uintptr_t begin = (uintptr_t) base.chars;
    uintptr_t end = (uintptr_t) (base.chars + base.len);
    uintptr_t sub_begin = (uintptr_t) sub.chars;
    return sub_begin >= begin && sub_begin < end;
}

NEAT_NODISCARD("discarding a new DString may cause memory leak") Neat_DString neat__dstr_init(unsigned int cap, Neat_Allocator *allocator)
{
    Neat_DString ret = { 0 };
    
    ret.allocator = allocator;
    size_t actual_allocated_cap = 0;
    
    if(cap > 0)
    {
        Neat_Allocation allocation = neat_alloc(allocator, unsigned char, cap + 1);
        ret.chars = allocation.ptr;
        actual_allocated_cap = allocation.n;
    }
    ret.cap = actual_allocated_cap;
    
    if(ret.chars != NULL && ret.cap > 0)
    {
        ret.chars[0] = '\0';
    }
    
    return ret;
}

Neat_DString neat__dstr_init_from(const Neat_String_View str, Neat_Allocator *allocator)
{
    Neat_DString ret = neat__dstr_init(str.len + 1, allocator);
    
    neat__dstr_copy(&ret, str);
    
    return ret;
}

void neat__dstr_deinit(Neat_DString *dstr)
{
    neat_dealloc(dstr->allocator, dstr->chars, unsigned char, dstr->cap);
    dstr->cap = 0;
    dstr->len = 0;
    dstr->chars = NULL;
}

void neat__dstr_shrink_to_fit(Neat_DString *dstr)
{
    Neat_Allocation allocation = neat_realloc(dstr->allocator, dstr->chars, unsigned char, dstr->cap, dstr->len + 1);
    dstr->chars = allocation.ptr;
    dstr->cap = allocation.n;
}

Neat_Error neat__dstr_maybe_grow(Neat_DString *dstr, unsigned int len_to_append)
{
    if(dstr->cap - dstr->len <= len_to_append)
    {
        // grow
        unsigned int new_cap = neat__uint_max(dstr->cap * 2, dstr->cap + len_to_append);
        
        Neat_Allocation allocation = neat_realloc(dstr->allocator, dstr->chars, unsigned char, dstr->cap, new_cap);
        dstr->chars = allocation.ptr;
        dstr->cap = allocation.n;
        
        if(dstr->chars == NULL || dstr->cap < new_cap)
        {
            return NEAT_ALLOC_ERR;
        }
    }
    
    return NEAT_OK;
}

Neat_Error neat__dstr_append_strv(Neat_DString *dstr, const Neat_String_View src)
{
    Neat_String_View to_append = src;
    Neat_Error err = NEAT_OK;
    if(neat__is_strv_within(neat__strv_dstr_ptr2(dstr, 0), to_append))
    {
        unsigned int begin_idx = to_append.chars - dstr->chars;
        err = neat__dstr_maybe_grow(dstr, to_append.len);
        to_append = (Neat_String_View){
            .len   = to_append.len,
            .chars = dstr->chars + begin_idx
        };
    }
    else
    {
        err = neat__dstr_maybe_grow(dstr, to_append.len);
    }
    
    if(err == NEAT_OK)
    {
        memmove(dstr->chars + dstr->len, to_append.chars, to_append.len * sizeof(unsigned char));
        
        dstr->len += to_append.len;
        dstr->chars[dstr->len] = '\0';
    }
    
    return err;
}

Neat_Error neat__dstr_prepend_strv(Neat_DString *dstr, const Neat_String_View src)
{
    Neat_String_View to_prepend = src;
    Neat_Error err = NEAT_OK;
    
    if(neat__is_strv_within(neat__strv_dstr_ptr2(dstr, 0), src))
    {
        unsigned int begin_idx = src.chars - dstr->chars;
        err = neat__dstr_maybe_grow(dstr, src.len);
        to_prepend = (Neat_String_View){
            .len = src.len, 
            .chars = dstr->chars + begin_idx
        };
    }
    else
    {
        err = neat__dstr_maybe_grow(dstr, to_prepend.len);
    }
    
    if(err == NEAT_OK)
    {
        memmove(dstr->chars + to_prepend.len, dstr->chars, dstr->len);
        memmove(dstr->chars, to_prepend.chars, to_prepend.len);
        
        dstr->len += to_prepend.len;
        dstr->chars[dstr->len] = '\0';
    }
    
    return err;
}

Neat_Error neat_dstr_insert_strv(Neat_DString *dstr, const Neat_String_View src, unsigned int idx)
{
    if(idx > dstr->len)
    {
        return NEAT_INDEX_OUT_OF_BOUNDS;
    }
    
    Neat_String_View to_insert = src;
    
    if(neat__is_strv_within(neat__strv_dstr_ptr2(dstr, 0), src))
    {
        unsigned int begin_idx = src.chars - dstr->chars;
        neat__dstr_maybe_grow(dstr, src.len);
        to_insert = (Neat_String_View){
            .len = src.len, 
            .chars = dstr->chars + begin_idx
        };
    }
    else
    {
        neat__dstr_maybe_grow(dstr, to_insert.len);
    }
    
    memmove(dstr->chars + idx + to_insert.len, dstr->chars + idx, dstr->len - idx);
    memmove(dstr->chars + idx, to_insert.chars, to_insert.len);
    
    dstr->len += to_insert.len;
    dstr->chars[dstr->len] = '\0';
    
    return true;
}

Neat_Error neat__dstr_ensure_cap(Neat_DString *dstr, unsigned int at_least)
{
    if(dstr->cap < at_least)
    {
        size_t actual_allocated_cap;
        unsigned char *save = dstr->chars;
        Neat_Allocation allocation = neat_realloc(dstr->allocator, dstr->chars, unsigned char, dstr->cap, at_least);
        dstr->chars = allocation.ptr;
        dstr->cap = actual_allocated_cap;
        
        if(dstr->chars == NULL)
        {
            dstr->chars = save;
            return NEAT_ALLOC_ERR;
        }
        if(dstr->cap < at_least)
        {
            return NEAT_ALLOC_ERR;
        }
    }
    
    return NEAT_OK;
}

char *neat__cstr_as_cstr(const char *str)
{
    return (char*) str;
}

char *neat__ucstr_as_cstr(const unsigned char *str)
{
    return (char*) str;
}

char *neat__dstr_as_cstr(const Neat_DString str)
{
    return (char*) str.chars;
}

char *neat__dstr_ptr_as_cstr(const Neat_DString *str)
{
    return (char*) str->chars;
}

char *neat__strv_as_cstr(const Neat_String_View str)
{
    return (char*) str.chars;
}

char *neat__strv_ptr_as_cstr(const Neat_String_View *str)
{
    return (char*) str->chars;
}

char *neat__strbuf_as_cstr(const Neat_String_Buffer str)
{
    return (char*) str.chars;
}

char *neat__strbuf_ptr_as_cstr(const Neat_String_Buffer *str)
{
    return (char*) str->chars;
}

char *neat__sstr_ref_as_cstr(const Neat_SString_Ref str)
{
    return (char*) str.sstr->chars;
}

char *neat__mutstr_ref_as_cstr(const Neat_Mut_String_Ref str)
{
    switch(str.ty)
    {
        case NEAT_DSTR_TY     : return (char*) str.str.dstr->chars;
        case NEAT_STRBUF_TY   : return (char*) str.str.strbuf->chars;
        case NEAT_SSTR_REF_TY : return (char*) str.str.sstr_ref.sstr->chars;
        case NEAT_CARR_TY     : return (char*) str.str.carr.ptr;
        default               : unreachable();
    };
}

unsigned char neat__cstr_char_at(const char *str, unsigned int idx)
{
    return str[idx];
}

unsigned char neat__ucstr_char_at(const unsigned char *str, unsigned int idx)
{
    return str[idx];
}

unsigned char neat__dstr_char_at(const Neat_DString str, unsigned int idx)
{
    return str.chars[idx];
}

unsigned char neat__dstr_ptr_char_at(const Neat_DString *str, unsigned int idx)
{
    return str->chars[idx];
}

unsigned char neat__strv_char_at(const Neat_String_View str, unsigned int idx)
{
    return str.chars[idx];
}

unsigned char neat__strv_ptr_char_at(const Neat_String_View *str, unsigned int idx)
{
    return str->chars[idx];
}

unsigned char neat__strbuf_char_at(const Neat_String_Buffer str, unsigned int idx)
{
    return str.chars[idx];
}

unsigned char neat_strbuf_ptr_char_at(const Neat_String_Buffer *str, unsigned int idx)
{
    return str->chars[idx];
}

unsigned char neat_sstr_ref_char_at(const Neat_SString_Ref str, unsigned int idx)
{
    return str.sstr->chars[idx];
}

unsigned char neat_mutstr_ref_char_at(const Neat_Mut_String_Ref str, unsigned int idx)
{
    return neat__mutstr_ref_as_cstr(str)[idx];
}

Neat_Error neat_mutstr_ref_set_len(Neat_Mut_String_Ref str, size_t new_len)
{
    switch(str.ty)
    {
        case NEAT_DSTR_TY     :
            str.str.dstr->len = new_len;
            assert(str.str.dstr->cap >= str.str.dstr->len);
            break;
        case NEAT_STRBUF_TY   :
            str.str.strbuf->len = new_len;
            assert(str.str.strbuf->cap >= str.str.strbuf->len);
            break;
        case NEAT_SSTR_REF_TY :
            str.str.sstr_ref.sstr->len = new_len;
            assert(str.str.sstr_ref.cap >= str.str.sstr_ref.sstr->len);
            break;
        case NEAT_CARR_TY     :
            return NEAT_INCORRECT_TYPE;
        default               :
            unreachable();
    };
    return NEAT_OK;
}

unsigned int neat_dstr_cap(const Neat_DString str)
{
    return str.cap;
}

unsigned int neat_dstr_ptr_cap(const Neat_DString *str)
{
    return str->cap;
}

unsigned int neat_strbuf_cap(const Neat_String_Buffer str)
{
    return str.cap;
}

unsigned int neat_strbuf_ptr_cap(const Neat_String_Buffer *str)
{
    return str->cap;
}

unsigned int neat_sstr_ref_cap(const Neat_SString_Ref str)
{
    return str.cap;
}

unsigned int neat_buf_cap(const Neat_Buffer buf)
{
    return buf.cap;
}

unsigned int neat_mutstr_ref_cap(const Neat_Mut_String_Ref str)
{
    switch(str.ty)
    {
        case NEAT_DSTR_TY     : return str.str.dstr->cap;
        case NEAT_STRBUF_TY   : return str.str.strbuf->cap;
        case NEAT_SSTR_REF_TY : return str.str.sstr_ref.cap;
        case NEAT_CARR_TY     : return str.str.carr.cap;
        default               : unreachable();
    };
}

Neat_Error neat_fmutstr_ref_insert(Fixed_Mut_String_Ref dst, const Neat_String_View src, unsigned int idx)
{
    unsigned int len = *dst.len;
    if(idx > len)
    {
        return NEAT_INDEX_OUT_OF_BOUNDS;
    }
    
    unsigned int nb_chars_to_insert = neat__uint_min(dst.cap - len - 1, src.len);
    
    // shift right
    memmove(dst.chars + idx + nb_chars_to_insert, dst.chars + idx, len - idx);
    
    // insert the src
    memmove(dst.chars + idx, src.chars, nb_chars_to_insert);
    
    len += nb_chars_to_insert;
    
    *dst.len = len;
    
    return nb_chars_to_insert == src.len ? NEAT_OK : NEAT_DST_TOO_SMALL;
}

Neat_Error neat_mutstr_ref_insert(Neat_Mut_String_Ref dst, const Neat_String_View src, unsigned int idx)
{
    switch(dst.ty)
    {
        case NEAT_DSTR_TY     : return neat_dstr_insert_strv(dst.str.dstr, src, idx);
        case NEAT_STRBUF_TY   : return neat_fmutstr_ref_insert(fmutstr_ref(dst.str.strbuf), src, idx);
        case NEAT_SSTR_REF_TY : return neat_fmutstr_ref_insert(fmutstr_ref(dst.str.sstr_ref), src, idx);
        case NEAT_CARR_TY     : return neat_fmutstr_ref_insert(fmutstr_ref(dst.str.carr, &(unsigned int){0}), src, idx);
        default               : unreachable();
    };
}

bool neat_strv_equal(const Neat_String_View str1, const Neat_String_View str2)
{
    return
    (str1.len == str2.len) &&
    (memcmp(str1.chars, str2.chars, str1.len) == 0);
}

Neat_String_View neat__strv_find(const Neat_String_View hay, const Neat_String_View needle)
{
    if(hay.chars == NULL || needle.chars == NULL || hay.len == 0 || needle.len > hay.len)
        return (Neat_String_View){.chars = NULL, .len = 0};
    if(needle.len == 0)
        return (Neat_String_View){.chars = hay.chars, .len = 0};
    
    unsigned char *max_possible_ptr = &hay.chars[hay.len] - needle.len;
    unsigned char *first_char = hay.chars;
    unsigned int remaining_len = hay.len;
    
    while(first_char && first_char <= max_possible_ptr)
    {
        if(memcmp(first_char, needle.chars, needle.len) == 0)
            return (Neat_String_View){.chars = first_char, .len = needle.len};
        first_char = memchr(first_char + 1, needle.chars[0], remaining_len - 1);
        remaining_len = hay.len - (first_char - hay.chars);
    }
    
    return (Neat_String_View){.chars = NULL, .len = 0};
}

Neat_Error neat_fmutstr_ref_copy(Fixed_Mut_String_Ref dst, const Neat_String_View src)
{
    unsigned int chars_to_copy = neat__uint_min(src.len, dst.cap - 1);
    
    memmove(dst.chars, src.chars, chars_to_copy * sizeof(unsigned char));
    dst.chars[chars_to_copy] = '\0';
    
    *dst.len = chars_to_copy;
    
    return chars_to_copy == src.len ? NEAT_OK : NEAT_DST_TOO_SMALL;
}

Neat_Error neat_dstr_copy(Neat_DString *dstr, Neat_String_View src)
{
    Neat_Error err = neat__dstr_ensure_cap(dstr, src.len + 1);
    
    if(err == NEAT_OK)
    {
        memmove(dstr->chars, src.chars, src.len * sizeof(unsigned char));
        
        dstr->len = src.len;
        dstr->chars[dstr->len] = '\0';
    }
    
    return err;
}

Neat_Error neat_mutstr_ref_copy(Neat_Mut_String_Ref dst, const Neat_String_View src)
{
    switch(dst.ty)
    {
        case NEAT_DSTR_TY     : return neat_dstr_copy(dst.str.dstr, src);
        case NEAT_STRBUF_TY   : return neat_fmutstr_ref_copy(fmutstr_ref(dst.str.strbuf), src);
        case NEAT_SSTR_REF_TY : return neat_fmutstr_ref_copy(fmutstr_ref(dst.str.sstr_ref), src);
        case NEAT_CARR_TY     : return neat_fmutstr_ref_copy(fmutstr_ref(dst.str.carr, &(unsigned int){0}), src);
        default               : unreachable();
    };
}

Neat_Error neat_dstr_putc(Neat_DString *dst, unsigned char c)
{
    Neat_Error err = neat__dstr_ensure_cap(dst, dst->len + 2);
    if(err != NEAT_OK)
        return err;
    
    dst->chars[dst->len] = c;
    dst->chars[dst->len + 1] = '\0';
    dst->len += 1;
    
    return NEAT_OK;
}

Neat_Error neat_fmutstr_ref_putc(Fixed_Mut_String_Ref dst, unsigned char c)
{
    if(dst.cap - *dst.len <= 1)
    {
        return NEAT_DST_TOO_SMALL;
    }
    
    dst.chars[*dst.len] = c;
    dst.chars[*dst.len + 1] = '\0';
    *dst.len += 1;
    
    return NEAT_OK;
}

Neat_Error neat_mutstr_ref_putc(Neat_Mut_String_Ref dst, unsigned char c)
{
    switch(dst.ty)
    {
        case NEAT_DSTR_TY     : return neat_dstr_putc(dst.str.dstr, c);
        case NEAT_STRBUF_TY   : return neat_fmutstr_ref_putc(fmutstr_ref(dst.str.strbuf), c);
        case NEAT_SSTR_REF_TY : return neat_fmutstr_ref_putc(fmutstr_ref(dst.str.sstr_ref), c);
        case NEAT_CARR_TY     : return neat_fmutstr_ref_putc(fmutstr_ref(dst.str.carr, &(unsigned int){0}), c);
        default               : unreachable();
    }
}

Neat_Error neat_fmutstr_ref_append_strv(Fixed_Mut_String_Ref dst, const Neat_String_View src)
{
    unsigned int dst_len = *dst.len;
    
    if(dst_len >= dst.cap - 1)
        return 0;
    
    unsigned int chars_to_copy = neat__uint_min(src.len, dst.cap - dst_len - 1);
    memmove(dst.chars + dst_len, src.chars, chars_to_copy);
    
    dst_len += chars_to_copy;
    
    if(dst.len != NULL)
        *dst.len = dst_len;
    
    dst.chars[dst_len] = '\0';
    
    return chars_to_copy == src.len ? NEAT_OK : NEAT_DST_TOO_SMALL;
}

Neat_Error neat_mutstr_ref_append(Neat_Mut_String_Ref dst, const Neat_String_View src)
{
    switch(dst.ty)
    {
        case NEAT_DSTR_TY     : return neat__dstr_append_strv(dst.str.dstr, src);
        case NEAT_STRBUF_TY   : return neat_fmutstr_ref_append_strv(fmutstr_ref(dst.str.strbuf), src);
        case NEAT_SSTR_REF_TY : return neat_fmutstr_ref_append_strv(fmutstr_ref(dst.str.sstr_ref), src);
        case NEAT_CARR_TY     : return neat_fmutstr_ref_append_strv(fmutstr_ref(dst.str.carr, &(unsigned int){0}), src);
        default               : unreachable();
    };
}

Neat_Error neat_fmutstr_ref_delete_range(Fixed_Mut_String_Ref str, unsigned int begin, unsigned int end)
{
    unsigned int len = *str.len;
    
    if(end > len || begin > end)
    {
        return NEAT_BAD_RANGE;
    }
    
    unsigned int substr_len = end - begin;
    
    memmove(str.chars + begin, str.chars + begin + substr_len, len - begin - substr_len);
    
    len -= substr_len;
    
    str.chars[len] = '\0';
    
    if(str.len != NULL)
    {
        *str.len = len;
    }
    
    return NEAT_OK;
}

Neat_Error neat_mutstr_ref_delete_range(Neat_Mut_String_Ref str, unsigned int begin, unsigned int end)
{
    switch(str.ty)
    {
        case NEAT_DSTR_TY     : return neat_fmutstr_ref_delete_range(fmutstr_ref(str.str.dstr), begin, end);
        case NEAT_STRBUF_TY   : return neat_fmutstr_ref_delete_range(fmutstr_ref(str.str.strbuf), begin, end);
        case NEAT_SSTR_REF_TY : return neat_fmutstr_ref_delete_range(fmutstr_ref(str.str.sstr_ref), begin, end);
        case NEAT_CARR_TY     : return neat_fmutstr_ref_delete_range(fmutstr_ref(str.str.carr, &(unsigned int){0}), begin, end);
        default               : unreachable();
    };
}

Neat_String_View_Array neat_strv_arr_from_carr(const Neat_String_View *carr, unsigned int nb)
{
    return (Neat_String_View_Array){
        .cap  = nb,
        .len  = nb,
        .strs = (Neat_String_View*) carr
    };
}

Neat_Error neat_strv_split_callback(const Neat_String_View str, const Neat_String_View delim, bool(*cb)(Neat_String_View found, void *ctx), void *ctx)
{
    if(delim.len > str.len)
    {
        cb(str, ctx);
    }
    else if(delim.len == 0)
    {
        for(unsigned int i = 0 ; i < str.len ; i++)
        {
            cb(neat_strv_strv3(str, i, i + 1), ctx);
        }
    }
    else
    {
        for(unsigned int i = 0 ; i <= str.len - delim.len ; )
        {
            Neat_String_View sub = neat_strv_strv3(str, i, i + delim.len);
            if(neat_strv_equal(sub, delim))
            {
                if(!cb(sub, ctx))
                {
                    return NEAT_CALLBACK_EXIT;
                }
                i += delim.len;
            }
            else
            {
                i += 1;
            }
        }
    }
    
    return NEAT_OK;
}

static bool str_split_combine_cb(Neat_String_View str, void *ctx)
{
    struct {
        Neat_Allocator *allocator;
        Neat_String_View_Array array;
    } *tctx = ctx;
    
    Neat_String_View_Array *array = &tctx->array;
    Neat_Allocator *allocator = tctx->allocator;
    
    if(array->cap <= array->len)
    {
        Neat_Allocation allocation = allocator->realloc(allocator, array->strs, _Alignof(Neat_String_View), array->cap * sizeof(Neat_String_View), (array->len + 1) * 2);
        array->strs = allocation.ptr;
        array->cap = allocation.n / sizeof(Neat_String_View);
    }
    
    return true;
}

NEAT_NODISCARD("str_split returns new String_View_Array") Neat_String_View_Array neat_strv_split(const Neat_String_View str, const Neat_String_View delim, Neat_Allocator *allocator)
{
    struct {
        Neat_Allocator *allocator;
        Neat_String_View_Array array;
    } ctx = {
        .allocator = allocator
    };
    
    neat_strv_split_callback(str, delim, str_split_combine_cb, &ctx);
    
    return ctx.array;
}

Neat_Error neat_strv_arr_join_into_dstr(Neat_DString *dstr, const Neat_String_View_Array strs, const Neat_String_View delim)
{
    Neat_Error err = NEAT_OK;
    
    if(strs.len > 0)
        err = neat_dstr_copy(dstr, strs.strs[0]);
    
    for(unsigned int i = 1 ; i < strs.len && err == NEAT_OK ; i++)
    {
        neat__dstr_append_strv(dstr, delim);
        err = neat__dstr_append_strv(dstr, strs.strs[i]);
    }
    
    return err;
}

Neat_Error neat_strv_arr_join_into_fmutstr_ref(Fixed_Mut_String_Ref dst, const Neat_String_View_Array strs, const Neat_String_View delim)
{
    Neat_Error err = NEAT_OK;
    
    if(strs.len > 0)
        err = neat_fmutstr_ref_copy(dst, strs.strs[0]);
    
    for(unsigned int i = 1 ; i < strs.len && err == NEAT_OK; i++)
    {
        neat_fmutstr_ref_append_strv(dst, delim);
        err = neat_fmutstr_ref_append_strv(dst, strs.strs[i]);
    }
    
    return err;
}

Neat_Error neat_strv_arr_join(Neat_Mut_String_Ref dst, const Neat_String_View_Array strs, const Neat_String_View delim)
{
    switch(dst.ty)
    {
        case NEAT_DSTR_TY     : return neat_strv_arr_join_into_dstr(dst.str.dstr, strs, delim);
        case NEAT_STRBUF_TY   : return neat_strv_arr_join_into_fmutstr_ref(fmutstr_ref(dst.str.strbuf), strs, delim);
        case NEAT_SSTR_REF_TY : return neat_strv_arr_join_into_fmutstr_ref(fmutstr_ref(dst.str.sstr_ref), strs, delim);
        case NEAT_CARR_TY     : return neat_strv_arr_join_into_fmutstr_ref(fmutstr_ref(dst.str.carr, &(unsigned int){0}), strs, delim);
        default               : unreachable();
    };
}

Neat_Error neat_dstr_replace_range(Neat_DString *dstr, unsigned int begin, unsigned int end, const Neat_String_View replacement)
{
    if(begin >= dstr->len)
        return NEAT_INDEX_OUT_OF_BOUNDS;
    if(begin > end || end > dstr->len)
        return NEAT_BAD_RANGE;
    if(neat__is_strv_within(neat__strv_dstr_ptr2(dstr, 0), replacement))
        return NEAT_ALIASING_NOT_SUPPORTED;
    
    unsigned int len_to_delete = end - begin;
    if(len_to_delete > replacement.len)
    {
        // shift left
        memmove(dstr->chars + begin + replacement.len, dstr->chars + end, dstr->len - end + 1);
        // insert the replacement
        memmove(dstr->chars + begin, replacement.chars, replacement.len);
    }
    else if(len_to_delete < replacement.len)
    {
        neat__dstr_ensure_cap(dstr, dstr->len + replacement.len - len_to_delete + 1);
        
        // shift right
        memmove(dstr->chars + end + (replacement.len - len_to_delete), dstr->chars + end, dstr->len - end + 1);
        // insert the replacement
        memmove(dstr->chars + begin, replacement.chars, replacement.len);
    }
    else
    {
        memmove(dstr->chars + begin, replacement.chars, replacement.len);
    }
    
    dstr->len = dstr->len - (len_to_delete) + replacement.len;
    return NEAT_OK;
}

void neat_fmutstr_ref_replace_range_unsafe(Fixed_Mut_String_Ref str, unsigned int begin, unsigned int end, const Neat_String_View replacement)
{
    unsigned int len_to_delete = end - begin;
    if(len_to_delete > replacement.len)
    {
        // shift left
        memmove(str.chars + begin + replacement.len, str.chars + end, *str.len - end + 1);
        // insert the replacement
        memmove(str.chars + begin, replacement.chars, replacement.len);
        
        *str.len -= len_to_delete - replacement.len;
    }
    else if(len_to_delete < replacement.len)
    {
        unsigned int new_space = neat__uint_min(replacement.len - len_to_delete, str.cap - *str.len - 1);
        
        // shift right
        memmove(str.chars + begin + new_space, str.chars + begin, *str.len - begin);
        // insert the replacement
        memmove(str.chars + begin, replacement.chars, neat__uint_min(replacement.len, len_to_delete + new_space));
        
        *str.len += new_space;
        
        str.chars[*str.len] = '\0';
    }
    else
    {
        memmove(str.chars + begin, replacement.chars, replacement.len);
    }
}

Neat_String_View neat_strv_fmutstr_ref2(Fixed_Mut_String_Ref str, unsigned int begin);

Neat_Error neat_fmutstr_ref_replace_range(Fixed_Mut_String_Ref str, unsigned int begin, unsigned int end, const Neat_String_View replacement)
{
    if(begin >= *str.len)
        return NEAT_INDEX_OUT_OF_BOUNDS;
    if(begin > end || end > *str.len)
        return NEAT_BAD_RANGE;
    if(neat__is_strv_within(neat_strv_fmutstr_ref2(str, 0), replacement))
        return NEAT_ALIASING_NOT_SUPPORTED;
    
    Neat_Error err = (*str.len - (end - begin) + replacement.len) >= str.cap ? NEAT_DST_TOO_SMALL : NEAT_OK;
    neat_fmutstr_ref_replace_range_unsafe(str, begin, end, replacement);
    
    return err;
}

Neat_Error neat_mustr_ref_replace_range(Neat_Mut_String_Ref str, unsigned int begin, unsigned int end, const Neat_String_View replacement)
{
    switch(str.ty)
    {
        case NEAT_DSTR_TY     : return neat_dstr_replace_range(str.str.dstr, begin, end, replacement);
        case NEAT_STRBUF_TY   : return neat_fmutstr_ref_replace_range(fmutstr_ref(str.str.strbuf), begin, end, replacement);
        case NEAT_SSTR_REF_TY : return neat_fmutstr_ref_replace_range(fmutstr_ref(str.str.sstr_ref), begin, end, replacement);
        case NEAT_CARR_TY     : return neat_fmutstr_ref_replace_range(fmutstr_ref(str.str.carr, &(unsigned int){0}), begin, end, replacement);
        default               : unreachable();
    };
}

Neat_Error neat_fmutstr_ref_replace(Fixed_Mut_String_Ref str, const Neat_String_View target, const Neat_String_View replacement)
{
    Neat_String_View as_strv = neat_strv_fmutstr_ref2(str, 0);
    if(neat__is_strv_within(as_strv, target) || neat__is_strv_within(as_strv, replacement))
    {
        return NEAT_ALIASING_NOT_SUPPORTED;
    }
    
    Neat_Error err = NEAT_OK;
    
    if(target.len == 0)
    {
        for(unsigned int i = 0 ; i <= *str.len && err == NEAT_OK ; i += replacement.len + 1)
        {
            err = neat_fmutstr_ref_insert(str, replacement, i);
        }
        return err;
    }
    
    if(target.len < replacement.len)
    {
        for(unsigned int i = 0 ; i <= *str.len - target.len; )
        {
            Neat_String_View match = neat__strv_find(neat_strv_fmutstr_ref2(str, i), target);
            if(match.chars != NULL)
            {
                unsigned int idx = match.chars - str.chars;
                
                if(str.cap > *str.len + (replacement.len - target.len))
                {
                    // shift right
                    memmove(str.chars + idx + replacement.len, str.chars + idx + target.len, (*str.len - idx - target.len) * sizeof(unsigned char));
                    
                    // put the replacement
                    memmove(str.chars + idx, replacement.chars, replacement.len * sizeof(unsigned char));
                    
                    *str.len += (replacement.len - target.len);
                    
                    i = idx + replacement.len;
                }
                else
                {
                    err = NEAT_DST_TOO_SMALL;
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }
    else if(target.len > replacement.len)
    {
        for(unsigned int i = 0 ; i <= *str.len - target.len; )
        {
            Neat_String_View match = neat__strv_find(neat_strv_fmutstr_ref2(str, i), target);
            if(match.chars != NULL)
            {
                unsigned int idx = match.chars - str.chars;
                
                // shift left
                memmove(str.chars + idx + replacement.len, str.chars + idx + target.len, (*str.len - idx - target.len) * sizeof(unsigned char));
                
                // put the replacement
                memmove(str.chars + idx, replacement.chars, replacement.len * sizeof(unsigned char));
                
                *str.len -= (target.len - replacement.len);
                
                i = idx + replacement.len;
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        for(unsigned int i = 0 ; i <= *str.len - target.len; )
        {
            Neat_String_View match = neat__strv_find(neat_strv_fmutstr_ref2(str, i), target);
            if(match.chars != NULL)
            {
                unsigned int idx = match.chars - str.chars;
                
                // put the replacement
                memmove(str.chars + idx, replacement.chars, replacement.len * sizeof(unsigned char));
                
                i = idx + replacement.len;
            }
            else
            {
                break;
            }
        }
    }
    
    if(str.cap > 0)
        str.chars[*str.len] = '\0';
    return err;
}

Neat_Error neat_dstr_replace(Neat_DString *dstr, const Neat_String_View target, const Neat_String_View replacement)
{
    Neat_String_View as_strv = neat__strv_dstr_ptr2(dstr, 0);
    if(neat__is_strv_within(as_strv, target) || neat__is_strv_within(as_strv, replacement))
    {
        return NEAT_ALIASING_NOT_SUPPORTED;
    }
    
    Neat_Error err = NEAT_OK;
    
    if(target.len == 0)
    {
        for(unsigned int i = 0 ; i <= dstr->len && err == NEAT_OK ; i += replacement.len + 1)
        {
            err = neat_dstr_insert_strv(dstr, replacement, i);
        }
        return err;
    }
    
    if(target.len < replacement.len)
    {
        for(unsigned int i = 0 ; i <= dstr->len - target.len; )
        {
            Neat_String_View match = neat__strv_find(neat__strv_dstr_ptr2(dstr, i), target);
            if(match.chars != NULL)
            {
                unsigned int idx = match.chars - dstr->chars;
                
                neat__dstr_ensure_cap(dstr, dstr->len + (replacement.len - target.len) + 1);
                
                // shift right
                memmove(dstr->chars + idx + replacement.len, dstr->chars + idx + target.len, (dstr->len - idx - target.len) * sizeof(unsigned char));
                
                // put the replacement
                memmove(dstr->chars + idx, replacement.chars, replacement.len * sizeof(unsigned char));
                
                dstr->len += (replacement.len - target.len);
                
                i = idx + replacement.len;
            }
        }
    }
    else if(target.len > replacement.len)
    {
        for(unsigned int i = 0 ; i <= dstr->len - target.len ; )
        {
            Neat_String_View match = neat__strv_find(neat__strv_dstr_ptr2(dstr, i), target);
            if(match.chars != NULL)
            {
                unsigned int idx = match.chars - dstr->chars;
                
                // shift left
                memmove(dstr->chars + idx + replacement.len, dstr->chars + idx + target.len, (dstr->len - idx - target.len) * sizeof(unsigned char));
                
                // put the replacement
                memmove(dstr->chars + idx, replacement.chars, replacement.len * sizeof(unsigned char));
                
                dstr->len -= (target.len - replacement.len);
                
                i = idx + replacement.len;
            }
            else
            {
                break;
            }
        }
    }
    else
    {
        for(unsigned int i = 0 ; i <= dstr->len - target.len; )
        {
            Neat_String_View match = neat__strv_find(neat__strv_dstr_ptr2(dstr, i), target);
            if(match.chars != NULL)
            {
                unsigned int idx = match.chars - dstr->chars;
                
                // put the replacement
                memmove(dstr->chars + idx, replacement.chars, replacement.len * sizeof(unsigned char));
                
                i = idx + replacement.len;
            }
            else
            {
                break;
            }
        }
    }
    
    dstr->chars[dstr->len] = '\0';
    
    return err;
}

Neat_Error neat_mutstr_ref_replace(Neat_Mut_String_Ref str, const Neat_String_View target, const Neat_String_View replacement)
{
    switch(str.ty)
    {
        case NEAT_DSTR_TY     : return neat_dstr_replace(str.str.dstr, target, replacement);
        case NEAT_STRBUF_TY   : return neat_fmutstr_ref_replace(fmutstr_ref(str.str.strbuf), target, replacement);
        case NEAT_SSTR_REF_TY : return neat_fmutstr_ref_replace(fmutstr_ref(str.str.sstr_ref), target, replacement);
        case NEAT_CARR_TY     : return neat_fmutstr_ref_replace(fmutstr_ref(str.str.carr, &(unsigned int){0}), target, replacement);
        default               : unreachable();
    };
}

Neat_Error neat_dstr_replace_first(Neat_DString *dstr, const Neat_String_View target, const Neat_String_View replacement)
{
    Neat_Error err = NEAT_NOT_FOUND;
    
    Neat_String_View match = neat__strv_find(neat__strv_dstr_ptr2(dstr, 0), target);
    if(match.chars != NULL)
    {
        if(dstr->cap > 0 && dstr->cap - 1 > dstr->len + (replacement.len - target.len))
        {
            unsigned int begin = match.chars - dstr->chars;
            unsigned int end = begin + match.len;
            err = neat_dstr_replace_range(dstr, begin, end, replacement);
        }
    }
    
    if(dstr->cap > 0)
        dstr->chars[dstr->len] = '\0';
    
    return err;
}

Neat_Error neat_fmutstr_ref_replace_first(Fixed_Mut_String_Ref str, const Neat_String_View target, const Neat_String_View replacement)
{
    Neat_Error err = NEAT_NOT_FOUND;
    
    Neat_String_View match = neat__strv_find(neat_strv_fmutstr_ref2(str, 0), target);
    if(match.chars != NULL)
    {
        if(str.cap > 0 && str.cap - 1 > *str.len + (replacement.len - target.len))
        {
            unsigned int idx = match.chars - str.chars;
            
            // shift
            memmove(str.chars + idx + replacement.len, str.chars + idx + target.len, (*str.len - idx - target.len) * sizeof(unsigned char));
            
            // put the replacement
            memmove(str.chars + idx, replacement.chars, replacement.len * sizeof(unsigned char));
            
            *str.len += (replacement.len - target.len);
            
            err = NEAT_OK;
        }
        else
        {
            err = NEAT_DST_TOO_SMALL;
        }
    }
    
    if(str.cap > 0)
        str.chars[*str.len] = '\0';
    
    return err;
}

Neat_Error neat_mutstr_ref_replace_first(Neat_Mut_String_Ref str, const Neat_String_View target, const Neat_String_View replacement)
{
    switch(str.ty)
    {
        case NEAT_DSTR_TY     : return neat_dstr_replace_first(str.str.dstr, target, replacement);
        case NEAT_STRBUF_TY   : return neat_fmutstr_ref_replace_first(fmutstr_ref(str.str.strbuf), target, replacement);
        case NEAT_SSTR_REF_TY : return neat_fmutstr_ref_replace_first(fmutstr_ref(str.str.sstr_ref), target, replacement);
        case NEAT_CARR_TY     : return neat_fmutstr_ref_replace_first(fmutstr_ref(str.str.carr, &(unsigned int){0}), target, replacement);
        default               : unreachable();
    };
}

unsigned int neat_strv_count(const Neat_String_View hay, const Neat_String_View needle)
{
    if(needle.len == 0)
        return 0;
    
    unsigned int count = 0;
    Neat_String_View found = neat__strv_find(hay, needle);
    
    while(found.chars != NULL)
    {
        count += 1;
        found = neat__strv_find(neat__strv_strv2(hay, (found.chars - hay.chars) + 1), needle);
    }
    
    return count;
}

bool neat_strv_starts_with(const Neat_String_View hay, const Neat_String_View needle)
{
    return (needle.len <= hay.len) && (memcmp(hay.chars, needle.chars, needle.len) == 0);
}

bool neat_strv_ends_with(const Neat_String_View hay, const Neat_String_View needle)
{
    return (needle.len <= hay.len) && (memcmp(hay.chars + hay.len - needle.len, needle.chars, needle.len) == 0);
}

void neat_chars_tolower(unsigned char *chars, unsigned int len)
{
    for(unsigned int i = 0 ; i < len ; i++)
    {
        chars[i] = tolower(chars[i]);
    }
}

void neat_chars_toupper(unsigned char *chars, unsigned int len)
{
    for(unsigned int i = 0 ; i < len ; i++)
    {
        chars[i] = toupper(chars[i]);
    }
}

Neat_Error neat_mutstr_ref_toupper(Neat_Mut_String_Ref str)
{
    switch(str.ty)
    {
        case NEAT_DSTR_TY:
            neat_chars_toupper(str.str.dstr->chars, str.str.dstr->len);
            break;
        case NEAT_STRBUF_TY:
            neat_chars_toupper(str.str.strbuf->chars, str.str.strbuf->len);
            break;
        case NEAT_SSTR_REF_TY:
            neat_chars_toupper(str.str.sstr_ref.sstr->chars, str.str.sstr_ref.sstr->len);
            break;
        case NEAT_CARR_TY:
            neat_chars_toupper(str.str.carr.ptr, strlen((char*) str.str.carr.ptr));
            break;
    }
    return NEAT_OK;
}

Neat_Error neat_mutstr_ref_clear(Neat_Mut_String_Ref str)
{
    switch(str.ty)
    {
        case NEAT_DSTR_TY:
            str.str.dstr->len = 0;
            break;
        case NEAT_STRBUF_TY:
            str.str.strbuf->len = 0;
            break;
        case NEAT_SSTR_REF_TY:
            str.str.sstr_ref.sstr->len = 0;
            break;
        case NEAT_CARR_TY:
            str.str.carr.ptr[0] = '\0';
            break;
    }
    return NEAT_OK;
}

Neat_Mut_String_Ref neat_cstr_as_mutstr_ref(const char *str)
{
    unsigned int len = (unsigned int) strlen(str);
    
    Neat_Buffer asbuf = {
        .ptr = (unsigned char*) str,
        .cap = len + 1
    };
    
    return neat_buf_as_mutstr_ref(asbuf);
}

Neat_Mut_String_Ref neat_ucstr_as_mutstr_ref(const unsigned char *str)
{
    unsigned int len = (unsigned int) strlen((char*) str);
    
    Neat_Buffer asbuf = {
        .ptr = (unsigned char*) str,
        .cap = len + 1
    };
    
    return neat_buf_as_mutstr_ref(asbuf);
}

Neat_Mut_String_Ref neat_buf_as_mutstr_ref(const Neat_Buffer str)
{
    return (Neat_Mut_String_Ref){
        .ty = NEAT_CARR_TY,
        .str.carr = *(Neat_Buffer*) &str
    };
}

Neat_Mut_String_Ref neat_dstr_ptr_as_mutstr_ref(const Neat_DString *str)
{
    return (Neat_Mut_String_Ref){
        .ty = NEAT_DSTR_TY,
        .str.dstr = (Neat_DString*) str
    };
}

Neat_Mut_String_Ref neat_strbuf_ptr_as_mutstr_ref(const Neat_String_Buffer *str)
{
    return (Neat_Mut_String_Ref){
        .ty = NEAT_STRBUF_TY,
        .str.strbuf = (Neat_String_Buffer*) str
    };
}

Neat_Mut_String_Ref neat_sstr_ref_as_mutstr_ref(const Neat_SString_Ref str)
{
    return (Neat_Mut_String_Ref){
        .ty = NEAT_SSTR_REF_TY,
        .str.sstr_ref = str
    };
}

Neat_Mut_String_Ref neat_mutstr_ref_as_mutstr_ref(const Neat_Mut_String_Ref str)
{
    return str;
}

Neat_String_Buffer neat_strbuf_from_cstr_(const char *ptr, unsigned int cap)
{
    unsigned int len = neat__chars_strlen(ptr, cap);
    
    return (Neat_String_Buffer){
        .cap = cap,
        .len = len,
        .chars = (unsigned char*) ptr
    };
}

Neat_String_Buffer neat_strbuf_from_buf_(const Neat_Buffer buf)
{
    Neat_String_Buffer ret = {
        .cap = buf.cap,
        .len = 0,
        .chars = buf.ptr
    };
    
    if(ret.cap > 0)
        ret.chars[0] = '\0';
    
    return ret;
}

Neat_String_View neat_strv_cstr2(const char *str, unsigned int begin)
{
    unsigned int len = strlen(str);
    
    if(begin > len)
    {
        return (Neat_String_View){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (Neat_String_View){
        .len   = len - begin,
        .chars = (unsigned char*) str + begin
    };
}

Neat_String_View neat_strv_ucstr2(const unsigned char *str, unsigned int begin)
{
    unsigned int len = strlen((char*) str);
    
    if(begin > len)
    {
        return (Neat_String_View){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (Neat_String_View){
        .len   = len - begin,
        .chars = (unsigned char*) str + begin
    };
}

Neat_String_View neat_strv_dstr2(const Neat_DString str, unsigned int begin)
{
    return neat__strv_dstr_ptr2(&str, begin);
}

Neat_String_View neat__strv_dstr_ptr2(const Neat_DString *str, unsigned int begin)
{
    if(begin > str->len)
    {
        return (Neat_String_View){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (Neat_String_View){
        .len   = str->len   - begin,
        .chars = str->chars + begin
    };
}

Neat_String_View neat_strv_strv_ptr2(const Neat_String_View *str, unsigned int begin)
{
    if(begin > str->len)
    {
        return (Neat_String_View){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (Neat_String_View){
        .len   = str->len   - begin,
        .chars = str->chars + begin
    };
}

Neat_String_View neat__strv_strv2(const Neat_String_View str, unsigned int begin)
{
    return neat_strv_strv_ptr2(&str, begin);
}

Neat_String_View neat_strv_strbuf_ptr2(const Neat_String_Buffer *str, unsigned int begin)
{
    if(begin > str->len)
    {
        return (Neat_String_View){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (Neat_String_View){
        .len   = str->len   - begin,
        .chars = str->chars + begin
    };
}

Neat_String_View neat_strv_strbuf2(const Neat_String_Buffer str, unsigned int begin)
{
    return neat_strv_strbuf_ptr2(&str, begin);
}

Neat_String_View neat_strv_sstr_ref2(const Neat_SString_Ref str, unsigned int begin)
{
    if(begin > str.sstr->len)
    {
        return (Neat_String_View){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (Neat_String_View){
        .len   = str.sstr->len   - begin,
        .chars = str.sstr->chars + begin
    };
}

Neat_String_View neat_strv_mutstr_ref2(const Neat_Mut_String_Ref str, unsigned int begin)
{
    switch(str.ty)
    {
        case NEAT_DSTR_TY     : return neat__strv_dstr_ptr2(str.str.dstr, begin);
        case NEAT_STRBUF_TY   : return neat_strv_strbuf_ptr2(str.str.strbuf, begin);
        case NEAT_SSTR_REF_TY : return neat_strv_sstr_ref2(str.str.sstr_ref, begin);
        case NEAT_CARR_TY     : return neat_strv_fmutstr_ref2(neat__buf_as_fmutstr_ref(str.str.carr, &(unsigned int){0}), begin);
        default               : unreachable();
    }
}

Neat_String_View neat_strv_fmutstr_ref2(const Fixed_Mut_String_Ref str, unsigned int begin)
{
    unsigned int len = *str.len;
    
    if(begin > len)
    {
        return (Neat_String_View){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (Neat_String_View){
        .len   = len       - begin,
        .chars = str.chars + begin
    };
}

Neat_String_View neat_strv_fmutstr_ref3(const Fixed_Mut_String_Ref str, unsigned int begin, unsigned int end)
{
    unsigned int len = *str.len;
    
    if(begin > len || end > len || begin > end)
    {
        return (Neat_String_View){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (Neat_String_View){
        .len   = end - begin,
        .chars = str.chars + begin
    };
}

Neat_String_View neat_strv_cstr3(const char *str, unsigned int begin, unsigned int end)
{
    unsigned int len = strlen(str);
    
    if(begin > len || end > len || begin > end)
    {
        return (Neat_String_View){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (Neat_String_View){
        .len   = end - begin,
        .chars = (unsigned char*) str + begin
    };
}

Neat_String_View neat_strv_ucstr3(const unsigned char *str, unsigned int begin, unsigned int end)
{
    unsigned int len = strlen((char*) str);
    
    if(begin > len || end > len || begin > end)
    {
        return (Neat_String_View){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (Neat_String_View){
        .len   = end - begin,
        .chars = (unsigned char*) str + begin
    };
}

Neat_String_View neat_strv_dstr_ptr3(const Neat_DString *str, unsigned int begin, unsigned int end)
{
    if(begin > str->len || end > str->len || begin > end)
    {
        return (Neat_String_View){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (Neat_String_View){
        .len   = end - begin,
        .chars = str->chars + begin
    };
}

Neat_String_View neat_strv_strv_ptr3(const Neat_String_View *str, unsigned int begin, unsigned int end)
{
    if(begin > str->len || end > str->len || begin > end)
    {
        return (Neat_String_View){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (Neat_String_View){
        .len   = end - begin,
        .chars = str->chars + begin
    };
}

Neat_String_View neat_strv_strbuf_ptr3(const Neat_String_Buffer *str, unsigned int begin, unsigned int end)
{
    if(begin > str->len || end > str->len || begin > end)
    {
        return (Neat_String_View){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (Neat_String_View){
        .len   = end - begin,
        .chars = str->chars + begin
    };
}

Neat_String_View neat_strv_sstr_ref3(Neat_SString_Ref str, unsigned int begin, unsigned int end)
{
    if(begin > str.sstr->len || end > str.sstr->len || begin > end)
    {
        return (Neat_String_View){
            .len = 0,
            .chars = NULL
        };
    }
    
    return (Neat_String_View){
        .len   = end - begin,
        .chars = str.sstr->chars + begin
    };
}

Neat_String_View neat_strv_mutstr_ref3(Neat_Mut_String_Ref str, unsigned int begin, unsigned int end)
{
    switch(str.ty)
    {
        case NEAT_DSTR_TY     : return neat_strv_dstr_ptr3(str.str.dstr, begin, end);
        case NEAT_STRBUF_TY   : return neat_strv_strbuf_ptr3(str.str.strbuf, begin, end);
        case NEAT_SSTR_REF_TY : return neat_strv_sstr_ref3(str.str.sstr_ref, begin, end);
        case NEAT_CARR_TY     : return neat_strv_fmutstr_ref3(neat__buf_as_fmutstr_ref(str.str.carr, &(unsigned int){0}), begin, end);
        default               : unreachable();
    }
}

Neat_String_View neat_strv_dstr3(Neat_DString str, unsigned int begin, unsigned int end)
{
    return neat_strv_dstr_ptr3(&str, begin, end);
}

Neat_String_View neat_strv_strv3(Neat_String_View str, unsigned int begin, unsigned int end)
{
    return neat_strv_strv_ptr3(&str, begin, end);
}

Neat_String_View neat_strv_strbuf3(Neat_String_Buffer str, unsigned int begin, unsigned int end)
{
    return neat_strv_strbuf_ptr3(&str, begin, end);
}

Neat_Error neat_dstr_fread_line_(Neat_DString *dstr, FILE *stream)
{
    dstr->len = 0;
    if(dstr->cap > 0)
    {
        dstr->chars[0] = '\0';
    }
    
    return neat_dstr_append_fread_line_(dstr, stream);
}

Neat_Error neat_dstr_append_fread_line_(Neat_DString *dstr, FILE *stream)
{
    // TODO optimize this
    int c = 0;
    while((c=fgetc(stream)) != EOF)
    {
        unsigned char as_char = c;
        Neat_Error err = neat_dstr_putc(dstr, as_char);
        if(err != NEAT_OK)
            return err;
        if(c == '\n')
            break;
    }
    
    return NEAT_OK;
}

Neat_Error neat_fmutstr_ref_fread_line(Fixed_Mut_String_Ref dst, FILE *stream)
{
    if(dst.cap == 0)
    {
        return NEAT_DST_TOO_SMALL;
    }
    
    unsigned int len = 0;
    int c = 0;
    while(len < dst.cap - 1 && c != '\n' && (c=fgetc(stream)) != EOF)
    {
        dst.chars[len] = c;
        len += 1;
    }
    
    dst.chars[len] = '\0';
    *dst.len = len;
    
    bool dst_too_small = (len == dst.cap - 1) && (c != '\n') && (c != EOF);
    
    if(dst_too_small)
        return NEAT_DST_TOO_SMALL;
    else
        return NEAT_OK;
}

Neat_Error neat_mutstr_ref_fread_line(Neat_Mut_String_Ref dst, FILE *stream)
{
    switch(dst.ty)
    {
        case NEAT_DSTR_TY     : return neat_dstr_fread_line_(dst.str.dstr, stream);
        case NEAT_STRBUF_TY   : return neat_fmutstr_ref_fread_line(neat__strbuf_as_fmutstr_ref(dst.str.strbuf), stream);
        case NEAT_SSTR_REF_TY : return neat_fmutstr_ref_fread_line(neat__sstr_ref_as_fmutstr_ref(dst.str.sstr_ref), stream);
        case NEAT_CARR_TY     : return neat_fmutstr_ref_fread_line(neat__buf_as_fmutstr_ref(dst.str.carr, &(unsigned int){0}), stream);
        default               : unreachable();
    };
}

Neat_Error neat_fmutstr_ref_append_fread_line(Fixed_Mut_String_Ref dst, FILE *stream)
{
    if(dst.cap == 0)
        return false;
    
    unsigned int appended_len = 0;
    
    Fixed_Mut_String_Ref right = {
        .cap = dst.cap - *dst.len,
        .len = &appended_len
    };
    
    right.chars = dst.chars + *dst.len;
    
    Neat_Error err = neat_fmutstr_ref_fread_line(right, stream);
    
    *dst.len += *right.len;
    
    dst.chars[*dst.len] = '\0';
    
    return err;
}

Neat_Error neat_mutstr_ref_append_fread_line(Neat_Mut_String_Ref dst, FILE *stream)
{
    switch(dst.ty)
    {
        case NEAT_DSTR_TY     : return neat_dstr_append_fread_line_(dst.str.dstr, stream);
        case NEAT_STRBUF_TY   : return neat_fmutstr_ref_append_fread_line(neat__strbuf_as_fmutstr_ref(dst.str.strbuf), stream);
        case NEAT_SSTR_REF_TY : return neat_fmutstr_ref_append_fread_line(neat__sstr_ref_as_fmutstr_ref(dst.str.sstr_ref), stream);
        case NEAT_CARR_TY     : return neat_fmutstr_ref_append_fread_line(neat__buf_as_fmutstr_ref(dst.str.carr, &(unsigned int){0}), stream);
        default               : unreachable();
    };
}

unsigned int neat_fprint_strv(FILE *stream, Neat_String_View str)
{
    return fwrite(str.chars, sizeof(unsigned char), str.len, stream);
}

unsigned int neat_fprintln_strv(FILE *stream, Neat_String_View str)
{
    unsigned int written = fwrite(str.chars, sizeof(unsigned char), str.len, stream);
    int err = fputc('\n', stream);
    if(err == EOF)
        return written;
    else
        return written + 1;
}

unsigned int neat_numstr_len(long long num)
{
    unsigned int len = 1;
    if(num < 0)
    {
        num *= -1;
        len += 1;
    }
    for(unsigned int i = 1 ; i < NEAT_CARR_LEN(ten_pows) && num >= ten_pows[i++] ; len++);
    return len;
}

unsigned int neat_numstr_len_ull(unsigned long long num)
{
    unsigned int len = 1;
    for(unsigned int i = 1 ; i < NEAT_CARR_LEN(ten_pows_ull) && num >= ten_pows_ull[i++] ; len++);
    return len;
}

#define neat_sinteger_min(ty) \
_Generic((ty){0},             \
signed char: SCHAR_MIN,   \
short      : SHRT_MIN,    \
int        : INT_MIN,     \
long       : LONG_MIN,    \
long long  : LLONG_MIN    \
)

#define neat_min_tostr(ty) \
_Generic((ty){0},          \
signed char: neat_schar_min_into_fmutstr_ref, \
short      : neat_short_min_into_fmutstr_ref, \
int        : neat_int_min_into_fmutstr_ref,   \
long       : neat_long_min_into_fmutstr_ref,  \
long long  : neat_llong_min_into_fmutstr_ref  \
)

Neat_Error neat_schar_min_into_fmutstr_ref(Fixed_Mut_String_Ref dst)
{
    if(SCHAR_MIN == -128)
    {
        const char *numstr = "-128";
        Neat_String_View s = {.chars = (unsigned char*) numstr, .len = strlen(numstr)};
        return neat_fmutstr_ref_copy(dst, s);
    }
    else
    {
        char temp[16] = {0};
        int len = snprintf(temp, sizeof(temp), "%hhd", SCHAR_MIN);
        return neat_fmutstr_ref_copy(dst, (Neat_String_View){.chars = (unsigned char*) temp, .len = len});
    }
}

Neat_Error neat_short_min_into_fmutstr_ref(Fixed_Mut_String_Ref dst)
{
    if(SHRT_MIN == -32768)
    {
        const char *numstr = "-32768";
        Neat_String_View s = {.chars = (unsigned char*) numstr, .len = strlen(numstr)};
        return neat_fmutstr_ref_copy(dst, s);
    }
    else
    {
        char temp[16] = {0};
        int len = snprintf(temp, sizeof(temp), "%hd", SHRT_MIN);
        return neat_fmutstr_ref_copy(dst, (Neat_String_View){.chars = (unsigned char*) temp, .len = len});
    }
}

Neat_Error neat_int_min_into_fmutstr_ref(Fixed_Mut_String_Ref dst)
{
    if(INT_MIN == -2147483648)
    {
        const char *numstr = "-2147483648";
        Neat_String_View s = {.chars = (unsigned char*) numstr, .len = strlen(numstr)};
        return neat_fmutstr_ref_copy(dst, s);
    }
    else
    {
        char temp[32] = {0};
        int len = snprintf(temp, sizeof(temp), "%d", INT_MIN);
        return neat_fmutstr_ref_copy(dst, (Neat_String_View){.chars = (unsigned char*) temp, .len = len});
    }
}

Neat_Error neat_long_min_into_fmutstr_ref(Fixed_Mut_String_Ref dst)
{
    if(LONG_MIN == INT_MIN)
    {
        return neat_int_min_into_fmutstr_ref(dst);
    }
    else if(LONG_MIN == -9223372036854775807 - 1)
    {
        const char *numstr = "-9223372036854775808";
        Neat_String_View s = {.chars = (unsigned char*) numstr, .len = strlen(numstr)};
        return neat_fmutstr_ref_copy(dst, s);
    }
    else
    {
        char temp[32] = {0};
        int len = snprintf(temp, sizeof(temp), "%ld", LONG_MIN);
        return neat_fmutstr_ref_copy(dst, (Neat_String_View){.chars = (unsigned char*) temp, .len = len});
    }
}

Neat_Error neat_llong_min_into_fmutstr_ref(Fixed_Mut_String_Ref dst)
{
    if(LLONG_MIN == LONG_MIN)
    {
        return neat_long_min_into_fmutstr_ref(dst);
    }
    else if(LLONG_MIN == -9223372036854775807 - 1)
    {
        const char *numstr = "-9223372036854775808";
        Neat_String_View s = {.chars = (unsigned char*) numstr, .len = strlen(numstr)};
        return neat_fmutstr_ref_copy(dst, s);
    }
    else
    {
        char temp[32] = {0};
        int len = snprintf(temp, sizeof(temp), "%lld", LLONG_MIN);
        return neat_fmutstr_ref_copy(dst, (Neat_String_View){.chars = (unsigned char*) temp, .len = len});
    }
}

#define neat_sintger_tostr_fmutstr_ref(fmutstr) \
do { \
    if(fmutstr.cap <= 1) \
        return NEAT_DST_TOO_SMALL; \
    if(obj == neat_sinteger_min(typeof(obj))) \
    { \
        return neat_min_tostr(typeof(obj))(fmutstr); \
    } \
    typeof(obj) num = obj; \
    \
    bool isneg = num < 0; \
    if(isneg) \
    { \
        num *= -1; \
        if(fmutstr.cap > 1) \
        { \
            neat_fmutstr_ref_putc(fmutstr, '-'); \
        } \
    } \
    unsigned int numstr_len = neat_numstr_len(num); \
    unsigned int chars_to_copy = neat__uint_min(fmutstr.cap - (1 + isneg), numstr_len); \
    num /= ten_pows[numstr_len - chars_to_copy]; \
    for (unsigned int i = 0; i < chars_to_copy ; i++) \
    { \
        unsigned int rem = num % 10; \
        num = num / 10; \
        fmutstr.chars[isneg + chars_to_copy - (i + 1)] = rem + '0'; \
    } \
    \
    *fmutstr.len = chars_to_copy + isneg; \
} while(0)

// TODO: optimize this
#define neat_sinteger_tostr_dstr(dstr) \
do { \
    unsigned int numlen = neat_numstr_len(obj); \
    err = neat__dstr_ensure_cap(dstr, numlen + 1); \
    if(err != NEAT_OK) \
        return err; \
    \
    Fixed_Mut_String_Ref as_fixed = neat__dstr_as_fmutstr_ref(dstr); \
    neat_sintger_tostr_fmutstr_ref(as_fixed); \
} while(0)

#define neat_sinteger_tostr() \
do { \
    Neat_Error err = NEAT_OK; \
    switch(dst.ty) \
    { \
        case NEAT_DSTR_TY: \
        { \
            neat_sinteger_tostr_dstr(dst.str.dstr); \
            return err; \
        } \
        case NEAT_STRBUF_TY: \
        { \
            Fixed_Mut_String_Ref strbuf_as_fixed = neat__strbuf_as_fmutstr_ref(dst.str.strbuf); \
            neat_sintger_tostr_fmutstr_ref(strbuf_as_fixed); \
            return err; \
        } \
        case NEAT_SSTR_REF_TY: \
        { \
            Fixed_Mut_String_Ref sstr_ref_as_fixed = neat__sstr_ref_as_fmutstr_ref(dst.str.sstr_ref); \
            neat_sintger_tostr_fmutstr_ref(sstr_ref_as_fixed); \
            return err; \
        } \
        case NEAT_CARR_TY: \
        { \
            Fixed_Mut_String_Ref buf_as_fixed = neat__buf_as_fmutstr_ref(dst.str.carr, &(unsigned int){0}); \
            neat_sintger_tostr_fmutstr_ref(buf_as_fixed); \
            return err; \
        } \
        default: unreachable(); \
    } \
} while(0)

// TODO optimize this
#define neat_uinteger_tostr_dstr(dstr) \
do { \
    unsigned int numlen = neat_numstr_len_ull(obj); \
    err = neat__dstr_ensure_cap(dstr, numlen + 1); \
    if(err != NEAT_OK) \
        return err; \
    \
    Fixed_Mut_String_Ref as_fixed = { \
        .chars = dstr->chars, \
        .len = &dstr->len, \
        .cap = dstr->cap \
    }; \
    neat_uintger_tostr_fmutstr_ref(as_fixed); \
} while(0)

#define neat_uintger_tostr_fmutstr_ref(fmutstr) \
do { \
    if(fmutstr.cap <= 1) \
        return NEAT_DST_TOO_SMALL; \
    typeof(obj) num = obj; \
    unsigned int numstr_len = neat_numstr_len_ull(num); \
    unsigned int chars_to_copy = neat__uint_min(fmutstr.cap - 1, numstr_len); \
    num /= ten_pows[numstr_len - chars_to_copy]; \
    for (unsigned int i = 0; i < chars_to_copy ; i++) \
    { \
        unsigned int rem = num % 10; \
        num = num / 10; \
        fmutstr.chars[chars_to_copy - (i + 1)] = rem + '0'; \
    } \
    \
    *fmutstr.len = chars_to_copy; \
} while(0)

#define neat_uinteger_tostr() \
do { \
    Neat_Error err = NEAT_OK; \
    switch(dst.ty) \
    { \
        case NEAT_DSTR_TY: \
        { \
            neat_uinteger_tostr_dstr(dst.str.dstr); \
            return err; \
        } \
        case NEAT_STRBUF_TY: \
        { \
            Fixed_Mut_String_Ref strbuf_as_fixed = neat__strbuf_as_fmutstr_ref(dst.str.strbuf); \
            neat_uintger_tostr_fmutstr_ref(strbuf_as_fixed); \
            return err; \
        } \
        case NEAT_SSTR_REF_TY: \
        { \
            Fixed_Mut_String_Ref sstr_ref_as_fixed = neat__sstr_ref_as_fmutstr_ref(dst.str.sstr_ref); \
            neat_uintger_tostr_fmutstr_ref(sstr_ref_as_fixed); \
            return err; \
        } \
        case NEAT_CARR_TY: \
        { \
            Fixed_Mut_String_Ref buf_as_fixed = neat__buf_as_fmutstr_ref(dst.str.carr, &(unsigned int){0}); \
            neat_uintger_tostr_fmutstr_ref(buf_as_fixed); \
            return err; \
        } \
        default: unreachable(); \
    } \
} while(0)

Neat_Error neat_bool_tostr(Neat_Mut_String_Ref dst, bool obj)
{
    Neat_String_View res = obj ? neat_strv("true") : neat_strv("false");
    return neat_strv_tostr(dst, res);
}

Neat_Error neat_cstr_tostr(Neat_Mut_String_Ref dst, char *obj)
{
    return neat_mutstr_ref_copy(
        dst,
        (Neat_String_View){
            .chars = (unsigned char*) obj,
            .len = strlen(obj)
        }
    );
}

Neat_Error neat_ucstr_tostr(Neat_Mut_String_Ref dst, unsigned char *obj)
{
    return neat_mutstr_ref_copy(
        dst,
        (Neat_String_View){
            .chars = obj,
            .len = strlen((char*) obj)
        }
    );
}

Neat_Error neat_char_tostr(Neat_Mut_String_Ref dst, char obj)
{
    neat_mutstr_ref_clear(dst);
    return neat_mutstr_ref_putc(dst, obj);
}

Neat_Error neat_schar_tostr(Neat_Mut_String_Ref dst, signed char obj)
{
    neat_sinteger_tostr();
}

Neat_Error neat_uchar_tostr(Neat_Mut_String_Ref dst, unsigned char obj)
{
    neat_mutstr_ref_clear(dst);
    return neat_mutstr_ref_putc(dst, obj);
}

Neat_Error neat_short_tostr(Neat_Mut_String_Ref dst, short obj)
{
    neat_sinteger_tostr();
}

Neat_Error neat_ushort_tostr(Neat_Mut_String_Ref dst, unsigned short obj)
{
    neat_uinteger_tostr();
}

Neat_Error neat_int_tostr(Neat_Mut_String_Ref dst, int obj)
{
    neat_sinteger_tostr();
}

Neat_Error neat_uint_tostr(Neat_Mut_String_Ref dst, unsigned int obj)
{
    neat_uinteger_tostr();
}

Neat_Error neat_long_tostr(Neat_Mut_String_Ref dst, long obj)
{
    neat_sinteger_tostr();
}

Neat_Error neat_ulong_tostr(Neat_Mut_String_Ref dst, unsigned long obj)
{
    neat_uinteger_tostr();
}

Neat_Error neat_llong_tostr(Neat_Mut_String_Ref dst, long long obj)
{
    neat_sinteger_tostr();
}

Neat_Error neat_ullong_tostr(Neat_Mut_String_Ref dst, unsigned long long obj)
{
    neat_uinteger_tostr();
}

Neat_Error neat_float_tostr(Neat_Mut_String_Ref dst, float obj)
{
    char tmp[32] = { 0 };
    int len = snprintf(tmp, sizeof(tmp), "%g", obj);
    return neat_mutstr_ref_copy(
        dst,
        (Neat_String_View){
            .chars = (unsigned char*) tmp,
            .len = len
        }
    );
}

Neat_Error neat_double_tostr(Neat_Mut_String_Ref dst, double obj)
{
    char tmp[32] = { 0 };
    int len = snprintf(tmp, sizeof(tmp), "%g", obj);
    return neat_mutstr_ref_copy(
        dst,
        (Neat_String_View){
            .chars = (unsigned char*) tmp,
            .len = len
        }
    );
}

Neat_Error neat_dstr_tostr(Neat_Mut_String_Ref dst, Neat_DString obj)
{
    return neat_mutstr_ref_copy(dst, (Neat_String_View){.chars = obj.chars, .len = obj.len});
}

Neat_Error neat_dstr_ptr_tostr(Neat_Mut_String_Ref dst, Neat_DString *obj)
{
    return neat_mutstr_ref_copy(dst, (Neat_String_View){.chars = obj->chars, .len = obj->len});
}

Neat_Error neat_strv_tostr(Neat_Mut_String_Ref dst, Neat_String_View obj)
{
    return neat_mutstr_ref_copy(dst, obj);
}

Neat_Error neat_strv_ptr_tostr(Neat_Mut_String_Ref dst, Neat_String_View *obj)
{
    return neat_mutstr_ref_copy(dst, *obj);
}

Neat_Error neat_strbuf_tostr(Neat_Mut_String_Ref dst, Neat_String_Buffer obj)
{
    return neat_mutstr_ref_copy(dst, (Neat_String_View){.chars = obj.chars, .len = obj.len});
}

Neat_Error neat_strbuf_ptr_tostr(Neat_Mut_String_Ref dst, Neat_String_Buffer *obj)
{
    return neat_mutstr_ref_copy(dst, (Neat_String_View){.chars = obj->chars, .len = obj->len});
}

Neat_Error neat_sstr_ref_tostr(Neat_Mut_String_Ref dst, Neat_SString_Ref obj)
{
    return neat_mutstr_ref_copy(dst, (Neat_String_View){.chars = obj.sstr->chars, .len = obj.sstr->len});
}

Neat_Error neat_mutstr_ref_tostr(Neat_Mut_String_Ref dst, Neat_Mut_String_Ref obj)
{
    return neat_mutstr_ref_copy(dst, neat_strv_mutstr_ref2(obj, 0));
}
