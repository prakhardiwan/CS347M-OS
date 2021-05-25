#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]) {
  double x = 0.0, z;
  int r1 = fork();
  if(r1==0){ // child 1
  	for(z = 0; z < 400000; z+=0.01){
	      x = x + 3.92*9.29; //Useless calculation to consume CPU Time
    }
    printf(1,"I am child with pid %d and created at %d and I am done \n",getpid(),getctime());
    exit();
  }
  else{		// parent
    for(z = 0; z < 10000; z+=0.01){
        x = x + 3.92*9.29; //Useless calculation to consume CPU Time
    }
  	int r2 = fork();
  	if(r2==0){	// child 2 
  		for(z = 0; z < 400000; z+=0.01){
	      x = x + 3.92*9.29; //Useless calculation to consume CPU Time
    	}
      printf(1,"I am child with pid %d and created at %d and I am done \n",getpid(),getctime());
    	exit();
    }
    else{ // parent 
      for(z = 0; z < 10000; z+=0.01){
        x = x + 3.92*9.29; //Useless calculation to consume CPU Time
      }
    	int r3 = fork();
    	if(r3==0){ // child 3
  			for(z = 0; z < 400000; z+=0.01){
	      		x = x + 3.92*9.29; //Useless calculation to consume CPU Time
    		}
        printf(1,"I am child with pid %d and created at %d and I am done \n",getpid(),getctime());
    		exit();
    	}
    	else{ //parent 
        for(z = 0; z < 10000; z+=0.01){
          x = x + 3.92*9.29; //Useless calculation to consume CPU Time
        }
    		int r4 = fork();
    		if(r4==0){
    			for(z = 0; z < 4000000; z+=0.01){
	     		x = x + 3.92*9.29; //Useless calculation to consume CPU Time
    			}
          printf(1,"I am child with pid %d and created at %d and I am done \n",getpid(),getctime());
    			exit();
    		}
    		else{
    			for(z = 0; z < 4000000; z+=0.01){
	     		x = x + 3.92*9.29; //Useless calculation to consume CPU Time
    			}
          for(z = 0; z < 400000; z+=0.01){
           x = x + 3.92*9.29; //Useless calculation to consume CPU Time
      }
    		}
    	}	
  	}
  } 
  exit();
}
