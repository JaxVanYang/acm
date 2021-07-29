#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5 + 100;
pair<int, int> a[N], ans[N];
int b[N];

struct Node {
    int val, id;
    int pre, next;
} nodes[N];
int head, tail, tot;

inline void init() {
    tot = 2;
    head = 1, tail = 2;
    nodes[head].next = tail;
    nodes[tail].pre = head;
}

inline int insert(int p, int val, int id) {
    int q = ++tot;
    nodes[q].val = val;
    nodes[nodes[p].next].pre = q;
    nodes[q].next = nodes[p].next;
    nodes[q].pre = p;
    nodes[p].next = q;
    nodes[q].id = id;
    return q;
}

inline void remove(int p) {
    nodes[nodes[p].pre].next = nodes[p].next;
    nodes[nodes[p].next].pre = nodes[p].pre;
}

int main() {
    init();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int val;
        scanf("%d", &val);
        a[i] = make_pair(val, i);
    }

    sort(a, a + n);
    for (int i = 0, p = head; i < n; ++i) {
        b[a[i].second] = insert(p, a[i].first, a[i].second);
        p = b[a[i].second];
    }
    for (int i = n - 1; i > 0; --i) {
        int p = b[i];
        // printf("i = %d p = %d val = %d\n", i, p, nodes[p].val);
        int pre = nodes[p].pre, next = nodes[p].next;
        // printf("pre = %d next = %d\n", pre, next);
        int pre_val = nodes[pre].val, next_val = nodes[next].val;
        // printf("pre_val = %d next_val = %d\n", pre_val, next_val);
        int pre_diff = nodes[p].val - nodes[pre].val, next_diff = nodes[next].val - nodes[p].val;
        // printf("pre_diff = %d next_diff = %d\n", pre_diff, next_diff);
        int pre_id = nodes[pre].id + 1, next_id = nodes[next].id + 1;
        // printf("pre_id = %d next_id = %d\n", pre_id, next_id);
        if (pre == head) {
            ans[i] = make_pair(next_diff, next_id);
        } else if (next == tail) {
            ans[i] = make_pair(pre_diff, pre_id);
        } else if (pre_diff < next_diff) {
            ans[i] = make_pair(pre_diff, pre_id);
        } else if (pre_diff > next_diff) {
            ans[i] = make_pair(next_diff, next_id);
        } else {
            if (pre_val < next_val) {
                ans[i] = make_pair(pre_diff, pre_id);
            } else {
                ans[i] = make_pair(next_diff, next_id);
            }
        }
        remove(p);
    }

    for (int i = 1; i < n; ++i) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
}