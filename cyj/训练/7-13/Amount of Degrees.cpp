/*
 * @Descripttion: 
 * @Topic link: https://ac.nowcoder.com/acm/contest/973/A
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-13 11:43:31
 * @LastEditTime: 2021-07-13 11:45:20
 */

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 35;

int f[N][N];
int l, r, k, b;

void init(){
    for (int i = 0; i < N; i ++){
        for (int j = 0; j <= i; j++){
            if (!j) f[i][j] = 1;
            else f[i][j] = f[i-1][j] + f[i-1][j-1];
        }
    }
}

int dp(int x){
    if (!x) return 0;
    vector<int> nums;
    while (x) nums.push_back(x % b), x /= b;
    int res = 0, last = 0;
    for (int i = nums.size()-1; i >= 0; i --){
        int v = nums[i];
        if (v){
            res += f[i][k-last];
            if (v > 1){ // 若该数大于1，则右方分支不存在
                if (k - last - 1 >= 0) res += f[i][k-last-1];
                break;
            }
            else {
                last ++;
                if (last > k) break;
            }
        }
        if (!i && last == k) res ++; // 最右端合法性的判断
    }
    return res;
}

int main(){
    cin >> l >> r >> k >> b;
    init();
    cout << dp(r) - dp(l-1) << endl;
    
    return 0;
}