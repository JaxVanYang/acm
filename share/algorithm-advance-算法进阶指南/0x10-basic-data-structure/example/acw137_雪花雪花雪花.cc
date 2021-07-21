#include <iostream>
#include <cstring>
using ll = long long;

const int N = 1e5 + 10;
int n, mod = 99991, snow[N][6];
int head[N], next[N], tot;

int hash(int a[]) {
    int sum = 0, mul = 1;
    for (int i = 0; i < 6; ++i) {
        sum = (sum + a[i]) % mod;
        mul = (ll)mul * a[i] % mod;
    }
    return (sum + mul) % mod;
}

bool equal(int a[], int b[]) {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            bool eq = 1;
            for (int k = 0; k < 6; ++k) {
                if (a[(i + k) % 6] != b[(j + k) % 6]) eq = 0;
            }
            if (eq) return 1;
            eq = 1;
            for (int k = 0; k < 6; ++k) {
                if (a[(i + k) % 6] != b[(j - k + 6) % 6]) eq = 0;
            }
            if (eq) return 1;
        }
    }
    return 0;
}

bool insert(int a[]) {
    int val = hash(a);
    for (int i = head[val]; i; i = next[i]) {
        if (equal(snow[i], a)) return 1;
    }
    ++tot;
    memcpy(snow[tot], a, 6 * sizeof(int));
    next[tot] = head[val];
    head[val] = tot;
    return 0;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int a[6];
        for (int j = 0; j < 6; ++j) {
            scanf("%d", a + j);
        }
        // printf("hash = %d\n", hash(a));
        if (insert(a)) {
            puts("Twin snowflakes found.");
            return 0;
        }
    }
    puts("No two snowflakes are alike.");
}