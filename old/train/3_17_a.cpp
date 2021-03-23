/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-17 19:35:47
 * @LastEditTime: 2021-03-17 22:52:34
 */

#include <iostream>

using namespace std;

const int N = 110;
int a[N];
int n;

int main(){

    cin >> n;
    for (int i = 1; i <= n; i ++){
        int t;
        cin >> t;
        if (t == 'U') a[i] = 1;
        else a[i] = 0;
    }
    int res = 0;
    for (int i = 1; i <= n;){
        if (a[i] ^ a[i+1]){
            res += 1;
            i += 2;
        }else {
            res += 1;
            i += 1;
        }
    }
    cout << res << endl;

    return 0;
}