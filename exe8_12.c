#include "apue.h"

void chartime(char *);

int main(void)
{
    int pid;

    if((pid = fork()) == -1){
        oops("fork", 1);
    }
    else if(pid == 0)
        chartime("a write from child\n");
    else
        chartime("a write from parent\n");

    exit(0);
}

void chartime(char *s)
{
    int c;
    char *s1 = s;
    setbuf(stdout, NULL);

    while(s1++ != 0){
        c = *s1;
        putc(c, stdout);
    }
}
