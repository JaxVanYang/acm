#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using pi = pair<int, int>;
template<typename T> using Heap = priority_queue<T, vector<T>, greater<T>>;

#define F first
#define S second
#define PF push_fornt
#define PB push_back
#define MP make_pair
#define Sort(v) sort(v.begin(), v.end())
#define Unique(v) unique(v.begin(), v.end())
#define Lower(v, val) lower_bound(v.begin(), v.end(), val)
#define Upper(v, val) upper_bound(v.begin(), v.end(), val)
#define Reverse(v) reverse(v.begin(), v.end())

const char el = '\n';
clock_t startTime;
inline double getCurTime() {
return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

template<typename T> istream &operator>>(istream &in, vector<T> &v) { for (auto &each : v) in >> each; return in; }
template<typename T, typename U> istream &operator>>(istream &in, pair<T, U> &p) { return in >> p.F >> p.S; }
template<typename T> ostream &operator<<(ostream &out, vector<T> &v) { for (auto &each : v) out << each << ' '; return out; }
template<typename T, typename U> ostream &operator<<(ostream &out, pair<T, U> p) { return out << p.F << ' ' << p.S; }
template<typename T> void read(T &t) {
    t = 0; int k = -1;
    char ch = getchar();
    while (ch <= ' ') ch = getchar();
    if (ch == '-') k = 1, ch = getchar();
    while (isdigit(ch)) t = t * 10 - ch + '0', ch = getchar();
    t *= k;
}
template<typename T, typename ...Args> void read(T &t, Args &...args) { read(t), read(args...); }

const int N = 1e5 + 10;
char s[N];

int main() {
    // startTime = clock();
    
    int n;
    read(n);

    scanf("%s", s);

    vector<int> twos, els;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '2') {
            twos.push_back(i);
        } else {
            els.push_back(i);
        }
    }

    int c = (n - 13) / 2;

    if (twos.size() <= c) {
        puts("orz");
        return 0;
    }

    if (twos[c] - c <= c) {
        puts("yyds");
    } else {
        puts("orz");
    }
}