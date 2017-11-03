/*C Program to check given Tree is BST
Coded by Vichitr
vichitrgandas@gmail.com
*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *leftchild,*rightchild;
};
struct node *root = NULL; 
int c=0;
void insert(int data)
{
	struct node *new=(struct node *)malloc(sizeof(struct node));
	struct node *p1=root;

	int x,flag;
	new->data=data;
	new->leftchild=NULL;
	new->rightchild=NULL;
	if(root==NULL)
	{
		root=new;
		return;
	}
	while(1)
	{
		
		printf("Insert left(0) or right(1) of %d: ",p1->data);
		scanf("%d",&x);
		if(x==0 )
		{
			if(p1->leftchild==NULL)
			{
				p1->leftchild=new;
				return;
			}
			p1=p1->leftchild;
		}
		else if (x==1 )
		{
			
			if(p1->rightchild==NULL)
			{
				p1->rightchild=new;	
				return;
			}
			else
			{
				p1=p1->rightchild;
			}
		}
	}
	
}
void check(struct node *p)
{
	if(p!=NULL)
	{
			if(p->leftchild!=NULL&&p->leftchild->data>p->data ||  p->rightchild!=NULL&&p->rightchild->data<p->data)
			{
				printf("Tree is not BST\n");
				c=1;
				exit(0);
			}
		check(p->leftchild);
		check(p->rightchild);
	}
	
}


int main()
{
	int data,x;
	do
	{
		printf("1. Insert 2. Check 3. Exit : ");
		scanf("%d",&x);
		switch(x)
		{
			case 1: 
				printf("Data : ");
				scanf("%d",&data);
				insert(data);
				break;
			case 2:
				check(root);
				if(c==0)
				printf("Tree is BST\n");
				break;
			case 3:
			    break;
			default:
			    printf("Invalid Choice\n");
		}
	}while(x != 3);
	return 0;
}
