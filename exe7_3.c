#include "apue.h"

void my_exit1(void);
void my_exit2(void);
int main(void)
{
    if(atexit(my_exit2) != 0)
        oops("atexit", 1);
    if(atexit(my_exit1) != 0)
        oops("atexit", 2);
    if(atexit(my_exit1) != 0)
        oops("atexit", 3);

    printf("main is done\n");

    return 0;
}

void my_exit1(void)
{
    printf("first exit handler\n");
}

void my_exit2(void)
{
    printf("second exit handler\n");
}
