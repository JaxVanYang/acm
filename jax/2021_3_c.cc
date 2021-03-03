#include <iostream>
#include <vector>
using namespace std;

const int mod = 1e9 + 7;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> ps{0}, pos{0}, pois{0};
  for (auto &ch : s) {
    int pCnt = ps.back(), poCnt = pos.back(), poiCnt = pois.back();
    ps.push_back(ps.back());
    pos.push_back(pos.back());
    pois.push_back(pois.back());
    if (ch == 'p')
      ps.back() = (ps.back() + 1) % mod;
    else if (ch == 'o')
      pos.back() = (pos.back() + ps.back()) % mod;
    else if (ch == 'i')
      pois.back() = (pos.back() + pois.back()) % mod;
    else if (ch == '*') {
      ps.back() = (pCnt * 3 % mod + 1) % mod;
      pos.back() = (poCnt * 3 % mod + pCnt) % mod;
      pois.back() = (poiCnt * 3 % mod + poCnt) % mod;
    }
  }
  cout << pois.back() << endl;
}