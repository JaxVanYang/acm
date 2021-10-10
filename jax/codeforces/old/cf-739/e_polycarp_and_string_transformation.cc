#include <iostream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

bool check(const string &s, const string &res, const string &seq) {
	string t;
	set<char> st;
	for (char ch : seq) {
		for (int i = 0; i < s.size(); ++i) {
			if (!st.count(s[i])) {
				t.push_back(s[i]);
			}
		}
		st.insert(ch);
	}
	return t == res;
}

void solve() {
	string res;
	cin >> res;
	map<char, int> mp;
	for (char ch : res) {
		mp[ch]++;
	}
	string seq, s;
	set<char> st;
	map<char, int> cnt;
	for (int i = res.size() - 1; i >= 0; --i) {
		if (!st.count(res[i])) {
			seq.push_back(res[i]);
			if (mp[res[i]] % (mp.size() - st.size())) {
				cout << -1 << endl;
				return;
			}
			cnt[res[i]] = mp[res[i]] / (mp.size() - st.size());
			st.insert(res[i]);
		}
	}
	reverse(seq.begin(), seq.end());
	for (int i = 0; i < res.size(); ++i) {
		cnt[res[i]]--;
		if (cnt[res[i]] == -1) break;
		s.push_back(res[i]);
	}
	if (!check(s, res, seq)) {
		cout << -1 << endl;
		return;
	}
	cout << s << ' ' << seq << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
