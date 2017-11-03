/*Tree Sort using BST
Coded by Vichitr
vichitrgandas@gmail.com
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left,*right;
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
		if(p1->data>data)
			{
				if(p1->left==NULL)
				{
					p1->left=new;
					return;
				}
				p1=p1->left;
			}
		else if (p1->data<data )
		{
			if(p1->right==NULL)
			{
				p1->right=new;	
				return;
			}
			else
			{
				p1=p1->right;
			}
		}
	}
}

void inorder(struct node * root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

int main()
{
	int i, x;
	printf("How many numbers is to be sorted: ");
	scanf("%d",&x);
	int arr[x];
	printf("Enter numbers:\n");
	for(i=0;i<x;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<x;i++)
		insert(arr[i]);
	printf("Sorted order is:\n");
	inorder(root);
	printf("\n");
	return 0;
}
