/*Orphan Process: The process whose parent process has finished (Completed execution) or terminated and do not exists in the process table are called orphan process. Usually, a parent process waits for its child to terminate or finish their job and report to it after execution but if he fails to do so it results in the Orphan process.*/
/*Suppose P1 and P2 are two process such that P1 is the parent process and P2 is the child process of P1. Now, if P1 finishes before P2 finishes, then P2 becomes an orphan process*/

/*Zombie process: A process which has finished the execution but still has entry in the process table to report to its parent process is known as a zombie process. A child process always first becomes a zombie before being removed from the process table */

#include <stdio.h>
#include <unistd.h>
int main() {
   int x = fork(); //create child process
   if (x > 0) //if x is non zero, then it is parent process
      printf("Inside Parent---- PID is : %d
", getpid());
   else if (x == 0) { //for chile process x will be 0
      sleep(5); //wait for some times
      x = fork();
      if (x > 0) {
         printf("Inside Child---- PID :%d and PID of parent : %d
", getpid(), getppid());
         while(1)
            sleep(1);
         printf("Inside Child---- PID of parent : %d
", getppid());
      }else if (x == 0)
      printf("Inside grandchild process---- PID of parent : %d
", getppid());
   }
   return 0;
}