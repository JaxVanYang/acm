#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

const int mod = 1e9 + 7;

int main() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  ll ps = 0, pos = 0, pois = 0;
  ll cnt = 1;
  for (auto &ch : s) {
    // 记录前一个前缀和
    ll pCnt = ps, poCnt = pos, poiCnt = pois;
    if (ch == 'p')
      ps = (ps + cnt) % mod;
    else if (ch == 'o')
      pos = (pos + ps) % mod;
    else if (ch == 'i')
      pois = (pois + pos) % mod;
    else if (ch == '*') {
      ps = (pCnt * 3 % mod + cnt) % mod;
      pos = (poCnt * 3 % mod + pCnt) % mod;
      pois = (poiCnt * 3 % mod + poCnt) % mod;
      cnt = cnt * 3 % mod;
    }
  }
  cout << pois << endl;
}