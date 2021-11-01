/*
 * @Descripttion: 匈牙利算法解法，注意数组范围，边最多有n^2条
 * @Topic link: https://www.acwing.com/problem/content/description/2177/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-08-09 12:01:31
 * @LastEditTime: 2021-08-09 12:02:26
 */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 110;
int m, n, match[N * 2];
bool st[N * 2];
int h[N], e[N * N], ne[N * N], idx;

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool find(int x){
    for (int i = h[x]; ~i; i = ne[i]){
        int j = e[i];
        if (st[j]) continue;
        st[j] = 1;
        int t = match[j];
        if (t == 0 || find(match[j])){
            match[j] = x;
            return true;
        }
    }
    return false;
}

int main(){
    cin >> m >> n;
    memset(h, -1, sizeof h);
    int a, b;
    while (cin >> a >> b, a != -1){
        add(a, b);
    }
    int res = 0;
    for (int i = 1; i <= m; i ++){
        memset(st, 0, sizeof st);
        if (find(i)) res ++;
    }
    cout << res << endl;
    for (int i = m+1; i <= m+1+n ; i++){
        if (match[i]) cout << match[i] << ' ' << i << endl;
    }
    return 0;
}

