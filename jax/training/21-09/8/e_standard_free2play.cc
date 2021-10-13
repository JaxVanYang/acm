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
int p[N];

void solve() {
    int h, n;
    cin >> h >> n;

    REP(i, 0, n) {
        cin >> p[i];
    }

    int height = p[0], i = 1;
    int ans = 0;

    while (height > 0 && i < n) {
        if (height > p[i] + 1) {
            height = p[i] + 1;
        }

        // cout << "height = " << height << " p[" << i << "] = " << p[i] << endl;

        if (i + 1 < n && p[i + 1] == p[i] - 1) {
            i += 2;
        } else if (height > 2) {
            ++ans;
            if (i + 1 >= n) {
                break;
            } else if (p[i + 1] < p[i] - 1) {
                ++i;
            }
        }

        height -= 2;
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
