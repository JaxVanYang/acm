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
const int N = 1e4 + 10;

template<typename T>
void print(T &v) {
    for (auto val : v) {
        cout << val << ' ';
    }
    cout << el;
}

int n, tot;
pi a[N], heap[N];

void up(int p) {
    while (p > 1 && heap[p] < heap[p / 2]) {
        swap(heap[p], heap[p / 2]);
        p /= 2;
    }
}

void push(pi val) {
    heap[++tot] = val;
    up(tot);
}

inline pi top() {
    return heap[1];
}

void down(int p) {
    int q = p * 2;
    while (q <= tot) {
        if (q < tot && heap[q + 1] < heap[q]) ++q;
        if (heap[q] < heap[p]) {
            swap(heap[q], heap[p]);
            p = q, q *= 2;
        } else {
            break;
        }
    }
}

void pop() {
    // swap(heap[1], heap[tot--]);
    if (tot < 1) return;
    heap[1] = heap[tot--];
    down(1);
}

void remove(int p) {
    heap[p] = heap[tot--];
    up(p), down(p);
}

void solve() {
    tot = 0;
    REP(i, 0, n) {
        cin >> a[i].F >> a[i].S;
    }
    sort(a, a + n, [](pi x, pi y){ return x.S < y.S; });

    REP(i, 0, n) {
        if (tot < a[i].S) {
            push(a[i]);
            // cout << "push " << a[i].F << ", " << a[i].S << el;
        } else if (a[i].F > top().F) {
            // cout << "pop " << top().F << ", " << top().S << el;
            // cout << "push " << a[i].F << ", " << a[i].S << el;
            pop();
            push(a[i]);
        }
    }

    int ans = 0;
    while (tot) {
        pi val = top();
        pop();
        // cout << val.F << ", " << val.S << el;
        ans += val.F;
    }
    cout << ans << el;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> n) {
        solve();
    }
}
