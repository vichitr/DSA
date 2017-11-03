/* C Program To check whether a Binary Tree is Complete/Full/Perfect 
Coded by Vichitr
vichitrgandas@gmail.com
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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
		else if (x==1 )
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

int node(struct node * root)
{
	int c=1;
	if (root ==NULL)
	return 0;
	else
	{
		c+=node(root->left);
		c+=node(root->right);
		return c;
	}


}
int complete(struct node * root,int i,int t)
{
	
	if(root==NULL)
		return 1;
	if(i>=t)
		return 0;
	return (complete(root->left,2*i+1,t) && complete(root->right,2*i+2,t));
}

int full(struct node* root)
{
	if (root==NULL)
    	return 1;
	if(root->left==NULL && root->right==NULL)
		return 1;
	if(root->left&&root->right)
	    return (full(root->left)&&full(root->right));
	return 0;
}

int depth(struct node *root)
{
	int i = 0;
	while (root != NULL)
	{
		i++;
		root = root->left;
	}
	return i;
}

int perfect(struct node *root, int t, int l)
{
	if(root == NULL)
		return 1;
	if(root->left == NULL && root->right == NULL)
		return (t == l+1);
	if(root->left == NULL || root->right == NULL)
		return 0;
	return perfect(root->left, t, l+1) && perfect(root->right, t, l+1);
}

int main()
{
	int data,x,key,i=0,m;
	unsigned int t;
	do
	{
		printf("1.Insert 2.Preorder 3.Complete BT 4.Full BT 5.Perfect BT 6.Exit\n");
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
				t=node(root);
				m=complete(root,i,t);
				if(m==0)
					printf("Not a Complete Binary Tree\n");
				else 
				    printf("Complete Binary Tree\n");
				break;
			case 4:
				m=full(root);
				if(m==0)
					printf("Not a Full Binary Tree\n");
				else 
					printf("Full Binary Tree\n");
				break;
			case 5:
				m=perfect(root,depth(root), 0);
				if(m==0)
					printf("Not a Perfect Binary Tree\n");
				else 
					printf("Perfect Binary Tree\n");
				break;
            case 6: 
                break;
            default:
                printf("Invalid choice\n");
		}
	}
	while(x!=6);
	return 0;
}
