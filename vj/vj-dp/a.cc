#include <iostream>
using namespace std;
typedef long long ll;
int main() {
  int t;
  cin >> t;
  ll n;
  while (t--) {
    cin >> n;
    cout << 2 * n * n - n + 1 << endl;
  }
  return 0;
}