/*
 * @Descripttion: 
 * @Topic link: 
 * @Question meaning: 
 * 给定n个矩形的左下角坐标与右上角坐标，求去掉一个矩形后剩下n-1个矩形的交矩形的任一点（保证必定有解）
 * 预处理前缀交矩形与后缀交矩形
 * 枚举每个除去的矩形的前缀和后缀交矩形是否不为空
 * @Status: 
 * @Author: cyj
 * @Date: 2021-04-07 20:15:51
 * @LastEditTime: 2021-04-15 10:42:00
 */
#include <iostream>
#include <cstring>

using namespace std;

const int N = 140000;
struct point{
    int x1, y1, x2, y2;
    point operator+ (const point & m) const{
        return (point){max(x1, m.x1), max(y1, m.y1), min(x2, m.x2), min(y2, m.y2)};
    }
}a[N], b[N], p[N]; // a为前缀交集，即前i个矩形的交集矩形，b为后缀交集
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i ++){
        cin >> p[i].x1 >> p[i].y1 >> p[i].x2 >> p[i].y2;
    }
    a[1] = p[1];
    for (int i = 2; i <= n; i ++) a[i] = a[i-1] + p[i]; // 处理前缀
    b[n] = p[n];
    for (int i = n - 1; i; i --) b[i] = b[i + 1] + p[i]; // 处理后缀
    for (int i = 1; i <= n; i ++){
        point cur;
        if (i == 1) cur = b[2];
        else if (i == n) cur = a[n-1];
        else {
            cur = a[i-1] + b[i+1]; 
        }
        if (cur.x1 <= cur.x2 && cur.y1 <= cur.y2){
            cout << cur.x1 << ' ' << cur.y1 << endl;
            break;
        }
    }
    return 0;
}