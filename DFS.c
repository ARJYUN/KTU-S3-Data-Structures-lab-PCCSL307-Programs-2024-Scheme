#include<stdio.h>
#define MAX 100
int e,n;
int stack[MAX],adj[MAX][MAX],visited[MAX];
int top=-1;

void push(int item){
    stack[++top]=item;
}

int pop(){
    return stack[top--];
}

void dfs(int v){
    push(v);
    while(top!=-1){
        v=pop();
        if(visited[v]==0){
            printf("%d ",v);
            visited[v]=1;
        }
        for(int j=n;j>=1;j--){
            if(adj[v][j]==1 && visited[j]==0){
                push(j);
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
    dfs(v);
