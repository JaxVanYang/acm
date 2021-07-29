#include <iostream>
#include <stack>

using ll = long long;

const int N = 1e5 + 10;
int n;

struct Pair {
    int x, y;
};

void solve() {
    auto stk = std::stack<Pair>();
    stk.push(Pair{0, 0});   // Trick: 压入冗余元素，避免判空处理
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        int h, begin = i;
        scanf("%d", &h);
        while (h < stk.top().x) {
            auto &p = stk.top();
            begin = p.y;    // Note: 当前高度小于已存在的高度时可以更新当前高度的开始位置
            stk.pop();
            ans = std::max(ans, (ll)p.x * (i - p.y));
        }
        if (h > stk.top().x) {
            stk.push(Pair{h, begin});
        }
    }
    while (stk.size()) {
        auto &p = stk.top();
        stk.pop();
        ans = std::max(ans, (ll)p.x * (n + 1 - p.y));
    }

    printf("%lld\n", ans);
}

int main() {
    while (~scanf("%d", &n) && n) {
        solve();
    }
}