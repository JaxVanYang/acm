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
clock_t startTime;
double getCurTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

template<typename T> istream &operator>>(istream &in, vector<T> &v) { for (auto &each : v) in >> each; return in; }
template<typename T> ostream &operator<<(ostream &out, vector<T> &v) { for (auto &each : v) out << each << ' '; return out; }
template<typename T, typename U> ostream &operator<<(ostream &out, pair<T, U> p) { return out << p.F << ' ' << p.S; }

const int N = 1e6 + 10;

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    cin >> a;
    vi b(a);
    Sort(b);
    map<int, int> nex;
    REP(i, 0, n - 1) nex[b[i]] = b[i + 1];
    nex[b[n - 1]] = INT32_MIN;
    int l = 0, cnt = 0;
    while (l < n) {
        int r = l;
        while (r + 1 < n && nex[a[r]] == a[r + 1]) {
            ++r;
        }
        ++cnt;
        l = r + 1;
    }
    // cout << "cnt = " << cnt << endl;
    if (k >= cnt) cout << "Yes" << endl;
    else cout << "No" << endl;
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
