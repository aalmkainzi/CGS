#define CGS_SHORT_NAMES
#include "../cgs.c"

int main()
{
    DStr d = dstr_init();
    cgs_copy(&d, "hello_");
    
    MutStrRef app = cgs_appender(&d, &(AppenderState){});
    cgs_append(app, "world");
    cgs_commit_appender(&d, app);
    
    println(d);
}
