#include "cgs.h"

int main()
{
    CGS_StrBuf buf = cgs_strbuf_init_from_buf((char[64]){});
    cgs_copy(&buf, "hello_");
    
    CGS_MutStrRef app = cgs_appender(&buf, &(CGS_AppenderState){});
    cgs_append(app, "world");
    cgs_commit_appender(&buf, app);
    
    cgs_println(buf);
}
