#include <iostream>
#include <queue>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
ll ans[N];

struct Node {
    int t, d, id;
};

int main() {
    int n, b;
    scanf("%d%d", &n, &b);

    ll ed = 0;
    queue<Node> q;

    for (int i = 0; i < n; ++i) {
        int t, d;
        scanf("%d%d", &t, &d);

        if (q.size() == b + 1) {
            ll lmt = max(ed, (ll)q.front().t) + q.front().d;

            if (lmt > t) {
                ans[i] = -1;
            } else {
                ans[q.front().id] = lmt;
                q.pop();
                ed = lmt;
                
                q.push({t, d, i});
            }
        } else {
            q.push({t, d, i});
        }
    }

    while (q.size()) {
        ed = max(ed, (ll)q.front().t) + q.front().d;
        ans[q.front().id] = ed;

        q.pop();
    }

    for (int i = 0; i < n; ++i) {
        printf("%lld ", ans[i]);
    }

    puts("");
}