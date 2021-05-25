#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h" 

int
main(int argc, char *argv[])
{
    int pid, priority;

    if(argc < 3){
        printf(2, "Usage: change_prio pid priority\n");
        exit();
    }
    pid = atoi(argv[1]);
    priority = atoi(argv[2]);
    if(priority<0 || priority>50){
        printf(2, "Invalid priority value\n");
        exit();
    }
    change_priority(pid, priority);
    exit();
}