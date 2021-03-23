#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
const int INF = 0x3f3f3f;  //无穷大
using namespace std;
typedef long long ll;
int T;
int N, X, Y, MAXH;
// 0表示第i个平台最左边到底的最短时间
// 1表示第i个平台最右边到底的最短时间
int dp[1010][2];
struct node {
  int x1, x2, h;
};
bool cmp(node a, node b)  //根据h从大到小排列
{
  return a.h > b.h;
}
node a[1010];
void LeftTime(int i)  //左
{
  int k = i + 1;
  while (k < N + 1 && a[i].h - a[k].h <= MAXH) {
    if (a[i].x1 >= a[k].x1 && a[i].x1 <= a[k].x2) {
      dp[i][0] =
          a[i].h - a[k].h +
          min(dp[k][0] + a[i].x1 - a[k].x1, dp[k][1] + a[k].x2 - a[i].x1);
      return;
    }
    k++;
  }
  if (a[i].h - a[k].h > MAXH)  //不能到达下一平台
    dp[i][0] = INF;
  else  //直接落地
    dp[i][0] = a[i].h;

  return;
}
void RightTime(int i)  //右
{
  int k = i + 1;
  while (k < N + 1 && a[i].h - a[k].h <= MAXH) {
    if (a[i].x2 >= a[k].x1 && a[i].x2 <= a[k].x2) {
      dp[i][1] =
          a[i].h - a[k].h +
          min(dp[k][0] + a[i].x2 - a[k].x1, dp[k][1] + a[k].x2 - a[i].x2);
      return;
    }
    k++;
  }
  if (a[i].h - a[k].h > MAXH)  //不能到达下一平台
    dp[i][1] = INF;
  else  //直接落地
    dp[i][1] = a[i].h;

  return;
}
int main() {
  cin >> T;
  while (T--) {
    memset(dp, 0, sizeof(dp));
    a[0].x1 = -20000, a[0].x2 = 20000, a[0].h = 0;  //大地
    cin >> N >> X >> Y >> MAXH;
    a[1].x1 = X, a[1].x2 = X, a[1].h = Y;  //初始位置
    for (int i = 2; i <= N + 1; i++) {
      cin >> a[i].x1 >> a[i].x2 >> a[i].h;
    }
    sort(a, a + N + 2, cmp);
    for (int i = N; i >= 0; i--) {
      LeftTime(i);   //左
      RightTime(i);  //右
    }
    int MinTime = min(dp[0][0], dp[0][1]);
    cout << MinTime << endl;
  }
  return 0;
}