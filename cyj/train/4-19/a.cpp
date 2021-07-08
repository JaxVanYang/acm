/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-04-19 20:56:23
 * @LastEditTime: 2021-04-19 21:10:14
 */

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 3010;
int n, m;
int a[N];
int main(){

    cin >> n >> m;
    bool suc = true;
    int t = 0;
    for (int i = 1; i <= m; i ++) cin >> a[i];
    sort(a + 1, a + 1 + m);
    for (int i = 1; i <= m; i ++) {
        if (a[i] == 1 || a[i] == n) {
            suc = false;
            break;
        }
        if (a[i] == a[i-1] + 1){
            t ++;
            if (t == 3){
                suc = false;
                break;
            }
        }else t = 1;
    }
    if (suc) cout << "YES"<< endl;
    else cout << "NO" << endl;
    return 0;
}