/* Breadth First Search on Graph
Coded by Vichitr
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node
{
    int data;
    struct node *next;
};

struct queue
{
    struct node *front, *rear;
};

struct nodeList
{
    struct node *head;
};

struct graph
{
    int v;
    struct nodeList *arr;
};

struct node *makeNode(int data)
{
    struct node *new = (struct node*) malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;
    return new;
}

struct graph *createGraph(int v)
{
    struct graph* new = (struct graph *) malloc(sizeof(struct graph));
    new->v = v;
    new->arr = (struct nodeList*) malloc(sizeof(struct nodeList)*v);
    int i;
    for(i=0;i<v;i++)
        new->arr[i].head = NULL;
    return new;
}

struct queue *createQueue()
{
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->front = q->rear = NULL;
    return q;
}

void enQueue(struct queue *q, int d)
{
    struct node *n = makeNode(d);
    if (q->rear == NULL)
    {
        q->front = q->rear = n;
        return;
    }
    q->rear->next = n;
    q->rear = n;
}

struct node *deQueue(struct queue *q)
{
    if (q->front == NULL)
        return NULL;
    struct node *n = q->front;
    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;
    return n;
}

int isEmpty(struct queue *q)
{
    return (q->front==NULL);
}

void addEdge(struct graph* g, int s, int d, int dir)
{
    if(s >= g->v || d >= g->v)
    {
        printf("No such edge is possible\n");
        return;
    }
    struct node* n = makeNode(d);
    n->next = g->arr[s].head;
    g->arr[s].head = n;
    //if graph is undirected
    if(dir == 0)
    {
        n = makeNode(s);
        n->next = g->arr[d].head;
        g->arr[d].head = n;
    }
}

void print(struct graph* g)
{
    int i;
    for(i=0; i<g->v;i++)
    {
        struct node* n = g->arr[i].head;
        printf("Adjcency list for vertex %d is: head", i);
        while(n)
        {
            printf("-> %d", n->data);
            n = n->next;
        }
        printf("\n");
    }
}

void bfs(struct graph *g, int s)
{
    if(s < 0 || s >= g->v)
    {
        printf("Given Source Vertex doesn't exist.\n");
        return;
    }
    printf("Breadth First Traversal for graph is:\n");
    printf("Vertex Distance\n");
    char color[g->v];
    int i, d[g->v];
    struct node* p[g->v];
    //For each vertex, set distance infinity, color white and parent as NULL
    for(i=0; i<g->v;i++)
    {
        d[i] = INT_MAX;
        color[i] = 'w';
        p[i] = NULL;
    }
    //Visit source vertex, set distance 0, color green
    d[s] = 0;
    color[s] = 'g';
    p[s] = NULL;
    //Create a queue and enqueue source vertex
    struct queue *q = createQueue();
    enQueue(q, s);
    
    while(!isEmpty(q))
    {
        struct node* u = deQueue(q);
        struct node *w = g->arr[u->data].head;
        //Visit all adjecency vertices of current vertex
        while(w)
        {
            if(color[w->data]=='w')
            {
                color[w->data]='g';
                d[w->data] = d[u->data]+1;
                p[w->data] = u;
                enQueue(q, w->data);
            }
            w=w->next;
        }
        //make current vertex visited and print 
        color[u->data] = 'b';
        printf("  %d\t %d\n", u->data, d[u->data]);
    }
}

int main()
{
    int v, c, v1, v2, dir, s;
    printf("No of vertex: ");
    scanf("%d", &v);
    struct graph *g = createGraph(v);
    printf("Direced Graph(1) or Undirected Graph(0)? ");
    scanf("%d", &dir);
    do
    {
        printf("1. Add edge 2. Print 3. BFS 4.Exit : ");
        scanf("%d", &c);
        switch(c)
        {
            case 1:
                printf("Enter Source Vertex: ");
                scanf("%d", &v1);
                printf("Enter Destination Vertex: ");
                scanf("%d", &v2);
                addEdge(g, v1, v2, dir);
                break;
            case 2:
                print(g);
                break;
            case 3:
                printf("Enter Source Vertex: ");
                scanf("%d", &s);
                bfs(g, s);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice\n");
        }
    }
    while(c != 4);
    return 0;
}
