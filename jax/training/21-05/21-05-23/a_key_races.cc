#include <iostream>
using namespace std;

int main() {
    int s, v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    int len1 = v1 * s + t1 * 2;
    int len2 = v2 * s + t2 * 2;
    if (len1 < len2) {
        puts("First");
    } else if (len1 > len2) {
        puts("Second");
    } else {
        puts("Friendship");
    }
}