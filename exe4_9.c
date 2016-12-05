#include "apue.h"
#include<sys/types.h>
#include<sys/stat.h>

int main(void)
{
    umask(0);

    if(creat("foo", 0666) == -1)
        oops("creat foo", 1);

    umask(0066);

    if(creat("bar", 0666) == -1)
        oops("creat bar", 2);

    return 0;
}
