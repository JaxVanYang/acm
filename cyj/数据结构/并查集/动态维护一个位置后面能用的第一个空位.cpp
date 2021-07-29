/*
 * @Descripttion: 
 链接：https://ac.nowcoder.com/acm/problem/50437
来源：牛客网

    tokitsukaze有n个数，需要按顺序把他们插入哈希表中，哈希表的位置为0到n-1。
    插入的规则是：
    刚开始哈希表是空的。
    对于一个数x，在哈希表中，如果(x mod n)的位置是空的，就把x放在(x mod n)的位置上。
    如果不是空的，就从(x mod n)往右开始找到第一个空的位置插入。
    若一直到n-1都不是空的，就从位置0开始继续往右找第一个空的位置插入。
    因为哈希表总共有n个空位，需要插入n个数，所以每个数都能被插入。
    现在tokitsukaze想知道把这n个数按顺序插入哈希表后，哈希表中的每个位置分别对应的是哪个数。
 * @Topic link: 
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-07-27 21:17:11
 * @LastEditTime: 2021-07-27 21:17:11
 */

#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1e6 + 10;

int p[N], pos[N];
int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) p[i] = i;
    int t;
    for (int i = 1; i <= n; i ++){       
        scanf("%d", &t);
        int a = find(t % n);
        pos[a] = t;
        p[a] = (a + 1) % n;
    }
    for (int i = 0; i < n; i ++) printf("%d ", pos[i]);
    return 0;
}