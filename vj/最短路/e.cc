#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 5205, INF = 0x3f3f3f3f;

int cnt, dist[N], Head[N], num[N], vis[N];
int n, m, w;

struct Edge
{
    int v, w, next;
}e[N];

void Add(int u, int v, int w)
{
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].next = Head[u];
    Head[u] = cnt++;
}

bool spfa()
{
    memset(vis, 0, sizeof(vis));
    memset(num, 0, sizeof(num));
    queue<int>Q;
    vis[1] = 1;
    dist[1] = 0;
    Q.push(1);
    num[1]++;
    while(Q.size())
    {
        int p=Q.front();
        Q.pop();
        vis[p] = 0;
        for(int i=Head[p]; i!=-1; i=e[i].next)
        {
            int q = e[i].v;
            if(dist[q] > dist[p] + e[i].w)
            {
                dist[q] = dist[p] + e[i].w;
                if(!vis[q])
                {
                    vis[q] = 1;
                    Q.push(q);
                    num[q] ++;
                    if(num[q]>n)
                        return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    int T, a, b, c;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &n, &m, &w);

        cnt = 0;
        memset(Head, -1, sizeof(Head));
        for(int i=1; i<=n; i++)
            dist[i] = INF;

        for(int i=1; i<=m; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            Add(a, b, c);
            Add(b, a, c);
        }
        for(int i=1; i<=w; i++)
        {
            scanf("%d%d%d", &a, &b, &c);
            Add(a, b, -c);
        }

        if( spfa() )
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}