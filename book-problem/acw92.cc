#include <iostream>
using namespace std;
int n;
bool chosen[16];

void dfs(int p) {
    if (p > n) {
        for (int i = 1; i <= n; ++i) if (chosen[i]) printf("%d ", i);
        putchar('\n');
        return;
    }
    dfs(p + 1);
    chosen[p] = 1;
    dfs(p + 1);
    chosen[p] = 0;  // 恢复默认状态，必不可少
}

int main() {
    cin >> n;
    dfs(1);
}