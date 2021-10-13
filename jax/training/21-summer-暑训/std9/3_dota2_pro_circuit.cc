#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
pair<int, int> a[N];
int b[N], ans[N][2];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    for (int i = 0; i < n; ++i) {
        // auto [val, idx] = a[i];
        int val = a[i].first, idx = a[i].second;
        int best = val + b[0];
        // b[p] 是给当前对手的加分，rank 是初始排名，当前比自己小的对手不用考虑
        // b[p] 应尽量小
        int p = n - 1, rank = n - i;
        // 按分数从高到低遍历当前所有大于自己的对手
        for (int j = n - 1; j > i; --j) {
            // 对手的新的分小于等于自己就是说比自己大的对手少了一个
            // 如果该对手不能比自己小，那就分配给他一个比较大的新的分，保证后面的对手得分尽量小
            if (a[j].first + b[p] <= best) {
                --rank;
                --p;
            }
        }
        ans[idx][0] = rank;
    }

    for (int i = 0; i < n; ++i) {
        // auto [val, idx] = a[i];
        int val = a[i].first, idx = a[i].second;
        int worst = val + b[n - 1];
        int p = 0, rank = n - i;
        // 已经比自己大的对手不可能再比自己小
        // 所以只需从小到大遍历比自己小的对手，尽量给分少的对手分配多的分
        for (int j = 0; j < i; ++j) {
            // Note：没有相等，因为相等的话不会影响名次
            if (a[j].first + b[p] > worst) {
                ++rank;
                ++p;
            }
        }
        // 因为前面没有考虑相等的情况，所以这里要对大于等于自己的对手进行遍历
        for (int j = i + 1; j < n; ++j) {
            if (a[j].first + b[p] == worst) {
                --rank;
                ++p;
            } else {
                break;
            }
        }
        ans[idx][1] = rank;
    }
    
    for (int i = 0; i < n; ++i) {
        cout << ans[i][0] << ' ' << ans[i][1] << endl;
    }
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