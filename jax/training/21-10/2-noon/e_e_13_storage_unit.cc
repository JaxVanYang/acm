#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back
#define endl "\n"
#define debug(x) cout << #x << ":" << x << endl;
#define bug cout << "********" << endl;
#define all(x) x.begin(), x.end()
#define lowbit(x) x & -x
#define fin(x) freopen(x, "r", stdin)
#define fout(x) freopen(x, "w", stdout)
#define ull unsigned long long
#define ll long long 

const double eps = 1e-15;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const double pi = acos(-1.0);
const int mod =  1e9 + 7;
const int maxn = 1e6 + 10;

using namespace std;

int s[maxn], n, le[maxn];
ll sum[maxn], ret;
int dp[maxn][32], fac[maxn];
char p[20];

int get(int i){
    ll a = sum[i - 1];
    int l = i, r = n;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(sum[mid] - a <= ret)l = mid;
        else r = mid - 1;
    }
    return l - i + 1;
}

void st(){
    for(int i = 2; i < maxn; i ++)fac[i] = fac[i/2] + 1;
    for(int i = 1; i <= n; i ++){
        dp[i][0] = le[i];
        for(int j = 1; j <= 30; j ++)dp[i][j] = inf;
    }

    for(int j = 1; (1 << j) <= n; j ++){
        for(int i = 1; i + (1 << j) - 1 <= n; i ++){
            dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int getmin(int a, int b){
    int len = b - a + 1;
    int k = fac[len];
    return min(dp[a][k], dp[b - (1 << k) + 1][k]);
}

int main(){
    scanf("%d%s", &n, p + 1);
    int len = strlen(p + 1);
    for(int i = 1; i < len; i ++)ret = ret * 10 + (p[i] - '0'); 
    if(p[len] == 'G')ret = ret * 1024;
    else if(p[len] == 'T')ret = ret * 1024 * 1024;

    for(int i = 1; i <= n; i ++)scanf("%d", &s[i]), sum[i] = sum[i - 1] + s[i];

    for(int i = 1; i <= n; i ++)le[i] = get(i);
    st();
    int ans = 0, l = 1, r = n;
    while(l < r){
        int mid = l + r + 1 >> 1;
        if(getmin(1, n - mid + 1) >= mid)l = mid;
        else r = mid - 1;
    }
    ans = l;
    int pos = -1;
    for(int i = 1; i <= n - ans; i ++){
        if(le[i] <= ans && pos == -1)pos = i;
    }
    printf("%d %d\n", ans, pos);
    return 0;
}