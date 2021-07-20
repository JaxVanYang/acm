#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;
// using ll = long long;
typedef long long ll;

const int N = 1e5 + 10;
int n;
int a[N];

struct Node {
    int h, s;
    Node(int h, int s) : h(h), s(s) {}
};

void solve() {
    for (int i = 0; i < n; ++i) scanf("%d", a + i);

    stack<Node> stk;
    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        if (stk.empty() || a[i] > stk.top().h) {
            stk.push(Node(a[i], i));
        } else if (a[i] < stk.top().h) {
            int pre;
            while (stk.size() && a[i] < stk.top().h) {
                int h = stk.top().h, s = pre = stk.top().s;
                stk.pop();
                ans = max(ans, (ll)(i - s) * h);
            }
            if (stk.empty() || a[i] > stk.top().h) {
                stk.push(Node(a[i], pre));
            }
        }
        // printf("i = %d ans = %lld\n", i, ans);
    }

    while (stk.size()) {
        int h = stk.top().h, s = stk.top().s;
        stk.pop();
        ans = max(ans, (ll)(n - s) * h);
    }
    printf("%lld\n", ans);
}

int main() {
    while (~scanf("%d", &n) && n) {
        solve();
    }
}