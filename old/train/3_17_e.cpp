/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-18 10:23:26
 * @LastEditTime: 2021-03-18 21:26:37
 */

#include <iostream>

using namespace std;

const int N = 110;

int  n;
string  a;

int main(){

    cin >> n  >> a;
    bool ans = false;
    for (int i = 0; i < n; i ++){
        if (a[i] != '?' && (i != n - 1 && a[i] == a[i+1])){
            ans = 0;
            break;
        }
        else if ((i == 0 || i == n - 1 || a[i-1]  == a[i + 1] || a[i +  1]  == '?') && a[i] == '?' ) {
            ans = 1;
        }
    }    
    if (ans) cout << "Yes";
    else cout << "No";

    return  0;
}