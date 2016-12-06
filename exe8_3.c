#include "apue.h"

char buf[] = "a write to stdout\n";
int globvar = 88;

int main(void)
{
    int var = 0;
    pid_t pid;

    if(write(STDOUT_FILENO, buf, sizeof(buf)- 1) != sizeof(buf) - 1) 
        oops("write", 1);

    printf("before fork\n");

    if((pid = vfork()) == -1){
        oops("fork", 2);
    }
    else if(pid == 0){
        globvar++;
        var++;
        _exit(0);
    }
    
    printf("pid = %d, globvar = %d, var = %d\n", getpid(), globvar, var);

    exit(0);
}
