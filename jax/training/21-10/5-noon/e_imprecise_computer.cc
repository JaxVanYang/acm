#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <deque>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
// #include <unordered_map>

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
const int maxn = 2e6 + 10;

using namespace std;

int s[maxn], n;
int p[maxn];

bool f(int a){
    p[1] = a;
    for(int i = 2; i < n; i ++){
        if(s[i] == 2){
            if(!p[i - 1])return false;
            p[i] = 1;
        }
        else if(s[i] == 1){
            if(p[i - 1])p[i] = 0;
            else p[i] = 1;
        }
        else{
            p[i] = p[i - 1];
        }
    }

    if(p[n - 1]){
        if(!s[n])return false;
    }
    else {
        if(s[n])return false;
    }
    return true;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)scanf("%d", &s[i]);

    int ok = 0;
    if(s[1] > 1 || s[n] > 1)ok = 1;
    for(int i = 2; i < n; i ++)if(s[i] > 2)ok = 1;
    if(ok)return puts("NO"), 0;

    if(s[1])ok = f(1);
    else ok = f(0);
    if(ok)puts("YES");
    else puts("NO");
    return 0;
}