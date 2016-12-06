#include "apue.h"
#include<sys/wait.h>

extern void pr_status(int);
char *env_init[] = {"PATH = /tmp", "USER = unkown", NULL};

int main(void)
{
    pid_t pid;
    int status;

    if((pid = fork()) == -1){
        oops("fork", 1);
    }
    else if(pid == 0){
        execle("/home/yyz/demo_apue/echoall", "echoall", "myarg1", "MY ARG2",
                (char *)0, env_init);
        oops("execle", 2);
    }

    if(wait(&status) == -1)
        oops("wait", 3);
    pr_status(status);

    if((pid = fork()) == -1){
        oops("fork", 4);
    }
    else if(pid == 0){
        execl("/home/yyz/demo_apue/echoall", "echoall", "only arg", (char *)0);
        oops("execl", 5);
    }
    wait(&status);
    pr_status(status);


    exit(0);
}
