#include <iostream>
#include <queue>
using namespace std;
using ui = unsigned int;
using ll = long long;
const int maxn = 1e6 + 5;
int a[maxn];

// int calc(int ans, int x) {
//     return ans ^ x;
// }

int main() {
    int n;
    scanf("%d", &n);
    int ans = 0;
    priority_queue<int> front, tail;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        int num = (x ^ ans);
        // cout << "num = " << num << " ans = " << ans << " x = " << x << endl;
        if (i & 1) {
            tail.push(-num);
            if ((-tail.top()) < front.top()) {
                int u = front.top(), v = -tail.top();
                front.pop(), tail.pop();
                front.push(v), tail.push(-u);
            }
        } else {
            front.push(num);
            if (tail.size() && (-tail.top()) < front.top()) {
                int u = front.top(), v = -tail.top();
                front.pop(), tail.pop();
                front.push(v), tail.push(-u);
            }
        }
        ans = front.top();
        // cout << "end ans = " << ans << endl;
        printf("%d\n", ans);
    }
}