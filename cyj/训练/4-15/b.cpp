/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-04-15 19:59:07
 * @LastEditTime: 2021-04-15 20:23:34
 */

#include <iostream>
#include <cstdio>

using namespace std;

int a[12];
int n;
string s;

int main(){
    
    cin >> n >> s;
    bool suc = false;
    for (int i = 1; i <= 9; i ++) cin >> a[i];
    int t = 0;
    for (int i = 0; i < s.size(); i ++){
        while (((a[s[i]-'0'] > s[i]-'0') && !suc ||  (a[s[i]-'0'] >= s[i]-'0') && suc) && i < s.size()){
            s[i] = '0' + a[s[i]-'0'];
            suc = true;
            i ++;
        }
        if (suc) break;
    }
    cout << s << endl;
    return 0;
}