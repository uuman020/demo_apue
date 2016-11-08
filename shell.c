#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

#define MAXARG 20
#define BUFLEN 20

char *makestring(char *);
void execute(char **);
void free_args(char **);
int main(void) {
    char *arglist[MAXARG];
    char buf[BUFLEN];
    int numargs = 0;

    /*
     * 若第一个输入的就是回车，则跳过
     * 不是第一个输入的回车，则执行execvp
     * 参数数量要小于20，最后一个用于null
     */
    while(numargs < MAXARG - 1){
        printf("arg[0]?>>");
        if(fgets(buf, BUFLEN, stdin) && buf[0] != '\n'){
            arglist[numargs++] = makestring(buf);
        }
        else{
            if(numargs > 0){
                arglist[numargs] = (char *)0;
                execute(arglist);

                numargs = 0;     /*reset*/
                free_args(arglist); /* 内存泄露！*/
            }
        }
    }

    fprintf(stderr, "too many args!");
    exit(1);
}

void execute(char *args[]){
    int pid;

    if((pid = fork()) == -1){
        perror("fork");
        exit(1);
    }

    if(pid == 0){
        execvp(args[0], args);
        perror("faile to exec");
        exit(1);
    }

    else{
        while(wait(NULL) != pid)
            ;
    }
}

char *makestring(char *input){
    char *rv_str;
    int len;

    len = strlen(input);

    rv_str = (char *)malloc(len);
    if(rv_str == NULL){
        fprintf(stderr, "malloc failed");
        exit(2);
    }

    input[len - 1] = '\0';
    strcpy(rv_str, input);

    return rv_str;

}

void free_args(char *args[])
{
    int i;

    for(i = 0; args[i] != NULL; i++){
        free(args[i]);
    }
}
