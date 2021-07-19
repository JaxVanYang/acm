/* 
 * 贪心策略：
 *
 * 1. 将牛按吃草时间递增排序
 * 2. 维护一个数组记录每个畜栏中牛最后的吃草时间，初始为空
 * 3. 依次处理每头牛，找到一个满足条件的畜栏将这头牛放进去，如果没有就新建一个
 * 4. 最后的数组长度即为答案
 * 
 * 正确性证明（微扰，范围放缩，决策包容性）：
 * 
 * 1. 依次处理每头牛时，要么不存在可放的畜栏，要么存在一个或多个可放的畜栏
 * 2. 如果不存在，那就只能新建畜栏
 * 3. 如果存在，因为牛已经有序，所以后面的牛也可以使用这些可放的畜栏。
 *    假如这头牛的结束时间晚于后面牛的开始时间，选择已存在的畜栏只会让后面的少一个可选的畜栏，
 *    如果这些畜栏已经可以容纳完，显然是最优解，如果后面有头牛必须新增一个畜栏，
 *    达成的局面也可以从当前牛选择新增畜栏扩展而来（只考虑畜栏的可选性）；
 *    假如这头牛的结束时间早于后面牛的开始时间，选择已存在的畜栏并不会减少后面的可选畜栏，
 *    后面需要新增的话也可以从当前牛选择新增扩展而来。
 */

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int N = 5e4 + 5;
// 通过 a[i].second 确定牛在排序之前的位置
pair<pair<int, int>, int> a[N];
int ans[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].first.first, &a[i].first.second);
        a[i].second = i;
    }
    sort(a, a + n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    for (int i = 0; i < n; ++i) {
        if (q.size() && q.top().first < a[i].first.first) {
            int id = q.top().second;
            q.pop();
            q.push(make_pair(a[i].first.second, id));
            ans[a[i].second] = id;
        } else {
            int id = q.size() + 1;
            ans[a[i].second] = id;
            q.push(make_pair(a[i].first.second, id));
        }
    }
    
    printf("%lu\n", q.size());
    for (int i = 0; i < n; ++i) {
        printf("%d\n", ans[i]);
    }
}