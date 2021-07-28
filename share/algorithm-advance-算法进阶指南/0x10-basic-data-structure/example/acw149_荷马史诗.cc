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

int main() {
    startTime = clock();
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    Heap<pair<ll, int>> heap;
    REP(i, 0, n) {
        ll w;
        cin >> w;
        heap.push(MP(w, 0));
    }
    // cout << "heap.size = " << heap.size() << el;
    REP(i, 0, (n + k - 3) / (k - 1) * (k - 1) - n + 1) heap.push(MP(0, 0));
    // cout << "heap.size = " << heap.size() << el;
    ll ans = 0;
    while (heap.size() > 1) {
        ll sum = 0;
        int h = 0;
        REP(i, 0, k) {
            sum += heap.top().F;
            h = max(h, heap.top().S);
            heap.pop();
        }
        ans += sum;
        heap.push(MP(sum, h + 1));
    }
    cout << ans << el << heap.top().S << el;
}
