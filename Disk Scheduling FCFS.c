#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void main(){
	 int q[10],nor,head,total=0,i;
	 clrscr();
	 printf("No of cylinders:");
	 scanf("%d",&nor);
	 printf("Head:");
	 scanf("%d",&head);
	 printf("cylinders:");
	 for(i=0;i<nor;++i){
		  scanf("%d",&q[i]);
		  total+=abs(head-q[i]);
		  head=q[i];
	 }
	 printf("Total Head Movement:%d",total);
	 getch();
}

