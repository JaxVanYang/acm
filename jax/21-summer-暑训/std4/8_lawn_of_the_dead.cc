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
template<typename T, typename U> istream &operator>>(istream &in, pair<T, U> &p) { return in >> p.F >> p.S; }
template<typename T> ostream &operator<<(ostream &out, vector<T> &v) { for (auto &each : v) out << each << ' '; return out; }
template<typename T, typename U> ostream &operator<<(ostream &out, pair<T, U> p) { return out << p.F << ' ' << p.S; }

int n, m, k;

void solve() {
    cin >> n >> m >> k;
    vector<pair<int, int>> mines(k);
    cin >> mines;
    Sort(mines);
    vector<vi> rows(n + 1, {0});
    for (auto &it : mines) {
        rows[it.F].PB(it.S);
    }
    REP(i, 1, n + 1) {
        rows[i].PB(m + 1);
        // cout << rows[i] << el;
    }
    vector<vector<pair<int, int>>> ranges(n + 1);
    ranges[0].PB(MP(1, 1));
    REP(i, 1, n + 1) {
        REP(j, 1, rows[i].size()) {
            if (rows[i][j] - rows[i][j - 1] > 1) ranges[i].PB(MP(rows[i][j - 1] + 1, rows[i][j] - 1));
        }
    }
    
    ll ans = 0;
    REP(i, 1, n + 1) {
        // cout << "pre: " << ranges[i - 1] << el;
        // cout << "cur: " << ranges[i] << el;
        for (auto &range : ranges[i]) {
            int l = 0, r = ranges[i - 1].size();
            while (l < r) {
                int mid = l + r >> 1;
                if (ranges[i - 1][mid].S >= range.F) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (l != ranges[i - 1].size() && ranges[i - 1][l].F <= range.S) {
                range.F = max(range.F, ranges[i - 1][l].F);
            } else {
                range.F = range.S + 1;
            }
        }
        auto cpy = ranges[i];
        ranges[i].clear();
        for (auto &range : cpy) {
            if (range.F != range.S + 1) {
                ranges[i].PB(range);
                ans += range.S - range.F + 1;
            }
        }
        // cout << "ans = " << ans << el;
    }
    cout << ans << el;
}

int main() {
    startTime = clock();
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
