/*
 * @Descripttion: 
 * @Topic link: https://www.acwing.com/problem/content/526/
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-17 23:43:03
 * @LastEditTime: 2021-07-17 23:44:41
 */
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 20, M = 1 << 18;
#define x first
#define y second
const double eps = 1e-8;
typedef pair<double, double> pdd;
pdd p[N];
int f[1<<N];
int path[N][N];
int n, m, ans;

int cmp(double x, double y){
    if (fabs(x-y) < eps) return 0;
    else {
        if (x < y) return -1;
        else return 1;
    }
}
int t = 0;
void dfs(int state, int cnt){
    if (state == (1 << n) - 1) {
        ans = min(ans, cnt);
        return;
    }
    for (int j = 0; j < n; j ++){
        if (!(state >> j & 1)){
            for (int k = 0; k < n; k ++){
                if ((state | path[j][k]) > state) dfs(path[j][k] | state, cnt + 1);
            }
        }
    }
}

int main(){
    int T;
    cin >> T;
    while ( T --){
        n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++){
            cin >> p[i].x >> p[i].y;
        }
        memset(path, 0 ,sizeof path);
        for (int i = 0; i < n; i ++){
            path[i][i] = 1 << i;
            for (int j = 0; j < n; j ++){
                double x1 = p[i].x, y1 = p[i].y, x2 = p[j].x, y2 = p[j].y;
                if (!cmp(x1, x2)) continue;
                double a = (y1 / x1 - y2 / x2) / (x1-x2), b = y1/x1 - a*x1;
                if (cmp(a, 0) >= 0) continue;
                for (int k = 0; k < n; k ++){
                    if (!cmp(p[k].x * p[k].x * a + b * p[k].x, p[k].y)) {
                        
                        path[i][j] += 1 << k;
                    }
                }
            }
        }
        ans = 1e9;
        // dfs(0, 0);

        memset(f, 0x3f, sizeof f);
        f[0] = 0;
        for (int i = 0; i + 1 < 1 << n; i ++){
            int x = 0;
            for (int j = 0; j < n; j ++){
                if (!(i>>j & 1)){
                    x = j;
                    break;
                }
                
                
            }
            for (int j = 0; j < n; j ++){
                f[i | path[x][j]] = min(f[i | path[x][j]], f[i] + 1);
            }
        }
        cout << f[(1 << n) - 1] << endl;
    }
    
    return 0;
}