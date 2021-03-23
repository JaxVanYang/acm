/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-21 12:05:07
 * @LastEditTime: 2021-03-21 12:34:36
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <limits.h>

using namespace std;
const int N = 400;

int a[N], tr[N];
int n;
int ma;

int lowbit(int x){
    return x & -x;
}

void add(int x){
    for (int i = x; i <= ma;  i += lowbit(i)) tr[i] += 1; 
}

int sum(int x){
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main(){

    int T;
    cin >> T;
    while (T --){
        memset(tr, 0, sizeof tr);
        cin >> n;
        ma = 0;
        int res = 0, ans = INT_MAX;
        for (int i = 1; i <= n; i ++) cin >> a[i], ma = max(ma, a[i]);
        for (int i = 1; i <= n; i ++){
            int y = a[i];
            res += sum(ma) - sum(y);
            add(y);
        } 
        ans = res, res = 0;
        memset(tr, 0, sizeof tr);
        for (int i = 1 ; i<= n; i ++){
            int y = a[i];
            res += sum(y-1);
            add(y);
        }
        ans = min(ans, res);

        cout << ans * n << endl;
    }

    return 0;
}