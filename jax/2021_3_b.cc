#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

const int maxn = 1e6;

set<int> primes;

bool isPrime(int num) {
  for (int i = 2; i * i <= num; ++i) {
    if (num % i == 0) {
      return false;
    }
  }
  return true;
}

inline bool isP(int num) { return primes.count(num); }

int distance(int a, int b) {
  int ret = 0;
  while (a > 0 || b > 0) {
    ret += abs((a % 10) - (b % 10));
    a /= 10;
    b /= 10;
  }
  return ret;
}

vector<int> adj(int num) {
  vector<int> values;  // 逆序存储
  for (int i = 0; i < 6; ++i) {
    values.push_back(num % 10);
    num /= 10;
  }
  vector<int> ret;
  for (int i = 0; i < 6; ++i) {
    int copys[3];
    copys[0] = values[i];
    copys[1] = values[i] - 1;
    copys[2] = values[i] + 1;
    for (int j = 1; j <= 2; ++j) {
      if (0 <= copys[j] && copys[j] <= 9) {
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

    values[i] = copys[0];
  }
  return ret;
}


int bfs(priority_queue<int, vector<int>, greater<int>> curs, set<int> &st) {
  priority_queue<int, vector<int>, greater<int>> nexts;
  while (curs.size()) {
    int cur = curs.top();
    curs.pop();
    if (isP(cur)) return cur;
    vector<int> nums = adj(cur);
    for (auto &num : nums) {
      if (st.count(num)) continue;
      nexts.push(num);
      st.insert(num);
    }
  }
  return bfs(nexts, st);
}

int main() {
  for (int i = 2; i <= maxn; ++i) {
    if (isPrime(i)) {
      primes.insert(i);
    }
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int num;
    scanf("%d", &num);
    if (num == maxn) {
      printf("2\n");
      continue;
    }

    if (isP(num)) {
      printf("%d\n", num);
      continue;
    }

    if (num == 1000000) return 2;

    // deque<Num> curs;
    priority_queue<int, vector<int>, greater<int>> curs;
    curs.push(num);
    set<int> st;
    st.insert(num);
    int ans = bfs(curs, st);
    printf("%d\n", ans);
  }
  return 0;
}