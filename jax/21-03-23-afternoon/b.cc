#include <iostream>
#include <unordered_set>
using namespace std;
using ll = long long;

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int i = 0;
    unordered_set<int> st;
    st.insert(0);
    ll sum = 0;
    for (; i < n; ++i) {
        int a;
        scanf("%d", &a);
        sum += a;
        a = sum % m;
        if (st.count(a)) {
            printf("YES");
            return 0;
        }
        st.insert(a);
    }
    printf("NO");
}