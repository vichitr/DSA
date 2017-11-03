/*C Program to create a Binary Tree by given Infix Expression
Coded by Vichitr
vichitrgandas@gmail.com
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node 
{
	char data;
	struct node *left;
	struct node *right;
}node;

node* s[100];
int top = -1;

node* createnode(char b)
{
	node *p=(struct node*)malloc(sizeof(struct node));
	p->data=b;
	p->left=NULL;
	p->right=NULL;
	return p;
}

void push(node* a)
{
	s[++top]=a;
}

node* pop()
{
	node *p;
	p=s[top--];
	return(p);
}

// Stack type
struct Stack
{
    int t;
    unsigned capacity;
    int* array;
};
 
// Stack Operations
struct Stack* createStack( unsigned capacity )
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
 
    if (!stack) 
        return NULL;
 
    stack->t = -1;
    stack->capacity = capacity;
 
    stack->array = (int*) malloc(stack->capacity * sizeof(int));
 
    if (!stack->array)
        return NULL;
    return stack;
}
int isEmpty(struct Stack* stack)
{
    return stack->t == -1 ;
}
char peek(struct Stack* stack)
{
    return stack->array[stack->t];
}
char pop1(struct Stack* stack)
{
    if (!isEmpty(stack))
        return stack->array[stack->t--] ;
    return '$';
}
void push1(struct Stack* stack, char op)
{
    stack->array[++stack->t] = op;
}
 
 
// A utility function to check if the given character is operand
int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
 
// A utility function to return precedence of a given operator
// Higher returned value means higher precedence
int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
 
    case '*':
    case '/':
        return 2;
 
    case '^':
        return 3;
    }
    return -1;
}
 
 
// The main function that converts given infix expression
// to postfix expression. 
char* infixToPostfix(char* exp)
{
    int i, k;
 
    // Create a stack of capacity equal to expression size 
    struct Stack* stack = createStack(strlen(exp));
    if(!stack) // See if stack was created successfully 
        return -1 ;
 
    for (i = 0, k = -1; exp[i]; ++i)
    {
        // If the scanned character is an operand, add it to output.
        if (isOperand(exp[i]))
            exp[++k] = exp[i];
         
        // If the scanned character is an ‘(‘, push it to the stack.
        else if (exp[i] == '(')
            push1(stack, exp[i]);
         
        // If the scanned character is an ‘)’, pop and output from the stack 
        // until an ‘(‘ is encountered.
        else if (exp[i] == ')')
        {
            while (!isEmpty(stack) && peek(stack) != '(')
                exp[++k] = pop1(stack);
            if (!isEmpty(stack) && peek(stack) != '(')
                return -1; // invalid expression             
            else
                pop1(stack);
        }
        else // an operator is encountered
        {
            while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack)))
                exp[++k] = pop1(stack);
            push1(stack, exp[i]);
        }
 
    }
 
    // pop all the operators from the stack
    while (!isEmpty(stack))
        exp[++k] = pop1(stack );
 
    exp[++k] = '\0';
    //printf( "%sn", exp );
	return exp;
}

void traversal(node* temp,int i)
{
	if(temp!=NULL)
	{
		if(i==1)
			 printf("%c",temp->data);
				traversal(temp->left,i);
		if(i==2) printf("%c",temp->data);
				traversal(temp->right,i);
		if(i==3) printf("%c",temp->data);
	}
}

int main()
{
	char exp[100];
	char *ex;
	int i;
	node *temp;
	printf("Enter Infix Expression: ");
	scanf("%s",exp);
	ex = infixToPostfix(exp);
	for(i=0;ex[i];i++)
	{
		if(ex[i] =='+' || ex[i] == '-' || ex[i] == '*' || ex[i] == '/' || ex[i] == '^')
		{
			temp=createnode(ex[i]);
			temp->right=pop();
			temp->left=pop();
			push(temp);
		} 
		else
		{
			temp=createnode(ex[i]);
			push(temp);
		}
	}
	printf("Preorder: ");
	traversal(temp,1);
	printf("\n");
	printf("Postorder: ");
	traversal(temp,3);
	printf("\n");
	printf("Inorder: ");
	traversal(temp,2);
	printf("\n");
	return 0;
}
