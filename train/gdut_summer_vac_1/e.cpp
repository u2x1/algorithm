#include <cstdio>
#include <algorithm>

#define NL putchar(10);

const int maxN = 5e3+5;

int num[maxN][maxN];

int main() {
  int n, m; scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    int x, y, v; scanf("%d%d%d", &x, &y, &v);
    num[x+1][y+1] = v;
  }

  for(int x = 1; x < maxN; ++x) {
    for(int y = 1; y < maxN; ++y) {
      num[x][y] += num[x][y-1];
    }
  }

  for(int x = 1; x < maxN; ++x) {
    for(int y = 1; y < maxN; ++y) {
      num[x][y] += num[x-1][y];
    }
  }

  int max = -1;
  for(int x = maxN-1; x >= m; --x) {
    for(int y = maxN-1; y >= m; --y) {
      int cur = num[x][y] + num[x-m][y-m] - num[x][y-m] - num[x-m][y];
      max = std::max(max, cur);
    }
  }

  printf("%d", max);

  return 0;
}
