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
const int N = 9;
clock_t startTime;
double getCurTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

template<typename T> istream &operator>>(istream &in, vector<T> &v) { for (auto &each : v) in >> each; return in; }
template<typename T> ostream &operator<<(ostream &out, vector<T> &v) { for (auto &each : v) out << each << ' '; return out; }
template<typename T, typename U> ostream &operator<<(ostream &out, pair<T, U> p) { return out << p.F << ' ' << p.S; }

string s;
int ones[1 << N], h[37];
int row[N], col[N], cell[3][3];

inline int lowbit(int n) { return n & -n; }
inline int count(int n) {
    int ret = 0;
    while (n) {
        ++ret;
        n -= lowbit(n);
    }
    return ret;
}

void init() {
    startTime = clock();
    ios::sync_with_stdio(false);
    cin.tie(0);
    REP(i, 0, 36) h[(1ll << i) % 37] = i;
    REP(i, 0, 1 << N) ones[i] = count(i);
}

void reset() {
    REP(i, 0, N) row[i] = col[i] = (1 << N) - 1;
    REP(i, 0, 3) REP(j, 0, 3) cell[i][j] = (1 << N) - 1;
}

inline int get(int i, int j) {
    return row[i] & col[j] & cell[i / 3][j / 3];
}

bool dfs(int cnt) {
    if (!cnt) return true;
    int r, c, val = INT32_MAX;
    REP(i, 0, 9) REP(j, 0, 9) if (s[i * 9 + j] == '.') {
        int t = ones[get(i, j)];
        if (t < val) {
            val = t;
            r = i, c = j;
        }
    }
    for (int mask = get(r, c); mask;) {
        int low = lowbit(mask), bit = h[low % 37];
        s[r * 9 + c] = '1' + bit;
        row[r] -= low;
        col[c] -= low;
        cell[r / 3][c / 3] -= low;
        if (dfs(cnt - 1)) return true;
        s[r * 9 + c] = '.';
        row[r] += low;
        col[c] += low;
        cell[r / 3][c / 3] += low;
        mask -= low;
    }
    return false;
}

int main() {
    init();

    while (cin >> s && s != "end") {
        reset();

        int cnt = 0;
        REP(i, 0, 9) REP(j, 0, 9) if (s[i * 9 + j] == '.') {
            ++cnt;
        } else {
            int mask = 1 << (s[i * 9 + j] - '1');
            row[i] -= mask;
            col[j] -= mask;
            cell[i / 3][j / 3] -= mask;
        }

        if (dfs(cnt)) cout << s << el;
    }
}
