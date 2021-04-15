/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-04-14 20:03:41
 * @LastEditTime: 2021-04-14 20:28:17
 */

#include <cstdio>
#include <iostream>
#include <algorithm>

#define x first
#define y second
using namespace std;

const int N = 2e5 + 10;
int a[N], f[N];
int main(){

    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1 ; i <= n; i ++) f[i] = 1;
    for (int i = 1; i <= n; i ++){
        if (a[i] <= 2 * a[i-1]){
            f[i] = max(f[i], f[i-1] + 1);
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i ++) res = max(res, f[i]);
    cout << res << endl;
    return 0;
}