#define CGS_SHORT_NAMES
#include "../cgs.h"

int main()
{
    StrBuf buf = strbuf_init_from_buf((char[64]){});
    cgs_copy(&buf, "hello_");
    
    MutStrRef app = cgs_appender(&buf, &(AppenderState){});
    cgs_append(app, "world");
    cgs_commit_appender(&buf, app);
    
    println(buf);
}
