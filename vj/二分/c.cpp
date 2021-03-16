/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-03-11 19:42:00
 * @LastEditTime: 2021-03-11 19:42:00
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef long long LL;
const int N = 1e5 + 5;
int n, m, k;
LL at;
int a[N], tmp[N];

bool check(int t){
    at = 0;
    if (k == 1){
        for (int i = 1; i <= n; i ++){
            at += a[i];
        }
        return t >= at;
    }else {
        for (int i = 1; i <= n; i ++){
            int tmp = a[i] - t;
            // cout << "a[i] " << a[i] << endl;
            if (tmp > 0){
                at += tmp / (k - 1);
                if (tmp % (k-1)) at ++;
                // cout << "nnn " << at  << " t "  << t << endl;
                if (at > t) return false;
            }
        }
        return true;
    }
    
    
}
    
int main(){
    scanf("%d", &n);
    int ma = 0;
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), ma = max(ma, a[i]);
    scanf("%d", &k);
    int l = 1, r = ma;
    while (l < r){
        int mid = l + r >> 1;
        // cout << mid << endl;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    
    printf("%d\n", l);
    
    return 0;
}