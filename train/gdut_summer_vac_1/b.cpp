#include <cstdio>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          putchar(10);

const int maxN = 7;
int arr[maxN][maxN];

int sx, sy, ex, ey;
int n, m, t; 
bool vis[maxN][maxN];

int dfs(int x, int y) {
  if (x <= 0 || x > n || y <= 0 || y > m) { return 0; }
  if (arr[x][y] || vis[x][y]) { return 0; }
  if (x==ex && y==ey) { return 1; }
  vis[x][y] = 1;
  int cur =
      dfs(x+1, y)
    + dfs(x-1, y)
    + dfs(x, y+1)
    + dfs(x, y-1);
  vis[x][y] = 0;
  return cur;
}

int main() {
  scanf("%d%d%d", &n, &m, &t);
  scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
  orep(i, 0, t) {
    int x,y; scanf("%d%d", &x, &y);
    arr[x][y] = 1;
  }

  printf("%d", dfs(sx, sy));

  return 0;
}
