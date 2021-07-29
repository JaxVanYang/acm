/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-07-22 12:23:21
 * @LastEditTime: 2021-07-22 12:42:01
 */

#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10, mod = 1e9 + 7;
ll f[N][26];
char s[N];
int main(){
    int n, m;
    scanf("%d", &n);
    while (n --){
        scanf("%d", &m);
        scanf("%s", s+1);
        char c = s[1];
        ll res = 1;
        for (int i = 2; i <= m; i ++){
            if (s[i] == c) res = (res * 2) % mod;
            else break; 
        }
        printf("%d\n", res);
    }
    return 0;
}
