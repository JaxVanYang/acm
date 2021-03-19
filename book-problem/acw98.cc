#include <cmath>
#include <iostream>
using namespace std;
using ll = long long;

pair<ll, ll> calc(int n, ll m) {
  if (!n) return make_pair(0, 0);
  ll len = 1ll << (n - 1), cnt = 1ll << (2 * n - 2);
  int a = m / cnt;
  ll b = m % cnt;
  auto pos = calc(n - 1, b);
  ll x = pos.first, y = pos.second;
  switch (a) {
    case 0:
      return make_pair(y, x);
    case 1:
      return make_pair(x, y + len);
    case 2:
      return make_pair(x + len, y + len);
    default:
      return make_pair(2 * len - y - 1, len - x - 1);
  }
}

ll dis(pair<ll, ll> &pos1, pair<ll, ll> &pos2) {
  return 10 * sqrt(pow(pos1.first - pos2.first, 2) +
                   pow(pos1.second - pos2.second, 2)) +
         0.5;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    ll n, a, b;
    scanf("%lld%lld%lld", &n, &a, &b);
    auto pos1 = calc(n, a - 1), pos2 = calc(n, b - 1);  // 将编号减 1 简化处理
    auto print = [](pair<ll, ll> &pos) {
      cout << pos.first << ", " << pos.second << endl;
    };
    print(pos1), print(pos2);
    printf("%lld\n", dis(pos1, pos2));
  }
}