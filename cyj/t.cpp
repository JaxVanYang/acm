/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-11-01 09:18:01
 * @LastEditTime: 2021-11-01 09:21:16
 */

#include <iostream>

using namespace std;

int main(){
    string a, b;
    char c[100];
    cin >> a >> b;
    int cnt = 0;
    for (int i = 0, j = 0; i < a.size(); i ++, j = (j+1) % b.size()){
        c[cnt ++] = ((a[i] - 'a') + (b[j] - 'a') ) % 26 + 'a';
    }
    for (int i = 0; i < cnt; i ++) cout << c[i];

    return 0;
}