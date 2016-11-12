#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

char str1[] = "abcdefghijkmlnop";
char str2[] = "ABCDEFGHIJKLMNOP";

int main(void)
{
    int fd;

    if((fd = creat("file.hole", 0644)) == -1){
        perror("creat");
        exit(1);
    }

    if(write(fd, str1, 0x10) != 0x10){
        perror("write");
        exit(1);
    }

    if(lseek(fd, 0x10, SEEK_CUR) == -1){
        perror("seek");
        exit(1);
    }

    if(write(fd, str2, 0x10) != 0x10){
        perror("write");
        exit(1);
    }
    
    return 0;
}
