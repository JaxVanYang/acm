#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
#define clr(a,b) memset(a,b,sizeof(a))
#define M 205
#define INF 0x7f7f7f7f
using namespace std;
int d[M][M][4],s[M][M][2];
int vis[M][M],cnt[M][M];
int lastx,lasty,maxx,maxy;
int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
struct Node     //优先队列，按cnt统计的步数排序
{
    int x,y;
    bool operator < (const Node &a) const{
        return cnt[a.x][a.y] < cnt[x][y];
    }
}node;
void BFS()
{
    priority_queue<Node>que;
    Node temp;
    node.x = lastx; node.y = lasty;
    que.push(node);
    vis[lastx][lasty] = 1;
    while(que.empty() != true){
        int x,y;
        temp = que.top();
        que.pop();
        for(int i = 0; i < 4; i++){
            x = temp.x + dir[i][0]; y = temp.y + dir[i][1];
            if(x < 0 || y < 0) continue;
            if(x > 199 || y > 199) continue;
            if(d[x][y][3-i] != 1){  //若不是墙
                node.x = x; node.y = y;
                if(d[x][y][3-i] == 0){  //若是门
                    if(vis[x][y]) //若被访问过，更新cnt值
                        cnt[x][y] = min(cnt[x][y],cnt[temp.x][temp.y]+1);
                    else{
                        cnt[x][y] = cnt[temp.x][temp.y]+1;
                        que.push(node);
                    }
                }
                else{ //若是空地
                    if(vis[x][y])//若被访问过，更新cnt值
                        cnt[x][y] = min(cnt[x][y],cnt[temp.x][temp.y]);
                    else{
                        cnt[x][y] = cnt[temp.x][temp.y];
                        que.push(node);
                    }
                }
                vis[x][y] = 1; //访问标记
                if(x > maxx || y > maxy){ //达到边界，将步数更新到cnt[0][0]
                    cnt[0][0] = min(cnt[0][0],cnt[x][y]);
                    break;
                }
            }
        }
    }
}
void BuildGrap()  //建图
{
    for(int i = 0; i < 200; i++){
        for(int j = 0; j < 200; j++){
            d[i][j][0] = s[i][j+1][0];
            d[i][j][1] = s[i+1][j][1];
            d[i][j][3] = s[i][j][0];
            d[i][j][2] = s[i][j][1];

        }
    }
}
int main(int argc,char *argv[])
{
    int n,m,a,b,dd,t;
    double xx,yy;
    while(scanf("%d%d",&n,&m)!=EOF){
        clr(d,-1);
        clr(s,-1);
        clr(vis,0);
        clr(cnt,0);
        if(n == -1 && m == -1) break;
        maxx = maxy = 0;
        for(int i = 0; i < n; i++){
            scanf("%d%d%d%d",&a,&b,&dd,&t);
            if(dd == 1){
                for(int k = 0; k < t; k++){
                    s[a][b][dd] = 1;
                    b++;
                }
            }
            if(dd == 0){
                for(int k = 0; k < t; k++){
                    s[a][b][dd] = 1;
                    a++;
                }
            }
            if(maxx < a){
                maxx = a;
            }
            if(maxy < b){
                maxy = b;
            }
        }
        for(int i = 0; i < m; i++){
            scanf("%d%d%d",&a,&b,&dd);
            s[a][b][dd] = 0;
        }
        scanf("%lf%lf",&xx,&yy);
        lastx = floor(xx);
        lasty = floor(yy);
        if(lastx < 0 || lastx > 199 || lasty < 0 || lasty > 199){
            printf("0\n");
            continue;
        }
        BuildGrap();
        cnt[0][0] = INF;
        BFS();
        if(cnt[0][0] == INF){
            printf("-1\n");
        }
        else{
            printf("%d\n",cnt[0][0]);
        }
    }
    return 0;
}