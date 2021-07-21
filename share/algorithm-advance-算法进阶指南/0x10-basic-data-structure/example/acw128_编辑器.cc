#include <iostream>
#include <vector>

char read_ch() {
    char ret;
    while ((ret = getchar()) <= ' ');
    return ret;
}

int main() {
    int q;
    scanf("%d", &q);
    // 插入数字有可能为负数
    std::vector<int> a{0}, b, f{INT32_MIN}, sum{0};
    while (q--) {
        char c;
        int x;
        c = read_ch();
        // printf("c = %c\n", c);
        switch (c) {
            case 'I':
                scanf("%d", &x);
                a.push_back(x);
                sum.push_back(sum.back() + x);
                f.push_back(std::max(f.back(), sum.back()));
                break;
            case 'D':
                if (a.size() > 1) {
                    a.pop_back();
                    sum.pop_back();
                    f.pop_back();
                }
                break;
            case 'L':
                if (a.size() > 1) {
                    b.push_back(a.back());
                    a.pop_back();
                    sum.pop_back();
                    f.pop_back();
                }
                break;
            case 'R':
                if (b.size()) {
                    a.push_back(b.back());
                    b.pop_back();
                    sum.push_back(sum.back() + a.back());
                    f.push_back(std::max(f.back(), sum.back()));
                }
                break;
            case 'Q':
                scanf("%d", &x);
                // printf("f.size = %ld x = %d\n", f.size(), x);
                printf("%d\n", f[x]);
        }
    }
}