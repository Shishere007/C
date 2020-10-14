#include<stdio.h>
#include<conio.h>
void swap(int *x,int *y)
{
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}
void quickSort(int a[],int first,int last)
{
	int pivot,i,j,number=last+1;
	if(first<last)
	{
		pivot=first;
		i=first;
		j=last;
		while(i<j)
		{
			while(a[i]<=a[pivot] && j<last)
				j++;
			while(a[j]>a[pivot])
				j--;
			if(i<j)
				swap(&a[i],&a[j]);
		}
		swap(&a[pivot],&a[j]);
		quickSort(a,first,j-1);
		quickSort(a,j+1,last);
	}
	printf("\nSorted Array:\n");
	for(i=0;i<number;++i)
		printf("%d\t",a[i]);
}
void main()
{
	int a[100],number,i;
	printf("Count:");
	scanf("%d",&number);
	printf("Enter Numbers:");
	for(i=0;i<number;++i)
		scanf("%d",&a[i]);
	quickSort(a,0,number-1);
	printf("Sorted Array:\n");
	for(i=0;i<number;++i)
		printf("%d\t",a[i]);
	getch();
}

