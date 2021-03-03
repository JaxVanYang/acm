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
    // 记录前一个前缀和
    int pCnt = ps.back(), poCnt = pos.back(), poiCnt = pois.back();
    if (ch == 'p')
      ps.push_back((ps.back() + 1) % mod);
    else if (ch == 'o')
      pos.push_back((pos.back() + ps.back()) % mod);
    else if (ch == 'i')
      pois.push_back((pos.back() + pois.back()) % mod);
    else if (ch == '*') {
      ps.push_back((pCnt * 3 + 1) % mod);
      pos.push_back((poCnt * 3 + pCnt) % mod);
      pois.push_back((poiCnt * 3 + poCnt) % mod);
    }
  }
  cout << pois.back() << endl;
}