/*
 * @Descripttion: Balance the Bits
 * @Topic link: https://codeforces.ml/contest/1504/problem/C
 * @Question meaning: 
 * 给定一个01组成的长度为n的字符串s，要求构造两个由）与（组成的字符串满足对应位置）与（
 * 相等（当s[i]==1）,不相等(s[i]==0)，且合法，即在任意前缀中（数量大于）数量
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-04-12 20:51:00
 * @LastEditTime: 2021-04-12 21:25:37
 */

#include <iostream>
#include <cstdio>

using namespace std;

const int N = 2e5 + 5;

string a, b, s;
int n, k;

void solve(){
    cin >> n >> s;
    a.clear(), b.clear();
    k = 0;
    // 由于a，b两个字符串中）与（数量一定为偶数，且s[i]为1时，可贡献两个）或（，为0时贡献一个）
    // 或一个（，所以0的数量一定为偶数，相应的1数量也一定为偶数（反之无解）
    // 而合法序列开头必均为（，末尾必为），所以当开头或结尾为'0'时，无解
    // 之后只需要保证序列（与）合法即可，前一半1放（，后一半1放），0时轮流放（，） 与 ），（
    for (int i = 0; i < s.size(); i ++) if (s[i] == '1') k ++;
    if (k & 1 || s[0] == '0' || s.back() == '0'){
        cout << "NO\n";
        return;
    }
    a.push_back('('), b.push_back('(');
    bool odd = 1;
    for (int cnt = 2, i = 1; i < s.size(); i ++){
        if (s[i] == '1'){
            if (cnt * 2 <= k) a.push_back('('), b.push_back('(');
            else a.push_back(')'), b.push_back(')');
            cnt ++;
        }
        else {
            if (odd) a.push_back(')'), b.push_back('(');
            else a.push_back('('), b.push_back(')');
            odd ^= 1;
        }
    }
    cout << "YES\n" << a << '\n' << b << '\n';
    return;
}

int main(){

    int T;
    cin >> T;
    while (T --){ // 多组测试数据这样写比较方便，错误时可以直接return
        solve();
    }

    return 0;
}