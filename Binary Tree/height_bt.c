/*C Program to find number of nodes and Height for given Binary Tree
Coded by Vichitr
vichitrgandas@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct node
{
	int data;
	struct node *leftchild,*rightchild;
};
int t=0;
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

void inorder(struct node * root)
{
	if(root!=NULL)
	{
		inorder(root->leftchild);
		printf("%d ",root->data);
		inorder(root->rightchild);
	}
}


void preorder(struct node * root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->leftchild);
		preorder(root->rightchild);
	}
}

void postorder(struct node * root)
{
	if(root!=NULL)
	{
		postorder(root->leftchild);
		postorder(root->rightchild);
		printf("%d\n\n ",root->data);
	}
	
}
 int node(struct node * root)
{
	int c=1;
	if (root ==NULL)
	return 0;
	else
	{
		c+=node(root->leftchild);
		c+=node(root->rightchild);
		return c;
	}


}

int height(struct node *root)
{
	if(root == NULL)
		return 0;
	else
	{
		int lh = height(root->leftchild);
		int rh = height(root->rightchild);
		
		if(lh > rh)
			return lh+1;
		else
			return rh+1;
	}
}

int main()
{
	int data,x,t;
	do
	{
		printf("1.Insert 2.Preorder 3.Inorder 4.Postorder 5.Height 6.Exit\n");
		scanf("%d",&x);
		switch(x)
		{
			case 1: 
				printf("data : ");
				scanf("%d",&data);
				insert(data);
				break;
			case 2:
			    printf("preorder \n\n");
				preorder(root);
				printf("\n\n");
				break;
			case 3:
			    printf("Inorder\n\n");
				inorder(root);
				printf("\n\n");
				break;
			case 4:
			    printf("Postorder\n\n");
				postorder(root);
				printf("\n\n");
				break;
			case 5:
				t=node(root);
				printf("Total numbers of nodes: %d\n",t);
				printf("Height of the tree: %d\n", height(root)-1);
				break;
			case 6:
			    break;
			default:
			    printf("Invalid choice\n");
		}
	}while(x!=6);
}
