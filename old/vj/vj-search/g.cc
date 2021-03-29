#include <iostream>
#include <vector>
using namespace std;
int board[4][4];

bool check() {
  int mask;
  for (int i = 0; i < 4; ++i) {
    mask = 1 << 4 - 1;
    for (int j = 0; j < 4; ++j) {
      mask &= ~(1 << board[i][j]);
    }
    if (mask) return false;
  }
  for (int i = 0; i < 4; ++i) {
    mask = 1 << 4 - 1;
    for (int j = 0; j < 4; ++j) {
      mask &= ~(1 << board[j][i]);
    }
    if (mask) return false;
  }
  for (int i = 0; i <= 2; i += 2) {
    for (int j = 0; j <= 2; j += 2) {
      mask = 1 << 4 - 1;
      mask &= ~(1 << board[i][j]);
      mask &= ~(1 << board[i + 1][j]);
      mask &= ~(1 << board[i][j + 1]);
      mask &= ~(1 << board[i + 1][j + 1]);
      if (mask) return false;
    }
  }
  return true;
}
bool flag = false;
void dfs(int row, int col) {
  if (flag) return;
  if (row < 0 || col < 0 || row >= 4 || col >= 4) return;
  if (row == 3 && col == 3 && check()) {
    
  }
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i < t; ++i) {
    char ch;
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        scanf("%c", &ch);
        board[i][j] = ch == '*' ? 0 : ch - '0';
      }
    }
    dfs(0, 0);
    printf("Case #%d:\n", i);
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        printf("%d", board[i][j]);
      }
      putchar('\n');
    }
  }
}