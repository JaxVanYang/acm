/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-09-06 20:11:07
 * @LastEditTime: 2021-09-06 20:27:32
 */

#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    while (T --){
        int n, a, b, c, d;
        bool f = 1;
        cin >> n >> a >> b >> c >> d;
        if (a > n || b > n || c > n || d > n){
            cout << "NO\n";
            continue;
        }
        int x[4] = {a, b, c, d};
        for (int i = 0; i <= 3; i ++){
            if (x[i] == 0 && (x[(i+1) % 4] >= n || x[(i+3)%4] >= n)) f = 0;
            if (x[i] == 0 && x[(i+2)%4] == 0 && (x[(i+1) % 4] >= n-1 || x[(i+3)%4] >= n-1)) f = 0;
            if (x[i] == 1 && (x[(i+1) % 4] >= n && x[(i+3)%4] >= n)) f = 0;
            if (x[i] == 1 && x[(i+2)%4] == 1 && ((x[(i+1) % 4] >= n && x[(i+3)%4] >= n-1) || (x[(i+1) % 4] >= n-1 && x[(i+3)%4] >= n))) f = 0;
            if (x[i] == 1 && x[(i+2) % 4] == 0 && (x[(i+1) % 4] >= n-1 && x[(i+3)%4] >= n-1)) f = 0;
        }
        if (!f) cout << "NO\n";
        else cout << "YES\n";
    }

    return 0;
}