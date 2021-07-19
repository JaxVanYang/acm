#include <iostream>
using namespace std;

const int N = 1010;

struct Node {
    int parent, size, sum;
    double avg;
} nodes[N];

int n, root;

int find() {
    int ret = -1;
    double avg = -1;
    for (int i = 1; i <= n; ++i) {
        if (i != root && nodes[i].avg > avg) {
            avg = nodes[i].avg;
            ret = i;
        }
    }
    return ret;
}

int main() {
    int ans = 0;
    cin >> n >> root;
    for (int i = 1; i <= n; ++i) {
        // Note: 在使用 auto 获取已存在的对象时记得加上引用 & 修饰
        auto &node = nodes[i];
        cin >> node.sum;
        node.size = 1;
        node.avg = node.sum;
        ans += node.sum;
    }

    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        nodes[b].parent = a;
    }

    for (int i = 1; i < n; ++i) {
        int cur_id = find();
        auto &cur = nodes[cur_id];
        cur.avg = -1;
        auto &parent = nodes[cur.parent];
        ans += parent.size * cur.sum;
        parent.size += cur.size;
        parent.sum += cur.sum;
        parent.avg = (double)parent.sum / parent.size;

        for (int j = 1; j <= n; ++j) {
            if (nodes[j].parent == cur_id) {
                nodes[j].parent = cur.parent;
            }
        }
    }

    cout << ans << endl;
}