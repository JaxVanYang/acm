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
int n;

bool dfs(ll cur, int dep, string &s) {
    if (!dep) return false;

    // cout << "cur = " << cur << endl;
    // cout << "dep = " << dep << endl;

    if (cur == -n) {
        cur = n;

        for (auto &it : s) {
            it = (it == '0' ? '1' : '0');
        }
    }

    if (cur == n) {
        cout << s.size() << endl;

        cout << s << endl;

        return true;
    }

    ll k = s.size() + 1;
    // cout << "k = " << k << endl;
    k *= k;

    ll nex = cur + k;

    s.push_back('1');
    if (dfs(nex, dep - 1, s)) return true;
    s.pop_back();

    nex = cur - k;
    s.push_back('0');
    if (dfs(nex, dep - 1, s)) return true;
    s.pop_back();

    return false;
}

string ans[4] = {
    "",
    "1",
    "0001",
    "01"
};

void solve() {
    cin >> n;

    // string s;
    // for (int dep = 1; ; ++dep) {
    //     s.clear();

    //     // cout << "dep = " << dep << endl;

    //     if (dfs(0, dep, s)) break;
    // }

    string s = ans[n % 4];
    for (int i = 0; i < n / 4; ++i) {
        s.append("1001");
    }

    cout << s.size() << el;
    cout << s << el;
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
