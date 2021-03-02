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

class Num {
 public:
  // 逆序存储每一位
  vector<int> values;
  int value;
  Num(int num) {
    value = num;
    for (int i = 0; i < 6; ++i) {
      values.push_back(num % 10);
      num /= 10;
    }
  }

  Num(vector<int> values) : values(values) {
    value = 0;
    for (int i = 0; i < 6; ++i) {
      value += values[i] * pow(10, i);
    }
  }

  inline bool operator<(const Num &num) { return value < num.value; }

  vector<Num> adj() {
    vector<Num> ret;
    int a = values[5], b = values[4], c = values[3], d = values[2],
        e = values[1], f = values[0];
    // cout << "a = " << a << " b = " << b << " c = " << c << " d = " << d << "
    // e = " << e << endl;
    if (0 <= a - 1) ret.push_back(Num({f, e, d, c, b, a - 1}));
    if (0 <= b - 1) ret.push_back(Num({f, e, d, c, b - 1, a}));
    if (0 <= c - 1) ret.push_back(Num({f, e, d, c - 1, b, a}));
    if (0 <= d - 1) ret.push_back(Num({f, e, d - 1, c, b, a}));
    if (0 <= e - 1) ret.push_back(Num({f, e - 1, d, c, b, a}));
    if (0 <= f - 1) ret.push_back(Num({f - 1, e, d, c, b, a}));
    if (f + 1 <= 9) ret.push_back(Num({f + 1, e, d, c, b, a}));
    if (e + 1 <= 9) ret.push_back(Num({f, e + 1, d, c, b, a}));
    if (d + 1 <= 9) ret.push_back(Num({f, e, d + 1, c, b, a}));
    if (c + 1 <= 9) ret.push_back(Num({f, e, d, c + 1, b, a}));
    if (b + 1 <= 9) ret.push_back(Num({f, e, d, c, b + 1, a}));
    if (a + 1 <= 9) ret.push_back(Num({f, e, d, c, b, a + 1}));
    // for (auto num : ret) {
    //   cout << num.value << ' ';
    // }
    // cout << endl << endl;
    return ret;
  }
};

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

int bfs(deque<Num> &curs, set<int> &st) {
  int n = curs.size();
  for (int i = 0; i < n; ++i) {
    Num cur = curs.front();
    // cout << cur.value << ' ';
    if (isP(cur.value)) return cur.value;
    curs.pop_front();
    vector<Num> nexts = cur.adj();
    for (auto &next : nexts) {
      if (st.count(next.value)) continue;
      curs.push_back(next);
      st.insert(next.value);
    }
  }
  sort(curs.begin(), curs.end());
  // for (auto &num : curs) {
  //   cout << num.value << ' ';
  // }
  // cout << endl << endl;
  return bfs(curs, st);
}

int main() {
  // cout << "num = " << num.value << endl;
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

    deque<Num> curs;
    curs.push_back(Num(num));
    set<int> st;
    st.insert(num);
    int ans = bfs(curs, st);
    printf("%d\n", ans);
  }
  return 0;
}