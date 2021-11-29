#include <iostream>

const int N = 1e5 + 10;
char s[N];
bool mark[N];

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    scanf("%s", s);

    int l = 0, ans = 0;
    while (l < n - 2) {
        if (s[l] == 'a' && s[l + 1] == 'b' && s[l + 2] == 'c') {
            mark[l] = true;
            l += 3;
            ++ans;
        } else {
            ++l;
        }
    }


    while (q--) {
        int p;
        char ch[2];
        scanf("%d%s", &p, ch);
        --p;
        s[p] = *ch;
        for (int i = std::max(0, p - 2); i <= std::min(p, n - 3); ++i) {
            // std::cout << "i = " << i << std::endl;
            if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c') {
                if (!mark[i]) {
                    mark[i] = true;
                    ++ans;
                }
            } else {
                if (mark[i]) {
                    // std::cout << "i = " << i << std::endl;
                    mark[i] = false;
                    --ans;
                }
            }
        }
        printf("%d\n", ans);
    }
}