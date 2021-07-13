#include <iostream>
#include <queue>
using namespace std;

int main() {
    int p;
    cin >> p;
    while (p--) {
        int id, m;
        scanf("%d%d", &id, &m);
        priority_queue<int> a, b;
        // 大根堆 a 存放前半部分，小根堆存放后半部分
        // a.top 就是前半部分的最大值，-b.top 就是后半部分的最小值
        int cnt = 0;
        printf("%d %d\n", id, (m + 1) / 2);
        for (int i = 1; i <= m; ++i) {
            int num;
            scanf("%d", &num);
            if (i & 1) {
                if (b.empty() || num <= -b.top()) {
                    a.push(num);
                } else {
                    a.push(-b.top());
                    b.pop();
                    b.push(-num);
                }
                printf("%d ", a.top());
                ++cnt;
                if (cnt == 10) {
                    putchar('\n');
                    cnt = 0;
                }
            } else {
                if (num >= a.top()) b.push(-num);
                else {
                    b.push(-a.top());
                    a.pop();
                    a.push(num);
                }
            }
        }
        if (cnt) puts("");
    }
}