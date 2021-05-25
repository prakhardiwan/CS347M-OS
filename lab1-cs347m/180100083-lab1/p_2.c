#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>


int main() {
    int self;
    int parent;

    self = getpid();
    printf("I am parent with PID %d \n", self);
        
    int r1 = fork();

    if(r1!=0){
        int r2 = fork();
        if(r2!=0){
            int r3 = fork();
            if(r3==0){
                self = getpid();
                parent = getppid();
                printf("I am child with PID %d from PPID %d \n", self,parent);
            }
        }
        else{
            self = getpid();
            parent = getppid();
            printf("I am child with PID %d from PPID %d \n", self,parent);
        }
    }
    else{
        self = getpid();
        parent = getppid();
        printf("I am child with PID %d from PPID %d \n", self,parent);
    }

    return 0;

}