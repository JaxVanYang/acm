#include <cstdio>
#include <iostream>
#include <deque>
using namespace std;

deque<int> down[14];
int up[14];

inline int trans(char ch) {
    if (ch == 'A') return 1;
    if (ch == '0') return 10;
    if (ch == 'J') return 11;
    if (ch == 'Q') return 12;
    if (ch == 'K') return 13;
    return ch - '0';
}

int get_front(deque<int> &dq) {
    int ret = dq.front();
    dq.pop_front();
    return ret;
}

int get_back(deque<int> &dq) {
    int ret = dq.back();
    dq.pop_back();
    return ret;
}

int main() {
    for (int i = 1; i <= 13; ++i) {
        for (int j = 1; j <= 4; ++j) {
            char ch;
            cin >> ch;
            down[i].push_back(trans(ch));
        }
    }

    for (int i = 0; i < 4; ++i) {
        int cur = get_front(down[13]);
        while (cur != 13) {
            up[cur]++;
            cur = get_back(down[cur]);
        }
    }

    int ans = 0;
    for (int i = 1; i <= 13; ++i) {
        if (up[i] == 4) ++ans;
    }
    printf("%d\n", ans);
}