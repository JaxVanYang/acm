#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

#define REP(i, l, r) for (int i = l; i < r; ++i)
#define F first
#define S second
#define PF push_fornt
#define PB push_back
#define MP make_pair

const char el = '\n';
const int N = 1e6 + 10;

void solve() {
    int n;
    cin >> n;
    int a = n / 3, b = a;
    if (n % 3 == 1) {
        ++a;
    } else if (n % 3 == 2) {
        ++b;
    }
    cout << a << ' ' << b << el;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
