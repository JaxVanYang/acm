/*
 * @Descripttion: 质数距离 任何一个合数必定包含一个不超过n^0.5的质因子
 * @Topic link: https://www.acwing.com/problem/content/198/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-04-02 15:35:27
 * @LastEditTime: 2021-04-02 16:24:54
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e6+ 10;
typedef long long LL;
int primes[N], cnt, tmp[N];
bool st[N], is_p[N];

void get(int n){
    for (int i = 2; i <= n; i ++){
        if (!st[i]) primes[cnt ++] = i;
        for (int j = 0; primes[j] <= n / i; j ++){
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}

int main(){
    
    get(N - 1);
    int l, r;
    while (cin >> l >> r){
        memset(is_p, 0, sizeof is_p);
        for (int i = 0; i < cnt; i ++){
            //  以下两处注意使用longlong t与j
            LL t = primes[i];
            for (LL j = max(t * 2, (l + t - 1) / t * t); j <= r; j += t){
                is_p[j - l] = 1;
            }
        }
        int num = 0;
        for (int i = 0; i < r - l + 1; i ++){
            if (!is_p[i] && i + l >= 2) tmp[num ++] = i + l;
        }
        // for (int i = 0; i < num; i ++) cout << tmp[i] << " ";
        // cout << endl;
        if (num < 2) puts("There are no adjacent primes.");
        else {
            int minv = 0, maxv = 0;
            for (int i = 0; i + 1 < num; i ++){
                int v = tmp[i + 1] - tmp[i];
                if (v < tmp[minv + 1] - tmp[minv]) minv = i;
                if (v > tmp[maxv + 1] - tmp[maxv]) maxv = i;
            }
            printf("%d,%d are closest, %d,%d are most distant.\n", tmp[minv], tmp[minv + 1], tmp[maxv], tmp[maxv + 1]);
        }
        
    }
    
    return 0;
}
