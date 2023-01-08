#include <cstdio>

#define NL putchar(10);

const int maxN = 1e3+5;
int num[maxN][maxN];

int main() {
  int n, m; scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    num[x1][y1]++;
    num[x1][y2+1]--;
    num[x2+1][y1]--;
    num[x2+1][y2+1]++;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      num[i][j] += num[i][j-1];
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      num[i][j] += num[i-1][j];
    }
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      printf("%d ", num[i][j]);
    } NL;
  }


  return 0;
}
