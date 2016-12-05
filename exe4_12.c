#include "apue.h"
#include <sys/stat.h>

int main(void)
{
    struct stat buf;

    if(stat("bar", &buf) == -1)
        oops("stat", 1);
    if(chmod("bar", (buf.st_mode & ~S_IWUSR) | S_IRGRP) == -1)
        oops("chmod", 2);

    if(chmod("foo", 0000) == -1)
        oops("chmod", 3);

    return 0;
}
