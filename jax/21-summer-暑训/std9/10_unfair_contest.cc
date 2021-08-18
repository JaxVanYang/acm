#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const char el = '\n';
const int N = 1e5 + 10;
int a[N], b[N];

void solve() {
    int n, s, t, h;
    cin >> n >> s >> t >> h;
    for (int i = 1; i < n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) cin >> b[i];
    // 添加冗余，处理 s = 0 或 t = 0 的情况
    a[0] = b[0] = 1;
    a[n] = b[n] = h;
    sort(a + 1, a + n);
    sort(b + 1, b + n);
    // 先计算删除 s 个最大值和 t 各最小值的得分
    ll sum_a = accumulate(a + t + 1, a + n - s, 0ll);
    ll sum_b = accumulate(b + t + 1, b + n - s, 0ll);
    // 因为还有一个分每算，所以可以加上两边的边界值得到最终得分的范围
    ll min_a = sum_a + a[t], max_a = sum_a + a[n - s];
    ll min_b = sum_b + b[t], max_b = sum_b + b[n - s];

    if (max_a <= min_b) {
        cout << "IMPOSSIBLE" << el;
        return;
    }

    ll ans;
    if (min_a > max_b) {
        ans = 1 - h;
    } else if (max_a > max_b) { // 此时 min_a <= max_b
        // 此时 val_a 不能取 min_a，也就是 a_n 不能取 1 了，所以 a_n 只能尽量取小
        // 假设 b_n 也没超过 b[n - s]，也就是 val_b <= max_b
        // val_a 可以取 val_b + 1，从而 a_n = val_b + 1 - sum_a
        // 所以 ans = a_n - b_n = val_b + 1 - sum_a - b_n = 1 - sum_a + (val_b - b_n) = 1 - sum_a + sum_b
        // 观察到如果 b_n <= b[n - s]，ans 是个常量，如果让 b_n 大于 b[n - s]，
        // 那么 val_a = max_b + 1 -> a_n = max_b + 1 - sum_a
        // ans = max_b + 1 - sum_a - b_n = 1 - sum_a + (sum_b + b[n -s] - b_n)
        // 所以应该取 b_n 为 h，a_n 尽量小，使得 val_n 刚好大于 max_b
        ans = max_b + 1 - sum_a - h;

        if (min_a > min_b) {
            // a_n 可以取 1
            // 注意特判，这种情况的答案可能比上面的 b_n 取 h 还小
            ll val_b = min_a - 1;
            ll b_n = val_b - sum_b;
            ans = min(ans, 1 - b_n);
        }
    } else if (min_a > min_b) {
        // 这里只有着一种特殊情况，所以无需特判
        ll b_n = min_a - 1 - sum_b;
        ans = 1 - b_n;
    } else {
        // 此时 min_a <= max_a <= max_b，所以 b_n 不能取 h
        // min_a <= min_b，所以 a_n 不能取 1
        // 这就是最一般的情况
        // val_a = sum_a + a_n, val_b = val_a - 1 = sum_b + b_n
        // a_n = val_a - sum_a, b_n = val_a - 1 - sum_b
        // ans = val_a - sum_a - val_a + 1 + sum_b = 1 - sum_a + sum_b
        ans = 1 - sum_a + sum_b;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }    
}