#include <iostream>

using ll = long long;

const int N = 1e5 + 10;
int trie[N * 32][2], tot = 1;

ll a[N];

void insert(ll num) {
    int p = 1;
    for (int i = 31; i >= 0; --i) {
        int val = (num >> i) & 1;
        if (trie[p][val] == 0) {
            trie[p][val] = ++tot;
        }
        p = trie[p][val];
    }
}

ll query(ll num) {
    ll p = 1, ret = 0;
    for (int i = 31; i >= 0; --i) {
        int val = !((num >> i) & 1);
        if (trie[p][val] == 0) {
            val ^= 1;
        }
        // printf("%d", val);
        ret = (ret << 1) + val;
        p = trie[p][val];
    }
    // puts("");
    // printf("ret = %lld\n", ret);
    return ret ^ num;
}

int main() {
    int n;
    scanf("%d", &n);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%lld", a + i);
        insert(a[i]);
        ans = std::max(ans, query(a[i]));
    }

    printf("%lld\n", ans);
}