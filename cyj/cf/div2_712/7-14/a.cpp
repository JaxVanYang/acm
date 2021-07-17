/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-07-14 22:40:12
 * @LastEditTime: 2021-07-14 22:46:50
 */

#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int T;
    cin >> T;
    while (T --){
        int t;
        cin >> t;
        t -= 1;
        int sum = 1, tmp = 3;;
        while (t){
            if (t - tmp >= 0) t -= tmp, sum ++, tmp += 2;
            else {
                sum ++;
                break;
            }
        }
        cout << sum << endl;
    }
    return 0;
}