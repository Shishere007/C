#include<stdio.h>
#include<conio.h>
void main()
{
	int arr[20],i,count,key,flag=0;
	printf("Count:");
	scanf("%d",&count);
	printf("Enter Numbers:");
	for(i=0;i<count;++i)
		scanf("%d",&arr[i]);
	printf("Number to Search:");
	scanf("%d",&key);	
	for(i=0;i<count;++i)
		if(arr[i]==key)
		{
			flag=1;
			printf("Number is present");
			break;
		}
	if(flag==0)
		printf("Number is not present.");
	getch();
}

