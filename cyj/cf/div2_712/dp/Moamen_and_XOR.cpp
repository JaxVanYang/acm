/*
 * @Descripttion: 
 * @Topic link: https://codeforces.ml/problemset/problem/1557/C
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-08-11 16:09:27
 * @LastEditTime: 2021-08-11 17:30:39
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <bitset>

using namespace std;

const int N = 1, mod = 1e9 + 7;
typedef long long ll;
typedef pair<int, int> PII;

int n, k;

int qmi(int x, int k){
    ll res = 1  % mod; 
    while (k){
        if (k & 1) res = res * x % mod;
        k >>= 1;
        x = (ll)x * x % mod;
    }
    return res;
}

int main()
{
    int T;
    scanf("%d\n", &T);
    while ( T --){
        scanf("%d%d", &n, &k);
        if (n & 1){
            printf("%d\n", qmi((qmi(2, n-1) + 1) % mod, k));
        }
        else {
            int res;
            if (!k) res = 1;
            else res = qmi(2, n-1);
            for (int i = 2; i <= k; i ++){
                res = (((ll)res * (qmi(2, n-1) - 1)) + qmi(qmi(2, n), i-1)) % mod;
            }
            printf("%d\n", res);
        }
    }
    return 0;
}
