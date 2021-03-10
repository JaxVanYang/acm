#include <iostream>
using namespace std;

const int maxn = 15;
int order[maxn];
int chosen[maxn];
int n;

void dfs(int p) {
    if (p == n) {
        for (int i = 0; i < n; ++i) {
            cout << order[i] << ' ';
        }
        cout << endl;
    }
    for (int i = 1; i <= n; ++i) if (!chosen[i]) {
        order[p] = i;
        chosen[i] = 1;
        dfs(p + 1);
        chosen[i] = 0;
    }
}

int main() {
    cin >> n;
    dfs(0);
}