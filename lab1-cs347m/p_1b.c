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
        int cpid = wait(NULL); // wait for child to exit
        printf("The child process with process ID %d has terminated.\n", r);
    }
    else{
        self = getpid();
        printf("Child process ID: %d \n", self);
    }

    return 0;

}