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

const int N = 1e5 + 10;
int sumA[N], sumB[N];

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    for (int i = 0; i < n; ++i) {
        sumA[i + 1] = sumA[i];
        sumB[i + 1] = sumB[i];

        if (s[i] == 'U') {
            sumA[i + 1]++;
        } else if (s[i] == 'D') {
            sumA[i + 1]--;
        } else if (s[i] == 'L') {
            sumB[i + 1]--;
        } else {
            sumB[i + 1]++;
        }
    }

    map<pair<int, int>, int> mp;

    for (int i = 0; i <= n; ++i) {
        auto p = MP(sumA[i], sumB[i]);

        mp[p]++;
    }

    ll ans = 0;

    for (auto &p : mp) {
        // cout << "cnt = " << p.S << endl;
        ans += (ll)p.S * (p.S - 1) / 2;
    }

    cout << ans << endl;
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
