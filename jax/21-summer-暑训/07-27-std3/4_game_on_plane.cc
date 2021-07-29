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

inline pair<int, int> calc(int x1, int y1, int x2, int y2) {
    int up = y1 - y2, down = x1 - x2;
    if (down < 0) up = -up, down = -down;
    int g = __gcd(up, down);
    return MP(up / g, down / g);
}

void solve() {
    int n;
    cin >> n;
    map<pair<int, int>, int> mp;
    int ver_cnt = 0;
    REP(i, 0, n) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2) ver_cnt++;
        else mp[calc(x1, y1, x2, y2)]++;
    }
    vi v;
    for (auto it : mp) {
        // printf("(%d, %d):%d ", it.F.F, it.F.S, it.S);
        v.PB(it.S);
    }
    // cout << el;
    if (ver_cnt) v.PB(ver_cnt);
    Sort(v);
    // cout << "v.size = " << v.size() << el;
    // cout << v << el;

    int ans = 1, m = v.size(), p = m - 1;
    REP(i, 1, n + 1) {
        if (p < 0 || v[p] == 0) {
            p = m - 1;
            ++ans;
        }
        v[p--]--;
        cout << i - ans << el;
    }
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
