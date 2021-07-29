/*
 * @Descripttion: 
 * @Topic link: https://vjudge.net/contest/433419#problem/D
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-04-14 20:35:41
 * @LastEditTime: 2021-04-15 09:41:01
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;
const int N = 3e5 + 10;
priority_queue<int, vector<int>, greater<int>> R;
priority_queue<int> L;
PII p[N];
int main(){
    
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> p[i].x >> p[i].y;
        R.push(p[i].y), L.push(p[i].x); // 维护左端点最大值以及右端点最小值
    }

    int maxn = 0; // 考虑最差可能为0
    for (int i = 1; i <= n; i ++){
        bool l = 0, r = 0; // 记录是否需要加回左右端点
        if (p[i].x == L.top()){ // 如果当前点的左端点就是左边界，弹出队首后次左端点成为边界
            L.pop();
            l = 1;
        }
        if (p[i].y == R.top()){
            R.pop();
            r = 1;
        }
        maxn = max(maxn, R.top() - L.top()); // 更新去除线段i后的并集最大值
        if (l) L.push(p[i].x);
        if (r) R.push(p[i].y);
    }
    
    cout << maxn << endl;
    return 0;
}