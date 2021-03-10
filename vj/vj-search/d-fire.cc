#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=1050;
char mp[maxn][maxn];
int time_map[maxn][maxn];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int n,m;
struct node
{
	int x,y;
	int ti;
}; 
queue<node>f;
queue<node>q;

bool check(int x,int y)
{
	if(x>=1&&x<=n&&y>=1&&y<=m) return true;
	else return false;
}

void bfs1()//先bfs出time_map; 
{
	while(!f.empty())
	{
		node now=f.front();
		f.pop();
		for(int i=0;i<4;i++)
		{
			int dx=now.x+dir[i][0];
			int dy=now.y+dir[i][1];
			if(check(dx,dy)&&now.ti+1<time_map[dx][dy])
			{
				node in;
				in.x=dx;
				in.y=dy;
				in.ti=now.ti+1;
				f.push(in);
				time_map[dx][dy]=in.ti;
			}
		}
	}
}

void bfs2()
{
	while(!q.empty())
	{
		node now=q.front();
		q.pop();
		if(!check(now.x,now.y))
		{
			printf("%d\n",now.ti);
			return;
		}
		for(int i=0;i<4;i++)
		{
			int dx=now.x+dir[i][0];
			int dy=now.y+dir[i][1];
			if(now.ti+1<time_map[dx][dy])
			{
				time_map[dx][dy]=now.ti+1;
				node in;
				in.ti=now.ti+1;
				in.x=dx;
				in.y=dy;
				q.push(in);
			}
		}
	}
	printf("IMPOSSIBLE\n");
}

int main()
{
	int i,j;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(time_map,INF,sizeof(time_map));
	    while(!q.empty()) q.pop();
	    while(!f.empty()) f.pop();
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%s",mp[i]+1);
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				if(mp[i][j]=='#') time_map[i][j]=0;
				if(mp[i][j]=='J')
				{
					node in;
					in.x=i;
					in.y=j;
					in.ti=0;
					q.push(in);
					time_map[i][j]=0;
				}
				if(mp[i][j]=='F')
				{
					node in;
					in.ti=0;
					in.x=i;
					in.y=j;
					f.push(in);
					time_map[i][j]=0;
				}
			}
		}
		bfs1();
		bfs2();
	}
	return 0;
}