#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e6 + 10;
int id[N], t, idx = 0;
queue<int> qs[1005];
char cmd[10];

void init() {
    for (int i = 0; i <= t; ++i) {
        qs[i] = queue<int>();
    }
}

void solve() {
    ++idx;
    // Note: memset cannot be used on non-builtin type
    // memset(qs, 0, sizeof(qs));
    init();

    for (int i = 1; i <= t; ++i) {
        int n;
        scanf("%d", &n);
        for (int j = 0; j < n; ++j) {
            int no;
            scanf("%d", &no);
            id[no] = i;
        }
    }

    printf("Scenario #%d\n", idx);

    while (~scanf("%s", cmd) && cmd[0] != 'S') {
        if (cmd[0] == 'E') {
            int x;
            scanf("%d", &x);
            // printf("x = %d id = %d\n", x, id[x]);
            qs[id[x]].push(x);
            if (qs[id[x]].size() == 1) qs[0].push(id[x]);
        } else {
            int qid = qs[0].front();
            printf("%d\n", qs[qid].front());
            qs[qid].pop();
            if (qs[qid].size() == 0) qs[0].pop();
        }
    }
    puts("");
}

int main() {
    while (~scanf("%d", &t) && t) {
        solve();
    }
}