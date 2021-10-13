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
const int N = 1e3 + 10;
bool valid[N][5];
int sum[5];

void solve() {
    int n;
    scanf("%d", &n);
    fill(sum, sum + 5, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            scanf("%d", valid[i] + j);
            sum[j] += valid[i][j];
        }
    }

    for (int a = 0; a < 5; ++a) {
        for (int b = a + 1; b < 5; ++b) {
            if (sum[a] < n / 2 || sum[b] < n / 2) {
                continue;
            }

            bool flag = true;
            for (int i = 0; i < n; ++i) {
                if (!valid[i][a] && !valid[i][b]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                puts("YES");
                return;
            }
        }
    }

    puts("NO");
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
