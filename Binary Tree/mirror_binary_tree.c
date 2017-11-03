/*C Program to create Mirror of a given Binary Tree
Coded by Vichitr
vichitrgandas@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *left, *right;
};
struct node *root = NULL;

void insert(int data)
{
	struct node *new=(struct node *)malloc(sizeof(struct node));
	struct node *p1=root;

	int x,flag;
	new->data=data;
	new->left=NULL;
	new->right=NULL;
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
			if(p1->left==NULL)
			{
				p1->left=new;
				return;
			}
			p1=p1->left;
		}
		else
		{
			
			if(p1->right==NULL)
			{
				p1->right=new;	
				return;
			}
			p1=p1->right;
		}
	}
	
}

void mirror(struct node *root)
{
	if(root==NULL)
		return;
	else
	{
		struct node *temp;
		mirror(root->left);
		mirror(root->right);
		
		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
}

void inorder(struct node * root)
{
	if(root!=NULL)
	{
		//printf("%d ",root->data);
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

void preorder(struct node * root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct node * root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
	
}

int main()
{
	int data,x,key;
	do
	{
		printf("1.Insert 2.Preorder 3.Inorder 4.Postorder 5.Mirror 6.Exit\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1: 
				printf("Data : ");
				scanf("%d",&data);
				insert(data);
				break;
			case 2:
			    printf("Preorder: ");
				preorder(root);
				printf("\n");
				break;
			case 3:
			    printf("Inorder:");
				inorder(root);
				printf("\n");
				break;
			case 4:
			    printf("Postorder:");
				postorder(root);
				printf("\n");
				break;
			case 5:
				mirror(root);
				break;
			case 6:
				break;
			default:
				printf("Invalid choice\n");
				break;
		}
	}while(x!=6);
}
