#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int maxn = 1e5 + 5;
int block;
int a[maxn], ans[maxn];
int numCnt[maxn], cntCnt[maxn];

struct Query {
    int l, r, id;
    bool operator<(const Query &q) {
        // return l < q.l || l == q.l && r < q.r;
        if (l / block == q.l / block) {
            return r < q.r;
        }
        return l < q.l;
    }
} query[maxn];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    block = sqrt(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &query[i].l, &query[i].r);
        query[i].l--, query[i].r--;
        query[i].id = i;
    }
    sort(query, query + m);

    int res = 1;
    auto move = [&](int p, bool flag) {
        int num = a[p];
        if (flag) {
            ++numCnt[num];
            ++cntCnt[numCnt[num]];
            if (numCnt[num] > res) {
                res = numCnt[num];
            }
        } else {
            --cntCnt[numCnt[num]];
            if (res == numCnt[num] && cntCnt[numCnt[num]] == 0) {
                --res;
            }
            --numCnt[num];
        }
    };
    int l = 0, r = 0;
    numCnt[a[0]] = 1;
    cntCnt[1] = 1;
    for (int i = 0; i < m; ++i) {
        const auto &q = query[i];
        while (l < q.l) {
            move(l++, false);
        }
        while (l > q.l) {
            move(--l, true);
        }
        while (r < q.r) {
            move(++r, true);
        }
        while (r > q.r) {
            move(r--, false);
        }
        ans[q.id] = res;
    }
    for (int i = 0; i < m; ++i) {
        printf("%d\n", ans[i]);
    }
}