#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 1e5 + 5;
int id[maxn], big[maxn], small[maxn];

int find(int p) {
    if (id[p] != p) {
        id[p] = find(id[p]);
    }
    return id[p];
}

int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
        id[i] = i;
        scanf("%d", big + i);
        small[i] = big[i];
    }

    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        int uId = find(u), vId = find(v);
        if (uId == vId) continue;
        int uBig = big[uId], vBig = big[vId];
        int uSmall = small[uId], vSmall = small[vId];
        int more = max(uBig, vBig), less = min(uSmall, vSmall);
        if (more - less > k) continue;
        if (uId < vId) {
            id[vId] = uId;
            big[uId] = more, small[uId] = less;
        } else {
            id[uId] = vId;
            big[vId] = more, small[vId] = less;
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        int idx = find(i);
        printf("%d %d\n", idx, big[idx] - small[idx]);
    }
}