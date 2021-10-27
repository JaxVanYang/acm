#include <iostream>
#include <queue>
#include <stack>
using namespace std;

const int N = 1e6 + 10;
bool ban[10], vis[N];
int valid[10], bit[N], pre[N];

int main() {
    int k, t;
    scanf("%d%d", &k, &t);

    for (int i = 0; i < t; ++i) {
        int a;
        scanf("%d", &a);
        ban[a] = true;
    }

    int c = 10 - t;
    for (int i = 0, p = 0; i < 10; ++i) {
        if (!ban[i]) {
            valid[p++] = i;
        }
    }

    queue<int> q;
    for (int i = 0; i < c; ++i) {
        if (valid[i] == 0) continue;
        int rem = valid[i] % k;
        if (vis[rem]) continue;
        vis[rem] = true;
        bit[rem] = valid[i];
        q.push(rem);
    }

    while (q.size()) {
        int rem = q.front();
        // cout  << "rem = " << rem << " bit = " << bit[rem] << endl;
        q.pop();

        if (rem == 0) {
            stack<int> ans;
            ans.push(bit[rem]);
            int p = pre[rem];
            while (p) {
                ans.push(bit[p]);
                p = pre[p];
            }

            while (ans.size()) {
                printf("%d", ans.top());
                ans.pop();
            }
            puts("");
            return 0;
        }

        for (int i = 0; i < c; ++i) {
            int nex = (rem * 10 + valid[i]) % k;
            if (vis[nex]) continue;
            // cout << "nex = " << nex << endl;
            vis[nex] = true;
            pre[nex] = rem;
            bit[nex] = valid[i];
            q.push(nex);
        }
    }

    puts("-1");
}