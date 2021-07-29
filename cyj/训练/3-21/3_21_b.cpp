#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int N = 1010, mod = 1e9 + 7;
typedef long long LL;
typedef pair<int, int> PII;

int a[N];
int n, k;

int main()
{
    cin >> n >> k;   
    for (int i = 1; i <= n; i ++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int res = 1e7;
    for (int i = 1; i <= n; i ++){
        for (int j = i; j <= n; j ++){
            if (a[j] - a[i] <= k) res = min(res, n - (j - i  + 1));
        }
    }
    cout << res << endl;
    return 0;
}
