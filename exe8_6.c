#include "apue.h"
#include<sys/wait.h>

extern void pr_status(int);

int main(void)
{
    pid_t pid;
    int status;

    if((pid = fork()) == -1){
        oops("fork", 1);
    }
    else if(pid == 0)
        exit(7);

    if(wait(&status) == -1)
        oops("wait", 2);
    pr_status(status);
    
    if((pid = fork()) == -1){
        oops("fork", 3);
    }
    else if(pid == 0)
        abort();
    if(wait(&status) == -1)
        oops("wait", 4);
    pr_status(status);

    
    if((pid = fork()) == -1){
        oops("fork", 5);
    }
    else if(pid == 0)
        status = status / 0;
    if(wait(&status) == -1)
        oops("wait", 6);
    pr_status(status);

}

