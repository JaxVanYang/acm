#include <iostream>
using namespace std;
const int maxn = 1005;
int a[maxn];

inline int transfer(int num) {
    return num & 1 ? num + 1 : num - 1;
}

inline int end(int num) {
    return num & 1 ? num : num - 1;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < n; ++i) a[i] = end(a[i]);
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
}