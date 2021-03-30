/*
 * @Descripttion: 
 * @Topic link: https://vjudge.net/contest/429131#problem/B
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-24 19:45:28
 * @LastEditTime: 2021-03-24 23:26:45
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

// const int N = , mod = 1e9 + 7;
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
LL k;

int main()
{
    cin >> n >> m >> k;
    if (k <= n - 1) cout << 1 + k << " " << 1 << endl;
    else {
        k -= n;
        LL t = k / (m-1), t2 = k % (m-1);
        if (k == 0){
            cout << n << " " << 2 << endl;
            return 0;
        }
        int x = 0, y = 0;
        if (t & 1){ 
            x = n - t;
            y = m - t2;
        }
        else {
            x = n - t;
            y = 2 + t2;
        }
        cout << x << " " << y << endl;
    }
    return 0;
}
