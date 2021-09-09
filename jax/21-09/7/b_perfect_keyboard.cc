#include <bits/stdc++.h>
using namespace std;

const int N = 30;

set<int> edges[N];
bool st[N];

inline void no() {
    cout << "NO" << endl;
}

void solve() {
    for (int i = 0; i < 26; ++i) edges[i].clear();

    string s;
    cin >> s;

    if (s.size() <= 1) {
        cout << "YES" << endl
             << "qwertyuiopasdfghjklzxcvbnm" << endl;
        return;
    }

    for (int i = 1; i < s.size(); ++i) {
        int u = s[i - 1] - 'a', v = s[i] - 'a';
        
        edges[u].insert(v);
        edges[v].insert(u);

        if (edges[u].size() > 2 || edges[v].size() > 2) {
            no();
            return;
        }
    }

    int c = 0;
    for (int i = 0; i < 26; ++i) {
        if (edges[i].size()) {
            ++c;
        }
    }

    fill(st, st + 26, false);

    int start = -1;

    for (int i = 0; i < 26; ++i) {
        if (edges[i].size() == 1) {
            start = i;
            break;
        }
    }

    // cout << "start = " << start << endl;

    if (start == -1) {
        no();
        return;
    }

    string ans;
    ans.push_back(start + 'a');
    st[start] = true;

    int p = *edges[start].begin();
    ans.push_back(p + 'a');
    st[p] = true;

    // cout << "ans = " << ans << endl;

    while (edges[p].size() == 2) {
        for (int v : edges[p]) {
            if (st[v]) continue;

            p = v;
            ans.push_back(p + 'a');
            st[p] = true;
        }
    }

    // cout << "ans = " << ans << endl;

    if (ans.size() < c) {
        no();
    } else {
        for (int i = 0; i < 26; ++i) {
            if (st[i]) continue;

            ans.push_back(i + 'a');
        }

        cout << "YES" << endl;
        cout << ans << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}