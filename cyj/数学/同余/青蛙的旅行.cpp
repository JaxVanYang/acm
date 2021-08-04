/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-07-30 19:22:13
 * @LastEditTime: 2021-07-30 19:57:16
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <bitset>

using namespace std;

const int N = 1, mod = 1e9 + 7;
typedef long long ll;
typedef pair<int, int> PII;

ll a, b, c, d, l;


ll exgcd(ll a, ll b, ll& x, ll&y){
    if (!b){
        x = 1, y = 0;
        return a;
    }
    else {
        ll t = exgcd(b, a % b, y, x);
        y -= a/b * x;
        return t;
    }
}

int main()
{
    cin >> a >> b >> c >> d >> l;
    c = d - c;
    a = b - a;
    ll x, y;
    d = exgcd(c, l, x, y);
    if (a % d) puts("impossible");
    else {
        x *= -(a / d);
        ll t = abs(l / d);
        x = (x % t + t) % t;
    }
    cout << x << endl;
    return 0;
}
