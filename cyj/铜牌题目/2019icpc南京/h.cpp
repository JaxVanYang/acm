/*
 * @Descripttion: 
 * @Topic link: https://nanti.jisuanke.com/t/42402
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-10-25 09:15:17
 * @LastEditTime: 2021-10-25 10:04:07
 */

#include <iostream>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b + c){
        cout << "YES\n";
        if (!b && !c && a == 1){
            cout << 0;
        }
        else cout << (b + c) * 2 + 1 << endl;
    }
    else {
        cout << "NO";
    }
    return 0;
}