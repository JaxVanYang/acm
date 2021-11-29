#include <iostream>
#include <set>

const int N = 1e3 + 10;
int n, d;
int id[N], cnt[N];

int find(int p) {
    if (id[p] != p) id[p] = find(id[p]);
    return id[p];
}

void un(int p, int q) {
    int i = find(p), j = find(q);
    if (i == j) return;
    id[i] = j;
    cnt[j] += cnt[i];
}

int main() {
    scanf("%d%d", &n, &d);
    std::set<std::pair<int, int>> st;
    for (int i = 1; i <= n; ++ i) {
        id[i] = i, cnt[i] = 1;
        st.insert({1, i});
    }


    int c = 1;
    for (int i = 0; i < d; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        int a = find(x), b = find(y);
        if (a == b) {
            ++c;
        } else {
            st.erase({cnt[a], a});
            st.erase({cnt[b], b});
            un(a, b);
            int idx = find(x);
            st.insert({cnt[idx], idx});
        }

        int ans = 0;
        auto ptr = st.rbegin();
        for (int j = 0; j < c; ++j) {
            ans += ptr->first;
            ++ptr;
        }
        printf("%d\n", ans - 1);
    }
}