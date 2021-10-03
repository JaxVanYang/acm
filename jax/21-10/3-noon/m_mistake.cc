#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
int c[N], ans[N];
vector<int> ids[N];

int main() {
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);

    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
    }

    for (int i = 0; i < n * k; ++i) {
        scanf("%d", c + i);
        ids[c[i]].push_back(i);
    }

    for (int i = 0; i < n * k; ++i) {
        // cout << "c[" << i << "] = " << c[i] << " ids[c[i]].size = " << ids[c[i]].size() << endl;
        if (ids[c[i]].empty()) {
            continue;
        }

        for (int j = 0; j < ids[c[i]].size(); ++j) {
            ans[ids[c[i]][j]] = j + 1;
        }

        ids[c[i]].clear();
    }

    for (int i = 0; i < n * k; ++i) {
        printf("%d ", ans[i]);
    }
}