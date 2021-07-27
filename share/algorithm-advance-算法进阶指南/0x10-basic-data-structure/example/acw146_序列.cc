#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using pi = pair<int, int>;

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

template<typename T>
void print(T &v) {
    for (auto val : v) cout << val << ' ';
    cout << el;
}
template<typename T>
istream &operator>>(istream &in, vector<T> &v) {
    for (auto &each : v) in >> each;
    return in;
}
template<typename T>
ostream &operator<<(ostream &out, vector<T> &v) {
    for (auto &each : v) out << each << ' ';
    return out;
}

void solve() {
    int m, n;
    cin >> m >> n;
    vector<vi> vs(3, vi(n));
    REP(i, 1, n) vs[0][i] = N;
    REP(i, 0, m) {
        int pre = i & 1, cur = pre ^ 1;
        // cout << "pre = " << pre << " cur = " << cur << el;
        cin >> vs[cur];
        Sort(vs[cur]);
        // cout << "cur -> " << vs[cur] << el;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        set<pair<int, int>> st;
        pq.push(MP(vs[cur][0] + vs[pre][0], MP(0, 0)));
        st.insert(MP(0, 0));
        REP(j, 0, n - 1) {
            vs[2][j] = pq.top().F;
            int x = pq.top().S.F, y = pq.top().S.S;
            pq.pop();
            auto a = MP(x, y + 1), b = MP(x + 1, y);
            if (!st.count(a)) {
                st.insert(a);
                pq.push(MP(vs[pre][a.F] + vs[cur][a.S], a));
            }
            if (!st.count(b)) {
                st.insert(b);
                pq.push(MP(vs[pre][b.F] + vs[cur][b.S], b));
            }
        }
        REP(i, 0, n - 1) {
            vs[cur][i] = vs[2][i];
        }
        vs[cur][n - 1] = pq.top().F;
        // cout << "pre: " << vs[pre] << el
        //      << "cur: " << vs[cur] << el;
    }
    cout << vs[m & 1] << el;
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
