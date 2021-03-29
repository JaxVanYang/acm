/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-03-05 08:34:34
 * @LastEditTime: 2021-03-05 08:34:35
 */

#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

typedef long long LL;
const int N = 200010;

int a[N], b[N];
LL sa[N], sb[N];
int n, m;
LL x, y;

int main(){
    cin >> n >> m >> x >> y;
    for (int i = 0; i < n; i ++){
        cin >> a[i];
        if (!i) sa[i] = a[i];
        else sa[i] = a[i] + sa[i-1];
    }
    for (int i = 0; i < m; i ++){
        cin >> b[i];
        if (!a) sb[i] = b[i];
        else sb[i] = b[i] + sb[i - 1];
    }
    int win = 0;
    LL k, t;
    LL live = 1e12 + 5;
    if (sa[n-1] >= 0){
        cout << -1 << endl;
        return 0;
    }
    if (sb[m-1] < 0){
        live = x / (-1 * sb[m-1]) * m;
    }
    t = y / (-1 * sa[n-1]) * n;
    if (t > live){
        cout << -1 << endl;
        return 0;
    }
    k += t;
    y %= (-sa[n-1]);
    LL dx = t / m, ax = t % m;
    x += dx * sb[m-1];
    for (int i = 0; i <= ax; i ++) x += b[i];
    
    for (int i = 0, j = ax + 1; ; i = (i + 1) % n, j = (j + 1) % m, k ++){
        y += a[i];
        if (y < 0){
            win = k;
            break;
        }
        x += b[j];
        if (x <= 0){
            break;
        }
    }
    
    
    if (win) cout << win;
    else cout << -1;
    
}