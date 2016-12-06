#include<unistd.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>


#define oops(s, n) {perror(s); exit(n);}
#define oois(s, n) {fprintf(stderr, s); exit(n);}

