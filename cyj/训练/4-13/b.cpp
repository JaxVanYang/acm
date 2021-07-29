/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-04-13 20:25:34
 * @LastEditTime: 2021-04-13 21:15:42
 */

#include <iostream>

using namespace  std;

const int N = 2e5 + 10;

string a, b;

int main(){

    cin >> a >> b;
    int l = 0, ra = a.size()-1,  rb = b.size()-1;
    while (l <= r){
        while(a[l] == b[l]) l ++;
        while (a[ra] == b[rb]) ra --, rb --;
    }

    return 0;
}