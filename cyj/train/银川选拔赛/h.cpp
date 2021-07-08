/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-04-28 08:36:10
 * @LastEditTime: 2021-04-28 08:41:08
 */

#include <iostream>

using namespace std;

const int N = 1e6 + 10, M = 1e7 + 10;
typedef long long LL;
LL a[N];
int num[M];
int n, k;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        a[i] %= k;
        num[a[i]] ++;
    }
    LL res = 0;
    for (int i = 1; i <= n; i ++){
        int t = (k-a[i]) % k;
        res += num[t];
        if (t == a[i]) res --;
    }
    cout << res / 2 << endl;
    return 0;
}