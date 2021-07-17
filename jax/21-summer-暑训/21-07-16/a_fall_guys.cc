#include <iostream>
using namespace std;

const int N = 2e5 + 20;
int x[N], c[N];
int n, h, H;

int calc(int t) {
    int no = t / H;
    int rem = t % H;
    if (no & 1) {
        return t + (rem < H - h ? H - h - rem : 0);
    } else {
        return t + (rem > h ? 2 * H - h - rem : 0);
    }
}

void solve() {
    scanf("%d%d%d", &n, &h, &H);
    for (int i = 0; i < n; ++i) scanf("%d", x + i);
    for (int i = 0; i < n; ++i) scanf("%d", c + i);
    int time = INT32_MAX, ans = -1;
    for (int i = 0; i < n; ++i) {
        int new_time = calc(x[i]) + c[i];
        // cout << "new_time = " << new_time << endl;
        if (new_time < time) {
            time = new_time;
            ans = i;
        }
    }
    printf("%d\n", ans + 1);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}