#include<stdio.h>
#include<conio.h>
struct process
{
 int bt,wt,tt;
 char name[10];
};
typedef struct process process;
void main()
{
 int nop,i;
 process p[10];
 clrscr();
 printf("No of Process:");
 scanf("%d",&nop);
 p[0].wt=0;
 p[0].bt=0;
 p[0].tt=0;
 printf("Enter details of process:");
 for(i=1;i<=nop;++i)
 {
  printf("\nName of process %d:",i);
  scanf("%s",&p[i].name);
  printf("Burst time:");
  scanf("%d",&p[i].bt);
 }
printf("Execution:\n");
 printf("Process\t  Burst Time\tTurn Around Time\tWaiting Time\n");
 for(i=1;i<=nop;++i)
 {
  p[i].wt=p[i-1].wt+p[i-1].bt;
  p[i].tt=p[i].wt+p[i].bt;
  printf("%s\t\t%d\t\t%d\t\t%d\n",p[i].name,p[i].bt,p[i].tt,p[i].wt);
 }
 printf("\nAverage Waiting Time:%d",p[i-1].wt/nop);
 printf("\nAverage Turn Around Time:%d",p[i-1].tt/nop);
 getch();
}



