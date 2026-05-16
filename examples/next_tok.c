#include "cgs.h"

int main()
{
    CGS_StrView base = cgs_strv("\ntoken1  token2 \ntoken3\n    ");
    while(base.len)
    {
        CGS_Result(CGS_StrView) res = cgs_next_tok_any(&base, " \n");
        cgs_printfln("('%?', %?)", res.val, res.err);
    }
}
