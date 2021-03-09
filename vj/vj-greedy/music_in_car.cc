#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
int arr[200005];
int happy[200005];

inline long max(long x, long y) { return x > y ? x : y; }

int main() {
  long N, W, K;
  cin >> N >> W >> K;
  long result = 0, RESULT = 0;
  set<pair<int, int> > S_, S;  //分别代表半曲容器和整首容器
  for (int i = 1; i <= N; ++i) scanf("%d", happy + i);
  for (int i = 1; i <= N; ++i) scanf("%d", arr + i);
  int l, r;
  l = r = 1;
  while (r <= N) {
    // right pointer;
    while (r <= N) {
      if (W) {
        if (K >= (arr[r] + 1) / 2) {
          K -= (arr[r] + 1) / 2;
          RESULT = max(RESULT, result += happy[r]);
          S_.insert(make_pair(arr[r], r));
          r++;
          W--;
        } else
          break;  //行程结束
      } else      //如果w位置已满
      {
        int tmp = S_.begin()->first;
        if (tmp <= arr[r] &&
            K >= (arr[r] + 1) / 2 - (tmp + 1) / 2 +
                     tmp)  //如果当前的比半曲列表中时间最短的花费时间长，替换
        {
          K -= (arr[r] + 1) / 2 - (tmp + 1) / 2 + tmp;
          RESULT = max(RESULT, result += happy[r]);
          auto p = S_.begin();
          S.insert(*p);
          S_.erase(p);
          S_.insert(make_pair(arr[r], r));
          r++;
        } else if (
            tmp > arr[r] &&
            K >=
                arr[r])  //如果当前的比半曲列表中时间最短的还短，那么就把当前的短歌放入S
        {
          K -= arr[r];
          RESULT = max(RESULT, result += happy[r]);
          S.insert(make_pair(arr[r], r));
          r++;
        } else
          break;
      }
    }
    // left pointer;   K时间已经满了，从左边开始删除歌曲，以保证继续往后遍历
    if (l < r) {
      if (S.find(make_pair(arr[l], l)) != S.end()) {
        K += arr[l];
        result -= happy[l];
        S.erase(make_pair(arr[l], l));
      } else {
        K += (arr[l] + 1) / 2;
        result -= happy[l];
        S_.erase(make_pair(arr[l], l));
        W++;
        if (!S.empty()) {
          auto p = --S.end();
          K += p->first - (p->first + 1) / 2;
          S_.insert(*p);
          W--;
          S.erase(p);
        }
      }
      l++;
    } else
      l++, r++;
  }
  printf("%d\n", RESULT);
}