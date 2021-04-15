/*
 * @Descripttion: 字符串
 * @Topic link: https://codeforces.ml/contest/1504
 * @Question meaning: 
 * 一个字符串中1与0相等的前缀可进行操作使得0->1，1->0，
 * 求让字符串a经过最少多少次操作能变为字符串b，不能则输出NO
 * 从后往前做，后面判断完之后对前面不再有影响，只需要记录前面是否反转即可
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-04-10 22:48:09
 * @LastEditTime: 2021-04-12 10:42:14
 */

#include <iostream>
#include <cstdio>

using namespace std;
const int N = 3e5 + 10;
int n;
bool st[N]; // 记录一个位置是否能进行反转操作
int sum[N]; // 前缀和
string a, b;

int main(){
    
    int T;
    cin >> T;
    while (T --){
        cin >> n >> a >> b;
        for (int i = 0; i <= n; i ++) st[i] = 0; // 重新初始化st数组
        if (n & 1 && a[n-1] != b[n-1]){ // 如果长度为奇数且最后一个字符不相等，则一定无法成功
            puts("NO");
            continue;
        }
        if (n & 1) --n; // 奇数 --n
        for (int i = 1; i <= n; i++){
            sum[i] = sum[i-1] + a[i-1] - '0';
            if (sum[i] * 2 == i) st[i] = 1; // 前缀中1的数目等于0数目
        }
        bool rever = 0, suc = true; // rever为是否需要反转
        for (int i = n - 2; i >= 0; i -= 2){
            if (rever){
                a[i] = a[i] == '0' ? '1' : '0';
                a[i + 1] = a[i + 1] == '0' ? '1' : '0';
            }
            if (a[i] == b[i] && a[i + 1] == b[i + 1] ) continue;
            // 如果刚好相反且可以进行反转操作
            else if (a[i] != b[i] && a[i + 1] != b[i + 1] && st[i + 2]){
                rever ^= 1;
            }
            else { // 01/10对00/11，反转后也必不可能相等
                suc = false;
                break;
            }
        }
        if (suc) cout << "YES"  << endl;
        else cout << "NO" << endl;;
    }

    return 0;
}