#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
using namespace std;
using ll = long long;

int main() {
    int a[24];
    for (int i = 0; i < 24; ++i) {
        cin >> a[i];
    }
    int q = -1;
    while (cin >> q && 0 <= q && q < 24) {
        if (a[q] > 50) {
            printf("%d Yes\n", a[q]);
        } else {
            printf("%d No\n", a[q]);
        }
    }
}