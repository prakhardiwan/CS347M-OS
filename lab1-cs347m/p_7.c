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
        printf("Parent: %d \n", self);
        sleep(60);
        int cpid = wait(NULL); // wait for child to exit
        self = getpid();
        printf("Exiting Parent: %d \n", self);
    }
    else{
        self = getpid();
        printf("Child: %d \n", self);
        getchar();
        
    }

    return 0;

}