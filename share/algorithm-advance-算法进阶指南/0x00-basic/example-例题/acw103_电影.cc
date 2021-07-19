/* 
 * 离散化模板题
 * 二分查找时注意要判断一下是否找到
 */

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 2e5 + 5;
int a[maxn], b[maxn], c[maxn];
int cnts[maxn];
int sz;

int find(int x) {
    int idx = lower_bound(a, a + sz, x) - a;
    if (idx == sz || a[idx] != x) return sz;
    return idx;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) scanf("%d", b + i);
    for (int i = 0; i < m; ++i) scanf("%d", c + i);

    // 直接在原数组上进行离散化
    sort(a, a + n);
    int l = 0;
    while (l < n) {
        int r = l;
        while (r < n && a[l] == a[r]) ++r;
        cnts[sz] = r - l;
        a[sz++] = a[l];
        l = r;
    }
    

    int ans = -1, lCnt = 0, vCnt = 0;
    for (int i = 0; i < m; ++i) {
        int lId = find(b[i]), vId = find(c[i]);
        if (lId == sz || vId == sz) continue;
        int l = cnts[lId], v = cnts[vId];
        if (l > lCnt || (l == lCnt && v > vCnt)) {
            ans = i;
            lCnt = l;
            vCnt = v;
        }
    }
    printf("%d", ans + 1);
}