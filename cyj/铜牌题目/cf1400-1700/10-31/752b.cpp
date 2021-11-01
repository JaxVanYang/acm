/*
 * @Descripttion: 思维题，分情况讨论
 * @Topic link: 
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-10-31 13:39:50
 * @LastEditTime: 2021-10-31 14:09:23
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    int T;
    cin >> T;
    int a, b;
    while (T --){
        cin >> a >> b;
        if (a > b) cout << (long long )a + b << endl;
        else {
            cout << (b - ((b%a)/2)) << endl;
        }
    }
    return 0;
}