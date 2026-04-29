#include "cgs.h"

int main()
{
    int array[] = {1,2,3,4,5,6,7,8,9,10};
    
    cgs_printfln("%?", cgs_arrfmt(array,10)); // default format, prints "{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}"
    cgs_printfln("%?", cgs_arrfmt(array,10, "[[", "]]", "--")); // open, close, and delim
    cgs_printfln("%?", cgs_arrfmt(array,10, "(", ")", ", ", ",")); // trailing delim
}