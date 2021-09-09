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

const int N = 2e5 + 10;
pi ps[N];

int main() {
    startTime = clock();
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    REP(i, 0, n) {
        cin >> ps[i].F;
    }

    REP(i, 0, n) {
        cin >> ps[i].S;
    }

    sort(ps, ps + n);

    priority_queue<int> pq;

    ll ans = 0, cur = 0, tmp = 0, sum = 0;

    while (pq.size() || cur < n) {
        if (pq.empty()) {
            tmp = ps[cur].F;
            sum = ps[cur].S;

            pq.push(sum);

            ++cur;
        }

        if (cur < n && ps[cur].F == tmp) {
            sum += ps[cur].S;
            pq.push(ps[cur].S);

            ++cur;
        } else {
            if (pq.size() > 1) {
                // cout << "sum = " << sum << endl;
                sum -= pq.top();

                ans += sum;
                ++tmp;
            } else {
                sum = 0;
            }

            // cout << "top = " << pq.top() << endl;
            pq.pop();
        }
    }

    cout << ans << endl;
}
