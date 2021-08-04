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

const int N = 1e4 + 10;
int n, m;
int area[N], vol[N];
int ans = INT32_MAX;

void dfs(int dep, int curA, int leftV, int preR, int preH) {
    if (dep == 0) {
        if (leftV == 0)
            ans = min(ans, curA);
        return;
    }
    if (leftV < vol[dep]) return;
    if (curA + area[dep] >= ans) return;
    for (int r = min((int)sqrt(leftV), preR - 1); r >= max(dep, 2 * leftV / (ans - curA)); --r) {
        if (2 * leftV / r + curA >= ans) break;
        for (int h = min(leftV / r / r, preH - 1); h >= dep; --h) {
            int nextA = curA + 2 * r * h;
            if (dep == m) nextA += r * r;
            dfs(dep - 1, nextA, leftV - r * r * h, r, h);
        }
    }
}

int main() {
    startTime = clock();
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    REP(i, 1, m + 1) {
        area[i] = 2 * i * i + area[i - 1];
        vol[i] = i * i * i + vol[i - 1];
    }
    area[m] += m * m;

    dfs(m, 0, n, INT32_MAX, INT32_MAX);
    if (ans == INT32_MAX) ans = 0;
    cout << ans << el;
}
