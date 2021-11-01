/*
 * @Descripttion: 贪心
 * @Topic link: 
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-10-31 13:16:05
 * @LastEditTime: 2021-10-31 13:28:35
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
typedef long long ll;
void solve(){
    int n, k;
    cin >> n >> k;
    k ++;
    vector<int> a(n);
    for (auto &x : a){
        cin >> x;
        int t = 1;
        while (x --) t *= 10;
        x = t;
    }
    ll res = 0;
    for (int i = 0; i < n; i ++){
        int cnt = k;
        if (i != n-1) cnt = min(cnt, a[i+1] / a[i] - 1);
        k -= cnt;
        res += 1ll * cnt * a[i];
    }
    cout << res << endl;
}

int main(){
    int T;
    cin >> T;
    while (T --){
        solve();
    }
    return 0;
}