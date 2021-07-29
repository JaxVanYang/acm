/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-04-14 19:31:30
 * @LastEditTime: 2021-04-14 19:47:27
 */

#include <iostream>
#include <cstring>
#include <set>
using namespace std;

const int N = 1e5+ 10;
set<char> s;
int main(){

int n;
   string a;
   cin >> n >> a;
   if (n == 1){
       cout << "YES" << endl;
       return 0;
   }
   for (int i = 0; i < a.size(); i ++){
       if (!s.count(a[i])) s.insert(a[i]);
   }
    if (s.size() == n) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}