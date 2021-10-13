/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-10-14 00:05:39
 * @LastEditTime: 2021-10-14 00:42:14
 */

#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;

const int N = 110;
int a[N];
set<int> s;
int main(){
    int T;
    cin >> T;
    while (T --){
        int n, minv = 1e9;
        cin >> n;
        s.clear();
        for (int i = 1; i <= n; i ++){
            cin >> a[i];
            minv = min(minv, a[i]);
            if (!s.count(a[i])) s.insert(a[i]);
        }
        if (s.size() == 1){
            cout << -1 << endl;
            continue;
        }
        int ans = 0;
        for (int i = 1; i <= n; i ++){
            bool f = 1;
            int del = a[i] - minv;
            if (!del) continue;
            for (int j = 1; j <= n; j ++){       
                if ((a[j]-a[i]) % del){
                    f = 0;
                    break;
                }
            }
            if (f) ans = max(ans, del);
        }
        if (!ans) ans = 1;
        cout << ans << endl;
    }
    return 0;
}