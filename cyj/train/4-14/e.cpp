/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-04-14 21:13:25
 * @LastEditTime: 2021-04-14 21:15:13
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <bitset>

using namespace std;

const int N = 140000, mod = 1e9 + 7;
typedef long long LL;

struct point{
    int x1, x2, y1, y2;
}p[N];

int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> p[i].x1 >> p[i].y1 >> p[i].x2 >> p[i].y2;
    }
    
    return 0;
}
