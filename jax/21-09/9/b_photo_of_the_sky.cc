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

const int N = 2e5 + 10;
int a[N];

int main() {
    startTime = clock();
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
    }

    sort(a, a + 2 * n);

    ll ans = 0;

    if (n > 1) {
        ans = (ll)(a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);

        for (int i = 1; i <= n; ++i) {
            ans = min(ans, (ll)(a[2 * n - 1] - a[0]) * (a[i + n - 1] - a[i]));
        }
    }

    cout << ans << endl;
}
