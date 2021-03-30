/*
 * @Descripttion: 状态压缩，26位01串存储字符串的根，set判重
 * @Topic link: https://vjudge.net/contest/429131#problem/C
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-24 21:06:48
 * @LastEditTime: 2021-03-24 23:27:43
 */

#include <iostream>
#include <set>

using namespace std;
typedef long long LL;
const int N = 1e3 + 10;

set<LL> sets;
bool st[N][27]; // 存储每个字符串的状态
int n;

int main(){

    cin >> n;
    for (int i = 1; i <= n; i ++){
        string a;
        cin >> a;
        LL num = 0;
        for (int j = 0; j < a.size(); j ++){
            int t = a[j] - 'a' + 1;
            if (!st[i][t]) st[i][t] = true;
        }
        for (int j = 1; j <= 26; j ++){
            if (st[i][j]) num += 1 << j;
        }
        sets.insert(num);
    }
    cout << sets.size() << endl;

    return 0;
}