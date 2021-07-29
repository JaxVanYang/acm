/*
 * @Descripttion: 木棒
 * @Topic link: https://www.acwing.com/problem/content/169/
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-26 16:17:53
 * @LastEditTime: 2021-03-26 17:22:07
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 70;

int n, w[N];
bool used[N];
int len, sum, maxn;


bool dfs(int u, int t, int s){ // u为当前根数，t正在拼的木棍的当前长度，s为开始枚举的起点
// s为起点开始枚举，因为先放长度为x，再放y（x > y）和先放y再放x无区别，可将将排列型降为组合型
    if (u * len == sum) return true;
    if (t == len) return dfs(u + 1, 0, 0);
    
    for (int i = s; i < n; i ++){
        if (used[i] || t + w[i] > len) continue;
        
        used[i] = 1;
        if (dfs(u, t + w[i], s + 1)) return true;
        used[i] = false;
        
        if (!t) return false; // 如果尝试拼入的第一根木棍就失败，那么直接判断当前分治失败并回溯
        if (t + w[i] == len) return false; // 如果在当前木棒中插入最后一根木棍后木棒恰好被拼完整，
                                           // 且接下来拼剩余木棒失败，则直接判断当前分支失败

        int j = i;
        while (j < n && w[j] == w[i]) j ++; // 接下来相同长度的木棍必定也会失败
        i = j - 1;
    }

    return false;
}


int main(){

    while (cin >> n, n){
        memset(used, 0, sizeof used);
        sum = 0, maxn = 0;
        for (int i = 0; i < n; i ++) cin >> w[i], sum += w[i], maxn = max(maxn, w[i]);
        
        sort(w, w + n);
        reverse(w, w + n); // 木棒从大到小枚举

        len = maxn;
        while (1){
            if (sum % len == 0 && dfs(0, 0, 0)){
                cout << len << endl;
                break;
            }
            len ++;
        }
    }


    return 0;
}