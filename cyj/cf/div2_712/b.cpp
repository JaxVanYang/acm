/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: Wrong Answer 从前往后做限制条件太多，难以考虑清楚
 * @Author: cyj
 * @Date: 2021-04-10 20:49:54
 * @LastEditTime: 2021-04-10 22:47:06
 */

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 3e5+ 10;

int n;
bool st[N];
string a, b;
int main(){

    int T;
    cin >> T;
    while (T --){
        cin >> n >> a >> b;
        bool suc = false;
        for (int i = 0; i <= n; i ++) st[i] = 0;
        if (n & 1 && a[n-1] != b[n-1]){
            cout <<"NO" <<endl;
            continue;
        }
        int zero = 0, one = 0;
        bool both = 1, rever = 1;
        for (int i = 0; i < n; i += 2){
            if (a[i] == '0') zero ++;
            else one ++;
            if (a[i +1]== '0') zero ++;
            else one ++;         
            st[i + 1] = one == zero ? 1 : 0;
            if (a[i] == b[i] && a[i + 1] == b[i + 1]){
                both &= 1;
            }else both =  0;
            if (a[i] != b[i] && a[i + 1] != b[i + 1]){
                rever &= 1;
            }else rever = 0;
            if (both) rever = 0;
            else if (rever) both = 0;
            if ((a[i] == a[i+1] && b[i] != b[i+1]) || (b[i] == b[i+1] && a[i] != a[i + 1])){
                suc = true;
                break;
            }
            if (!st[i + 1] && (!both && !rever)){ 
                suc = true;
                break;
            }
            // cout << "i " << i << " " << both << " " << rever << endl;
            if (st[i+ 1]) both = rever = 1;
        }
        if (suc) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

    return 0;
}