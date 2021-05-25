#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int fd;
    //FILE *fptr;
    if ( argc != 2 ){ /* argc should be 2 for correct execution */
    
        /* We print argv[0] assuming it is the program name */
        printf( "usage: %s filename", argv[0] );
    }
    else{
        // We assume argv[1] is a filename to open
        //fptr = fopen( argv[1], "w" );
        fd = open( argv[1], O_RDONLY);
    }
    int r = fork();

    if(r!=0){ // Parent goes here 
        int cpid = wait(NULL); // wait for child to exit
    }
    else{ // Child here
        char *myargs [] = { NULL };
        char *myenv [] = { NULL };
        dup2(fd, STDIN_FILENO);
        close(fd);
        execve ("sample", myargs, myenv);
        
    }

    return 0;

}
