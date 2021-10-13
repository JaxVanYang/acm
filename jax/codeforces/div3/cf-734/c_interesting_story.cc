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
    int n;
    cin >> n;
    vector<string> v(n);
    cin >> v;
    auto calc = [&](char c) {
        vi cnts(n);
        REP(i, 0, n) {
            int cnt = 0;
            for (auto &ch : v[i]) {
                if (ch == c) ++cnt;
            }
            cnts[i] = cnt * 2 - v[i].size();
        }
        sort(cnts.begin(), cnts.end(), greater<>());
        // cout << cnts << el;
        int i = 0;
        for (int cnt = 0; i < n && cnt + cnts[i] > 0; ++i) cnt += cnts[i];
        return i;
    };

    cout << max({calc('a'), calc('b'), calc('c'), calc('d'), calc('e')}) << el;
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
