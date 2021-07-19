#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;
int n, m;
pair<string, int> ops[maxn];

int calc(int bit, int val) {    // 计算第 bit 位的值，最终的结果在第 0 位
    for (int i = 0; i < n; ++i) {
        int x = ops[i].second >> bit & 1;
        if (ops[i].first == "AND") {
            val &= x;
        } else if (ops[i].first == "OR") {
            val |= x;
        } else {
            val ^= x;
        }
    }
    return val;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        char op[4];
        int val;
        scanf("%s%d", op, &val);
        ops[i] = make_pair(op, val);
    }
    int ans = 0;
    int atk = 0;    // attack
    for (int i = 30; i >= 0; i--) {
        int res0 = calc(i, 0);
        int res1 = calc(i, 1);
        if (res0 || res1)
            // cout << "i = " << i << " res0 = " << res0 << " res1 = " << res1 << endl;
        if (atk + (1 << i) <= m && res0 < res1) {
            ans += res1 << i;
            atk += 1 << i;
        } else {
            ans += res0 << i;   // 注意不要将 i 写成 1！
        }
        // cout << "i = " << i << " ans = " << ans << endl;
    }
    cout << ans << endl;
}