#include <bits/stdc++.h>
using namespace std;

int n;

void change(vector<int> &v, int cur, int width, int nex) {
    vector<int> cpy(v.begin() + cur, v.begin() + cur + width);
    const int len = nex - cur;
    for (int i = 0; i < len; ++i) {
        v[cur + i] = v[cur + width + i];
    }
    for (int i = 0; i < width; ++i) {
        v[nex + i] = cpy[i];
    }
}

int f(vector<int> &v) {
    int ret = 0;
    for (int i = 1; i < n; ++i) {
        if (v[i - 1] + 1 != v[i]) ++ret;
    }
    return ret;
}

bool dfs(int dep, vector<int> &v) {
    if (dep < 0) return false;
    int pred = (f(v) + 2) / 3;
    if (pred == 0) return true;
    if (pred > dep) return false;

    const vector<int> cpy = v;
    for (int cur = 0; cur < n; ++cur) {
        for (int width = 1; cur + width <= n; ++width) {
            for (int nex = cur + 1; nex + width <= n; ++nex) {
                change(v, cur, width, nex);
                if (dfs(dep - 1, v)) return true;
                v = cpy;
            }
        }
    }

    return false;
}

void solve() {
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    for (int dep = 0; dep < 5; ++dep) {
        if (dfs(dep, v)) {
            cout << dep << endl;
            return;
        }
    }
    cout << "5 or more" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}