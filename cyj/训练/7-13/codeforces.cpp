/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-07-13 09:48:49
 * @LastEditTime: 2021-07-13 09:51:14
 */
/*
 * @Descripttion: 
 链接：https://ac.nowcoder.com/acm/problem/21314
来源：牛客网

牛牛正在打一场CF
比赛时间为T分钟，有N道题，可以在比赛时间内的任意时间提交代码
第i道题的分数为maxPoints[i],题目的分数随着比赛的进行，每分钟减少pointsPerMinute[i]
这是一场比较dark的Cf，分数可能减成负数
已知第i道题需要花费 requiredTime[i] 的时间解决
请问最多可以得到多少分
 * @Topic link: https://ac.nowcoder.com/acm/problem/21314
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-07-13 09:48:49
 * @LastEditTime: 2021-07-13 09:48:50
 */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 55;

int n, score[N], decline[N], w[N], t;
long long f[100010];

struct stds{
    int id;
    double v;
    bool operator< (stds x) const { // 推导公式后得出 w / d比值小的选择优先级较高，然后做01背包即可
        return v < x.v;
    }
}s[N];

int main(){
    cin >> n >> t;
    for (int i = 1; i <= n; i ++) cin >> score[i];
    for (int i = 1; i <= n; i ++) cin >> decline[i];
    for (int i = 1; i <= n; i ++) cin >> w[i];
    for (int i = 1; i <= n; i ++) s[i].v = w[i] * 1.0 / decline[i], s[i].id = i;
    sort(s + 1, s + 1 + n);
    long long ans = 0;

    for (int i = 1; i <= n; i ++){
        for (int m = t; m >= w[s[i].id]; m --){
            f[m] = max(f[m], f[m - w[s[i].id]] + score[s[i].id] - decline[s[i].id] * m);
            ans= max(ans, f[m]);
        }
    }
//     cout << f[t] << endl;  由于存在 -declin[s[i].id] * m的影响， 并不是用时越多越好，状态表示第二维为所用时间
    cout << ans << endl;
    return 0;
}