#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;
using ll = long long;
const int maxn = 1e5 + 5;
vector<int> ps[maxn];
int rcd[105];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            int num;
            scanf("%d", &num);
            ps[i].push_back(num);
        }
    }
    int now = 1;
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == 0) {
            now = ps[now][b - 1];
        } else if (a == 1) {
            rcd[b - 1] = now;
            printf("%d\n", now);
        } else {
            now = rcd[b - 1];
        }
    }
    printf("%d\n", now);
}