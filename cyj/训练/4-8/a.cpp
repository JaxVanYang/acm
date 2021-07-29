/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-04-08 19:29:53
 * @LastEditTime: 2021-04-08 19:42:10
 */

#include <iostream>
#include <cstring>

using namespace std;

string a;

int main(){

    cin >> a;
    if (a.size() < 2) cout << a << endl;
    else {
        for (int i = 0, j = 1; j < a.size(); i ++, j ++){
            if (a[i] == '2' && a[j] == '1'  || a[i] ==  '1' && a[j] == '0'){
                char c = a[j];
                a[j] = a[i], a[i] = c;
            }
        }
        cout << a << endl;
    }

    return 0;
}