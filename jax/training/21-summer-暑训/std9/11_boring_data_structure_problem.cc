#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
deque<int> dq[2];
int len0, len1;
int mark[N];

void update() {
    if (len0 < len1) {
        while (len0 < len1) {
            int val = dq[1].front();
            dq[1].pop_front();
            if (mark[val] == 1) {
                dq[0].push_back(val);
                mark[val] = 0;
                --len1, ++len0;
            }
        }
    } else if (len0 > len1 + 1) {
        while (len0 > len1 + 1) {
            int val = dq[0].back();
            dq[0].pop_back();
            if (mark[val] == 0) {
                dq[1].push_front(val);
                mark[val] = 1;
                ++len1, --len0;
            }
        }
    }
}

void l_add(int val) {
    dq[0].push_front(val);
    mark[val] = 0;
    ++len0;
    update();
}

void r_add(int val) {
    dq[1].push_back(val);
    mark[val] = 1;
    ++len1;
    update();
}

void del(int val) {
    if (mark[val] == 0) {
        --len0;
    } else if (mark[val] == 1) {
        --len1;
    }
    mark[val] = 2;
    update();
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int q;
    cin >> q;
    int cur = 1;
    while (q--) {
        char ch;
        cin >> ch;
        if (ch == 'L') {
            l_add(cur++);
        } else if (ch == 'R') {
            r_add(cur++);
        } else if (ch == 'Q') {
            int cnt = len0 + len1;
            if (cnt & 1) {
                while (mark[dq[0].back()] == 2) dq[0].pop_back();
                cout << dq[0].back() << endl;
            } else {
                while (mark[dq[1].front()] == 2) dq[1].pop_front();
                cout << dq[1].front() << endl;
            }
        } else {
            int x;
            cin >> x;
            del(x);
        }
    }
}