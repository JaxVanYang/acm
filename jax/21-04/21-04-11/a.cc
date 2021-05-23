#include <iostream>
using namespace std;
const int maxn = 55;
int xs[maxn], ys[maxn];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", xs + i);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", ys + i);
    }

    int sumX = 0, sumY = 0;
    for (int i = 0; i < n; ++i) {
        sumX += xs[i];
        sumY += ys[i];
    }
    if (sumX >= sumY) {
        puts("YES");
    } else {
        puts("NO");
    }
}