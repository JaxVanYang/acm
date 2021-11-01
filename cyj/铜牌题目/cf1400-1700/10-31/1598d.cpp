/*
 * @Descripttion: 正难则反，正着做是容斥，但比较难理清楚，反着减去唯一的一种情况，
                由于不存在两个完全相同的，不存在重复
 * @Topic link: 
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-10-31 14:19:31
 * @LastEditTime: 2021-10-31 15:44:30
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

map<int, int> s, s1;
typedef long long ll;
const int N = 2e5 + 10;

struct node {
    int a, b;
}p[N];

int main(){
    int T;
    cin >> T;
    while (T --){
        int n;
        cin >> n;
        s.clear(), s1.clear();
        for (int i = 1; i <= n; i ++){
            int a, b;
            cin >> a >> b;
            p[i] = {a, b};
            s[a] ++ , s1[b] ++;
        }
        ll res = 0;
        for (int i = 1; i <= n; i ++){
            int a = p[i].a, b = p[i].b;
            if (s[a] && s1[b]) res += (long long)(s[a]-1) * (s1[b] - 1);
        }
        cout << (long long)n * (n-1) * (n-2) / 6 - res << endl;
    }
    return 0;
}