#include<stdio.h>
int main()
{
  int count,j,n;
  int time , remaining;
  int flag=0, quantum=10;
  int wait_t=0,
  turn_around=0,arr_t[10]
  ,burst_t[10]
  ,remain[10];
  
  printf("\n\nEnter the number of processes:\t ");
  scanf("%d",&n);
  remaining=n;
  
  for(count=0;count<n;count++)
  {
    printf("Enter Arrival Time and Burst Time for process %d :",count+1);
    scanf("%d",&arr_t[count]);
    scanf("%d",&burst_t[count]);
    remain[count]=burst_t[count];
  }
  
  printf("Time Quantum:%d\t",quantum);
  printf("\n\n    P   |  Turn around  | Wait Time |\n\n");
  
  for(time=0,count=0;remaining!=0;)
  {
    if(remain[count]<=quantum && remain[count]>0)
    {
      time+=remain[count];
      remain[count]=0;
      flag=1;
    }
    else if(remain[count]>0)
    {
      remain[count]-=quantum;
      time+=quantum;
    }   
    if(remain[count]==0 && flag==1)
    {
      remaining--;
      printf("  P[%d]  |\t%d\t|\t%d|\n",
	  count+1,
	  time-arr_t[count],
	  time-arr_t[count]-burst_t[count]);
      wait_t+=time-arr_t[count]-burst_t[count];
      turn_around+=time-arr_t[count];
      flag=0;
    }
    if(count==n-1)
      count=0;
    else if(arr_t[count+1]<=time)
      count++;
    else
      count=0;
  }
  
  printf("\nAverage Waiting Time= %f\n",wait_t*1.0/n);
  printf("Average Turn around Time = %f",turn_around*1.0/n);
 
  return 0;
}

