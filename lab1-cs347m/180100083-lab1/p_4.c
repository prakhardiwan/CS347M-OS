#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    FILE *fptr;
    if ( argc != 2 ){ /* argc should be 2 for correct execution */
    
        /* We print argv[0] assuming it is the program name */
        printf( "usage: %s filename", argv[0] );
    }
    else{
        // We assume argv[1] is a filename to open
        fptr = fopen( argv[1], "w" );
    }
    
    if(fptr == NULL){
      printf("Error!");   
      exit(1);             
    }
    
    int r = fork();

    if(r!=0){
        fprintf(fptr,"Hello world! I am parent\n");
        fflush(fptr);
        int cpid = wait(NULL); // wait for child to exit
        //fclose(fptr);
        printf("The child process with process ID %d has terminated.\n", r);
    }
    else{
        fprintf(fptr,"Hello world! I am child\n");
        fclose(fptr);
    }

    return 0;

}
