#include <iostream>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);

	while (t--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);

		int x = max(0, -a + max(b, c) + 1);
		int y = max(0, -b + max(c, a) + 1);
		int z = max(0, -c + max(b, a) + 1);

		printf("%d %d %d\n", x, y, z);
	}
}
