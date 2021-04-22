/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-04-07 19:29:09
 * @LastEditTime: 2021-04-07 20:41:13
 */

#include <iostream>
#include <cstring>

using namespace std;

const int N = 2e5 + 10;
string a, b;
int main(){
    cin >> a >> b;
    int len1 = a.size(), len2 = b.size();
    int cnt = 0;
    for (int i = 0; i < min(len1, len2); i ++){
        if (a[len1 - 1 - i] != b[len2 - 1 - i]) break;
        cnt ++;
    }
    cout << len1 + len2 - 2 * cnt << endl;

    return 0;
}