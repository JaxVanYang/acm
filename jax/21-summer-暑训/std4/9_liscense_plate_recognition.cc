#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using pi = pair<int, int>;
template<typename T> using Heap = priority_queue<T, vector<T>, greater<T>>;

#define REP(i, l, r) for (int i = l; i < r; ++i)
#define F first
#define S second
#define PF push_fornt
#define PB push_back
#define MP make_pair
#define Sort(v) sort(v.begin(), v.end())
#define Unique(v) unique(v.begin(), v.end())
#define Lower(v, val) lower_bound(v.begin(), v.end(), val)
#define Upper(v, val) upper_bound(v.begin(), v.end(), val)
#define Reverse(v) reverse(v.begin(), v.end())

const char el = '\n';
const int N = 1e6 + 10;
clock_t startTime;
double getCurTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

template<typename T> istream &operator>>(istream &in, vector<T> &v) { for (auto &each : v) in >> each; return in; }
template<typename T> ostream &operator<<(ostream &out, vector<T> &v) { for (auto &each : v) out << each << ' '; return out; }
template<typename T, typename U> ostream &operator<<(ostream &out, pair<T, U> p) { return out << p.F << ' ' << p.S; }

int idx = 0, lmt;
vector<string> sv(30);
int l, r;
void dfs(int i, int j) {
    // cout << "i = " << i << " j = " << j << el;
    l = min(l, j), r = max(r, j);
    sv[i][j] = '.';
    for (int a = -1; a <= 1; ++a) {
        for (int b = -1; b <= 1; ++b) {
            if (a == b && a == 0) continue;
            int x = i + a, y = j + b;
            if (x < 0 || x >= 30 || y < 0 || y >= lmt) continue;
            if (sv[x][y] == '#') dfs(x, y);
        }
    }
}

void solve() {
    vector<pair<int, int>> ans(7);
    auto &s = sv[0];
    cin >> sv;
    lmt = s.size();
    int p = s.size() - 1;
    for (int i = 6; i >= 1; --i) {
        l = 300, r = -1;
        while (sv[15][p] != '#') --p;
        // cout << "p = " << p << el;
        dfs(15, p);
        // cout << "l = " << l << " r = " << r << el;
        ans[i].F = l + 1, ans[i].S = r + 1;
    }
    REP(i, 1, 30) {
        REP(j, 0, sv[i].size()) if (sv[i][j] == '#') sv[0][j] = '#';
    }
    ans[0].F = 300, ans[0].S = -1;
    REP(i, 0, s.size()) if (s[i] == '#') ans[0].F = min(ans[0].F, i), ans[0].S = max(ans[0].S, i);
    ans[0].F++, ans[0].S++;
    cout << "Case #" << idx << ':' << el;
    for (auto &p : ans) {
        cout << p << el;
    }

}

int main() {
    startTime = clock();
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ++idx;
        solve();
    }
}
