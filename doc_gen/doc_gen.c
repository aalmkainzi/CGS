#include "cgs.h"

#define non_newline_whitespace " \f\r\t\v"
#define whitespace non_newline_whitespace "\n"

typedef struct API
{
    CGS_StrView name;
    struct API *next_variant;
    struct API *next_api;
} API;

int main()
{
    FILE *f = fopen("../cgs.h", "r");
    CGS_DStr cgs_h = cgs_dstr_init();
    _Defer cgs_dstr_deinit(&cgs_h);

    cgs_fread_until(&cgs_h, f, EOF);

    CGS_StrView walk = cgs_strv(cgs_h);
    CGS_Result(CGS_StrView) found_api;
    while((found_api = cgs_find_tokens(walk, non_newline_whitespace, "//", "@", "API", ":")), found_api.err.ec == CGS_OK)
    {
        walk = cgs_strv(walk, (found_api.val.chars + found_api.val.len) - walk.chars);

        unsigned int found_newline = cgs_find(walk, '\n').val;

        CGS_StrView line = cgs_strv(walk, 0, found_newline);
        auto name_token = cgs_next_token(&line, non_newline_whitespace);

        if (name_token.err.ec != CGS_OK)
        {
            cgs_fprintf(stderr, "expected a name");
            return 1;
        }

        cgs_printf("found an API of the name: %?\n", name_token.val);
    }
}
