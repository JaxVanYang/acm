/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-04-28 08:03:09
 * @LastEditTime: 2021-04-28 08:05:38
 */

#include <iostream>

using namespace std;

int main(){
    int n;
    while (cin >> n, n){
        if (n & 1) cout << "Bob" << endl;
        else cout << "Alice" << endl;
    }

    return 0;
}