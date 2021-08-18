#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int LMT = 1e6 + 5;
const int N = 1 << 16;
int v[N];
vector<int> primes;
int l, r;
bool mark[LMT];

void solve() {
    memset(mark, 0, sizeof mark);
    if (l == 1) mark[0] = 1;
    vector<int> ps;
    for (int prime : primes) {
        if (r / 2 < prime) break;
        int begin = ((ll)l + prime - 1) / prime;
        if (begin == 1) ++begin;
        int end = r / prime;
        for (int i = begin; i <= end; ++i) {
            mark[i * prime - l] = 1;
        }
    }
    for (int i = 0; i < r - l + 1; ++i) {
        // cout << "mark[" << i << "] = " << mark[i] << endl;
        if (mark[i] == 0) {
            ps.push_back(i + l);
        }
    }
    // cout << "ps.size = " << ps.size() << endl;
    // cout << ps[0] << ' ' << ps[1] << ' ' << ps[2] << endl;
    if (ps.size() < 2) {
        cout << "There are no adjacent primes." << endl;
    } else {
        int min_dis = ps[1] - ps[0], max_dis = min_dis;
        int a = ps[0], b = ps[1], c = ps[0], d = ps[1];
        for (int i = 1; i < ps.size(); ++i) {
            int dis = ps[i] - ps[i - 1];
            if (dis < min_dis) {
                min_dis = dis;
                a = ps[i - 1], b = ps[i];
            } 
            if (dis > max_dis) {
                max_dis = dis;
                c = ps[i - 1], d = ps[i];
            }
        }
        cout << a << "," << b << " are closest, " << c << "," << d << " are most distant." << endl;
    }
}

int main() {
    for (int i = 2; i < N; ++i) {
        if (v[i] == 0) {
            v[i] = i;
            primes.push_back(i);
        }
        for (int prime : primes) {
            if (prime > v[i] || prime >= N / i) break;
            v[i * prime] = prime;
        }
    }
    // cout << "primes.size = " << primes.size() << endl;
    while (cin >> l >> r) {
        solve();
    }
}