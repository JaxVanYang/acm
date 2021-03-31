#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 105;

int main() {
    int n;
    cin >> n;
    char s[maxn];
    scanf("%s", s);
    vector<int> divs;
    for (int i = 1; i <= n; ++i) if (n % i == 0) divs.push_back(i);
    for (auto &each : divs) {
        reverse(s, s + each);
    }
    puts(s);
}