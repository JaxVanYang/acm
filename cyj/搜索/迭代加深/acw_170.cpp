/*
 * @Descripttion: 加成序列
 * @Topic link: https://www.acwing.com/problem/content/description/172/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-03-29 22:00:23
 * @LastEditTime: 2021-03-29 22:07:03
 */

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 110;

int a[N], cnt;
int n;

bool dfs(int u, int depth){
    // 注意这两个if判断的顺序，由于我们在外使用迭代加深层数来记录数组元素个数，
    // 即使下一个元素满足了我们也需要退出，加深最大层数后再判断，否则会少输出数
    if (u > depth) return false; // 如果层数超过最大层数且还未找到，退出
    if (a[u-1] == n) return true; // 
    bool st[N] = {0}; // 判重数组，排除等效冗余
    for (int i = u - 1; i >= 0; i --){ // 优化搜索顺序，先搜索分支较少的，更快接近并找到结果
        for (int j = i; j >= 0; j --){
            int s = a[i] + a[j];
            if (s > n || st[s] || s <= a[u-1]) continue;
            st[s] = true;
            a[u] = s; // 每次更新会覆盖原始值，不需要恢复现场
            if (dfs(u + 1, depth)) return true;
        }
    }
    return false;
}

int main(){
    
    a[0] = 1;
    while (cin >> n, n){
        int depth = 1;
        while (!dfs(1, depth)) depth ++;
        for (int i = 0; i < depth; i ++) cout << a[i] << ' '; // depth记录了找到时的深度
        cout << endl;
    }
    
    return 0;
}