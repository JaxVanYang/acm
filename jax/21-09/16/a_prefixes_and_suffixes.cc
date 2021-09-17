#include <bits/stdc++.h>
using namespace std;

bool is_pre(string &t, string &s) {
    for (int i = 0; i < t.size(); ++i) {
        if (t[i] != s[i]) {
            return false;
        }
    }
    return true;
}

bool is_suf(string &t, string &s) {
    for (int i = 0; i < t.size(); ++i) {
        if (t[t.size() - 1 - i] != s[s.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    int len = 2 * n - 2;
    vector<string> sv(len), candi;

    for (int i = 0; i < len; ++i) {
        cin >> sv[i];
        if (sv[i].size() == n - 1) {
            candi.push_back(sv[i]);
        }
    }

    string &a = candi[0], &b = candi[1];

    string s = a + b.back();

    vector<bool> vis(n, false);
    string ans;
    ans.resize(len);

    bool flag = true;
    for (int i = 0; i < len; ++i) {
        int size = sv[i].size();

        if (!vis[size] && is_pre(sv[i], s)) {
            vis[size] = true;
            ans[i] = 'P';
        } else if (is_suf(sv[i], s)) {
            ans[i] = 'S';
        } else {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << ans << endl;
        return 0;
    }

    s = b + a.back();
    vis.assign(n, false);

    for (int i = 0; i < len; ++i) {
        int size = sv[i].size();

        if (!vis[size] && is_pre(sv[i], s)) {
            vis[size] = true;
            ans[i] = 'P';
        } else if (is_suf(sv[i], s)) {
            ans[i] = 'S';
        }
    }
    cout << ans << endl;
}