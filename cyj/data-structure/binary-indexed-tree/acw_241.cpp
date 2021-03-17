/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-17 16:57:14
 * @LastEditTime: 2021-03-17 20:42:46
 */
// /*
//  * @Descripttion: 树状数组基本应用——求逆序对
//  * @Topic link: https://www.acwing.com/problem/content/243/
//  * @Question meaning: 
//  * @Status: writing
//  * @Author: cyj
//  * @Date: 2021-03-17 16:57:14
//  * @LastEditTime: 2021-03-17 19:24:38
//  */

// #include <iostream>
// #include <algorithm>
// #include <cstring>
// #include <cstdio>
// #include <vector>
// #include <queue>
// #include <set>

// using namespace std;

// const int N = 2e5 + 5, mod = 1e9 + 7;
// typedef long long LL;
// typedef pair<int, int> PII;

// int n, a[N], more[N], less[N], tr[N];

// int lowbit(int x){
//     return x & -x;
// }

// void add(int x, int y){
//     int res = 0;
//     for (int i = x; i <= n; i += lowbit(i)) tr[i] += y;
// }

// int sum(int x){
//     int res = 0;
//     for (int i = x; i; i -= lowbit(i)) res += tr[i];
//     return res;
// }

// int main()
// {
//     cin >> n;
//     for (int i = 1 ; i <= n; i ++) cin >> a[i];
//     for (int i = 1; i <= n; i ++){
//         int t = a[i];
//         more[i] = sum(n) - sum(t + 1);
//         less[i] = sum(t ) - sum(1);
//     }
//     return 0;
// }
