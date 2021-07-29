/*
 * @Descripttion: 
 * @Topic link: https://vjudge.net/contest/429131#problem/E
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-24 20:31:35
 * @LastEditTime: 2021-03-24 23:28:07
 */

#include <iostream>

using namespace std;

int n1, n2;

int main(){

    string a;
    cin >> a;
    for (int i = 0; i < a.size(); i ++){
        if (a[i] == 'o') n1 ++;
        if (a[i] == '-') n2 ++;
    }
    if (n1 == 0){
        puts("YES");
        return 0;
    }
    if (n2 % n1) puts("NO");
    else puts("YES");

    return 0;
}