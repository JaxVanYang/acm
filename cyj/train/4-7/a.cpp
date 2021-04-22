/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-04-07 19:29:01
 * @LastEditTime: 2021-04-07 19:42:39
 */

#include <iostream>

using namespace std;

const int N =  1010;

int a[N], b[N], cnt;

int main(){

    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) cin >> a[i];
    a[n] = 0;
    int last = -1;
    for (int i = 0; i <= n; i ++){
        if (a[i] <= last) b[++ cnt] = last, last = a[i];  // <= 为错点
        else last = a[i];
    }
    cout << cnt << endl;
    for (int j = 1; j <= cnt; j ++) cout << b[j] << ' ';

    return 0;
}