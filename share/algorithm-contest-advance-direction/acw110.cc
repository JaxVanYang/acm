#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 2505;

struct Cow {
    int l, r;
} cows[maxn];

struct Spf {
    int val, cnt;
} spfs[maxn];

bool operator <(const Cow &a, const Cow &b) {
    return a.l > b.l;
}

bool operator <(const Spf &a, const Spf &b) {
    return a.val > b.val;
}

int main() {
    int c, l;
    cin >> c >> l;
    for (int i = 0; i < c; ++i) scanf("%d%d", &cows[i].l, &cows[i].r);
    for (int i = 0; i < l; ++i) scanf("%d%d", &spfs[i].val, &spfs[i].cnt);
    sort(cows, cows + c);
    // for (int i = 0; i < c; ++i) {
    //     cout << i << " : " << cows[i].l << ", " << cows[i].r << endl;
    // }
    // sort(spfs, spfs + l);
    int ans = 0;
    for (int i = 0; i < c; ++i) {
        int p = -1;
        for (int j = 0; j < l; ++j) {
            if (cows[i].l <= spfs[j].val && spfs[j].val <= cows[i].r && spfs[j].cnt > 0) {
                if (p == -1 || spfs[j].val > spfs[p].val) p = j;
            }
        }
        if (p != -1) {
            ++ans;
            spfs[p].cnt--;
        }
    }
    cout << ans << endl;
}