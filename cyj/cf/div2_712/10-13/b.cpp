/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-10-13 22:48:23
 * @LastEditTime: 2021-10-13 23:12:33
 */

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<int> v;
int main(){
    int T;
    cin >> T;
    while (T --){
        long long x;
        cin >> x;
        v.clear();
        if (x % 25 == 0){
            cout << 0 << endl;
            continue;
        }
        while (x){
            v.push_back(x%10);
            x/=10;
        }

        int ans = 1e6, tmp = 0;
        int f0 = 0, f1 = 0;
        for (int i = 0; i <v.size(); i ++){
            if (v[i] == 0) f0 ++;
            else tmp ++;
            if (f0 == 2) ans = min(ans, tmp);
        } 

        tmp = f0 = f1 = 0;
        for (int i = 0; i <v.size(); i ++){
            if (!f0 && v[i] == 5){
                f0++;
                continue;
            }
            if (f0 && v[i] == 2) f1 ++;
            if (f1) {
                ans = min(ans, tmp);
                break;
            }
            tmp ++;
        }

        tmp = f0 = f1 = 0;
        for (int i = 0; i <v.size(); i ++){
            if (!f0 && v[i] == 0){
                f0++;
                continue;
            }
            if (f0 && v[i] == 5) f1 ++;
            if (f1) {
                ans = min(ans, tmp);
                break;
            }
            tmp ++;
        }

        tmp = f0 = f1 = 0;
        for (int i = 0; i <v.size(); i ++){
            if (!f0 && v[i] == 5){
                f0++;
                continue;
            }
            if (f0 && v[i] == 7) f1 ++;
            if (f1) {
                ans = min(ans, tmp);
                break;
            }
            tmp ++;
        }

        cout << ans << endl;
    }
    return 0;
}