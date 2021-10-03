#include <iostream>
#include <cstring>
using namespace std;

const int N = 1e6 + 10;
char s[N];

int main() {
    scanf("%s", s);
    int n = strlen(s);

    int ones = 0, c = 0;

    for (int i  = 0; i < n; ++i) {
        if (s[i] == '1') {
            ones = (ones + 1) % 3;
        } else {
            c = (c + ones) % 3;
        }
    }

    if (c) {
        puts("Alice");
    } else {
        puts("Bob");
    }
}