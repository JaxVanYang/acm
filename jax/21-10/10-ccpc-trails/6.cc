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
const int N = 1e5 + 10;
const int mod = 998244353;
char s[N];
const char t[15] = "xnunhehheh";
int dp[N][10], cnt[N];

void reset(int n) {
    for (int i = 0; i <= n + 10; ++i) {
        cnt[i] = 0;
        
        for (int j = 1; j <= 9; ++j) {
            dp[i][j] = 0;
        }
    }
}

ll quick(ll x, ll y) {
    if (y < 0) {
        return 0;
    }

    ll ret = 1;

    while (y) {
        if (y & 1) {
            ret = ret * x % mod;
        }

        y >>= 1;
        x = x * x % mod;
    }

    return ret;
}

void solve() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    reset(n);

    for (int i = 1; i <= n; ++i) {
        dp[i][1] = dp[i - 1][1];

        if (s[i] == 'n') {
            dp[i][1] = (dp[i][1] + 1) % mod;
        }

        for (int j = 2; j < 9; ++j) {
            dp[i][j] = dp[i - 1][j];

            if (s[i] == t[j]) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
            }
        }

        if (s[i] == 'h') {
            dp[i][9] = dp[i - 1][8];
        }
    }

    for (int i = n; i >= 1; --i) {
        cnt[i] = cnt[i + 1];
        if (s[i] == 'a') {
            cnt[i] = (cnt[i] + 1) % mod;
        }
    }

    ll ans = 0;

    // for (int i = 1; i <= n; ++i) {
    //     cout << "ch = " << s[i] << ' ';
    //     for (int j = 1; j <= 9; ++j) {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    for (int i = 1; i <= n; ++i) {
        // ll tmp = (ll)dp[i][9] * (quick(2, cnt[i] - 1) - 1 + mod) % mod;
        if (s[i] == 'h') {
            // cout << "dp[" << i << "] = " << dp[i][9] << " cnt[i] = " << cnt[i] << endl;
            
            ll tmp  = dp[i][9];
            if (cnt[i] > 0) {
                tmp = tmp * (quick(2, cnt[i]) - 1 + mod) % mod;
            } else {
                tmp = 0;
            }

            // cout << "tmp = " << tmp << endl;

            ans = (ans + tmp) % mod;
        }
    }

    printf("%lld\n", ans);
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
