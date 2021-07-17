/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-07-14 22:54:16
 * @LastEditTime: 2021-07-14 23:34:52
 */

#include <iostream>
#include <cstdio>

using namespace std;

const int N = 110;

char s[N];

int main(){
    int T;
    cin >> T;
    while (T --){
        int len, a, b;
        cin >> len >> a >> b;
        scanf("%s", s + 1);
        if (b >= 0){
            cout << a * len + b * len << endl;
        }
        else {
            int n1 = 0, n2 = 0, t = -1, s1 = 0, s2 = 0;
            for (int i = 1; i <= len; i ++){
                if (s[i] == '1') s1 ++;
                else s2 ++;
                if (t == -1 || (s[i] - '0' == t)){
                    t = s[i] - '0';
                }
                else {
                    t = s[i] - '0';
                    if (s[i] == '1') n2 ++;
                    else n1 ++;
                }
                if (i == len) t == 1 ? n1 ++ : n2 ++; // 最后一段别忘了判断
            }
            if (n1 > n2) cout << s2 * a + n2 * b + s1 * a + b << endl;
            else cout << s1 * a + n1 * b + s2 * a + b << endl;
        }
    }
    return 0;
}