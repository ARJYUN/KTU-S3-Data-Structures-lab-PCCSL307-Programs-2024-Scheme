#include<stdio.h>
#define MAX 100
int e,n;
int stack[MAX],adj[MAX][MAX],visited[MAX];
int front=-1,rear=-1;

void enqueue(int item){
    stack[++rear]=item;
    if (front==-1)
        ++front;
}

int dequeue(){
    int item=stack[front];
    if(front==rear){
        front=-1;
        rear=-1;
    }
    else
        front++;
    return item;
}

void bfs(int v){
    printf("%d ",v);
    visited[v]=1;
    enqueue(v);
    while(front!=-1){
        v=dequeue();
        for(int j=1;j<=n;j++){
            if(adj[v][j]==1 && visited[j]==0){
                printf("%d ",j);
                visited[j]=1;
                enqueue(j);
            }
        }
    }

}

void main(){
    int u1,v1,v;
    printf("Enter the no. of vertices: ");
    scanf("%d",&n);
    printf("Enter the no. of edges: ");
    scanf("%d",&e);
    for(int i=1;i<=n;i++)
        visited[i]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            adj[i][j]=0;
        }
    }
    printf("Enter the edges u,v :\n");
    for(int i=0;i<e;i++){
        scanf("%d %d",&u1,&v1);
        adj[u1][v1]=1;
        adj[v1][u1]=1;
    }
    printf("Enter the starting node : ");
    scanf("%d",&v);
    bfs(v);
}
