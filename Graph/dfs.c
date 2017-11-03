/* Depth First Search on Graph
Coded by Vichitr
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
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

void dfsVisit(struct graph *g, char *color, int *d1, int *d2, int *time, int i)
{
    //if not visited then visit it
    if(color[i] == 'w')
    {
        struct node *n = g->arr[i].head;
        color[i] = 'g';
        d1[i] = ++(*time);
        //visit all adjecency vertices of vertex i
        while(n)
        {
            if(color[n->data] == 'w')
                dfsVisit(g, color, d1, d2, time, n->data);
            n = n->next;
        }
    }
    //update color and time for visited node
    color[i] = 'b';
    d2[i] = ++(*time);
    printf("  %d\t    %d\t\t%d\n", i, d1[i], d2[i]);
}

void dfs(struct graph *g)
{
    char color[g->v];
    int d1[g->v], d2[g->v];
    int i, time = 0;
    for(i = 0; i < g->v; i++)
    {
        color[i] = 'w';
        d1[i] = -1;
        d2[i] = -1;
    }
    
    for(i = 0; i < g->v; i++)
    {
        if(color[i] == 'w')
            dfsVisit(g, color, d1, d2, &time, i);
    }
}

int main()
{
    int v, c, v1, v2, dir;
    printf("No of vertex: ");
    scanf("%d", &v);
    struct graph *g = createGraph(v);
    printf("Direced Graph(1) or Undirected Graph(0)? ");
    scanf("%d", &dir);
    do
    {
        printf("1. Add edge 2. Print 3. DFS 4.Exit : ");
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
                printf("Depth First Traversal for graph is:\n");
                printf("vertex initial time final time\n");
                dfs(g);
                printf("\n");
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
