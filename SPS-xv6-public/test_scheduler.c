#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[]) {
  double x = 0.0, z;
  int r1 = fork();
  if(r1==0){ // child 1
  	printf(1,"Child %d created\n",getpid());
    change_priority(getpid(), 8);
    printf(1,"Child %d assigned priority %d \n",getpid(),getprio());
  	for(z = 0; z < 400000; z+=0.01){
	      x = x + 3.92*9.29; //Useless calculation to consume CPU Time
    }
    printf(1,"I am child with pid %d and priority variable = %d ; and I am done. \n",getpid(), getprio());
    exit();
  }
  else{		// parent
    		int r2 = fork();
    		if(r2==0){
    			printf(1,"Child %d created\n",getpid());
          change_priority(getpid(), 9);
          printf(1,"Child %d assigned priority %d \n",getpid(),getprio());
    			for(z = 0; z < 4000000; z+=0.01){
	     		x = x + 3.92*9.29; //Useless calculation to consume CPU Time
    			}
          printf(1,"I am child with pid %d and priority variable = %d ; and I am done. \n",getpid(), getprio());
    			exit();
    		}
    		else{
    			printf(1,"I am Parent with %d \n",getpid());	
  	}
  } 
  exit();
}