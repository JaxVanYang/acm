/*
 * @Descripttion: 
 这个难题是这样子的：给出一个 1 到 n 的排列，现在对这个排列序列进行 m 次局部排序，排序分为两种：

0 l r 表示将区间 [l,r] 的数字升序排序
1 l r 表示将区间 [l,r] 的数字降序排序
注意，这里是对下标在区间 [l,r] 内的数排序。
最后询问第 q 位置上的数字。

    建立n颗权值线段树，动态开点，用set维护每个有序区间的左右端点与此区间权值线段树的根节点，当对某个区间排序时，
根据lower_bound找到其左右端点所在的区间，若被某个区间包含，则将此区间线段树分裂，并将端点加入set维护，对于最后
的查询，将询问点单独分为一个区间查询即可，此做法还可以处理询问区间第k大
 * @Topic link: https://www.luogu.com.cn/problem/P2824
 * @Question meaning: 
 * @Status: Accepted
 * @Author: cyj
 * @Date: 2021-08-19 19:33:00
 * @LastEditTime: 2021-08-19 19:34:53
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#define IT set<node>::iterator
using namespace std;

const int N = 1e5 + 10, M = N * 20;

int n, m, nodes[M], tt, w[N], tot, rubbish[M], times;
struct Tree {
    int l, r;
    int num;
}tr[M];

struct node{
    int l, r, root, st;
    bool operator< (const node& m) const {
        return l < m.l;  // 根据区间左端点排序即可
    }
};
set<node> s;

int New(){
    if (tot) return rubbish[tot --]; 
    else return ++ tt;
}

void Del(int & now){
    tr[now].l = tr[now].r = tr[now].num = 0;  // 垃圾回收机制
    rubbish[++ tot] = now;
    now = 0;
}

void pushup(int u){
    tr[u].num = tr[tr[u].l].num + tr[tr[u].r].num;
}

void insert(int &q, int l, int r, int x){
    if (!q) q = New();
    if (l == r){
        tr[q].num ++;
        return;
    }
    int mid = l + r >> 1;
    if (x <= mid) insert(tr[q].l, l, mid, x);
    else insert(tr[q].r, mid + 1, r, x);
    pushup(q);
}

int find(int p, int l, int r){
    if (l == r) return l;
    int mid = l + r >> 1;
    if (tr[tr[p].l].num) return find(tr[p].l, l, mid);
    else return find(tr[p].r, mid + 1, r);
}

void Split(int &p, int &q, int l, int r, int k){
    // times ++;
    if (k <= 0 || k > tr[p].num) return;
    if (!p) return;
    // 此处分裂不同于板子，是按个数分裂，对此区间左端的k个数均分给q
    if (tr[p].num <= k){  // 若p的个数小于等于k，则将其划给q
        q = p;
        p = 0;
        return;
    }
    if (!q) q = New();
    int mid = l + r >> 1;
    int t = tr[tr[p].l].num;
    if (t >= k) Split(tr[p].l, tr[q].l, l, mid, k);
    else Split(tr[p].l, tr[q].l, l, mid, t);
    if (k > t) Split(tr[p].r, tr[q].r, mid + 1, r, k-t);
    pushup(p), pushup(q);
}

void Merge(int &p, int &q, int l, int r){
    // times ++;
    if (!p || !q){
        p += q;
        return;
    }
    if (l == r){
        tr[p].num += tr[q].num;
        Del(q);
        return;
    }
    int mid = l + r >> 1;
    Merge(tr[p].l, tr[q].l, l, mid), Merge(tr[p].r, tr[q].r, mid + 1, r);
    pushup(p), Del(q);
}

void nodesplit(int l, int r, int ope){
    // 找到左端点大于等于l的区间，若区间左端点大于l，则l在上个区间内部，迭代器--
    IT it = s.lower_bound((node){l, 0, 0, 0});
    if (it->l != l){
        it --;
        int q = 0;
        // 指针不太懂怎么用，这里不用node代替直接传指针进函数会报错，好像指针指向处不满足修改？
        // 但我们传入的是引用，需要修改值
        node now = *it; 
        s.erase(it);
        if (!it->st){  // 若区间为升序，我们需要后面这么多个数，否则需要前面那么多个数
            Split(now.root, q, 1, n, l - now.l);
            s.insert((node){l, now.r, now.root, 0});
            s.insert((node){now.l, l-1, q, 0});
        }
        else {
            Split(now.root, q, 1, n, now.r-l+1);
            s.insert((node){now.l, l-1, now.root, 1});
            s.insert((node){l, now.r,q, 1});
        }
    }
    // 由于排序方式为左端点大小，直接查询左端点>=r+1的区间，r必为此区间的前一个区间
    it = s.lower_bound((node){r+1, 0, 0, 0});
    it --;
    if (it->r != r){ // 若右端点不等于r，则r必在此区间内部
        int q = 0;
        node now = *it;
        s.erase(it);
        if (!it->st){
            Split(now.root, q, 1, n, r - now.l + 1);
            s.insert((node){now.l, r, q, 0});
            s.insert((node){r+1, now.r, now.root, 0});
        }
        else {
            Split(now.root, q, 1, n, now.r - r);
            s.insert((node){now.l, r, now.root, 1});
            s.insert((node){r+1, now.r, q, 1});
        }
    }
    // 同理，此时已经存在以l为左端点的区间以及以r为右端点的区间，合并中间区间即可
    IT itl = s.lower_bound((node){l, 0, 0, 0}), itr = s.lower_bound((node){r+1, 0, 0, 0});
    int q = 0;
    auto t = itl;
    while (itl != itr){
        // times ++;
        auto node = *itl;
        Merge(q, node.root, 1, n);
        // 此处需要注意用t来记录s中要删除的区间，直接删itl之后再itl++会出错，指针什么的太麻烦了
        itl ++;
        s.erase(t);
        t = itl;
    }
    s.insert((node){l, r, q, ope}); // 插入合并后的新区间
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++){
        scanf("%d", &w[i]);
        int q = 0;
        insert(q, 1, n, w[i]);
        s.insert((node){i, i, q, 0}); // 建树，开始默认都为升序
    }
    for (int i = 1; i <= m; i ++){
        int l, r, op;
        scanf("%d%d%d", &op, &l, &r);
        nodesplit(l, r, op);
    }
    int q;
    scanf("%d", &q);
    nodesplit(q, q, 0);
    IT it = s.lower_bound((node){q, 0, 0, 0});
    node now = *it;
    printf("%d\n", find(now.root, 1, n));
    // cout << times << endl;
    return 0;
}