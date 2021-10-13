#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int id[N];

int find(int p) {
    if (id[p] != p) {
        id[p] = find(id[p]);
    }
    return id[p];
}

void un(int u, int v) {
    id[find(u)] = find(v);
}

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        id[i] = i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin.exceptions(cin.failbit);

    int n, m;
    cin >> n >> m;

    init(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        un(u, v);
    }

    map<int, int> lmtL, lmtR;

    for (int i = 1; i <= n; ++i) {
        int id = find(i);
        // cout << id << ' ';
        lmtR[id] = i;
    }
    // cout << endl;
    for (int i = n; i >= 1; --i) {
        int id = find(i);
        lmtL[id] = i;
        // cout << id << ' ';
    }
    // cout << endl;

    int ans = 0;

    vector<pair<int, int>> ps;
    for (auto [id, l] : lmtL) {
        ps.push_back({l, lmtR[id]});
    }

    sort(ps.begin(), ps.end());

    int begin = -1, end = -1;
    for (auto [l, r] : ps) {
        begin = max(begin, l);
        end = max(end, r);

        // cout << "l = " << l << " r = " << r << endl;
        // cout << "begin = " << begin << " end = " << end << endl;

        for (int i = begin + 1; i <= end; ++i) {
            if (find(i - 1) != find(i)) {
                ++ans;
                un(i - 1, i);
            }
        }
        begin = end;
    }


    cout << ans << endl;
}