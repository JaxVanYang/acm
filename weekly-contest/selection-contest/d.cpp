/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-03-14 11:29:15
 * @LastEditTime: 2021-03-14 19:52:36
 */

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long LL;


const int mod = 1e9 + 7, N = 1e6 + 5;
int n;
int num[N];

void divide(int x){
    for (int i = 2; i <= x / i; i ++){
        if (x % i == 0){
            int s = 0;
            while (x % i == 0) x /= i, s ++;
            num[i] += s;
        }
    }
    if (x > 1) num[x] += 1;
}

int main(){
    cin >> n;
    for (int i = 2; i <= n; i++){
        divide(i);
    }
    LL ans = 1;
    for (int i = 2; i <= n; i ++){
        if (num[i]) ans = ans * (num[i] + 1) % mod;
    }

    cout << ans << endl;

    return 0;
}