#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ans;

bool dfs(int dep) {
    if (ans.back() == n) return true;
    if (dep == 0) return false;
    set<int> st;
    for (int i = 0; i < ans.size(); ++i) for (int j = 0; j < ans.size(); ++j) st.insert(ans[i] + ans[j]);

    for (auto it = st.rbegin(); it != st.rend(); ++it) {
        if ((1 << (dep - 1)) * *it < n) return false;
        ans.push_back(*it);
        if (dfs(dep - 1)) return true;
        ans.pop_back();
    }
    return false;
}

void solve() {
    ans.assign({1});

    for (int dep = 1;; ++dep) {
        if (dfs(dep)) break;
    }
    for (int num : ans) cout << num << ' ';
    cout << endl;
}

int main() {
    while (cin >> n && n != 0) {
        solve();
    }
}