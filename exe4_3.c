#include "apue.h"
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    int i;
    struct stat buf;

    if(argc == 1)
        oois("Usage: a.out <filename...>", 1);

    for(i = 1; i < argc; i++){
        if(lstat(argv[i], &buf) == -1) 
            oops("stat failed", 2);

        if(S_ISREG(buf.st_mode))
            printf("%s: regular\n", argv[i]);

        else if(S_ISDIR(buf.st_mode))
            printf("%s: dictionary\n", argv[i]);

        else if(S_ISCHR(buf.st_mode))
            printf("%s: character special\n", argv[i]);

        else if(S_ISBLK(buf.st_mode))
            printf("%s: block special\n", argv[i]);

        else if(S_ISFIFO(buf.st_mode))
            printf("%s: fifo\n", argv[i]);

        else if(S_ISLNK(buf.st_mode))
            printf("%s: symbolic link\n", argv[i]);

        else if(S_ISSOCK(buf.st_mode))
            printf("%s: socket", argv[i]);
    }

    return 0;
}

