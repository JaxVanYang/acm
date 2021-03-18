/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-17 20:29:19
 * @LastEditTime: 2021-03-18 09:48:23
 */

#include <iostream>
#include <cstring>


using namespace std;

const int N = 110;
int n;

int main(){

    cin >> n;
    string a;
    cin >> a;
    int res = n;
    for( int i = 1; i <= n /2; i ++){
        if (a.substr(0, i) ==  a.substr(i, i)) res = n - i + 1;
    }

    cout <<res << endl;
    return 0;
}