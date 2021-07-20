#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

const int N = 2e3 + 10;
int a[N][N], b[N][N];

struct Node {
    int h, s;
};

void solve() {
    int n, m;
    scanf("%d%d", &n, &m);
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", a[i] + j);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] >= a[i - 1][j]) b[i][j] = b[i - 1][j] + 1;
            else b[i][j] = 1;
        }
        stack<Node> stk;
        // stk.push(Node{0, 0});
        for (int j = 1; j <= m; ++j) {
            if (stk.empty() || b[i][j] > stk.top().h) {
                stk.push(Node{b[i][j], j});
            } else if (b[i][j] < stk.top().h) {
                int pre;
                while (stk.size() && b[i][j] < stk.top().h) {
                    int h = stk.top().h, s = pre = stk.top().s;
                    stk.pop();
                    ans = max(ans, (j - s) * h);
                }
                if (stk.empty() || b[i][j] > stk.top().h) {
                    stk.push(Node{b[i][j], pre});
                }
            }
        }

        while (stk.size()) {
            int h = stk.top().h, s = stk.top().s;
            stk.pop();
            ans = max(ans, (m - s + 1) * h);
        }
    }
    printf("%d\n", ans);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}