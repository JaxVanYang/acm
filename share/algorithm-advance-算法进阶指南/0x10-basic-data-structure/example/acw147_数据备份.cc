#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using pi = pair<int, int>;

#define REP(i, l, r) for (int i = l; i < r; ++i)
#define F first
#define S second
#define PF push_fornt
#define PB push_back
#define MP make_pair
// #define Sort(v) sort(v.begin(), v.end())
#define Unique(v) unique(v.begin(), v.end())
#define Lower(v, val) lower_bound(v.begin(), v.end(), val)
#define Upper(v, val) upper_bound(v.begin(), v.end(), val)
#define Reverse(v) reverse(v.begin(), v.end())

const char el = '\n';
const int N = 1e5 + 10;
const int INF = 0x3f3f3f3f;
clock_t startTime;
double getCurTime() {
  return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

template<typename T>
void print(T &v) {
    for (auto val : v) cout << val << ' ';
    cout << el;
}
template<typename T>
istream &operator>>(istream &in, vector<T> &v) {
    for (auto &each : v) in >> each;
    return in;
}
template<typename T>
ostream &operator<<(ostream &out, vector<T> &v) {
    for (auto &each : v) out << each << ' ';
    return out;
}
template<typename T> void Sort(T &t) { sort(t.begin(), t.end()); }
template<typename T> using Heap = priority_queue<T, vector<T>, greater<T>>;

struct Node {
    ll val;
    Node *pre, *nex;
    Node(ll val) : val(val), pre(nullptr), nex(nullptr) {}
    void add(Node *node) {
        pre->nex = node;
        node->pre = pre;
        node->nex = this;
        this->pre = node;
    }
    void remove() {
        pre->nex = nex;
        nex->pre = pre;
        delete this;
    }
};

int main() {
    startTime = clock();
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vi dis(n);
    cin >> dis;
    // cout << dis << endl;
    Node *head = new Node(INT32_MAX), *tail = new Node(INT32_MAX);
    head->nex = tail, tail->pre = head;
    REP(i, 1, n) tail->add(new Node(dis[i] - dis[i - 1]));
    // for (auto p = head->nex; p != tail; p = p->nex) cout << p->val << ' ';
    // cout << endl;

    ll ans = 0;
    unordered_set<Node*> st;
    Heap<pair<ll, Node*>> heap;
    for (auto p = head->nex; p != tail; p = p->nex) heap.push(MP(p->val, p));

    REP(i, 0, k) {
        while (st.count(heap.top().S)) heap.pop();

        ll val = heap.top().F;
        auto node = heap.top().S;
        auto pre = node->pre, nex = node->nex;
        ll new_val = pre->val + nex->val - val;
        heap.pop();

        ans += val;
        node->val = new_val;
        st.insert(pre), st.insert(nex);

        heap.push(MP(new_val, node));
        
        if (nex != tail) nex->remove();
        if (pre != head) pre->remove();
    }
    cout << ans << el;
}
