/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-10-13 23:19:49
 * @LastEditTime: 2021-10-13 23:44:32
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const int N = 4e5 + 10;

int n, m, k;

int main(){
    int T;
    cin >> T;
    while (T --){
        cin >> n >> k;
        int x = 0;
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 1; i <= k; i ++){
            int t;
            cin >> t;
            q.push(n-t);
        }
        int ans = 0;
        while (x < n){
            int t = q.top();
            q.pop();
            if (x < (n - t)){
            ans ++;
            x += t;
            }else break;
        }
        cout << ans << endl;
    }
    return 0;
}