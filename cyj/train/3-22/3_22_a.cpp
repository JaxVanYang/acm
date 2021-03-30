/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-23 18:51:28
 * @LastEditTime: 2021-03-23 18:58:02
 */

#include <iostream>

using namespace std;

const int N = 1010;

int n, a, b, c, T;
int h[N];

int main(){

    cin >> n >> a >> b >> c >> T;
    int res = 0;
    if (c > b){
        for (int i = 0; i < n; i ++){
            cin >> h[i];
            res += a + (c - b) * (T - h[i]);
        }
    }
    else {
        for (int i = 0; i < n; i ++){
            cin >> h[i];
            res += a;
        }
    }
    cout << res << endl;

    return 0;
        
    
    

    return 0;
}