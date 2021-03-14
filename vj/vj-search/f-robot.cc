#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
int n,m,x1,y1,x2,y2,d;
char b[20];
int tu[105][105];
bool vis[105][105][4];
int dx[4]={-1,0,1,0};//这里要注意东南西北相对应
int dy[4]={0,1,0,-1};
struct node
{
    int x,y,step,fang;
};
int check(int x,int y)
{
    if(x<1||y<1||x>=n||y>=m||tu[x][y]||tu[x+1][y]||tu[x][y+1]||tu[x+1][y+1]) return 0;//因为是左上角，所以x不能等于n，同理y也不能等于m。
    return 1;
}
int bfs()
{
    queue<node>que;
    node a;
    a.x=x1;
    a.y=y1;
    a.fang=d;
    a.step=0;
    que.push(a);
    vis[a.x][a.y][a.fang]=1;
    while(!que.empty())
    {
 
    a=que.front();que.pop();
    if(a.x==x2&&a.y==y2) return a.step;
    node ex=a;//注意这个ex要定义在外面，因为ex会累加，累加一次说明走一步，两次走两步，以此类推
    for(int i=1;i<4;i++)//第一个for来走步数，三种情况，所以三次循环
    {
        ex.x+=dx[a.fang];
        ex.y+=dy[a.fang];
        if(!check(ex.x,ex.y)) break;
        if(!vis[ex.x][ex.y][a.fang])
        {
            ex.fang=a.fang;
            vis[ex.x][ex.y][ex.fang]=1;
            ex.step=a.step+1;
            que.push(ex);
        }
    }
    for(int i=0;i<4;i++)//第二个for来走方向，四种情况，四次循环
    {
        if(max(a.fang,i)-min(a.fang,i)==2) continue;
        if(vis[a.x][a.y][i]) continue;
        vis[a.x][a.y][i]=1;
        node ex=a;
        ex.fang=i;
        ex.step=a.step+1;
        que.push(ex);
    }
    }
    return -1;
}
 
int main()
{
    while(scanf("%d%d",&n,&m)&&(n+m))
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                scanf("%d",&tu[i][j]);
        }
        memset(vis,0,sizeof(vis));
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        scanf("%s",b);
        if(b[0]=='n') d=0;
        if(b[0]=='e') d=1;
        if(b[0]=='s') d=2;
        if(b[0]=='w') d=3;
        printf("%d\n",bfs());
    }
    return 0;
}