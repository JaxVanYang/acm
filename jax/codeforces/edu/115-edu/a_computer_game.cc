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
const int N = 100 + 10;
char grid[2][N];

void solve() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < 2; ++i) {
        scanf("%s", grid[i] + 1);
    }

    for (int i = 2; i < n; ++i) {
        if (grid[0][i] == '1' && grid[1][i] == '1') {
            puts("NO");
            return;
        }
    }
    puts("YES");
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
