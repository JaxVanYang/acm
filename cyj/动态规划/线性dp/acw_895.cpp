/*
 * @Descripttion: 最长上升子序列
 * @Topic link: https://www.acwing.com/problem/content/897/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-04-09 09:12:35
 * @LastEditTime: 2021-04-09 09:13:06
 */

#include <iostream>

using namespace std;

const int N = 1010;

int f[N], d[N];

int main(){
    
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++){
        cin >> d[i];
    }
    for (int i = 0; i < n; i ++) f[i] = 1;
    for (int i = 1; i < n; i ++){
        for (int j = 0; j < i; j ++){
            if (d[i] > d[j]) f[i] = max(f[i], f[j] + 1);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i ++) ans = max(ans, f[i]);
    cout << ans << endl;
    
    return 0;
}