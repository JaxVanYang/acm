/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-04-15 20:36:29
 * @LastEditTime: 2021-04-15 21:02:47
 */

#include <set>
#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int a[N], b[N];
set<int> s;
int n, m, st;

void solve(){
    s.clear();
    st = 1;
    int res = 0;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= m; i ++) cin >> b[i];
    for(int j = 1; j <= m;){
        if (a[st] == b[j]){
            res += s.size() * 2 + 1;
            if (st < n) st ++;
            j ++;
        } 
        else if (s.count(b[j])) res += 1, s.erase(b[j]), j ++;
        else {
            s.insert(a[st]);
            if (st < n) st ++;
        }
    }
    cout << res << endl;
}

int main(){
    int T;
    cin >> T;
    while (T --){
        cin >> n >> m;
        solve();
    }

    return 0;
}