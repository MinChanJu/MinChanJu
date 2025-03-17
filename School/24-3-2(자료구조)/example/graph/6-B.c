#include <stdio.h>
#include <stdlib.h>

#define MIN(x,y) ((x) < (y) ? (x) : (y))
#define MAX_VERTICES 100
#define FALSE 0
#define TRUE 1

typedef struct node* nodePointer;
typedef struct node {
    int data;
    nodePointer next;
} node;

typedef struct edge* edgePointer;
typedef struct edge {
    edgePointer previous;
    int u, v;
} edge;


// declare function prototype
void makeGraph();
nodePointer makePointer(int node);
void makeInputGraph();
void init();

void addq(int key);
int deleteq();

void push(int u, int v);
void pop(int* x, int* y);

void bfs(int v);
void dfs(int v);

void dfnlow(int u, int v);
void printDfnLow();
void bicon (int u, int v);


// global variable
short int visited[MAX_VERTICES];
short int dfn[MAX_VERTICES];
short int low[MAX_VERTICES];
int num, size;
nodePointer* graph;
nodePointer front, rear;
edgePointer back;



int main() {
    // makeInputGraph();
    makeGraph();

    int start = 1;

    init();
    printf("dfs(%d) : ", start);
    dfs(start);
    printf("\n");

    init();
    printf("bfs(%d) : ", start);
    bfs(start);
    printf("\n");

    init();
    dfnlow(start, -1);
    printDfnLow();

    init();
    bicon(start, -1);
}

void makeGraph() {
    size = 10;
    graph = (nodePointer*)malloc(size*sizeof(nodePointer));
    for (int i = 0; i < size; i++) graph[i] = makePointer(i);
    nodePointer cur;

    cur = graph[0];
    cur->next = makePointer(1);

    cur = graph[1];
    cur->next = makePointer(0);
    cur->next->next = makePointer(2);
    cur->next->next->next = makePointer(3);

    cur = graph[2];
    cur->next = makePointer(1);
    cur->next->next = makePointer(4);

    cur = graph[3];
    cur->next = makePointer(1);
    cur->next->next = makePointer(4);
    cur->next->next->next = makePointer(5);
    
    cur = graph[4];
    cur->next = makePointer(2);
    cur->next->next = makePointer(3);
    cur->next->next->next = makePointer(6);

    cur = graph[5];
    cur->next = makePointer(3);
    cur->next->next = makePointer(6);
    cur->next->next->next = makePointer(7);

    cur = graph[6];
    cur->next = makePointer(4);
    cur->next->next = makePointer(5);
    cur->next->next->next = makePointer(7);

    cur = graph[7];
    cur->next = makePointer(5);
    cur->next->next = makePointer(6);
    cur->next->next->next = makePointer(8);
    cur->next->next->next->next = makePointer(9);

    cur = graph[8];
    cur->next = makePointer(7);

    cur = graph[9];
    cur->next = makePointer(7);
    
}

nodePointer makePointer(int node) {
    nodePointer tmp = (nodePointer)malloc(sizeof(nodePointer));
    tmp->data = node;
    tmp->next = NULL;

    return tmp;
}

void makeInputGraph() {
    printf("그래프 사이즈 : ");
    scanf("%d", &size);

    graph = (nodePointer*)malloc(size*sizeof(nodePointer));
    for (int i = 0; i < size; i++) graph[i] = makePointer(i);

    for (int i = 0; i < size; i++) {
        int num;
        printf("%d 개수 : ", i);
        scanf("%d", &num);

        nodePointer current = graph[i];
        for (int i = 0; i < num; i++) {
            int x;
            scanf("%d", &x);

            current->next = makePointer(x);
            current = current->next;
        }
    }
}

void init() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        visited[i] = FALSE;
        dfn[i] = low[i] = -1;
    }
    front = rear = NULL;
    back = NULL;
    num = 0;
}

void addq(int key) {
    nodePointer tmp = makePointer(key);

    if (front == NULL) front = tmp;
    else rear->next = tmp;
    rear = tmp;
}

int deleteq() {
    int tmp = front->data;
    front = front->next;
    return tmp;
}

void push(int u, int v) {
    edgePointer tmp = (edgePointer)malloc(sizeof(edgePointer));
    tmp->previous = back;
    tmp->u = u;
    tmp->v = v;

    back = tmp;
}

void pop(int* x, int* y) {
    if (back == NULL) *x = *y = -1;
    else {
        *x = back->u;
        *y = back->v;
        back = back->previous;
    }
}

void bfs(int v) {
    nodePointer w;
    
    printf("%d ", v);

    visited[v] = TRUE;
    addq(v);
    while (front) {
        v = deleteq();
        for (w = graph[v]; w; w = w->next) {
            if (!visited[w->data]) {
                printf("%d ", w->data);
                addq(w->data);
                visited[w->data] = TRUE;
            }
        }
    }
}

void dfs(int v) {
    nodePointer w;
    visited[v] = TRUE;
    printf("%d ", v);
    for (w = graph[v]; w; w = w->next){
        if (!visited[w->data]) dfs(w->data);
    }
}

void dfnlow(int u, int v) {
    nodePointer ptr;
    int w;
    dfn[u] = low[u] = num++;

    for(ptr = graph[u]; ptr; ptr = ptr->next) {
        w = ptr->data;
        if(dfn[w] < 0){
            dfnlow(w,u);
            low[u] = MIN(low[u],low[w]);
        } else if (w != v) low[u] = MIN(low[u], dfn[w]);
    }
}

void printDfnLow() {
    printf("dfn : ");
    for (int i = 0; i < size; i++) printf("%d ", dfn[i]);
    printf("\n");
    printf("low : ");
    for (int i = 0; i < size; i++) printf("%d ", low[i]);
    printf("\n");
}

void bicon (int u, int v) {
    nodePointer ptr;
    int w, x, y;
    dfn[u] = low[u] = num++;

    for (ptr = graph[u]; ptr; ptr = ptr->next){
        w = ptr->data;
        if(v != w && dfn[w] < dfn[u]) push(u, w);
        
        if(dfn[w] < 0) {
            bicon(w, u);
            low[u] = MIN(low[u], low[w]);
            if(low[w] >= dfn[u]) {
                printf("New biconnected component: ");
                do {
                    pop(&x,&y);
                    printf(" <%d,%d>",x,y);
                } while(!(((x == u) && (y == w)) || ((x == w) && (y == u))));
                printf("\n");
            }
        } else if (w != v) low[u] = MIN(low[u], dfn[w]);
    }
}