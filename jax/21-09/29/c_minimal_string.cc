#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

const int N = 1e5 + 10;
char s[N], ans[N];

int main() {
    scanf("%s", s);
    int n = strlen(s);

    int len = 0;

    stack<char> r, stk;

    r.push(s[n - 1]);
    for (int i = n - 2; i >= 0; --i) {
        if (s[i] <= r.top()) {
            r.push(s[i]);
        }
    }

    for (int i = 0; i < n; ++i) {
        stk.push(s[i]);
        if (s[i] == r.top()) {
            r.pop();
        }

        while (stk.size() && (r.empty() || stk.top() <= r.top())) {
            ans[len++] = stk.top();

            stk.pop();
        }
    }

    while (stk.size()) {
        ans[len++] = stk.top();
        stk.pop();
    }

    ans[len] = '\0';
    printf("%s\n", ans);
}