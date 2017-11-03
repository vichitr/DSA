/*C Program to Construct Tree using Inorder and Preorder Traversals 
Coded by Vichitr
vichitrgandas@gmail.com
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>	

struct node
{
	char data;
	struct node* left;
	struct node* right;
};

int search(char arr[], int strt, int end, char value)
{
	int i;
	for(i = strt; i <= end; i++)
	{
		if(arr[i] == value)
		return i;
	}
}

struct node* newNode(char data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

struct node* buildTree(char in[], char pre[], int inStrt, int inEnd)
{
	static int preIndex = 0;
	if(inStrt > inEnd)
		return NULL;
	struct node *tNode = newNode(pre[preIndex++]);
	if(inStrt == inEnd)
		return tNode;
	int inIndex = search(in, inStrt, inEnd, tNode->data);
	tNode->left = buildTree(in, pre, inStrt, inIndex-1);
	tNode->right = buildTree(in, pre, inIndex+1, inEnd);
	return tNode;
}

void printInorder(struct node* node)
{
    if (node == NULL)
    	return;
    printInorder(node->left);
    printf("%c", node->data);
    printInorder(node->right);
}

void printPreorder(struct node* node)
{
	if (node == NULL)
		return;
	printf("%c", node->data);
	printPreorder(node->left);
	printPreorder(node->right);
} 

void printPostorder(struct node* node)
{
	if (node == NULL)
		return;
	printPostorder(node->left);
	printPostorder(node->right);
	printf("%c", node->data);
} 

int main()
{
	char in[100] ;
	char pre[100];
	printf("Enter Inorder Traversal: ");
	scanf("%s",in);
	printf("Enter Preorder Traversal: ");
	scanf("%s",pre);
  
	int len = strlen(in);
	struct node *root = buildTree(in, pre, 0, len - 1);
	printf("Inorder traversal of the constructed tree is: ");
	printInorder(root);
	printf("\n");
  
	printf("Postorder traversal of the constructed tree is: ");
	printPostorder(root);
	printf("\n");
  
	printf("Preorder traversal of the constructed tree is: ");
	printPreorder(root);
	printf("\n");
	return 0;
}
