/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-08-28 12:08:25
 * @LastEditTime: 2021-08-28 12:40:28
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <cmath>
#include <bitset>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T --){
        int x;
        cin >> x;
        if (x & 1){
            x ++;
            int t = x / 2;
            t = (x-t);
            int t2 = ceil((x-1)/3);
            if (t2 & 2 == 0) t2 ++;
            t += (x-t2 + 1)/2;
            cout << t << endl;
        }
        else {
            int t = 0;
            int t1 = x/2;
            t += (x-t1)-1;
            int t2 = ceil((x-1)/3);
            if (t2 % 2 == 0) t2 ++;
            t += (x- t2 + 1)/2;
            cout << t << endl;
        }
    }
    return 0;
}
