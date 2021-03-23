/*
 * @Descripttion: 数独，从能填的合法数字最少的位置开始
 * @Topic link: https://www.acwing.com/problem/content/168/
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-03-23 16:58:23
 * @LastEditTime: 2021-03-23 16:59:11
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 9, M = 1 << N;

int r[N], c[N], g[N][N];
int map[M], ones[M];
char str[100];

void init(){
    for (int i = 0; i < N; i ++) r[i] = c[i] = (1 << N) - 1;
    for (int i = 0; i < 3; i ++){
        for (int j = 0; j < 3; j ++){
            g[i][j] = (1 << N) - 1;
        }
    }
}

void draw(int x, int y, int k, bool is_set){
    if (is_set) str[x * N + y] = '1' + k;
    else str[x * N + y] = '.';
    
    int v = 1 << k;
    if (is_set) v = -v;
    r[x] += v;
    c[y] += v;
    g[x/3][y/3] += v;
}

int get(int i, int j){
    return r[i] & c[j] & g[i/3][j/3];
}

int lowbit(int x){
    return x & -x;
}

bool dfs(int cnt){
    if (!cnt) return true;
    int minv = 10;
    int x, y;
    for (int i = 0; i < N; i ++){
        for (int j = 0; j < N; j++){
            if (str[i * N + j] == '.'){
                int state = get(i, j);
                if (ones[state] < minv){
                    minv = ones[state];
                    x = i, y = j;
                }
            }
        }
    }
    
    int state = get(x, y);
    
    for (int i = state; i ; i -= lowbit(i)){
        int t = map[lowbit(i)];
        draw(x, y, t, true);
        if (dfs(cnt - 1)) return true;
        draw(x, y, t, false);
    }
    
    return false;
}

int main(){
    for (int i = 0; i < N; i ++) map[1<<i] = i;
    for (int i = 0; i < M; i ++){
        for (int j = 0; j < N; j ++){
            ones[i] += i >> j & 1;
        }
    }
    
    while (cin >> str, str[0] != 'e'){
        init();
        int cnt = 0;
        for (int i = 0, t = 0; i < N; i ++){
            for (int j = 0; j < N ; j ++, t ++){
                if (str[t] != '.'){
                    int k = str[t] - '1';
                    draw(i, j, k, true);
                }
                else cnt ++;
            }
        }
        dfs(cnt);
        
        puts(str);
    }
    
    return 0;
}