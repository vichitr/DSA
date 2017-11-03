/*Binary Tree using Linked List
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

//flag for searching an element
int t=0;

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
		else
		{
			
			if(p1->rightchild==NULL)
			{
				p1->rightchild=new;	
				return;
			}
			p1=p1->rightchild;
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
		printf("%d ",root->data);
	}
	
}

void search(struct node * root,int key)
{
	if(root!=NULL)
	{
		if(root->data==key)
		{
			printf("%d is found\n",root->data);
			t=1;
			return;
		}
		search(root->leftchild,key);
		search(root->rightchild,key);
	}
}

void delete(struct node *root, int key)
{
	struct node *p1 = root,*temp;
	if(p1==NULL)
	{
		return;
	}
	if(p1->data==key)
	{
		temp=p1;
		root = NULL;
		free(temp);
		return;
	}
	if(p1!=NULL)
	{
		if((p1->leftchild!=NULL && p1->leftchild->data==key)||(p1->rightchild!=NULL && p1->rightchild->data==key))
		{
			temp=p1;
			if(p1->leftchild!=NULL && p1->leftchild->data==key)
			{
				p1->leftchild=NULL;
				free(temp->leftchild);
			}
			else
			{
				p1->rightchild=NULL;
				free(temp->rightchild);
			}
			return;
		}
		if(p1->leftchild!=NULL)
		delete(p1->leftchild,key);
	if(p1->rightchild!=NULL)
		delete(p1->rightchild,key);
	}
}


int main()
{
	int data,x,key;
	do
	{
		printf("1.Insert 2.Preorder 3.Inorder 4.Postorder 5.Delete 6.Search 7.Exit\n");
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
				printf("Enter element to delete: ");
				scanf("%d", &key);
				delete(root, key);
				break;
			case 6:
				printf("Enter search element: ");
				scanf("%d", &key);
				search(root, key);
				if(t==1)
					t=0;
				else
					printf("Element not found\n");
				break;
			case 7:
				break;
			default:
				printf("Invalid choice\n");
				break;
		}
	}while(x!=7);
}
