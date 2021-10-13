#include <iostream>
#include <stack>
#include <queue>
using namespace std;

const int maxn = 3e5 + 100;
int n;
char s[10];

int main() {
    int ans = 0;
    scanf("%d", &n);
    stack<int> st;
    int tar = 1;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < 2 * n; ++i) {
        scanf("%s", s);
        if (s[0] == 'a') {
            int num;
            scanf("%d", &num);
            st.push(num);
        } else {
            if (st.empty() && pq.size() && pq.top() == tar) {
                pq.pop();
            } else if (st.size() && st.top() == tar) {
                st.pop();
            } else {
                ++ans;
                while (st.size()) {
                    pq.push(st.top());
                    st.pop();
                }
                pq.pop();
            }
            ++tar;
        }
    }
    printf("%d\n", ans);
}