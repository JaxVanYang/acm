#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
const int maxn = 1e9 + 5;

struct Num {
  int val, cnt;
  Num(int &val, int &cnt) : val(val), cnt(cnt) {}
  bool operator<(Num &num) { return val < num.val; }
};

int main() {
  int n;
  scanf("%d", &n);
  ll size = 0;
  ll maxCnt = 0;
  vector<Num> nums;
  for (int i = 0; i < n; ++i) {
    int cnt, len;
    scanf("%d%d", &cnt, &len);
    size += cnt * len;
    for (int j = 0; j < len; ++j) {
      int num;
      scanf("%d", &num);
      nums.push_back(Num(num, cnt));
    }
  }

  sort(nums.begin(), nums.end());

  int val = nums[0].val;
  ll cnt = 0;
  for (auto num : nums) {
    if (num.val == val) {
      cnt += num.cnt;
    } else {
      cnt = num.cnt;
      val = num.val;
    }
    maxCnt = max(maxCnt, cnt);
  }

  if (maxCnt * 2 > size) {
    cout << (size - maxCnt) * 2 << endl;
  } else {
    cout << size << endl;
  }
}