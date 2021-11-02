#include <iostream>
using namespace std;

const int N = 1e5 + 10;
int a[N], b[N], c[N];
int n;

inline int lowbit(int x) {
    return x & -x;
}

int highbit(int x) {
    int ret = 0;
    for (; x; x -= lowbit(x)) ret = x;
    return ret;
}

int ask(int x) {
    int ret = 0;
    for (; x; x -= lowbit(x)) ret += b[x];
    return ret;
}

void flip(int x) {
    for (; x <= n; x += lowbit(x)) b[x] -= 1;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        b[i] = 1;
        for (int low = lowbit(i), t = 1; t < low; t <<= 1) b[i] += b[i - t];
        // cout << "b[" << i << "] = " << b[i] << endl;
    }

    for (int i = 2; i <= n; ++i) {
        scanf("%d", a + i);
    }

    const int high = highbit(n);
    for (int i = n; i >= 1; --i) {
        int ans = 0, cnt = 0;
        for (int j = high; j; j >>= 1) {
            if (ans + j <= n && cnt + b[ans + j] <= a[i]) {
                cnt += b[ans + j];
                ans += j;
            }
        }
        c[i] = ++ans;
        flip(ans);
    }

    for (int i = 1; i <= n; ++i) {
        printf("%d\n", c[i]);
    }
}