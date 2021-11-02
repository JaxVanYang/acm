#include <iostream>
#include <queue>
using ll = long  long;

const int N = 1e5 + 10, M = N << 2;
int n, m, mod;
int a[N];
ll vals[M], mul[M], add[M];

inline ll add_mod(const ll &x, const ll &y) {
    return (x + y) % mod;
}
inline ll mul_mod(const ll &x, const ll &y) {
    return x * y % mod;
}
inline int avg(const int &x, const int &y) {
    return x + ((y - x) >> 1);
}
inline void pushup(int p) {
    vals[p] = add_mod(vals[p << 1], vals[p << 1 | 1]);
}

void build(int s = 1, int t = n, int p = 1) {
    mul[p] = 1;
    if (s == t) {
        vals[p] = a[s];
        return;
    }
    int mid = avg(s, t);
    build(s, mid, p << 1);
    build(mid + 1, t, p << 1 | 1);
    pushup(p);
}

struct Node {
    int s, t, p;
};

// void bfs() {
//     std::queue<Node> q;
//     q.push({1, n, 1});
//     while (q.size()) {
//         int len = q.size();
//         while (len--) {
//             Node node = q.front();
//             q.pop();
//             std::cout << "(" << node.s << ", " << node.t << ", " << node.p << "): val = " << vals[node.p] << " mul = "
//                       << mul[node.p] << " add = " << add[node.p] << "\t";
//             if (node.s != node.t) {
//                 int mid = avg(node.s, node.t);
//                 q.push(Node{node.s, mid, node.p << 1});
//                 q.push(Node{mid + 1, node.t, node.p << 1 | 1});
//             }
//         }
//         std::cout << std::endl;
//     }
//     std::cout << std::endl;
// }

void pushdown(int s, int t, int mid, int p, int lson, int rson) {
    if (s != t) {
        if (mul[p] != 1) {
            vals[lson] = mul_mod(vals[lson], mul[p]);
            vals[rson] = mul_mod(vals[rson], mul[p]);
            add[lson] = mul_mod(add[lson], mul[p]);
            add[rson] = mul_mod(add[rson], mul[p]);
            mul[lson] = mul_mod(mul[lson], mul[p]);
            mul[rson] = mul_mod(mul[rson], mul[p]);
            mul[p] = 1;
        }
        if (add[p]) {
            vals[lson] = add_mod(vals[lson], mul_mod(mid - s + 1, add[p]));
            vals[rson] = add_mod(vals[rson], mul_mod(t - mid, add[p]));
            add[lson] = add_mod(add[lson], add[p]);
            add[rson] = add_mod(add[rson], add[p]);
            add[p] = 0;
        }
    }
}

ll getSum(int l, int r, int s = 1, int t = n, int p = 1) {
    if (l <= s && t <= r) {
        return vals[p];
    }
    int mid = avg(s, t);
    int lson = p << 1, rson = lson | 1;
    pushdown(s, t, mid, p, lson, rson);
    ll ret = 0;
    if (l <= mid) ret = add_mod(ret, getSum(l, r, s, mid, lson));
    if (mid < r) ret = add_mod(ret, getSum(l, r, mid + 1, t, rson));
    return ret;
}

void update(int l, int r, int op, int k, int s = 1, int t = n, int p = 1) {
    if (l <= s && t <= r) {
        if (op == 1) {
            vals[p] = mul_mod(vals[p], k);
            mul[p] = mul_mod(mul[p], k);
            add[p] = mul_mod(add[p], k);
        } else {
            vals[p] = add_mod(vals[p], mul_mod(t - s + 1, k));
            add[p] = add_mod(add[p], k);
        }
        return;
    }
    int mid = avg(s, t);
    int lson = p << 1, rson = lson | 1;
    pushdown(s, t, mid, p, lson, rson);
    if (l <= mid) update(l, r, op, k, s, mid, lson);
    if (mid < r) update(l, r, op, k, mid + 1, t, rson);
    pushup(p);
}

void solve() {
    int op, x, y, k;
    scanf("%d%d%d", &op, &x, &y);
    if (op == 3) {
        printf("%lld\n", getSum(x, y));
        return;
    }
    scanf("%d", &k);
    update(x, y, op, k);
    // bfs();
}

int main() {
    scanf("%d%d%d", &n, &m, &mod);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
    }
    build();
    // bfs();

    while (m--) {
        solve();
    }
}