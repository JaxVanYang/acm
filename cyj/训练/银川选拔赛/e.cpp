/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-04-28 08:05:57
 * @LastEditTime: 2021-05-08 15:14:00
 */

#include <iostream>
#include <map>

using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
int a[N], s[N];
map<int , int> m;
int main(){

    int n, v;
    cin >> n >> v;
    int x;
    for (int i = 1; i <= n; i ++){
        cin >> a[i];
        if (a[i] > v) a[i] = 1;
        else if (a[i] < v) a[i] = -1;

        if (a[i] == v) a[i] = 0, x = i;
    }
    for (int i = 1; i <= n; i ++) s[i] = s[i-1] + a[i];
    for (int i = 0; i < x; i ++){
        m[s[i]] ++;
    }
    LL res = 0;
    for (int i = x; i <= n; i ++){
        int t = s[i];
        if (m.count(t)) res += m[t];
    }
    cout << res << endl;

    return 0;
}