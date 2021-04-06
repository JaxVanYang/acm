/*
 * @Descripttion: Goldbach's Conjecture
 * @Topic link: https://ac.nowcoder.com/acm/contest/978/D
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-03-31 22:47:58
 * @LastEditTime: 2021-03-31 22:48:29
 */

#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

int primes[N], cnt;
bool st[N];

void get_primes(int n){
    for (int i = 2; i <= n; i ++){
        if (!st[i]) primes[cnt ++] = i;
        for (int j = 0; primes[j] <= n / i; j ++){
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}
int n;

int main(){
    get_primes(N - 1);
    
    while (scanf("%d", &n), n){
        for (int i = 1; i < cnt; i ++){
            int a = primes[i], b = n - a;
            if (!st[b]) {
                printf("%d = %d + %d\n", n, a, b);
                break;
            }
        }
    }
    
    return 0;
}