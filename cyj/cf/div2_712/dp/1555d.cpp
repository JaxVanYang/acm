/*
 * @Descripttion: 
 字符串s只由a，b，c构成，子串不能有长度两个及以上的回文串，每次询问一个区间至少需要修改多少个字符才能使这一段满足要求
 n， l， r 范围均为2e5

 由于只有三个字母，回文串长度限制为2，si必不等于s i-1， 且si 必不等于s i-2， 所以si等于si-3
 所以字符串必然是abcabcabc这样的形式

 函数next_permutation可以求出一个数组或字符串的所有排列组合，按字典序递增
 
 * @Topic link: https://codeforces.ml/problemset/problem/1555/D
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-08-12 10:13:56
 * @LastEditTime: 2021-08-12 11:00:43
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <bitset>

using namespace std;

const int N = 2e5 + 10, mod = 1e9 + 7;
typedef long long ll;
typedef pair<int, int> PII;

int n, m;
int a[6][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    string s;
    cin >> s;
    string t = "abc";
    int cur = 0;
    do {
        for (int i = 0; i < n; i ++){
            a[cur][i+1] = a[cur][i] + (s[i] != t[i % 3]);
        }
        cur ++;
    }while (next_permutation(t.begin(), t.end()));
    while (m --){
        int l, r, res = 2e5;
        cin >> l >> r;
        for (int i = 0; i < 6; i ++){
            res = min(res, a[i][r] - a[i][l-1]);
        }
        cout << res <<"\n";
    }
    return 0;
}
