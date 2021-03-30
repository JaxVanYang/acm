/*
 * @Descripttion: 
 * @Topic link: https://vjudge.net/contest/429131#problem
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-24 19:35:56
 * @LastEditTime: 2021-03-24 23:27:27
 */

#include <iostream>

using namespace std;

int n;
string a;

int main(){

    cin >> n;
    cin >> a;
    int num = 0;
    if (a[0] == '0'){
        cout << '0' << endl;
        return 0;
    }
    for (int i = 0; i < n; i ++){
        if (a[i] == '0') num ++;
    }
    string b;
    b += '1';
    for (int i = 0; i < num ; i++) b += '0';
    cout << b << endl;

    return 0;
}