/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-10-24 18:59:52
 * @LastEditTime: 2021-10-24 19:10:41
 */

#include <iostream>
#include <cstdio>

using namespace std;

const int N = 3e6 + 500;

int tr[N][2], n, idx;

void insert(int x){
    int p = 0;
    for (int i = 30; i >= 0; i --){
        int v = x >> i & 1;
        if (!tr[p][v]) tr[p][v] = ++ idx;
        p = tr[p][v];
    }
}

int dfs(int x, int i){
    int res = 0;
    if (i < 0) return res;
    if (tr[x][0] && tr[x][1]) return res + (1<<i) + min(dfs(tr[x][0], i-1), dfs(tr[x][1], i-1));
    else if (tr[x][0]) res += dfs(tr[x][0], i-1);
    else res += dfs(tr[x][1], i-1);
    return res;
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i ++){
        int x;
        cin >> x;
        insert(x);
    }
    int ans = dfs(0, 30);
    cout << ans << endl;
    return 0;
}