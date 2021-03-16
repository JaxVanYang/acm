/*
 * @Descripttion: 
 * @Author: cyj
 * @Date: 2021-02-25 09:05:19
 * @LastEditTime: 2021-02-25 09:05:27
 */

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int ans = 0x7f7f7f7f;

class path {
 public:
  vector<int> cities;
  int sid = -1, tid = -1; 
  int price;
  
  path(int s, int t) { 
    int c_cnt;
    scanf("%d%d", &price, &c_cnt);
    int city;
    for (int j = 0; j < c_cnt; j ++) {
      scanf("%d", &city);
      if (city == s) {
        sid = j;
      } else if (city == t) {
        tid = j;
      }
      cities.push_back(city);
    }


    if (sid != -1 && tid != -1 && sid < tid) {
      ans = min(ans, price);
    }
  }
};


int main() {
  int s, t, n;
  scanf("%d%d%d", &s, &t, &n);
  vector<path> paths;
  for (int i = 0; i < n; i ++) {
    paths.push_back(path(s, t));
  }

  for (int i = 0; i < n; i ++) {
    for (int j = 0; j < n; j ++) {
      if (i == j) {
        continue;
      }
      if (paths[i].sid == -1 || paths[j].tid == -1) {
        continue;
      }
      set<int> st; 
      for (int k = paths[i].sid + 1; k < paths[i].cities.size(); k ++) {
        st.insert(paths[i].cities[k]);
      }

      for (int k = 0; k < paths[j].tid; k ++) {
        if (st.count(paths[j].cities[k])) {  
          ans = min(ans, paths[i].price + paths[j].price);
          break;
        }
      }
    }
  }

  if (ans != 0x7f7f7f7f) 
    printf("%d\n", ans);
  else
    printf("-1\n");
}
