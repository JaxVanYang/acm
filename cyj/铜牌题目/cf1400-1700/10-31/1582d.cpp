/*
 * @Descripttion: 分别讨论n为奇偶时
        偶数个时前后直接乘对方即可，
        奇数只需讨论最后三个，两个和不为0的看作一个与另一个相乘
 * @Topic link: 
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-10-31 20:51:59
 * @LastEditTime: 2021-10-31 21:11:13
 */

#include <iostream>
#include <cstdio>
#include <map>

using namespace std;
const int N = 1e5 + 10;
int a[N], n;

int main(){
    int T;
    cin >> T;
    while (T --){
        scanf("%d", &n);
        for (int i = 1;  i<= n; i ++) scanf("%d", &a[i]);
        if (n % 2 == 0){
            for (int i = 1;  i<= n; i ++){
                if (i & 1) cout << a[i+1] << ' ';
                else cout << -a[i-1] << ' ';
            }
            cout << '\n';
        }else {
            for (int i = 1; i <= n-3; i ++){
                if (i & 1) cout << a[i+1] << ' ';
                else cout << -a[i-1] << ' ';
            }
            int t1 = a[n-2] + a[n-1], t2 = a[n-2] + a[n], t3 = a[n-1] + a[n];
            if (t1) cout << a[n] << ' ' << a[n] << ' ' << -t1 << endl;
            else if (t2) cout << a[n-1] << ' ' << -t2 << ' ' << a[n-1] << endl;
            else cout << -t3 << ' ' << a[n-2] << ' ' << a[n-2] << endl;

        }
    }
    return 0;
}