#include "apue.h"

int globvar = 0;
char buf[] = "a write to stdout\n";

int main(void)
{
    pid_t pid;
    int var = 99;

    if(write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
        oops("write", 1);

    printf("before fork\n");

    if((pid = fork()) == -1){
        oops("fork", 2);
    }
    else if(pid == 0){
        globvar++;
        var++;
    }
    else
        sleep(2);

    printf("pid = %d, glob = %d, var = %d\n", getpid(), globvar, var);
    exit(0);
}
