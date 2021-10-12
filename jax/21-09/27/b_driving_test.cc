#include <iostream>
#include <stack>
using namespace std;

const int N = 2e5 + 10;

int main() {
    int n;
    scanf("%d", &n);

    stack<int> stk;
    int c = 0, speed;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            scanf("%d", &speed);

            while (stk.size() && stk.top() < speed) {
                stk.pop();
                ++ans;
            }
        } else if (op == 2) {
            ans += c;
            c = 0;
        } else if (op == 3) {
            int lmt;
            scanf("%d", &lmt);

            if (lmt < speed) {
                ++ans;
            } else {
                stk.push(lmt);
            }
        } else if (op == 4) {
            c = 0;
        } else if (op == 5) {
            while (stk.size()) {
                stk.pop();
            }
        } else if (op == 6) {
            ++c;
        }
    }

    printf("%d\n", ans);
}