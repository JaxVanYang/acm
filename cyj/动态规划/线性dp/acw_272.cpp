/*
 * @Descripttion: 最长公共上升子序列
 * @Topic link: https://www.acwing.com/activity/content/35/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-04-10 09:16:44
 * @LastEditTime: 2021-04-10 09:25:09
 */

#include <iostream>
#include <cstdio>

using namespace std;

const int N = 3e3 + 10;

int f[N][N];
int a[N], b[N];
int n;

int main(){
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    for (int i = 1; i <= n; i ++) cin >> b[i];
    
    for (int i = 0; i <= n; i ++) f[i][0] = 0;
    for (int i = 1; i <= n; i ++){
        int maxr = 1;
        for (int j = 1; j <= n; j ++){
            f[i][j] = f[i-1][j];
            // 关键优化，由于每次决策候选集合只有一个数进入且没有弹出，而我们维护的仅为一个
            // 最大值，所以可以用一个int变量来记录，降低一个维度
            // 在一个阶段i中，只有a[i]==b[j]时才更新，虽然b[j]一直在变，但阶段a[i]不变
            if (b[j-1] < a[i]) maxr = max(maxr, f[i-1][j-1] + 1);
            if (a[i] == b[j]){
                f[i][j] = max(f[i][j], maxr);
            }
        }
    }
    
    int res = 0;
    for (int i = 1; i <= n; i ++) res = max(res, f[n][i]);
    cout << res << endl;
    
    
    return 0;
}