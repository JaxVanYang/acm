/*
 * @Descripttion:  阶乘分解 分解质因数
 * @Topic link: https://www.acwing.com/problem/content/199/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-04-03 16:18:03
 * @LastEditTime: 2021-04-03 16:18:51
 */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

int primes[N], cnt;
bool st[N];

void init(int n){
    for (int i = 2; i <= n; i ++){
        if (!st[i]) primes[cnt ++] = i;
        for (int j = 0; primes[j] <= n / i; j ++){
            st[primes[j] * i] = 1;
            if (i % primes[j] == 0) break;
        }
    }
}

int main(){
    
    int n;
    cin >> n;
    init(n);
    for (int i = 0; i < cnt; i ++){
        int t = primes[i];
        int s = 0;
        for (int j = n; j; j /= t) s += j / t;
        cout << t << ' ' << s << endl;
    }
    return 0;
}
