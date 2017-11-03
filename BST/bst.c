/*Binary Search Tree using Linked List
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
struct node *root = NULL ,*p2=NULL;

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

void search(struct node * root,int key)
{
	int c=0,flag=0;
	struct node *p1=root;
	printf("Path from root is: ");
	while(p1!=NULL)
	{
		if(p1->data==key)
		{
			printf("%d\n",p1->data);
			printf("Key %d is found\n\n",key);
			printf("Level of element is %d\n",c);
			return;
		}
		else
		{
			if(p1->data>key )
			{
				printf("%d ",p1->data);
				p1=p1->left;
				c++;
			}	
			else if(p1->data<key)
			{
				printf("%d ",p1->data);
				p1=p1->right;
				c++;
			}
		}
	}
	if(p1==NULL)
	printf("Key not found in above path\n");	
}

void delete(int key )
{
	int temp;
	struct node *p1=root;p2=p1;
	if(p1==NULL)
	{
		printf("Node not found\n");
		return;
	}
	if(root->right == NULL && root->left == NULL && root->data==key)
	{
		root=NULL;
		return;
	}
	else if((root->left == NULL ||root->right == NULL) &&root->data==key)
	{
		if(	root->left!=NULL)
			root=root->left;
		else
			root=root->right;
	}
	while(p1!=NULL)
	{
		if(p1->data==key)
		{
			if(p1->left == NULL && p1->right==NULL)
			{
				if(p2->right!=NULL&&p2->right->data==key)
				{
					p2->right=NULL;
					free(p1);
					break;
				}
				else if(p2->left!=NULL&&p2->left->data==key)
				{
					p2->left=NULL;
					free(p1);
					break;
				}
			}
			if(p1->left==NULL && p1->right !=NULL)
			{
			 	if(p2->data > p1->right->data)
					p2->left=p1->right;
				else
					p2->right=p1->right;
				free(p1);
				return;
			}	
			if(p1->right ==NULL && p1->left!=NULL)
			{
				if(p2->data <p1->left->data)
					p2->right=p1->left;
				else
					p2->left=p1->left;
				free(p1);
				return;
			}
			//node having both children
			if(p1->right!=NULL && p1->left!=NULL)
			{
				struct node *p3=NULL;
				p2=p1;
				p3=p1->right;
				while(p3->left!=NULL)
				{
					p2=p3;
					p3=p3->left;
				}
				p1->data=p3->data;
				if(p3->left == NULL && p3->right==NULL)
				{
					if(p2->right!=NULL&&p2->right->data==p3->data)
					{
						p2->right=NULL;
						free(p3);
						break;
					}
					else if(p2->left!=NULL&&p2->left->data==p3->data)
					{
						p2->left=NULL;
						free(p3);
						break;
					}
				}
				if(p3->left==NULL && p3->right !=NULL)
				{ 	
					if(p2->data > p3->right->data)
						p2->left=p3->right;
					else
						p2->right=p3->right;
					free(p3);
					return;
				}	
				if(p3->right==NULL && p3->left!=NULL)
				{
					if(p2->data <p3->left->data)
						p2->right=p3->left;
					else
						p2->left=p3->left;
					free(p3);
					return;
				}					
			}					
		}
		//searching element
		else
		{
			if(p1->data>key )
			{
				p2=p1;
				p1=p1->left;
			}	
			if(p1->data<key)
			{
				p2=p1;
				p1=p1->right;
			}
		}
	}
}

void minmax()
{
	struct node *p1=root,*p2=root;
	if(root==NULL)
	{
		printf("Tree is empty\n");
		return;
	}
	while(p1->left!=NULL)
		p1=p1->left;
	while(p2->right!=NULL)
		p2=p2->right;	
	printf("Maximum element: %d\nMinimum element: %d\n",p2->data,p1->data);
}

int main()
{
	int data,x,key,t=2;
	do
	{
		printf("1.Insert 2.Preorder 3.Inorder 4.Postorder 5.Search 6.Delete 7.Find Min/Max of Tree 8.Exit : ");
		scanf("%d",&x);
		switch(x)
		{
			case 1: 
				printf("Data: ");
				scanf("%d",&data);
				insert(data);
				break;
			case 2:
			    printf("Preorder: ");
			    preorder(root);
				printf("\n");
				break;
			case 3:
			    printf("Inorder: ");
				inorder(root);
				printf("\n");
				break;
			case 4:
			    printf("Postorder: ");
				postorder(root);
				printf("\n");
				break;
			case 5:
				printf("Enter search element: ");
				scanf("%d",&key);
				search(root,key);
				break;
			case 6:
				printf("Enter data to be deleted: ");
				scanf("%d",&key);
				delete(key);
				break;
			case 7:
			   minmax();
			   break;
			case 8:
				break;
			default:
				printf("Invalid choice\n");
		}
	}while(x!=8);
	return 0;
}

