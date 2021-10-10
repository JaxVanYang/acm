#include <iostream>
using namespace std;
const int maxn = 2e5 + 5;
char s[maxn];

int main() {
    int t;
    cin >> t;
    NEXT:
    while (t--) {
        int a, b;
        cin >> a >> b;
        scanf("%s", s);
        int n = a + b;
        bool flag = false;
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] == '?') {
                if (s[n - 1 - i] == '1') {
                    s[i] = '1';
                    b -= 2;
                } else if (s[n - 1 - i] == '0') {
                    s[i] = '0';
                    a -= 2;
                }
            } else if (s[i] == '1') {
                --b;
                if (s[n - 1 - i] == '0') {
                    flag = true;
                    break;
                }
                if (s[n - 1 - i] == '?') {
                    s[n - 1 - i] = '1';
                }
                --b;
            } else {
                --a;
                if (s[n - 1 - i] == '1') {
                    flag = true;
                    break;
                }
                if (s[n - 1 - i] == '?') {
                    s[n - 1 - i] = '0';
                }
                --a;
            }
            // cout << "s = " << s << " a = " << a << " b = " << b << endl;
        }

        if (a < 0 || b < 0) {
            flag = true;
        }
        if (flag) {
            puts("-1");
            continue;
        }
        if ((n & 1) && s[n / 2] == '?') {
            s[n / 2] = a & 1 ? '0' : '1';
        }
        if (n & 1) {
            if (s[n / 2] == '0') --a;
            else --b;
        }
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] == '?') {
                // cout << "i = " << i << " a = " << a << " b = " << b << endl;
                if (a >= 2) {
                    s[i] = s[n - 1 - i] = '0';
                    a -= 2;
                } else if (b >= 2) {
                    s[i] = s[n - 1 - i] = '1';
                    b -= 2;
                } else {
                    puts("-1");
                    goto NEXT;
                }
            }
        }
        // cout << "a = " << a << " b = " << b << endl;
        // cout << "s = " << s << endl;
        if (a != 0 || b != 0) {
            puts("-1");
            continue;
        }
        printf("%s\n", s);
    }
}