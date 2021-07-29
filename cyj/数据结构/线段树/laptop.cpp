/*
 * @Descripttion: 二维偏序问题，排序一个关键字降维后判断
 链接：https://ac.nowcoder.com/acm/contest/16/A?&headNav=www
来源：牛客网

FST是一名可怜的小朋友，他很强，但是经常fst，所以rating一直低迷。
但是重点在于，他非常适合ACM！并在最近的区域赛中获得了不错的成绩。
拿到奖金后FST决定买一台新笔记本，但是FST发现，在价格能承受的范围内，笔记本的内存和速度是不可兼得的。
可是，有一些笔记本是被另外一些“完虐”的，也就是内存和速度都不高于另外某一个笔记本，现在FST想统计一下有多少笔记本被“完虐”。
 * @Topic link: 
 * @Question meaning: 
 * @Status: 
 * @Author: cyj
 * @Date: 2021-07-23 21:04:15
 * @LastEditTime: 2021-07-23 21:06:07
 */

#include <iostream>
#include <cstring>
#include <algorithm>
#define x first
#define y second
using namespace std;

const int N = 1e5 + 10;

typedef pair<int, int > PII;
PII q[N], t[N];
int n, ans, tr[N];

int lowbit(int x){
    return x & -x;
}

void add(int x){
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += 1;
}

int sum(int x){
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++){
        scanf("%d%d", &q[i].x, &q[i].y);
        t[i].x = q[i].y, t[i].y = i;
    }
    sort(t+1, t + 1 + n);
    for (int i = 1; i <= n; i ++) q[t[i].y].y = i;
    sort(q + 1, 1 + q + n);
    for (int i = n; i ; i --){
        int t = q[i].y;
        if (sum(n) - sum(t)) ans ++; // 后面的第一维都是比他高的，若存在第二维也比他高的，则此电脑被完虐
        add(t);
    }
    printf("%d", ans);
    return 0;
}