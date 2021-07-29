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

struct Rank
{
    int r[5];
    inline bool operator<(Rank &rank) {
        int cnt = 0;
        REP(i, 0, 5) {
            cnt += r[i] < rank.r[i];
        }
        return cnt < 3;
    }
};



void solve() {
    int n;
    cin >> n;
    vector<Rank> data(n);
    REP(i, 0, n) {
        REP(j, 0, 5) cin >> data[i].r[j];
    }
    int candi = 0;
    REP(i, 1, n) {
        if (data[candi] < data[i]) candi = i;
    }
    REP(i, 0, n) {
        if (i == candi) continue;
        if (data[candi] < data[i]) {
            cout << -1 << el;
            return;
        }
    }
    cout << candi + 1 << el;
}

int main() {
    startTime = clock();
    ios::sync_with_stdio(false);
    cin.tie(0);
    srand(time(nullptr));

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
