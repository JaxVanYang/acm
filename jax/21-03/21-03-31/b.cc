#include <iostream>
#include <unordered_set>
using namespace std;

const int maxn = 1e5 + 5;
// int a[maxn];

int main() {
    int n;
    scanf("%d", &n);
    unordered_set<int> st;
    int num;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num);
        if (num != 0)
            st.insert(num);
    }
    printf("%d", (int)st.size());
    // for(int i = 0; i < n; ++i) scanf("%d", a + i);
}