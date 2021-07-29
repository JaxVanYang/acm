/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-30 19:34:03
 * @LastEditTime: 2021-03-30 19:53:28
 */

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

string a;
bool st[3];

bool cal(int i){
    memset(st, 0, sizeof st);
    for (int j = 0; j < 3; j ++){
        if (a[i + j] != '.') st[a[i + j] - 'A'] = 1;
    }
    for (int j = 0; j < 3; j ++){
        if (!st[j]) return false;
    }
    return true;
}

int main(){

    cin >> a;
    bool suc = false;
    if (a.size() < 3){
        puts("No");
        return 0;
    }
    for (int i = 0; i < a.size() - 2; i ++){
        if (a[i] != '.' && cal(i)) suc = true, puts("Yes");
        if (suc) return 0;
    }
    puts("No");

    return 0;
}