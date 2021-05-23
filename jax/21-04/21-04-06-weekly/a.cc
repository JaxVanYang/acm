/* 
 * 不要忘记范围
 */
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;

pair<int, int> men[maxn];
int cnts[maxn];

struct Seg {
    int l, r;
    int cnt;
} t[maxn * 4];

void build(int p, int l, int r) {
    t[p].l = l, t[p].r = r;
    if (l == r) {
        t[p].cnt = cnts[l];
        return;
    }
    int mid = l + r >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    t[p].cnt = t[p << 1].cnt + t[p << 1 | 1].cnt;
}

int ask(int p, int l, int r) {
    if (l <= t[p].l && t[p].r <= r) {
        return t[p].cnt;
    }
    int ret = 0;
    int mid = t[p].l + t[p].r >> 1;
    if (l <= mid) ret += ask(p << 1, l, r);
    if (mid < r) ret += ask(p << 1 | 1, l, r);
    return ret;
}

void dec(int p, int x) {
    if (t[p].l == t[p].r) {
        --t[p].cnt;
        return;
    }
    int mid = t[p].l + t[p].r >> 1;
    if (x <= mid) dec(p << 1, x);
    else dec(p << 1 | 1, x);
    t[p].cnt = t[p << 1].cnt + t[p << 1 | 1].cnt;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) scanf("%d%d", &men[i].first, &men[i].second);
    sort(men, men + n);
    
    // for (int i = 0; i < n; ++i) {
    //     cout << "i = " << i << " x = " << men[i].first << " y = " << men[i].second << endl;
    // }

    for (int i = 0; i < n; ++i) cnts[men[i].second]++;
    // for (int i = 0; i < n; ++i) cout << men[i].second << endl;
    build(1, 0, 2e5);
    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        dec(1, men[i].second);
        ans += ask(1, 1, men[i].second);
    }
    printf("%lld\n", ans);
}