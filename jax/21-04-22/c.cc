#include <iostream>
#include <vector>
using namespace std;
const int maxn = 105;

int main() {
    int n;
    cin >> n;
    vector<int> neg, zero, pos;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (num < 0) {
            neg.push_back(num);
        } else if (num == 0) {
            zero.push_back(num);
        } else {
            pos.push_back(num);
        }
    }
    printf("1 %d\n", neg.back());
    neg.pop_back();
    if (neg.size() & 1) {
        zero.push_back(neg.back());
        neg.pop_back();
    }
    printf("%ld ", pos.size() + neg.size());
    for (int num : pos) {
        printf("%d ", num);
    }
    for (int num : neg) {
        printf("%d ", num);
    }
    puts("");
    printf("%ld ", zero.size());
    for (int num : zero) {
        printf("%d ", num);
    }
    puts("");
}