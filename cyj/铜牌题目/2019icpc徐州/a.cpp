/*
 * @Descripttion: 利用异或和性质进行模拟，小于4个时使用异或前缀和暴力
 * @Topic link: https://nanti.jisuanke.com/t/42540
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-10-25 11:19:01
 * @LastEditTime: 2021-10-25 20:52:51
 */

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

ll a[10];

int main(){
    int T;
    scanf("%d", &T);
    while (T --){
        ll l, r, s;
        scanf("%lld%lld%lld", &l, &r, &s);
        ll num = r - l + 1;
        memset(a, 0, sizeof a);
        if (num <= 4){
            ll t = l, ans = -1;
            for (int i = 1; i <= num; i ++, t ++){
                a[i] = t;
                a[i] ^= a[i-1];
            }
            for (int i = 1; i <= num; i ++){
                for (int j = i; j <= num; j ++){
                    if ((a[i-1] ^ a[j]) <= s && (j-i+1) > ans){
                        ans = j-i+1;
                    }
                }
            }
            printf("%d\n", ans);
        }
        else {
            ll ans = -1;
            ll t = l, idx = 0;
            if (t % 2) a[++idx] = t, t ++;
            int tim = (r-t+1) % 4;
            ll  num = (r-t+1)/4;
            for (ll i = r-tim+1; i <= r; i ++){
                a[++ idx] = i;
            }
            for (int i = 1; i <= idx; i ++){
                a[i] ^= a[i-1];
            }
            for (int i = 1; i <= idx; i ++){
                for (int j = i; j <= idx; j ++){
                    if ((a[i-1] ^ a[j]) <= s && (j-i+1) > ans){
                        ans = j-i+1;
                    }
                }
            }
            if (ans == -1 && num) ans = 4 * num;
            else if (num) ans += 4 * num;
            printf("%lld\n", ans);
        }
    }
    return 0;
}