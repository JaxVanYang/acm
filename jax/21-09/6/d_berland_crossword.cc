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

inline void yes() {
    cout << "YES" << endl;
}

inline void no() {
    cout << "NO" << endl;
}

void solve() {
    int n, cnt[4];
    cin >> n;

    for (int i = 0; i < 4; ++i) cin >> cnt[i];

    for (int mask = 0; mask < 16; ++mask) {
        bitset<4> bits(mask);
        // cout << bits << endl;

        int tmp[4];

        bool flag = true;
        for (int i = 0; i < 4; ++i) {
            int sum = bits[i] + bits[(i + 1) % 4];

            tmp[i] = cnt[i] - sum;

            // cout << "tmp[" << i << "] = " << tmp[i] << endl;

            // cout << "n - 2 = " << n - 2 << endl;

            if (tmp[i] < 0 || tmp[i] > n - 2) {
                flag = false;
                break;
            }
        }

        if (flag) {

            // cout << "mask = " << mask << endl;
            yes();
            return;
        }
    }

    no();
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
