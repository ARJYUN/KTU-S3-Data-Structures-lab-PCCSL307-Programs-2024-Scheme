#include <stdio.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    int x,y,z;
} State;

State queue[MAX*MAX*MAX];
bool visited[MAX][MAX][MAX];
int front=0,rear=0;

void enqueue(State s){
    queue[rear++]=s;
}

State dequeue(){
    return queue[front++];
}

bool isVisited(State s){
    return visited[s.x][s.y][s.z];
}

void markVisited(State s){
    visited[s.x][s.y][s.z]=true;
}

bool isGoal(State s,int target){
    return(s.x==target||s.y==target);
}

void resetVisited(int capX,int capY,int capZ){
    for(int i=0;i<=capX;i++)
        for(int j=0;j<=capY;j++)
            for(int k=0;k<=capZ;k++)
                visited[i][j][k]=false;
}

bool bfs(int capX,int capY,int capZ,int target){
    resetVisited(capX,capY,capZ);
    front=rear=0;
    State start={capX,capY,0};
    enqueue(start);
    markVisited(start);

    while(front<rear){
        State cur=dequeue();
        printf("Checking state:(%d,%d,%d)\n",cur.x,cur.y,cur.z);

        if(isGoal(cur,target)){
            printf("\nGoal reached! Final state:(%d,%d,%d)\n",cur.x,cur.y,cur.z);
            return true;
        }

        int current[3]={cur.x,cur.y,cur.z};
        int capacity[3]={capX,capY,capZ};

        for(int from=0;from<3;from++){
            for(int to=0;to<3;to++){
                if(from==to)continue;

                int pourAmount=(current[from]<capacity[to]-current[to])?
                                current[from]:(capacity[to]-current[to]);
                if(pourAmount==0)continue;

                State next=cur;

                if(from==0)next.x-=pourAmount;
                else if(from==1)next.y-=pourAmount;
                else next.z-=pourAmount;

                if(to==0)next.x+=pourAmount;
                else if(to==1)next.y+=pourAmount;
                else next.z+=pourAmount;

                if(!isVisited(next)){
                    markVisited(next);
                    enqueue(next);
                    printf("Pour %dL from %c -> %c:(%d,%d,%d)\n", pourAmount,'X'+from,'X'+to,next.x,next.y,next.z);
                }
            }
        }
    }
    return false;
}

int main(){
    int x,y,z,target;
    printf("Enter capacities of 3 containers (x y z): ");
    scanf("%d%d%d",&x,&y,&z);
    printf("Enter target amount: ");
    scanf("%d",&target);

    printf("\nStarting BFS to find solution...\n\n");
    if(!bfs(x,y,z,target))
        printf("\nNo solution found.\n");
    return 0;
}
