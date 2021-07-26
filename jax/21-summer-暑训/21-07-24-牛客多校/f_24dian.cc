#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

#define REP(i, l, r) for (int i = l; i < r; ++i)
#define F first
#define S second
#define PF push_fornt
#define PB push_back
#define MP make_pair

const char el = '\n';
const int N = 1e6 + 10;
int n, m;

set<vi> ans;
bool st[15 * 15 * 15 * 15];
double eps = 1e-9;

template<typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
    for (auto &each : v) out << each << ' ';
    return out;
}

void check(vector<double> v, vi &chosen, bool hasFrac) {
    if (v.empty()) return;
    if (v.size() == 1) {
        int val = 0, base = 1;
        for (auto each : chosen) {
            val += each * base;
            base *= 14;
        }

        if (abs(v[0] - m) < eps) {
            if (!hasFrac) {
                st[val] = 1;
            } else if (!st[val]) {
                ans.insert(chosen);
            }
        }
        return;
    }
    // cout << v << el;
    REP(i, 0, v.size()) {
        REP(j, i + 1, v.size()) {
            vector<double> a;
            for (int k = 0; k < v.size(); ++k) {
                if (k == i || k == j) continue;
                a.PB(v[k]);
            }
            auto lam = [&](double val, bool flag) {
                a.PB(val);
                check(a, chosen, flag);
                a.pop_back();
            };
            
            lam(v[i] + v[j], hasFrac);
            lam(v[i] - v[j], hasFrac);
            if (v[i] != v[j]) lam(v[j] - v[i], hasFrac);
            lam(v[i] * v[j], hasFrac);
            if (v[i] != 0) {
                bool flag = hasFrac;
                if (!flag) {
                    flag = (int)v[j] % (int)v[i] != 0;
                }
                lam(v[j] / v[i], flag);
            }
            if (v[j] != 0) {
                bool flag = hasFrac;
                if (!flag) {
                    flag = (int)v[i] % (int)v[j] != 0;
                }
                // if (flag) cout << "frac = " << v[i] / v[j] << el;
                lam(v[i] / v[j], flag);
            }
        }
    }
}

void dfs(int left, vi &chosen) {
    if (left == 0) {
        vector<double> v(chosen.begin(), chosen.end());
        // cout << v << el;
        check(v, chosen, false);
        return;
    }
    int begin = chosen.size() ? chosen.back() : 1;
    REP(i, begin, 14) {
        chosen.PB(i);
        dfs(left - 1, chosen);
        chosen.pop_back();
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    if (m > 13 * 13 * 13 * 13) {
        cout << 0 << el;
        return 0;
    }
    vi chosen;
    dfs(n, chosen);
    vector<vi> ret;
    for (auto & v : ans) {
        // cout << each << el;
        int val = 0, base = 1;
        for (auto each : v) {
            val += each * base;
            base *= 14;
        }
        if (!st[val]) ret.PB(v);
    }
    cout << ret.size() << el;
    for (auto &v : ret) {
        cout << v << el;
    }
}
