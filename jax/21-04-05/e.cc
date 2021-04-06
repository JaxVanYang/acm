#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
int a[11];
int n;

bool valid(int mask) {
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i, mask >>= 1) {
        if (mask & 1) l += a[i];
        else r += a[i];
    }
    return l != r && l != 0 && r != 0;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < (1 << n); ++i) {
        if (valid(i)) {
            // cout << "i = " << i << endl;
            vector<int> ans;
            for (int j = 0; j < n; ++j) {
                if (i & 1) ans.push_back(j + 1);
                i >>= 1;
            }
            printf("%ld\n", ans.size());
            for (auto num : ans) {
                printf("%d ", num);
            }
            return 0;
        }
    }
    puts("-1");
}