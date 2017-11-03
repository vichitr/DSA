/* AVL Tree
Coded by Vichitr
vichitrgandas@gmail.com
*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data,height;
	struct node * left,*right;
};
int height(struct node * root)
{
	int lheight,rheight;
	if(root==NULL)
		return 0;
	else
	{
		lheight=height(root->left);
		rheight=height(root->right);
		if(lheight>rheight)
			return lheight+1;
		else
			return rheight+1;	
	}
}
int getbalance(struct node *root)
{
	if(root==NULL)
		return 0;
	return (height(root->left)-height(root->right));
}
int max(int a, int b)
{
	if(a>b)
		return a;
	else return b;
}
struct node* leftrotate(struct node *p)
{
	struct node *p1=p->right;
	struct node* p2= p1->left;
	p1->left=p;
	p->right=p2;
	p->height=max(height(p->left),height(p->right));
	p1->height=max(height(p1->left),height(p1->right));
	return p1;
}

struct node* rightrotate(struct node *p)
{
	struct node *p1=p->left;
	struct node* p2= p1->right;
	p1->right=p;
	p->left=p2;
	p->height=max(height(p->left),height(p->right));
	p1->height=max(height(p1->left),height(p1->right));
	return p1;
}

struct node* makebalance(struct node *root,int data)
{
	int balance = getbalance(root);

	if(balance>1&& data<root->left->data)
		return rightrotate(root);

	if(balance <-1 && data>root->right->data)
		return leftrotate(root);

	if(balance>1&& data>root->left->data)
	{
		root->left=leftrotate(root->left);
		return rightrotate(root);
	}

	if(balance<-1&& data<root->right->data)
	{
		root->right=rightrotate(root->right);
		return leftrotate(root);
	}
	
	return root;
	
}
struct node* insert(struct node *root,int data)
{
	

	if(root==NULL)
	{
		struct node * p=(struct node*)malloc(sizeof(struct node));
		p->data=data;
		p->left=NULL;
		p->right=NULL;
		root = p;		
	}
	if(root->data>data)
		root->left=insert(root->left,data);
	else if(root->data<data)
		root->right=insert(root->right,data);
	else 
		return root;
	root->height=max(height(root->left),height(root->right));
	root=makebalance(root,data);
	return root;
	
}
struct node * minvaluenode(struct node* root)
{
    struct node* p = root;
 
    /* loop down to find the leftmost leaf */
    while (p->left != NULL)
        p = p->left;
 
    return p;
}
struct node* delete(struct node *root,int data)
{
	struct node* temp=NULL; 
	if(root==NULL)
		return root;
	if(data<root->data)
		root->left=delete(root->left,data);
	else if(data>root->data)
		root->right=delete(root->right,data);
	else
	{
        if (root->left == NULL)
        {
           	temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
       temp = minvaluenode(root->right);
       root->data = temp->data;
        root->right = delete(root->right, temp->data);
	}
	//if(root==NULL)
		return root;
	root->height=max(height(root->left),height(root->right));
	root=makebalance(root,data);
	return root;
	
}

void inorder(struct node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}

void preorder(struct node* root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct node* root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
void findminmax(struct node* root)
{
	struct node*p1=root,*p2=root;
	while(p1->left!=NULL)
		p1=p1->left;
	while(p2->right!=NULL)
		p2=p2->right;
	printf("Maximum data = %d\nMinimum data = %d\n",p2->data,p1->data);
}
int main()
{
	struct node* root=NULL;
	int data,x;
	do
	{
		printf("1.Insert 2.Print 3.Delete 4.Min/Max 5.Exit : ");
		scanf("%d",&x);
		switch(x)
		{
			case 1:
				printf("Data: ");
				scanf("%d",&data);
				root=insert(root,data);
				break;
			case 2:
					printf("Inorder: ");
					inorder(root);
					printf("\n");
					printf("Preorder: ");
					preorder(root);
					printf("\n");
					printf("Postorder: ");
					postorder(root);
					printf("\n");
					break;
			case 3:
					printf("Enter data to be deleted: ");
					scanf("%d",&data);
					root=delete(root,data);
					break;
			case 4:
					findminmax(root);
					break;
			case 5:
					break;
			default:
					printf("Enter valid choice\n");
		}
	}while(x!=5);
return 0;
}
