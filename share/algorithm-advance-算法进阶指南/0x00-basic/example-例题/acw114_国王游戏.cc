#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

vector<int> mul(vector<int> &a, int b) {
    vector<int> ret;
    int t = 0;
    for (int i = 0; i < a.size(); ++i) {
        t += a[i] * b;
        ret.push_back(t % 10);
        t /= 10;
    }
    // Note: t may be greater than 9 here, because b can be 10 or larger
    while (t) {
        ret.push_back(t % 10);
        t /= 10;
    }
    return ret;
}

vector<int> div(vector<int> &a, int b) {
    vector<int> c;
    bool is_first = true;
    for (int i = a.size() - 1, t = 0; i >= 0; --i) {
        t = t * 10 + a[i];
        int x = t / b;
        if (!is_first || x) {
            is_first = false;
            c.push_back(x);
        }
        t %= b;
    }
    if (c.empty()) c.push_back(0);
    reverse(c.begin(), c.end());
    return c;
}

vector<int> max_vec(vector<int> &a, vector<int> &b) {
    if (a.size() > b.size()) return a;
    if (a.size() < b.size()) return b;
    if (vector<int>(a.rbegin(), a.rend()) < vector<int>(b.rbegin(), b.rend())) return b;
    return a;
}

void print(vector<int> num) {
    for (int i = num.size() - 1; i >= 0; --i) {
        printf("%d", num[i]);
    }
    puts("");
}

int main() {
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> arr(n + 1);
    for (int i = 0; i <= n; ++i) {
        scanf("%d%d", &arr[i].first, &arr[i].second);
    }
    sort(arr.begin() + 1, arr.end(), [](const pair<int, int> &x, const pair<int, int> &y) { return x.first * x.second < y.first * y.second; });

    auto pre = vector<int>{1};
    auto val = vector<int>{0};
    for (int i = 1; i <= n; ++i) {
        // pre *= arr[i - 1].first;
        pre = mul(pre, arr[i - 1].first);
        // ll new_val = pre / arr[i].second;
        vector<int> new_val = div(pre, arr[i].second);
        val = max_vec(val, new_val);
    }
    // printf("%lld\n", val);
    print(val);
}