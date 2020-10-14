//   NOT DONE


#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coef,pwr;
	struct node *link;
};
typedef struct node node;
node *poly1=NULL,*poly2=NULL,*poly3=NULL;
node *ptr,*ptr1,*ptr2,*ptr3,*a,*b;
void create_poly1();
void create_poly2();
void traverse(node*);
void polymult();
void rmduplicate();
void main()
{
	printf("Enter datas of First polynomial:\n");
	create_poly1();
	printf("Enter datas of second Polynomial:\n");
	create_poly2();
	printf("First Polynomial:\n");
	traverse(poly1);
	printf("\nSecond Polynomial:\n");
	traverse(poly2);
	printf("\nResultant Polynomial:\n");
	polymult();
	traverse(poly3);
}
void create_poly1()
{
	int ch;
	do
	{
		if(poly1==NULL)
		{
			ptr=(node *)malloc(sizeof(node));
			printf("coef:");
			scanf("%d",&ptr->coef);
			printf("pwr:");
			scanf("%d",&ptr->pwr);
			ptr->link=NULL;
			poly1=ptr;
		}
		else
		{
			ptr1=(node *)malloc(sizeof(node));
			printf("coef:");
			scanf("%d",&ptr1->coef);
			printf("pwr:");
			scanf("%d",&ptr1->pwr);
			ptr->link=ptr1;
			ptr1->link=NULL;
			ptr=ptr1;
		}
		printf("Press 1 to add more nodes:");
		scanf("%d",&ch);
	}while(ch==1);
}
void create_poly2()
{
	int ch;
	do
	{
		if(poly2==NULL)
		{
			ptr=(node *)malloc(sizeof(node));
			printf("coef:");
			scanf("%d",&ptr->coef);
			printf("pwr:");
			scanf("%d",&ptr->pwr);
			ptr->link=NULL;
			poly2=ptr;
		}
		else
		{
			ptr1=(node *)malloc(sizeof(node));
			printf("coef:");
			scanf("%d",&ptr1->coef);
			printf("pwr:");
			scanf("%d",&ptr1->pwr);
			ptr->link=ptr1;
			ptr1->link=NULL;
			ptr=ptr1;
		}
		printf("Press 1 to add more nodes:");
		scanf("%d",&ch);
	}while(ch==1);
}
void traverse(node* ptr)
{
	while(ptr!=NULL)
	{
		printf("(%d,%d),",ptr->coef,ptr->pwr);
		ptr=ptr->link;
	}
}
void polymult()
{
	int coef,pwr;
	a=(node *)malloc(sizeof(node));
	b=(node *)malloc(sizeof(node));
	ptr1=poly1;
	ptr2=poly2;
	while(ptr1!=NULL)
	{
		while(ptr2!=NULL)
		{
			coef=ptr1->coef*ptr2->coef;
			pwr=ptr1->pwr+ptr2->pwr;
			if(poly3==NULL)
			{
				a->coef=coef;
				a->pwr=pwr;
				a->link=NULL;
				poly3=a;
			}
			else
			{
				b->coef=coef;
				b->pwr=pwr;
				b->link=NULL;
				a->link=b;
				a=b;
			}	
			ptr2=ptr2->link;
		}	
		ptr1=ptr1->link;
	}
	rmduplicate();
}
void rmduplicate()
{
	ptr3=poly3;
	while(ptr3->link!=NULL)
	{
		ptr=ptr3;
		ptr=ptr->link;
		ptr2=ptr3;
		if(ptr3->pwr==ptr->pwr)
		{
			ptr3->coef=ptr3->coef+ptr->coef;
			ptr2->link=ptr->link;
			ptr=ptr->link;
		}
		else
		{
			ptr2=ptr2->link;
			ptr=ptr->link;
		}
	}
}
