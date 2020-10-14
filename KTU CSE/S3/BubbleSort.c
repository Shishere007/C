#include<stdio.h>
#include<conio.h>
void main()
{
	int arr[20],i,j,count,temp;
	printf("Count:");
	scanf("%d",&count);
	printf("Enter numbers:");
	for(i=0;i<count;++i)
		scanf("%d",&arr[i]);
	for(i=0;i<count-1;++i)
		for(j=0;j<count-i-1;++j)
			if(arr[j]>arr[j+1])
			{
				printf("qqn\n");
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
	printf("\nSorted Array:\n");
	for(i=0;i<count;++i)
		printf("%d\t",arr[i]);
	getch();
}

