/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-04-13 20:07:06
 * @LastEditTime: 2021-04-13 22:01:54
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

const int N = 1010, mod = 1e9 + 7;
typedef long long LL;
typedef pair<int, int> PII;


int p[N];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> p[i];
    for (int i = 1; i <= n; i ++){
        bool st[N] = {0}, suc = false;
        int t = i;
        while (st[t] != 1){
            st[t] = 1;
            t = p[t];
        }
        cout << t << ' ';
    }
    return 0;
}
