#include <iostream>

const int N = 1e6 + 10;

void solve() {
    int x1, p1, x2, p2;
    scanf("%d%d%d%d", &x1, &p1, &x2, &p2);
    while (x1 % 10 == 0) {
        x1 /= 10;
        ++p1;
    }
    while (x2 % 10 == 0) {
        x2 /= 10;
        ++p2;
    }

    auto s1 = std::to_string(x1);
    auto s2 = std::to_string(x2);

    if (s1.size() + p1 > s2.size() + p2) {
        puts(">");
    } else if (s1.size() + p1 < s2.size() + p2) {
        puts("<");
    } else {
        int k = std::abs(std::min(p1, p2) - p1);
        for (int i = 0; i < k; ++i) {
            x1 *= 10, --p1;
        }
        k = std::abs(std::min(p1, p2) - p2);
        for (int i = 0; i < k; ++i) {
            x2 *= 10, --p2;
        }


        if (x1 > x2) {
            puts(">");
        } else if (x1 < x2) {
            puts("<");
        } else {
            puts("=");
        }
    }
    
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        solve();
    }
}