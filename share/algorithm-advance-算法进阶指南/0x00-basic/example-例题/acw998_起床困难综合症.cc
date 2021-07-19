// 位运算

#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;
char op[maxn][3];
int t[maxn];
int n, m;

int calc(int bit, int val) {
    for (int i = 0; i < n; ++i) {
        int x = t[i] >> bit & 1;
        if (op[i][0] == 'A') val &= x;
        else if (op[i][0] == 'X') val ^= x;
        else val |= x;
    }
    return val;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) scanf("%s%d", op + i, t + i);
    int ans = 0, val = 0;
    for (int i = 29; i >= 0; --i) {
        int res0 = calc(i, 0), res1 = calc(i, 1);
        // 居然粗心把 res0 和 res1 当作要移位的位数了
        if (res1 > res0 && val + (1 << i) <= m) val += 1 << i, ans += res1 << i;
        else ans += res0 << i;
    }
    cout << ans << endl;
}