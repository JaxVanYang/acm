#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

const int maxn = 1e6 + 100;
char s[maxn];

int n, k;
pair<int, int> guards[26];
const pair<int, int> zero = {0, 0};

template<typename T>
inline priority_queue<T, vector<T>, greater<T>> min_heap() {
    return priority_queue<T, vector<T>, greater<T>>();
}

int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", s);
    for (int i = 0; i < n; ++i) {
        int id = s[i] - 'A';
        if (guards[id] == zero) {
            guards[id] = {i, i + 1};
        } else {
            guards[id].second = i + 1;
        }
    }
    sort(guards, guards + 26);
    auto pq = min_heap<int>();
    int cnt = 0;
    for (int i = 0; i < 26; ++i) {
        // cout << "(" << guards[i].first << ", " << guards[i].second << ")" << endl;
        if (guards[i] == zero) {
            continue;
        }
        if (pq.empty() || pq.top() > guards[i].first) {
            ++cnt;
        } else {
            pq.pop();
        }
        pq.push(guards[i].second);
    }
    if (cnt > k) {
        puts("YES");
    } else {
        puts("NO");
    }
}