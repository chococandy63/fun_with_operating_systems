#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    int pid=fork(); //create a child process
    if(pid>0){//it is a parent process

    printf("Id of Parent process: %d", getpid());

    }
    else(pid==0){//it is a child process

    printf("Id of Child process: %d",getpid());
        printf("Id of Parent process: %d", getppid());

    sleep(10);

    printf("Child Process ID: %d",getpid());
    printf("Parent Process ID: %d",getppid());



    }
    else{
        printf("failed to create a child process");
    }


    return 0;
}