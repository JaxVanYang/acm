/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-23 19:06:56
 * @LastEditTime: 2021-03-23 22:17:35
 */
 /*
  * @Descripttion: 
  * @Topic link: 
  * @Question meaning: 
  * @Status: 
  * @Author: cyj
  * @Date: 2021-03-23 19:06:56
  * @LastEditTime: 2021-03-23 21:55:45
  */

 #include <iostream>
 #include <cstdio>
 #include <algorithm>

 using namespace std;

 const int N = 110;

 int n, s;
 int a[N];

 int main(){

     cin >> n >> s;
     for (int i = 0; i < n; i ++){
         int h, m;
         cin >> h >> m;
         a[i] = h * 60 + m;
     }
     int last = a[0], res = 0;
     if (a[0] >= s + 1) {
         cout << 0 << " " << 0 << endl;
         return 0;
     }
     bool flag = true;
     for (int i = 1; i < n; i ++){
         if (a[i] - last >= 2 * s + 2){ // 错误处，
             res = last + 1 + s;
             flag = false;
             break;
         }
         else last = a[i];
     }
     if (flag) res = a[n-1] + s + 1;

     cout << res/60 << " " << res % 60 << endl;

     return 0;
 }