/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-02-05 19:51:52
 * @LastEditTime: 2021-02-05 19:51:52
 */

#include <iostream>

using namespace std;

string a;
bool work[26];
char t;

int main(){
    
    cin >> a;
    a += '*';
    int len = 0;
    for (int i = 0; i < a.size(); i ++){
        if (!i || t == a[i]){
            len ++;
            t = a[i];
        }
        else {
            if (len % 2)work[t - 'a'] = true;
            len = 1;
            t = a[i];
        }
    }
    
    int res = 0;
    for (int i = 0; i < 26; i ++){
        if (work[i]) res ++;
    }
    
    cout << 26 - res;
    
    return 0;
}