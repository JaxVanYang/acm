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

const int N = 100 + 10;
int p[N];

int main() {
    startTime = clock();
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    int c[2] = {0, 0};
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        if (p[i] != 0) {
            c[p[i] & 1]++;
        }
    }

    c[0] = n / 2 - c[0];
    c[1] = (n + 1) / 2 - c[1];

    if (c[0] + c[1] == n) {
        cout << 1 << endl;
        return 0;
    }

    vector<pi> ps;
    vector<pi> boarder;

    int l = 1;
    while (l <= n && p[l] == 0) {
        ++l;
    }

    if (1 < l && l <= n) {
        boarder.push_back({l - 1, p[l] & 1});
    }

    int ans = 0;
    while (l < n) {
        int r = l + 1;
        while (r <= n && p[r] == 0) {
            ++r;
        }

        if (r > n) {
            break;
        }

        if (r - l > 1) {
            int val = 2;

            if (p[l] % 2 == p[r] % 2) {
                if (p[l] % 2 == 0) {
                    val = 0;
                } else {
                    val = 1;
                }
            }

            // cout << "p[" << l << "] = " << p[l] << " p[" << r << "] = " << p[r] << " val = " << val << endl;

            ps.push_back({r - l - 1, val});
        } else if (p[l] % 2 != p[r] % 2) {
            ++ans;
        }

        l = r;
    }

    if (l < n) {
        boarder.push_back({n - l, p[l] & 1});
    }
    
    Sort(boarder);
    Sort(ps);

    for (auto &[len, val] : ps) {
        if (val == 2) {
            continue;
        }

        if (len <= c[val]) {
            c[val] -= len;
        } else {
            val = 3;
        }
    }


    for (auto &[len, val] : boarder) {
        if (len <= c[val]) {
            c[val] -= len;
        } else {
            ++ans;
        }
    }

    for (auto &[len, val] : ps) {
        if (val == 2) {
            ++ans;
        } else if (val == 3) {
            ans += 2;
        }
    }

    cout << ans << endl;
}
