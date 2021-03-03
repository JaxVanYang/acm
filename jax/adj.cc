#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

const int maxn = 1e6;

vector<int> adj(int num) {
  vector<int> values;  // 逆序存储
  for (int i = 0; i < 6; ++i) {
    values.push_back(num % 10);
    num /= 10;
  }
  vector<int> ret;
  for (int i = 0; i < 6; ++i) {  // 遍历每一位
    int copys[3];
    copys[0] = values[i];      // 保存原值
    copys[1] = values[i] - 1;  // 保存修改值
    copys[2] = values[i] + 1;
    for (int j = 1; j <= 2; ++j) {
      if (0 <= copys[j] && copys[j] <= 9) {  //看是否越界
        values[i] = copys[j];
        int next = 0;
        int weight = 1;
        for (int k = 0; k < 6; ++k) {
          next += weight * values[k];
          weight *= 10;
        }
        ret.push_back(next);
      }
    }

    values[i] = copys[0];  // 改回原值
  }
  return ret;
}

int main() {
  // cout << "num = " << num.value << endl;

  vector<int> nums = adj(111111);
  for (auto num : nums) {
    cout << num << ' ';
  }
}