#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1e5 + 10;
const int inf = 0x3f3f3f3f3f;
int tr[maxn << 2];
int x[maxn], y[maxn], vis[maxn];

#define lson (rt << 1)
#define rson (rt << 1 | 1)

void build(int rt, int l, int r){
    if(l == r){
        tr[rt] = 0;
        return ;
    }
    int mid = l + r >> 1;
    build(lson, l, mid), build(rson, mid+1, r);
    tr[rt] = min(tr[lson], tr[rson]);
}

void update(int rt, int l, int r, int pos, int d){
    if(l == r){
        tr[rt] = d;
        return ;
    }
    int mid = l + r >> 1;
    if(pos <= mid)update(lson, l, mid, pos, d);
    else update(rson, mid+1, r, pos, d);
    tr[rt] = min(tr[lson], tr[rson]);
}

int query(int rt, int l, int r, int L, int R, int d){
    if(l == r){
        if(tr[rt] <= d)return l;
        else return inf;
    }
    // cout << l << " " << r << " " << "**" << endl;
    int ret = inf, mid = l + r >> 1;
    if(L <= l && r <= R){
        if(tr[lson] <= d)ret = min(ret, query(lson, l, mid, L, R, d));
        else if(tr[rson] <= d)ret = min(ret, query(rson, mid + 1, r, L, R, d));
    }
    else{
        if(L <= mid)ret = min(ret, query(lson, l, mid, L, R, d));
        if(mid < R)ret = min(ret, query(rson, mid + 1, r, L, R, d));
    }
    return ret;
}

int main(){
    int k, n;
    scanf("%d%d", &k, &n);
    memset(tr, inf, sizeof tr);
    for(int i = 1; i <= n; i ++)scanf("%d%d", &x[i], &y[i]);
    build(1, 1, k);
    int maxx = -1;
    // cout << endl;
    for(int i = 1; i <= n; i ++){
        int pos = (i - 1) % k + 1;
        // cout << pos << " ";
        int t = query(1, 1, k, pos, k, x[i]);
        // cout << t << endl;
        if(t == inf)t = query(1, 1, k, 1, pos - 1, x[i]);
        if(t == inf)continue;
        // cout << t << endl;
        vis[t] ++, maxx = max(maxx, vis[t]);
        update(1, 1, k, t, x[i] + y[i]);
        // cout << "***" << endl;
    }
    vector<int> v;
    for(int i = 1; i <= n; i ++){
        if(vis[i]== maxx)v.push_back(i - 1);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i ++){
        printf("%d%c", v[i], (i == v.size() - 1) ? '\n' : ' ');
    }
    return 0;
}