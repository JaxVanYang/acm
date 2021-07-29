/*
 * @Descripttion: 
 链接：https://ac.nowcoder.com/acm/contest/973/E
来源：牛客网

杭州人称那些傻乎乎粘嗒嗒的人为62（音：laoer）。
杭州交通管理局经常会扩充一些的士车牌照，新近出来一个好消息，以后上牌照，不再含有不吉利的数字了，这样一来，就可以消除个别的士司机和乘客的心理障碍，更安全地服务大众。
不吉利的数字为所有含有4或62的号码。例如：62315,73418,88914都属于不吉利号码。但是，61152虽然含有6和2，但不是62连号，所以不属于不吉利数字之列。
你的任务是，对于每次给出的一个牌照区间号，推断出交管局今后又要实际上给多少辆新的士车上牌照了
 * @Topic link: 
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-13 16:14:50
 * @LastEditTime: 2021-07-13 16:15:01
 */

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

const int N = 12;

int f[N][11];
int l, r;

void init(){
    for (int i = 0; i <= 9; i ++){
        if (i == 4) continue;
        f[1][i] = 1;
    }
    for (int i = 2; i < N; i ++){
        for (int j = 0; j <= 9; j ++){
            for (int k = 0; k <= 9; k ++){
                if ((j == 6 && k == 2 )|| j == 4) continue;
                f[i][j] += f[i-1][k];
            }
        }
    }
}

int dp(int x){
    if (!x) return 1;
    vector<int> nums;
    while (x) nums.push_back(x % 10), x/= 10;
    int res = 0, pre = 0;
    for (int i = nums.size()-1; i >= 0; i --){
        int v = nums[i];
        for (int j = 0; j < v; j ++){
            if (j == 4 || (j == 2 && pre == 6)) continue;
            res += f[i + 1][j];
        }
        if (v == 4 || (v == 2 && pre == 6)) break;
        pre = v;
        if (!i) res ++;
    }
    return res;
}

int main(){
    init();
    while (cin >> l >> r, l || r){
        cout << dp(r) - dp(l-1) << endl;
    }
    
    return 0;
}