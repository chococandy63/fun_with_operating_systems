//First come first serve: CPU scheduling algorithm

#include <stdio.h>

int main(){
printf("enter burst time for 5 processes\n");
int burst_time[5];
for(int i=0;i<5;i++){
   scanf("%d",&burst_time[i]);
}

int waiting_time[5];
int turn_around_time[5];
waiting_time[0]=0;
turn_around_time[0]=burst_time[0];
for(int i=1;i<5;i++){
   waiting_time[i]=waiting_time[i-1]+burst_time[i-1];
   turn_around_time[i]=waiting_time[i]+burst_time[i];
}
int total_waiting_time=0;
int total_turn_around_time=0;
for(int i=0;i<5;i++){
   total_waiting_time+=waiting_time[i];
   total_turn_around_time+=turn_around_time[i];
}

int average_waiting_time=total_waiting_time/5;
printf("average waiting time is %d\n",average_waiting_time);

int average_turn_around_time=total_turn_around_time/5;
printf("average turn around time is %d\n",average_turn_around_time);

return 0;
}