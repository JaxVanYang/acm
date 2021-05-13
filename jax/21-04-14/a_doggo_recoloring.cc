#include <iostream>
using namespace std;
const int maxn = 1e5 + 5;
int cnts[26];
char s[maxn];

int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; ++i) {
        cnts[s[i] - 'a']++;
    }
    int cnt = 0, total = 0;
	bool has2 = false;
    for (int i = 0; i < 26; ++i) {
		if (cnts[i]) {
			++total;
		}
		if (cnts[i] >= 2) {
			has2 = true;
		} else if (cnts[i] == 1) {
			++cnt;
        }
    }
	if (total == 1 && cnt == 1) {
		puts("YES");
		return 0;
	}
    if (cnt == 0 || has2) {
	    puts("YES");
    } else {
	    puts("NO");
    }
}
