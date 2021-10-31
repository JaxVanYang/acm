#include <iostream>
using namespace std;

const int N = 5e4 + 10, M = 3 * N;
int id[M];

int find(int p) {
    if (id[p] != p) {
        id[p] = find(id[p]);
    }
    return id[p];
}

inline void un(int u, int v) {
    id[find(u)] = find(v);
}

void init(int n) {
    for (int i = 1; i <= 3 * n; ++i) {
        id[i] = i;
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    init(n);

    int ans = 0;
    while (k--) {
        int d, x, y;
        scanf("%d%d%d", &d, &x, &y);

        if (x > n || y > n) {
            ++ans;
            continue;
        }

        int x1 = x + n, x2 = x1 + n;
        int y1 = y + n, y2 = y1 + n;

        if (d == 1) {
            if (find(x2) == find(y) || find(y2) == find(x)) {
                ++ans;
            } else {
                un(x, y);
                un(x1, y1);
                un(x2, y2);
            }
        } else {
            if (find(x) == find(y) || find(y2) == find(x)) {
                ++ans;
            } else {
                un(x2, y);
                un(x1, y2);
                un(x, y1);
            }
        }
    }

    printf("%d\n", ans);
}