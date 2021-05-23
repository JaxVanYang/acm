#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool all_even = true;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        if (num & 1) {
            all_even = false;
        }
        sum = (sum + num) & 1;
    }
    if (sum) {
        puts("First");
    } else if (all_even) {
        puts("Second");
    } else {
        puts("First");
    }
}