/*
 * @Descripttion: 将一个回文串中加一个'a'使之变为非回文串
 * @Topic link: https://codeforces.ml/contest/1504/problem/A
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-04-10 20:24:15
 * @LastEditTime: 2021-04-12 10:32:36
 */

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;
string a;
int n;
int main(){
    cin >> n;
    while (n  --){
        cin >> a;
        int l = 0, r = a.size() - 1 ;
        bool suc = false;
        while (l <= r){
            if (a[l] == a[r] && a[l] != 'a'){
                // 右边加个a
                puts("YES");
                for (int i = 0; i <= r; i ++) printf("%c", a[i]);
                printf("a");
                for (int i = r + 1; i < a.size(); i ++) printf("%c", a[i]);
                suc = true;
                break;
            }
            else if (a[l] != a[r]){
                // r左边加个a
                puts("YES");
                for (int i = 0; i < r; i ++) printf("%c", a[i]);
                printf("a");
                for (int i = r; i < a.size(); i ++) printf("%c", a[i]);
                suc = true;
                break;
            }
            l ++, r --;
        }
        if (!suc) puts("NO");
        else puts("");
    }

    return 0;
}