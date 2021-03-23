#include <iostream>
#include <vector>

using namespace std;

class UF {
 public:
  vector<int> id;
  vector<int> cnts;
  UF(int n) {
    cnts = vector<int>(n, 1);
    for (int i = 0; i < n; ++i) {
      id.push_back(i);
    }
  }

  int find(int p) {
    if (p != id[p]) {
      id[p] = find(id[p]);
    }
    return id[p];
  }

  void un(int p, int q) {
    int pId = find(p), qId = find(q);
    if (pId == qId) return;
    if (cnts[pId] < cnts[qId]) {
      id[pId] = qId;
      cnts[qId] += cnts[pId];
    } else {
      id[qId] = pId;
      cnts[pId] += cnts[qId];
    }
  }
};

int main() {
  int n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  UF uf = UF(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    uf.un(a - 1, b - 1);
  }
  for (int i = 0; i < q; ++i) {
    int x;
    scanf("%d", &x);
    x -= 1;
    int cnt = 0, xId = uf.find(x);
    cnt = n - uf.cnts[xId];
    printf("%d\n", cnt);
  }
}