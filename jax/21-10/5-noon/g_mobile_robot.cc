#include <bits/stdc++.h>

#define ll long long
#define INF 0x3f3f3f3f
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar();ll f=1;
    if(c>'9'||c<'0')
    {
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c<='9'&&c>='0')
    {
        x=(x<<1)+(x<<3)+c-'0';
        c=getchar();
    }
    x*=f;
}
template<typename T> inline void write(T x)
{

    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
using namespace std;
int n;
ll d;
ll a[1000010];
int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    read(n);read(d);
    long double minn=1e16,maxn=-1e16;
    for(int i=1;i<=n;i++)read(a[i]),minn=min(minn,(long double)a[i]),maxn=max(maxn,(long double)a[i]);
    long double mid=(minn+maxn)/2.0,s;
    if(n&1)s=mid-d*(n/2);
    else s=mid-d/2.0-d*(n/2-1);
    long double m1=0,m2=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>s)m1=max(m1,a[i]-s);
        else m2=max(m2,s-a[i]);
        s=s+d;
    }
    if(n&1)s=mid-d*(n/2);
    else s=mid-d/2.0-d*(n/2-1);
    long double ans=(m1+m2)/2.0;
    m1=0,m2=0;
    for(int i=n;i>=1;i--)
    {
        if(a[i]>s)m1=max(m1,a[i]-s);
        else m2=max(m2,s-a[i]);
        s=s+d;
    }
    long double x=(m1+m2)/2.0;
    ans=min(ans,x);
    printf("%.1Lf\n",ans);
    return 0;
}