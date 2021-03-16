/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-03-14 10:14:25
 * @LastEditTime: 2021-03-14 10:17:16
 */

#include <iostream>
#include <cstring>

using namespace std;

const int N = 4;

typedef long long LL;

LL S;
int original[N], stand[N], consume[N];

bool check(LL lev){
    LL total = 0;
    LL ne[N] = {0};
    // cout << ne[1] << " " << ne[2] << " " << ne[3] << endl;
    for (int i = 1; i <= 3; i ++){
        ne[i] += (lev * stand[i] - original[i])  * consume[i];
        if(ne[i] > 0) total += ne[i];
    }
    // cout << total << endl;
    return S >= total;
}

int main(){
    
    int T;
    scanf("%d", &T);
    while (T --){
        scanf("%lld%d%d%d", &S, &original[1], &original[2], &original[3]);
        scanf("%d%d%d", &stand[1], &stand[2], &stand[3]);
        scanf("%d%d%d", &consume[1], &consume[2], &consume[3]);
        
        LL l = 0, r = 1e12;
        while (l < r){
            // cout << "l " << l << " r " << r  << endl;
            LL mid = l + r + 1 >> 1;    // 注意 二分写法
            if (check(mid)) l = mid;
            else r = mid  - 1;
        }
        
        printf("%lld\n", l);
    }
    
}