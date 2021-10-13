#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<int> row_max(n, 0), col_min(m, INT32_MAX);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            row_max[i] = max(row_max[i], grid[i][j]);
            col_min[j] = min(col_min[j], grid[i][j]);
        }
    }

    int tmp = row_max[0];
    int ans = grid[0][0];
    // 最多只能进行一次操作可以特判答案为第一行的最大值
    if (k == 1) {
        ans = tmp;
    } else if (k % 2 == 0) {
        // 当 A 走了一步后，若 B 只有一步可走，那么 B 肯定会走到该列上的最小值，为了让这个最小值最大，A 就只能走到最小值最大的列上
        // 如果 B 有多步可走，假设多步后可以达到更小的值，那么 A 肯定会在 B 走完当前步后停止，所以 B 每次只能选择局部最优
        // 所以上述的情况可以推广到所有步数为偶数的情形。
        ans = max(ans, *max_element(col_min.begin(), col_min.end()));
    } else {
        // 如果 A 走完当前步后还有两步（A，B 各一步），B 可以选择停下，对应 tmp；
        // 或者走到最大值最小的列上（因为 A 还会选择走到该行的最大值上，所以不能选局部最优），对应 min_row。
        // 所以如果给 B 做选择，他一定会选 tmp 和 min_row 中较小的一个。
        // 而 A 在走当前步的时候就会预料到这种情况，所以他也可能不走了，对应初始值；走了就会落入 B 的选择，对应 min(tmp, min_row)。
        // 假设还有两步可走（B，A 各一步），如果 B 选择停下，此时和没有两步可走是相同的；
        // 如果 B 选择走的话，又回到了上面给 B 做选择的情况，所以这也可以扩展到所有 k 为大于 1 的奇数的情况。
        int min_row = *min_element(row_max.begin(), row_max.end());
        ans = max(ans, min(tmp, min_row));
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