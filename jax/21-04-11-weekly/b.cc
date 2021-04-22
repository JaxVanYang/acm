#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;
int nexts[maxn], cnts[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int num;
        scanf("%d", &num);
        cnts[num]++;
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (cnts[i] == 0) {
            ++cnt;
        }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= n; ++i) {
        if (cnts[i] == 0) {
            printf("%d ", i);
        }
    }
    puts("");
}