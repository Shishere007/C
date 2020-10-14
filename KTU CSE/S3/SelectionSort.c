#include<stdio.h>
#include<conio.h>
void swap(int *x, int *y) 
{ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 

void selectionSort(int arr[], int n) 
{ 
	int i, j, min; 
	for (i = 0; i < n-1; i++) 
	{ 
		min = i; 
		for (j = i+1; j < n; j++) 
		if (arr[j] < arr[min]) 
			min = j; 
		swap(&arr[min], &arr[i]); 
	} 
} 
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 
} 
int main() 
{ 
	int arr[5],i,n=5;
	n=5;
	printf("Element count is limted to 5..!!\n");
	printf("Enter 5 Numbers:");
	for(i=0;i<n;++i)
		scanf("%d",&arr[i]);
	selectionSort(arr,n);
	printf("Sorted Array:\n");
	printArray(arr,n);
	getch();
} 

