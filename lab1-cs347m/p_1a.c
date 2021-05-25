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
        self = getpid();
        printf("Parent: My process ID: %d \n", self);
        printf("Parent: Child's process ID: %d \n", r);
        //int cpid = wait(NULL); // wait for child to exit
        getchar();
    }
    else{
        self = getpid();
        parent = getppid();
        printf("Child: My process ID: %d \n", self);
        printf("Child: Parent’s process ID: %d \n", parent);

    }

    return 0;

}