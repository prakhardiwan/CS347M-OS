#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>


int main() {
    int self;
    int parent;

    int r = fork();

    if(r!=0){
        sleep(1);
        self = getpid();
        printf("Parent: Parent process ID: %d \n", self);
    }
    else{
        self = getpid();
        parent = getppid();
        printf("Child: Child process ID: %d \n", self);
        printf("Child: Parent process ID: %d \n", parent);
        sleep(2);
        self = getpid();
        parent = getppid();
        printf("Child: Child process ID: %d \n", self);
        printf("Child: Parent process ID: %d \n", parent);
    }

    return 0;

}