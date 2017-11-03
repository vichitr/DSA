/*C Program to find Maximum Height of a Binary Search Tree
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
		if(p1->data>data)
			{
				if(p1->leftchild==NULL)
				{
					p1->leftchild=new;
					return;
				}
				p1=p1->leftchild;
			}
		
		else if (p1->data<data )
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

int findheight(struct node * root)
{
	int lheight,rheight;
	if(root==NULL)
		return 0;
	else
	{
		lheight=findheight(root->leftchild);
		rheight=findheight(root->rightchild);
		if(lheight>rheight)
			return lheight+1;
		else
			return rheight+1;	
	}
}

void inorder(struct node * root)
{
	if(root!=NULL)
	{
		inorder(root->leftchild);
		printf("%d ",root->data);
		inorder(root->rightchild);
	}
}

int main()
{
	int data,x,key,t;
	do
	{
		printf("1.Insert 2.Inorder 3.Height 4.Exit: ");
		scanf("%d",&x);
		switch(x)
		{
			case 1: 
				printf("Data : ");
				scanf("%d",&data);
				insert(data);
				break;
			case 2:
			    printf("Inorder: ");
				inorder(root);
				printf("\n");
				break;
			case 3:
				t=findheight(root);
			    printf("Maximum height of tree is %d\n",t-1);
				break;
			case 4:
				break;
			default:
				printf("Invalid choice\n");
		}
	}while(x!=4);
	return 0;
}
