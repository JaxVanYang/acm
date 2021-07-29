#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

#define REP(i, l, r) for (int i = l; i < r; ++i)
#define F first
#define S second
#define PF push_fornt
#define PB push_back
#define MP make_pair

const char el = '\n';
const int N = 1e5 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    set<pi> st;
    int n, num;
    cin >> n;
    if (n) {
        cin >> num;
        st.insert(MP(num, 0));
    }
    REP(i, 1, n) {
        cin >> num;
        auto cur = MP(num, i);
        auto p = st.upper_bound(cur);
        int val = INT32_MAX, idx;
        if (p != st.end()) {
            val = p->F - num;
            idx = p->S + 1;
        }
        if (p != st.begin()) {
            --p;
            if (num - p->F <= val) {
                val = num - p->F;
                idx = p->S + 1;
            }
        }
        cout << val << ' ' << idx << el;
        st.insert(cur);
    }
}
