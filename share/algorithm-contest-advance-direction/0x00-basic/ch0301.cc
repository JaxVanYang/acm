#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> chosen;
void dfs(int i) {
    if (i == n + 1) {
        if (chosen.size()) cout << chosen[0];
        for (int i = 1; i < chosen.size(); ++i) {
            cout << ' ' << chosen[i];
        }
        cout << endl;
        return;
    }
    dfs(i + 1);
    chosen.push_back(i);
    dfs(i + 1);
    chosen.pop_back();
}
int main() {
    cin >> n;
    dfs(1);
}