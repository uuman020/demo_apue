#include "apue.h"
#include<sys/wait.h>

void pr_status(int state)
{
    if(WIFEXITED(state))
        printf("normal termination, exit status = %d\n", WEXITSTATUS(state));
    else if(WIFSIGNALED(state))
        printf("abnormal termination, signal number = %d%s\n", WTERMSIG(state),
    #ifdef WCOREDUMP
                WCOREDUMP(state) ? " (core file generated)" : "");
    #else
                "");
    #endif
}
