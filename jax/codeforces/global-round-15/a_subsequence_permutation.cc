// Verbose template for CP
// You can create a snippet for this in VS Code

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using pi = pair<int, int>;

#define REP(i, l, r) for (int i = l; i < r; ++i)
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
const int N = 1e6 + 10;

template<typename T>
void print(T &v) {
    for (auto val : v) cout << val << ' ';
    cout << el;
}
template<typename T>
istream &operator>>(istream &in, vector<T> &v) {
    for (auto &each : v) in >> each;
    return in;
}
template<typename T>
ostream &operator<<(ostream &out, vector<T> &v) {
    for (auto &each : v) out << each << ' ';
    return out;
}

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	string t = s;
	sort(s.begin(), s.end());
	int ans = 0;
	REP(i, 0, n) {
		if (s[i] != t[i]) ++ans;
	}
	cout << ans << el;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
