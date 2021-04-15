/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-04-07 20:07:58
 * @LastEditTime: 2021-04-07 20:35:06
 */

#include <iostream>
#include <limits.h>

using namespace std;

const int N = 1e5 + 10;

int a[N], b[N];

int main(){

    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i] >> b[i];
    int last = INT_MAX;
    for (int i = 1; i <= n; i ++){
        int t = max(a[i], b[i]), u = min(a[i], b[i]);
        if (t <= last){
            last = t;
            continue;
        } else if (u <= last){
            last = u;
            continue;
        }
        else {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}