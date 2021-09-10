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

const int N = 1e3 + 10;
int a[N], b[N], c[N];

int main() {
    startTime = clock();
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin.exceptions(cin.failbit);

    int n, k1, k2;
    cin >> n >> k1 >> k2;

    REP(i, 0, n) {
        cin >> a[i];
    }

    REP(i, 0, n) {
        cin >> b[i];
    }

    REP(i, 0, n) {
        c[i] = abs(a[i] - b[i]);
    }

    sort(c, c + n, greater<int>());

    int k = k1 + k2;
    priority_queue<int> pq;

    REP(i, 0, n) {
        if (c[i] > 0)
            pq.push(c[i]);
    }

    while (k > 0 && pq.size()) {
        int val = pq.top();
        pq.pop();
        
        --k;
        if (val > 1) {
            pq.push(val - 1);
        }
    }

    ll ans = 0;

    // cout << "k = " << k << endl;
    // cout << "size = " << pq.size() << endl;
    if (k > 0) {
        if (k & 1) {
            ans = 1;
        }
    } else {
        while (pq.size()) {
            int val = pq.top();
            pq.pop();

            ans += (ll)val * val;
        }
    }

    cout << ans << endl;
}
