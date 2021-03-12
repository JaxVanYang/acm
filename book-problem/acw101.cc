#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;
const int maxn = 10005;
// unordered_map 不能用 pair 作为 key，不知道为什么
// unordered_map<pair<int, int>, bool> existed;
map<pair<int, int>, bool> existed;
int c[maxn], d[maxn];

int main() {
    int n, p, h, m;
    cin >> n >> p >> h >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a > b) swap(a, b);
        if (existed[make_pair(a, b)]) continue;
        // 将第 a + 1 到 b - 1 头牛降低高度
        d[a + 1]--, d[b]++; // 差分变化
        existed[make_pair(a, b)] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        c[i] = c[i - 1] + d[i]; // 前一项加上这一项与前一项的差就是这一项的值
        printf("%d\n", h + c[i]);
    }
}