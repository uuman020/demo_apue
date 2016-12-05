#include "apue.h"

int main(int argc, char *argv[])
{
    if(argc == 1)
        oois("Usage: a.out <filename>", 1);

    if(access(argv[1], R_OK) == -1)
        perror("access error");
    else
        printf("access ok\n");

    if(open(argv[1], O_RDONLY) == -1)
        perror("open error");
    else
        printf("open ok\n");

    return 0;
}
