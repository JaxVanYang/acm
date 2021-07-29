/*
 * @Descripttion: 反素数
 * @Topic link: https://www.acwing.com/problem/content/200/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-04-04 10:08:00
 * @LastEditTime: 2021-04-04 10:19:16
 */

/**
 * 1：1~N中最大的反素数，就是1~N中约数个数最多的数中最小的一个
 * 2：1~N（N<2e9）中任何数的不同质因子数量不会超过10个，且质因子的指数总和不超过30
 * 3：1~N中反素数的必要条件是x分解质因数， 质因子均为前十个素数组成，且指数递减
 */

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
typedef long long LL;
int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
int n;
int ans, maxd;

void dfs(int u, int k, int s, int num){
    if (num > ans || (num == ans && s < maxd)){
        maxd = s;
        ans = num;
    } 
    if (u == 9) return;
    for (int i = 1; i <= k; i ++){
        if ((LL)s * primes[u] > n) break;
        s = s * primes[u];
        dfs(u + 1, i, s, num * (i + 1));
    }
}

int main(){
    cin >> n;
    dfs(0, 30, 1, 1);
    cout << maxd << endl;
    
    return 0;
}