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
const int N = 1e5 + 10;
clock_t startTime;
double getCurTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

template<typename T> istream &operator>>(istream &in, vector<T> &v) { for (auto &each : v) in >> each; return in; }
template<typename T> ostream &operator<<(ostream &out, vector<T> &v) { for (auto &each : v) out << each << ' '; return out; }
template<typename T, typename U> ostream &operator<<(ostream &out, pair<T, U> p) { return out << p.F << ' ' << p.S; }

ll pan[N], a[N];
pair<int, int> pv[N];
vector<ll> ans[N];
int n, m;

int main() {
    startTime = clock();
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    REP(i, 1, n + 1) {
        cin >> pv[i].F;
        pv[i].S = i;
    }
    sort(pv + 1, pv + n + 1, greater<pair<int, int>>());
    REP(i, 1, n + 1) {
        a[i] = pv[i].F + a[i - 1];
    }
    
    int pl = 1, sl = 1;
    while (true) {
        int leftP = m - pl + 1;
        ll sum = a[n] - a[sl - 1];
        ll avg = sum / leftP;
        int extra = sum % leftP;
        int maxCnt = 0;
        for (int i = sl; i <= n; ++i) if (pv[i].F == pv[sl].F) ++maxCnt;
        // cout << "sum = " << sum << " avg = " << avg << " extra = " << extra << " maxCnt = " << maxCnt << el;
        if (pv[sl].F <= avg || pv[sl].F == avg + 1 && maxCnt <= extra) {
            for (int i = 0; i < extra; ++i) {
                int sId = sl + i;
                if (pv[sId].F + pan[pl] > avg + 1) {
                    pan[pl + 1] = pv[sId].F - (avg + 1 - pan[pl]);
                    ans[pv[sId].S].assign({2, pl + 1, 0, pan[pl + 1], pl, pan[pl], avg + 1});
                    ++pl;
                } else {
                    ans[pv[sId].S].assign({1, pl, pan[pl], pan[pl] + pv[sId].F});
                    pan[pl] += pv[sId].F;
                    if (pan[pl] == avg + 1) ++pl;
                }
            }
            sl += extra;
            for (int sId = sl; sId <= n; ++sId) {
                if (pv[sId].F + pan[pl] > avg) {
                    pan[pl + 1] = pv[sId].F - (avg - pan[pl]);
                    ans[pv[sId].S].assign({2, pl + 1, 0, pan[pl + 1], pl, pan[pl], avg});
                    ++pl;
                } else {
                    ans[pv[sId].S].assign({1, pl, pan[pl], pan[pl] + pv[sId].F});
                    pan[pl] += pv[sId].F;
                    if (pan[pl] == avg) ++pl;
                }
            }
            break;
        }
        int cab = 2 * avg;
        if (extra == 1) ++cab;
        else if (extra > 1) cab += 2;
        if (pl < m && pv[sl].F <= cab) {
            if (extra == 0) {
                pan[pl + 1] = pv[sl].F - avg;
                
            }
        } else {
            ans[pv[sl].S].assign({1, pl, 0, pv[sl].F});
            ++pl, ++sl;
        }
    }
    REP(i, 1, n + 1) {
        cout << ans[i][0];
        REP(j, 1, ans[i].size()) cout << ' ' << ans[i][j];
        cout << el;
    }
}
