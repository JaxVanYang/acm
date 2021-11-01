/*
 * @Descripttion: 
 * @Topic link: https://nanti.jisuanke.com/t/42542
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-10-25 21:24:35
 * @LastEditTime: 2021-10-25 21:37:25
 */

#include <cstdio>
#include <iostream>

using namespace std;

bool is_prime(int x){
    bool f = 1;
    for (int i = 2; i <= x / i; i ++){
        if (x % i == 0) {
            f = 0;
            break;
        }
    }
    return f;
}

int main(){
    int T;
    cin >> T;
    while (T --){
        int l, r;
        cin >> l >> r;
        if (r - l + 1 > 50) cout << "Yes\n";
        else {
            int t = 0;
            for (int i = l; i <= r; i ++){
                if (is_prime(i)) t ++;
            }
            if (t * 3 >= (r-l+1)) cout << "No\n";
            else cout << "Yes\n";
        }
    }
    return 0;
}