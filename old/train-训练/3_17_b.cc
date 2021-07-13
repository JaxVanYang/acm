#include <iostream>
#include <cstring>
using namespace std;

int dp[105][105];
char s[105];

bool check(int p) {
    if (p % 2) return false;
    for (int i = 1; i <= p / 2; ++i) {
        if (s[i] != s[p / 2 + i]) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    getchar();
    for (int i = 1; i <= n; ++i) scanf("%c", s + i);
    // for (int i = 1; i <= n; ++i) cout << s[i];
    // cout << endl;
    int ans = n;
    for (int i = n - n % 2; i >= 2; i--) {
        // cout << "i = " << i << " check = " << check(i) << endl;
        if (check(i)) {
            ans = i / 2 + 1 + n - i;
            break;
        }
    }
    cout << ans << endl;
}