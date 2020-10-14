#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
	int data;
	struct node *rlink;
	struct node *llink;
}*tmp=NULL;
typedef struct node NODE;
NODE *create();
void preorder(NODE *);
void inorder(NODE *);
void postorder(NODE *);
void insert(NODE *);
void main()
{
	int n,i,m;
	do
	{
		printf("1.Create\n2.Insert \n3.Preorder\n4.Postorder\n5.Inorder\n6.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&m);
		switch(m)
		{
			case 1:	tmp=create();
							break;
			case 2:	insert(tmp);
							break;
			case 3:	printf("\nDisplay tree in Preorder traversal:\n");
							preorder(tmp);
							printf("\n\n");
							break;
			case 4:	printf("\nDisplay Tree in Postorder:\n");
							postorder(tmp);
							printf("\n\n");
							break;
			case 5:	printf("\nInorder:\n");
							inorder(tmp);
							printf("\n\n");
							break;
			case 6: 	goto end;
			default: printf("\nWrong option chooosed..!!\n\n");
		}	
	}
	while(n!=5);
	end:
	getch();
}
void insert(NODE *root)
{
	NODE *newnode;
	if(root==NULL)
	{
		newnode=create();
		root=newnode;
	}
	else
	{
		newnode=create();
		while(1)
		{
			if(newnode->data<root->data)
			{
				if(root->llink==NULL)
				{
					root->llink=newnode;
					break;
				}		
				root=root->llink;
			}
			if(newnode->data>root->data)
			{
				if(root->rlink==NULL)
				{
					root->rlink=newnode;
					break;
				}
				root=root->rlink;
			}
		}
	}
}
NODE *create()
{
	NODE *newnode;
	int n;
	newnode=(NODE *)malloc(sizeof(NODE));
	printf("Enter the Data:");
	scanf("%d",&n);
	newnode->data=n;
	newnode->llink=NULL;
	newnode->rlink=NULL;
	return(newnode);
}
void postorder(NODE *tmp)
{
	if(tmp!=NULL)
	{
	postorder(tmp->llink);
	postorder(tmp->rlink);
	printf("%d->",tmp->data);
	}
}
void inorder(NODE *tmp)
{
	if(tmp!=NULL)
	{
	inorder(tmp->llink);
	printf("%d->",tmp->data);
	inorder(tmp->rlink);
	}
}
void preorder(NODE *tmp)
{
	if(tmp!=NULL)
	{
		printf("%d->",tmp->data);
		preorder(tmp->llink);
		preorder(tmp->rlink);
	}
}


