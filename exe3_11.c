#include"apue.h"

int main(int argc, char *argv[])
{
    int flag;

    if(argc != 2){
        fprintf(stderr, "Usage: a.out<discriptor>");
        exit(1);
    }
    
    if((flag = fcntl(atoi(argv[1]), F_GETFL, 0)) == -1)
        oops("fcntl", 1);
    
    switch(flag & O_ACCMODE){
        case O_RDONLY:
            printf("read only");
            break;
        case O_WRONLY:
            printf("write only");
            break;
        case O_RDWR:
            printf("read and write");
            break;
        default:
            fprintf(stderr, "unknown this mode");
            exit(1);
    }
    if(flag & O_APPEND)
        printf(", append");

    if(flag & O_NONBLOCK)
        printf(", no blocking");

    if(flag & O_SYNC)
        printf(", wait true I/O done");

    printf("\n");

    return 0;
}
