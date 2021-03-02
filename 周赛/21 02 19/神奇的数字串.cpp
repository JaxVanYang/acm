/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-02-25 09:13:01
 * @LastEditTime: 2021-02-25 09:13:01
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#define x first
#define y second

using namespace std;

const int N = 1000005;

typedef pair<int, int> PII;

int s[N * 2], a[N * 2];
PII q[N * 2];

int n;


int main(){
    
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        s[i] = a[i] + s[i - 1];
    }
    for (int i = n + 1; i < 2 * n + 1; i ++) a[i] = a[i - n], s[i] = s[i-1] + a[i];
    
    int hh = 0, tt = -1;
    
    int res = 0;
    for (int i = 1; i <= 2 * n - 1; i ++){
        if (hh <= tt && i - q[hh].y + 1 > n) hh ++;
        while (hh <= tt && q[tt].x >= s[i] ) tt --;
        q[++ tt] = {s[i], i};
        if (i >= n && hh <= tt && q[hh].x  - s[i - n] >= 0) res ++;
    }
    
    cout << res << endl;

    
    return 0;
}