#include <iostream>
#include <set>
using namespace std;

const int N = 155;
int a[N];
set<int> dp[N][N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }

    for (int i = 0; i < n; ++i) {
        dp[i][i].insert(a[i]);
    }

    for (int i = 2; i <= n; ++i) {
        for (int l = 0; l + i - 1 < n; ++l) {
            int r = l + i - 1;
            for (int mid = l; mid < r; ++mid) {
                for (int x : dp[l][mid]) for (int y: dp[mid + 1][r]) {
                    dp[l][r].insert((x + y) >> 1);
                }
            }
        }
    }

    for (int val: dp[0][n - 1]) {
        printf("%d ", val);
    }
    puts("");
}