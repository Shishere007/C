#include<stdio.h>
#include<conio.h>
void sort(int count);
int arr[20];
void main()
{
	int i,count,key,start,end,middle,flag=0;
	printf("Count:");
	scanf("%d",&count);
	printf("Enter numbers:");
	for(i=0;i<count;++i)
		scanf("%d",&arr[i]);
	printf("Number to Search:");
	scanf("%d",&key);
	sort(count);
	start=0;
	end=count-1;
	while(start<=end)
	{
		middle=(start+end)/2;
		if(key>arr[middle])
			start=middle+1;
		else if(key<arr[middle])
			end=middle-1;
		else
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		printf("Number is Found");
	else
		printf("Number is not found");
	getch();
}

void sort(int count)
{
	int i,j,temp;
	for(i=0;i<count-1;++i)
		for(j=0;j<count-i-1;++j)
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
}

