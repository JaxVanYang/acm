/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-02-05 19:39:02
 * @LastEditTime: 2021-02-05 19:39:02
 */

#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

LL n;

int main(){
    
    cin >> n;
    int len = 0;
    LL t = n;
    while (t / 10 != 0){
        t /= 10;
        len ++;
    }
    len ++;
    int res = 0;
    if (len % 2){
        for (int i = 0; i < len / 2; i ++){
            res = res * 10 + 9;
        }
    }
    else {
        LL a = n;
        for (int i = 0; i < len / 2; i ++) a /= 10;
        LL c = a;
        for (int i = 0; i < len / 2; i ++) c *= 10;
        LL b = n - c;
        if (a > b) res = a - 1;
        else res = a;
    }
    
    cout << res;
    return 0;
}