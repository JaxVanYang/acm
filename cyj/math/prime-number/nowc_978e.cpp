/*
 * @Descripttion: Sherlock and His Girlfriend
 * @Topic link: https://ac.nowcoder.com/acm/contest/978/E
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-03-31 23:16:55
 * @LastEditTime: 2021-03-31 23:20:15
 */

/**
 * 转化为一般性的问题后，每个价值可看成一个点，当a为b的质因子时，a和b连边，在这个图中求至少需要多少种函数
 * 换个方式考虑，一个数a如果是另一个数b的质因子，则a一定为质数，b一定为合数，所以可看为一个二分图，两种颜色即可
 */

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int n;
int primes[N], cnt;
bool st[N];

void get(int n){
    for (int i = 2; i <= n; i ++){
        if (!st[i]) primes[cnt ++] = i;
        for (int j = 0; primes[j] <= n / i; j ++){
            st[primes[j]*i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int main(){
    cin >> n;
    if (n <= 2) puts("1");
    else puts("2");
    get(n + 1);
    for (int i = 2; i <= n + 1; i ++){
        if (!st[i]) printf("1 ");
        else printf("2 ");
    }
    
    
    return 0;
}