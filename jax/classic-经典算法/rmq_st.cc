// 区间最值 RMQ 的 ST 算法

#include <iostream>
#include <cmath>
using namespace std;

const int N = 1e7 + 5;
int a[N];
int f[N][24];
int n;

void st_prework() {
    // 先处理递推边界
    for (int i = 0; i < n; ++i) {
        f[i][0] = a[i];
    }

    // 确定层数
    int lmt = log(n) / log(2);

    // 逐层推导
    for (int j = 1; j <= lmt; ++j) {
        for (int i = 0; i <= n - (1 << j); ++i) {
            f[i][j] = min(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
        }
    }
}

inline int st_query(int l, int r) {
    int len = r - l;
    int lmt = log(len) / log(2);
    return min(f[l][lmt], f[r - (1 << lmt)][lmt]);
}

int main() {

    // 读入数组
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);

    // 预处理
    st_prework();
    
    // q 次查询，每次查询区间 [l, r) 的最小值
    int q;
    scanf("%d", &q);
    while (q--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", st_query(l, r));
    }
}