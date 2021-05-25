#include <iostream>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    if (a == b) {
        puts("-1");
    } else {
        printf("%ld\n", max(a.length(), b.length()));
    }
}