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
const int N = 1e6 + 10;
clock_t startTime;
double getCurTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

template<typename T> istream &operator>>(istream &in, vector<T> &v) { for (auto &each : v) in >> each; return in; }
template<typename T> ostream &operator<<(ostream &out, vector<T> &v) { for (auto &each : v) out << each << ' '; return out; }
template<typename T, typename U> ostream &operator<<(ostream &out, pair<T, U> p) { return out << p.F << ' ' << p.S; }

void solve() {
    string s;
    cin >> s;
    int l = 0, n = s.size();
    map<string, int> mp;
    while (l < n) {
        int r = l;
        while (r < n && s[r] != '+') ++r;
        int mid = l;
        while (mid < r && isdigit(s[mid])) ++mid;
        // cout << s.substr(l, mid - l) << ' ' << s.substr(mid, r - mid) << el;
        mp[s.substr(mid, r - mid)] += stoi(s.substr(l, mid - l));
        l = r + 1;  // Note: offset from '+'
    }
    for (auto &it : mp) {
        if (it.S != 0) {
            cout << "NO" << el;
            return;
        }
    }
    cout << "YES" << el;
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
