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

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

void solve() {
    int r, b, k;
    scanf("%d%d%d", &r, &b, &k);

    int g = gcd(r, b);
    r /= g, b /= g;

    if (r > b) {
        swap(r, b);
    }

    if ((k - 1ll) * r >= b - 1) {
        puts("OBEY");
    } else {
        puts("REBEL");
    }
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);
    // cin.exceptions(cin.failbit);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
