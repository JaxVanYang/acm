/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-04-15 19:47:25
 * @LastEditTime: 2021-04-15 19:56:04
 */

#include <cstdio>
#include <iostream>

using namespace std;
int n, k;

void solve(){
    if (n % 2 == 0) cout << (k % n) + 1;
    else {
        int i = 1, j = n, t = 0;
        while (t && i == 1 && j == n){
            if (i == 1 && j == n && ) 
            if (i == j){
                if (i == n) i = 1;
                else i += 1;
                 
            }
        }
        
    }
}

int main(){

    int T;
    
    while (T --){
        cin >> n >> k;
        solve();
    }

    return 0;
}