#pragma comment(linker, "/STACK:102400000,102400000")
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#define pi 3.1415926535898
#define ll long long
#define lson rt<<1
#define rson rt<<1|1
#define eps 1e-6
#define ms(a,b) memset(a,b,sizeof(a))
#define legal(a,b) a&b
#define print1 printf("111\n")
#define pb(x) push_back(x)
#define pair4 pair<pair<int,int>,pair<int,int> >
#define fi first
#define se second
using namespace std;
const int maxn = 2000+10;
const int inf = 1e9+10;
const ll llinf =1e18+10;
const ll mod = 1e9+7;

int a[maxn][maxn];
ll dp[maxn][maxn];
int q[maxn],num[maxn];

int main()
{


    int _;
    scanf("%d",&_);
    while(_--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                dp[i][j]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(int j=1;j<=m;j++)
        {
            for(int i=n;i>=1;i--)
            {
                if(a[i][j]<=a[i+1][j])
                {
                    dp[i][j]=max(dp[i][j],dp[i+1][j]+1);
                }
            }
        }
        ll ans=1;

        for(int i=1;i<=n;i++)
            dp[i][m+1]=0;
        for(int i=1;i<=n;i++)
        {
            int x=n-i+1;
            int head=1,tail=0;
            for(int j=1;j<=m+1;j++)
            {
                int temp=0;
                while(head<=tail&&q[tail]>dp[i][j])
                {
                    temp+=num[tail];
                    ans=max(ans,q[tail]*(ll)temp);
                    tail--;
                }
                q[++tail]=dp[i][j];
                num[tail]=temp+1;
            }
        }
        printf("%lld\n",ans);
    }


}