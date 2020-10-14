#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#define SIZE 20
struct DataItem
{
	int data;
	int key;
};
typedef struct DataItem DataItem;
DataItem* hashArray[SIZE];
DataItem* dummyItem;
DataItem* item;
int hashCode(int key)
{
	return key % SIZE;
}
DataItem * search(int key)
{
	int hashIndex=hashCode(key);
	while(hashArray[hashIndex]!=NULL)
	{
		if(hashArray[hashIndex]->key==key)
			return hashArray[hashIndex];
		++hashIndex;
		hashIndex %= SIZE;
	}
	return NULL;
}
void insert(int key,int data)
{
	DataItem *item=(DataItem*)malloc(sizeof(DataItem));
	item->data=data;
	item->key=key;
	int hashIndex=hashCode(key);
	while(hashArray[hashIndex]!=NULL && hashArray[hashIndex]->key!=-1)
	{
		++hashIndex;
		hashIndex %= SIZE;
	}
	hashArray[hashIndex]=item;
}
DataItem* delete(DataItem* item)
{
	int key=item->key;
	int hashIndex=hashCode(key);
	while(hashArray[hashIndex]!=NULL)
	{
			if(hashArray[hashIndex]->key==key)
			{
				DataItem* temp=hashArray[hashIndex];
				hashArray[hashIndex]=dummyItem;
				return temp;
			}
			++hashIndex;
			hashIndex %= SIZE;
	}
	return NULL;
}
void display()
{
	int i=-0;
	for(i=0;i<SIZE;i++)
	{
		if(hashArray[i]!=NULL)
			printf(" (%d,%d) ",hashArray[i]->key,hashArray[i]->data);
		else
			printf("~~");
	}
	printf("\n");
}
void main()
{
	dummyItem=(DataItem*)malloc(sizeof(DataItem));
	dummyItem->data=-1;
	dummyItem->key=-1;
	insert(2,20);
	insert(42,80);
	insert(4,25);
	insert(12,44);
	insert(14,32);
	insert(17,11);
	insert(13,78);
	insert(37,97);
	display();
	item=search(37);
	if(item!= NULL)
		printf("Element found: %d\n",item->data);
	else
		printf("Element Not Found\n");
	delete(item);
	item=search(37);
	if(item!= NULL)
		printf("Element found: %d\n",item->data);
	else
		printf("Element Not Found\n");
}
