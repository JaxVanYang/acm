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
const double eps = 1e-8;
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

double calc(vi &v, int lmt) {
    const int n = v.size();
    vector<double> sum(n + 1);

    double l = 0, r = 1e5 + 10;
    while (r - l > eps) {
        // cout << "l = " << l << " r = " << r << el;
        double mid = (l + r) / 2;
        REP(i, 0, n) sum[i + 1] = (double)v[i] - mid + sum[i];
        // cout << sum << el;
        double val = -1e18, min_val = 1e18;
        for (int i = lmt; i <= n; ++i) {
            min_val = min(min_val, sum[i - lmt]);
            val = max(val, sum[i] - min_val);
        }
        // cout << "val = " << val << el;
        if (val > 0) l = mid;
        else r = mid;
    }
    return l;
}

int main() {
    startTime = clock();
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vi a(n), b(m);
    cin >> a >> b;
    // cout << a << el << b << el;
    cout << setprecision(10) << calc(a, x) + calc(b, y) << el;
}
