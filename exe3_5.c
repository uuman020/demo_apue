#include"cpt1.h"

int main(void)
{
    char buf[BUFSIZ];
    int n;

    while((n = read(STDIN_FILENO, buf, BUFSIZ)) > 0){
        if(write(STDOUT_FILENO, buf, n) != n){
            perror("write");
            exit(1);
        }
    }

    if(n == -1){
        perror("read");
        exit(1);
    }

    return 0;
}
