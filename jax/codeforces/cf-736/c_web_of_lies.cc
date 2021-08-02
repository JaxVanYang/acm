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
const int N = 2e5 + 10;
clock_t startTime;
double getCurTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

template<typename T> istream &operator>>(istream &in, vector<T> &v) { for (auto &each : v) in >> each; return in; }
template<typename T> ostream &operator<<(ostream &out, vector<T> &v) { for (auto &each : v) out << each << ' '; return out; }
template<typename T, typename U> ostream &operator<<(ostream &out, pair<T, U> p) { return out << p.F << ' ' << p.S; }

int above[N];
int ans;
inline void add(int u, int v) {
    if (u < v) swap(u, v);
    if (above[v] == 0) --ans;
    ++above[v];
}

int main() {
    startTime = clock();
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    ans = n;
    REP(i, 0, m) {
        int u, v;
        cin >> u >> v;
        add(u, v);
    }
    int q;
    cin >> q;
    while (q--) {
        int sel;
        cin >> sel;
        if (sel == 1) {
            int u, v;
            cin >> u >> v;
            add(u, v);
        } else if (sel == 2) {
            int u, v;
            cin >> u >> v;
            if (u < v) swap(u, v);
            above[v]--;
            if (above[v] == 0) ++ans;
        } else {
            cout << ans << el;
        }
    }
}
