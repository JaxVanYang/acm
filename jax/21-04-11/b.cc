#include <iostream>
#include <set>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], b[maxn];

int main() {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        b[i] = x & a[i];
    }

    set<int> st;
    for (int i = 0; i < n; ++i) {
        if (st.count(a[i])) {
            puts("0");
            return 0;
        }
        st.insert(a[i]);
    }

    for (int i = 0; i < n; ++i) {
        st.erase(a[i]);
        if (st.count(b[i])) {
            puts("1");
            return 0;
        }
        st.insert(a[i]);
    }

    st.clear();
    for (int i = 0; i < n; ++i) {
        if (st.count(b[i])) {
            puts("2");
            return 0;
        }
        st.insert(b[i]);
    }

    puts("-1");
}