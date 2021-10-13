#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;
using ll = long long;

const int maxn = 105;
double a[maxn];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        scanf("%lf", a + i);
        if (a[i] < m) {
            printf("On Sale! %.1lf\n", a[i]);
        }
    }

}