#include <iostream>
#include <set>
using namespace std;

const int maxn = 10005;
int a[maxn];    // 只使用一个数组节省存储空间

int main() {
    int n, p, h, m;
    scanf("%d%d%d%d", &n, &p, &h, &m);
    set<pair<int, int>> st;
    while (m--) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x > y) swap(x, y);  // 注意保持 x < y，如果颠倒会导致在差分序列上的操作与正常相反
        auto xy = make_pair(x, y);
        if (!st.count(xy)) {
            st.insert(xy);
            a[x + 1]--;
            a[y]++;
        }
    }
    for (int i = 1; i <= n; ++i) {
        a[i] += a[i - 1]; // 前一项加上这一项与前一项的差就是这一项的值
        printf("%d\n", h + a[i]);
    }
}
/*
 * 书上的题解使用 map 来记录，这里使用了 set 来替代
 * 另外值得注意的一点是：map 和 set 都能使用 pair 作为键，而 unordered_map 和 unordered_set 不行
 * 具体原因待考
 */