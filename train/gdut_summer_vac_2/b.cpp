#include <cstdio>
#include <algorithm>

#define orep(i,l,r) for(int i = (l); i < (r); ++i)
#define NL          putchar(10);

const int maxN = 1e2+5;
int dp[maxN][maxN];
int arr[maxN][maxN];

int r,c;
int dfs(int x, int y, int val) {
  if (x < 0 || x > r || y < 0 || y > c) { return 0; }
  if (arr[x][y] <= val) { return 0; }
  if (dp[x][y]) { return dp[x][y]; }
  const int n = arr[x][y];
  return dp[x][y] = 1 + std::max({dfs(x-1,y,n), dfs(x+1,y,n), dfs(x,y+1,n), dfs(x,y-1,n)});
}

int main() {
  scanf("%d%d", &r, &c);
  orep(i, 0, r) {
    orep(j, 0, c) { 
      scanf("%d", &arr[i][j]);
    }
  }

  int ret = 0;
  orep(i, 0, r) {
    orep(j, 0, c) { 
      ret = std::max(dfs(i, j, -1), ret);
    }
  }
  printf("%d", ret);

  return 0;
}
