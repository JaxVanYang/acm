/*
 * @Descripttion: 
  a^b = c  == a^c = b
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-08-13 20:43:36
 * @LastEditTime: 2021-08-13 21:17:56
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

typedef long long ll;
typedef pair<int, int> PII;



int main()
{
    int T;
    cin >> T;
    while (T --){
        int n, m;
        cin >> n >> m;
        if (n > m) cout << 0 << "\n";
        else {
            int t = m + 1, ans = 0;
            for (int i = 30; i >= 0; i --){
                if (!(n >> i & 1) && t >> i & 1) ans += 1 << i;
                if (n >> i & 1 && (!(t >> i & 1))) break;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
