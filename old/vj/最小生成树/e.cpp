/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-03-12 21:24:12
 * @LastEditTime: 2021-03-12 21:24:13
 */

#include<bits/stdc++.h>

using namespace std;

const int N=1005;

int t,n,p[N],pre[N];
double ans,MST,e[N][N],g[N][N],x[N],y[N],dis[N];
bool vis[N],used[N][N];

double get_dis(double a,double b,double c,double d){
    return sqrt((a-c)*(a-c)+(b-d)*(b-d));
}

void prim()
{
    memset(vis,0,sizeof(vis));
    memset(used,0,sizeof(used));
    memset(g,0,sizeof(g));
    for (int i=1;i<=n;++i)
    dis[i]=e[1][i],pre[i]=1;
    for (int i=1;i<=n;++i)
    {
        int u=-1;
        for (int j=1;j<=n;++j)
        if (!vis[j]&&(u==-1||dis[j]<dis[u])) u=j;
        MST+=dis[u]; vis[u]=1; used[u][pre[u]]=used[pre[u]][u]=1;
        for (int j=1;j<=n;++j)
        {
            if (vis[j]&&j!=u) g[u][j]=g[j][u]=max(g[j][pre[u]],dis[u]);
            if (!vis[j]&&e[u][j]<dis[j]) dis[j]=e[u][j],pre[j]=u;
        }
    }
}
int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        
        for (int i=1;i<=n;++i)
        scanf("%lf%lf%d",&x[i],&y[i],&p[i]);
        for (int i=1;i<n;++i)
        for (int j=i+1;j<=n;++j)
        e[i][j]=e[j][i]=get_dis(x[i],y[i],x[j],y[j]);
        MST=0; ans=-1; prim();
        for (int i=1;i<n;++i)
        for (int j=i+1;j<=n;++j)
        if (used[i][j]) ans=max(ans,(p[i]+p[j])/(MST-e[i][j]));
        else ans=max(ans,(p[i]+p[j])/(MST-g[i][j]));
        printf("%0.2lf\n",ans);
    }
    
    return 0;
}