#include"cpt1.h"

void set_fl(int fd, int flag,int opt)
{
    int state;

    if((state = fcntl(fd, F_GETFL, 0)) == -1){
        oops("fcntl getfl error", 1);
    }

    if(opt == 0){
        state &= ~flag;
    }
    else if(opt == 1){
        state |= flag;
    }
    else{
        fprintf(stderr, "no such opt");
        exit(1);
    }

    if(fcntl(fd, F_SETFL, state) == -1){
        oops("fcntl setfl error", 2);
    }
}

