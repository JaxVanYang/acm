#include <iostream>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int x[10], y[10];
    for (int i = 0; i < n; ++i) scanf("%d", x + i);
    for (int i = 0; i < m; ++i) scanf("%d", y + i);
    set<int> st;
    for (int i = 0; i < m; ++i) st.insert(y[i]);
    for (int i = 0; i < n; ++i) if (st.count(x[i])) cout << x[i] << ' ';
    
}