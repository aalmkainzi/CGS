
#define NEAT_PRIVATE static inline
#define NEAT_API     static inline
#define NEAT_STR_SHORT_NAMES
#include "../neat_str.c"

constexpr int asize = 1048576;

static inline int *make_rand_arr(size_t bsize)
{
    int *arr = malloc(bsize * sizeof(int));
    for(size_t i = 0 ; i < bsize ; i++)
    {
        arr[i] = rand() % 10000;
    }
    return arr;
}

size_t nsbm(size_t bsize)
{
    srand(bsize);
    int *arr = make_rand_arr(bsize);
    String_Buffer sb = strbuf_init_from_buf(malloc(asize), asize);
    tostr(&sb, arrfmt(arr, bsize, "[[", "]]", ", "));
    
    println(sb);
    
    size_t ret = sb.len;
    
    free(arr);
    free(sb.chars);
    
    return ret;
}

size_t stdbm(size_t bsize)
{
    srand(bsize);
    int *arr = make_rand_arr(bsize);
    char *s = malloc(asize);
    strcpy(s, "[[");
    size_t len = 2;
    for(size_t i = 0 ; i < bsize - 1 ; i++)
    {
        len += sprintf(s + len, "%d, ", arr[i]);
    }
    len += sprintf(s + len, "%d]]", arr[bsize - 1]);
    
    free(arr);
    free(s);
    
    return len;
}

size_t std_it2str(size_t i)
{
    char C[32];
    sprintf(C, "%zu", i);
    return strlen(C);
}

size_t neat_it2str(size_t i)
{
    char C[32];
    tostr(C, i);
    return strlen(C);
}
