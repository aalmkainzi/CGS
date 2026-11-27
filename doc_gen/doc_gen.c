#include "cgs.h"

#define non_newline_whitespace " \f\r\t\v"

typedef struct API
{
    CGS_StrView name;
    struct API *next_variant;
    struct API *next_api;
} API;

int main()
{
    FILE *f = fopen("../cgs.h", "r");
    CGS_DStr cgs_h;
    cgs_fread_until(&cgs_h, f, EOF);
    
    CGS_StrView walk = cgs_strv(cgs_h);
    CGS_Result(CGS_StrView) found_api;
    while((found_api = cgs_find_tokens(walk, non_newline_whitespace, "//", "@", "API", ":")), found_api.err.ec == CGS_OK)
    {
        walk = cgs_strv(walk, (found_api.val.chars + found_api.val.len) - walk.chars);
        walk = cgs_skip_any(walk, non_newline_whitespace);
    }
}
