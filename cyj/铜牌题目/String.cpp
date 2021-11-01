/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-10-16 16:18:40
 * @LastEditTime: 2021-10-16 16:52:31
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <map>

using namespace std;

const int N = 1e5 + 10, mod = 1e9 + 7;
typedef long long ll;
typedef pair<int, int> PII;

map<string, int> s;
int n, m;
string str;
int main()
{
    while (scanf("%d%d", &n, &m)){
        cin >> str;
        int sum = 0;
        for (int i = 0; i < 3; i ++){
            s.clear();
            int f = 0, ans = 0;
            for (int j = 0; j < m*n; j += m){
                string t = str.substr(i + j, m);
                if (!s.count(t)) s[t] = 1;
                else s[t] += 1, f ++;
            }
            if (!f) ans ++;
            for (int j = 0; i + m*n + j * m + m < str.length(); j ++){
                string t  =str.substr(i + m*n + j * m, m);
                string t1 = str.substr(i + j * m, m);
                if (!s.count(t)) s[t] = 1;
                else s[t] ++, f ++;
                if (--s[t1] == 0) f--;
                if (!f) ans ++;
            }
            sum += ans;
            // cout << ans << endl;
        }
        cout << sum << endl;
    }
    return 0;
}
