/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-17 20:02:45
 * @LastEditTime: 2021-03-17 20:29:11
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// const int N = , mod = 1e9 + 7;
typedef long long LL;
typedef pair<int, int> PII;

int H, D, N;
double C;
int hh, mm;
const double eps = 1e-6;

double buy8(int more){
    if (more){
        return C * 0.8 * (H % N == 0 ? (H / N) : (H / N) + 1);
    }
    else {
        int t = (20 - hh) * 60 - mm;
        // cout << t << endl;
        int H1 = H + t * D;
        return C * 0.8 * (H1 % N == 0 ? H1 / N : H1 / N + 1);
    }
}

double buyn(){
    // cout << H << " " << N << endl;
    // cout << H / N << endl;
    return C * (H % N == 0 ? (H / N) : (H / N) + 1);
}

int main()
{
    double res = 0;
    cin >> hh >> mm;
    cin >> H >> D >> C >> N;
    if (hh >= 20){
        res = buy8(1);
    }else{
        res = min(buyn(), buy8(0));
    }

    printf("%.4lf", res);
    return 0;
}
