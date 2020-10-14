#include<stdio.h>
void main()	{
	int queue[20],head,noCyl,loopVar,leftArray[10],rightArray[10],headMove = 0,newHead;
	int lCount = 0,rCount = 0,loopVar2,temp,S_left,S_right,F_end,S_end,var,newArray[20];
	printf("No of cylinders:");
	scanf("%d",&noCyl);
	printf("Head:");
	scanf("%d",&head);
	printf("Queue Values:");
	for(loopVar = 0 ;loopVar < noCyl ; ++loopVar )
		scanf("%d",&queue[loopVar]);
	queue[noCyl] = 0;
	queue[noCyl + 1] = 199;
	noCyl += 2;
	for (loopVar = 0 ;loopVar < noCyl - 1 ; ++loopVar)
		for (loopVar2 = 0 ;loopVar2 < noCyl - loopVar - 1 ; ++loopVar2){
			if (queue[loopVar2] > queue[loopVar2 + 1]){
				temp = queue[loopVar2];
				queue[loopVar2] = queue[loopVar2 + 1];
				queue[loopVar2 + 1] = temp;
			}
		}
	printf("\nHead Movement :%d\t",head);
	for(loopVar = 0 ;loopVar < noCyl ; ++loopVar ){
		if (queue[loopVar] > head){
			S_right = loopVar;
			S_left  = loopVar - 1;
			break;
		}
	}
	if (head > 100){
		F_end = 199;
		S_end = queue[1];
		newHead = S_right;
		var = 1;
	}
	else{
		F_end = 0;
		S_end = queue[noCyl];
		newHead = S_left;
		var = -1;
	}
	temp = 0;
	while (temp < noCyl - 1){
		printf("%d\t",queue[newHead]);
		headMove += abs(head - queue[newHead]);
		head = queue[newHead];
		newHead = newHead + var;
		if (head == F_end){
			if (var > 0){
				var = -1;
				newHead = S_left;
			}
			else{
				var = 1;
				newHead = S_right;
			}
		}
		temp++;
	}
	printf ("\nTotal HeadMovement=%d",headMove);
}	
