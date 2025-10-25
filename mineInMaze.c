#include<stdio.h>
#define MAX 1000
int m,n;
int dirX[]={-1,1,0,0};
int dirY[]={0,0,-1,1};
struct node{
    int x,y,d;
}queue[MAX*MAX];
int front=0,rear=0;

int isValid(int x,int y,int m,int n,char grid[m][n],int visited[m][n]){
    if(x<0||y<0||x>=m||y>=n)return 0;
    if(grid[x][y]!='O')return 0;
    if(visited[x][y])return 0;
    return 1;
}

void mineD(int m,int n,char cell[m][n]){
    int dist[m][n],visited[m][n];
    front=rear=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            dist[i][j]=-1;
            visited[i][j]=0;
            if(cell[i][j]=='M'){
                struct node temp={i,j,0};
                queue[rear++]=temp;
                visited[i][j]=1;
                dist[i][j]=0;
            }
        }
    }
    while(front<rear){
        struct node curr=queue[front++];
        for(int k=0;k<4;k++){
            int nx=curr.x+dirX[k];
            int ny=curr.y+dirY[k];
            if(isValid(nx,ny,m,n,cell,visited)){
                visited[nx][ny]=1;
                dist[nx][ny]=curr.d+1;
                queue[rear++]=(struct node){nx,ny,curr.d+1};
            }
        }
    }
    printf("\nShortest distance from nearest mine:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(cell[i][j]=='X')printf("X ");
            else printf("%d ",dist[i][j]);
        }
        printf("\n");
    }
}

int main(){
    printf("Enter the dimension of maze  m,n : ");
    scanf("%d %d",&m,&n);
    char cell[m][n];
    printf("Enter the maze data:\n'M'->landmine\n'O'->open cell\n'X'->wall\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf(" %c",&cell[i][j]);
        }
    }
    mineD(m,n,cell);
    return 0;
}
