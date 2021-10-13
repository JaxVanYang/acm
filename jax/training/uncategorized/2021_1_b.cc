#include <iostream>
#include <vector>

using namespace std;

class UF {
public:
    vector<int> id;
    vector<int> sz;
    UF(int n) {
        id.resize(n + 1);
        sz.assign(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            id[i] = i;
        }
    }
    int find(int p) {
        if (p != id[p]) {
            id[p] = find(id[p]);
        }
        return id[p];
    }
    void un(int p, int q) {
        int pId = find(p), qId = find(q);
        if (sz[pId] > sz[qId]) {
            id[qId] = pId;
            sz[pId] += sz[qId];
        } else {
            id[pId] = qId;
            sz[qId] += sz[pId];
        }
    }
};

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    UF uf(n);
    while (m--) {
        int x, y;
        cin >> x >> y;
        uf.un(x, y);
    }
    vector<int> must(k);
    for (int i = 0; i < k; ++i) {
        cin >> must[i];
    }
    int id = uf.find(must[0]);
//    cout << "id = " << id << endl;
    for (int i = 1; i < k; ++i) {
//        cout << uf.find(must[i]) << endl;
        if (uf.find(must[i]) != id) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
