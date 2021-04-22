/*
 * @Descripttion: D. 3-Coloring
 * @Topic link: https://codeforces.ml/contest/1504/problem/D
 * @Question meaning: 
 * 交互题
 * 等价于在一个n*n的国际象棋棋盘中放置棋子，每次给一个数1,2,3，
 * 从除给定数外的另两数中取一个数放入棋盘中，要求无两数相邻，其实就是按照国际象棋盘下就行了
 * 放1与2，有一个放满了且不让放另外一个数时我们放3就可以了
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-04-12 21:25:50
 * @LastEditTime: 2021-04-13 16:51:20
 */

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> PII;
const int N = 105, M = N * N;

vector<PII> w, b; // vector存储黑白两种放置点的集合
int p[M]; // 存储每次交互不能放的值
int n;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1, k = 1; i <= n; i ++){
        for (int j = 1; j <= n; j ++, k ++){
            if ((i + j) % 2) w.push_back({i, j});
            else b.push_back({i, j});
        }
    }
    int cho = 0, full = 0; // cho记录放什么，full记录是否有点放满了
    for (int i = 1; i <= n * n; i ++){
        cin >> p[i];
        if (p[i] == 1){
            if (!w.empty()) cho = 2; // 2的位置不为空
            else full = 2, cho = 3; // 2满了，在1的位置放3
        }else if (p[i] == 2){
            if (!b.empty()) cho = 1; // 1的位置不空
            else full = 1, cho = 3; // 1满了，在2的位置放3
        }
        else {
            if (!b.empty()) cho = 1; // 为3时看哪里没放满就放哪里
            if (!w.empty()) cho = 2;
        }
        if (cho == 1){
            cout << cho << ' ' << b.back().first << ' ' << b.back().second << endl;
            b.pop_back();
        }else if (cho == 2) {
            cout << cho << ' ' << w.back().first << ' ' << w.back().second << endl;
            w.pop_back();
        }else {
            if (full == 1) {
                cout << cho << ' ' << w.back().first << ' ' << w.back().second << endl;
                w.pop_back();
            }else {
                cout << cho << ' ' << b.back().first << ' ' << b.back().second << endl;
                b.pop_back();
            }
        }
    }

    return 0;
}