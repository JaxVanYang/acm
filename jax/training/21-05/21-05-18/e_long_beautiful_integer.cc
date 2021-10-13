#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 2e5 + 100;
int a[maxn], b[maxn];
int n, k;

bool check_9() {
    for (int i = 0; i < n; ++i) if (a[i] != 9) {
        return false;
    }
    return true;
}

void inc() {
    int carry = 1;
    for (int i = k - 1; i >= 0; --i) {
        b[i] += carry;
        carry = b[i] / 10;
        b[i] %= 10;
    }
}

void answer() {
    printf("%d\n", n);
    for (int i = 0; i < n; ++i) {
        printf("%d", b[i % k]);
    }
}

int check_b(int seg, int len) {
    for (int i = 0; i < len; ++i) if (b[i] > a[seg * k + i]) {
        return 1;
    } else if (b[i] < a[seg * k + i]) {
        return -1;
    }
    return 0;
}

int main() {
    scanf("%d%d", &n, &k);
    getchar();
    for (int i = 0; i < n; ++i) {
        // scanf("%d", a + i);
        a[i] = getchar() - '0';
    }
    memcpy(b, a, sizeof(int) * k);
    if (check_9()) {
        answer();
        return 0;
    }
    bool preEqual = true;
    for (int i = 1; i < n / k; ++i) {
        if (check_b(i, k) == 1) {
            answer();
            return 0;
        }
        if (check_b(i, k) == -1) {
            inc();
            answer();
            return 0;
        }
    }
    if (n % k == 0) {
        answer();
    } else {
        int flag = check_b(n / k, n % k);
        if (flag == -1) {
            inc();
        }
        answer();
    }
}