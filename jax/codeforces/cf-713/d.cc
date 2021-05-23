#include <iostream>
#include <set>
#include <numeric>
using namespace std;
using ll = long long;

const int maxn = 2e5 + 5;
int b[maxn];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n + 2; ++i) {
    scanf("%d", b + i);
  }
  multiset<int> st(b, b + n + 2);
  // cout << "begin = " << st.size() << endl;
  ll sum = accumulate(b, b + n + 2, 0ll);
  for (int i = 0; i < n + 2; ++i) {
    sum -= b[i];
    st.erase(st.find(b[i]));
    if (sum % 2 == 0 && sum <= 2e9 && st.find(sum / 2) != st.end()) {
      // st.erase(sum / 2);
      st.erase(st.find(sum / 2));
      // cout << "st.size = " << st.size() << endl;
      for (auto num : st) {
        printf("%d ", num);
      }
      puts("");
      return;
    }
    st.insert(b[i]);
    sum += b[i];
  }
  puts("-1");
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}