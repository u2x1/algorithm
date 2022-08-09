//QQ 1351966042
//ID U2FsdGVkX1
#include <cstdio>

#define orep(i,a,b)  for(int i=(a); i< (b); ++i)
#define crep(i,a,b)  for(int i=(a); i<=(b); ++i)
#define abs(a)       ((a) < 0 ? -(a) : a)
#define min(a,b)     ((a)<(b)?(a):(b))
#define min3(a,b,c)  min(min(a,b),c)
#define max(a,b)     ((a)>(b)?(a):(b))
#define max3(a,b,c)  max(max(a,b),c)
#define HIT          printf("entered <%s> at ln:%d\n", __FUNCTION__, __LINE__); fflush(stdout);
#define PTD(v)       printf(#v ": %d\t", v); fflush(stdout);
#define PTC(v)       printf(#v ": %c\t", v); fflush(stdout);
#define NL           putchar(10);
#define REDIR        freopen("../../data.in", "r", stdin);

int n, m, k, cnt;

void dfs(int *arr, const int x, const int y, const int prev) {
  if (x < 0 || y < 0 || x >= n || y >= m) { return; }
  const int curr = *(arr+x*m+y); if (curr == -1) { return; }
  if (abs(curr-prev) >= k) { return; }
  *(arr+x*m+y) = -1; ++cnt;
  dfs(arr, x+1, y, curr);
  dfs(arr, x-1, y, curr);
  dfs(arr, x, y+1, curr);
  dfs(arr, x, y-1, curr);
}

int main() {
  scanf("%d%d", &n, &m);
  int arr[n][m];
  int startx, starty;
  scanf("%d%d%d", &startx, &starty, &k); --startx; --starty;
  orep(i, 0, n) {
    orep(j, 0, m) {
      scanf("%d", &arr[i][j]);
    }
  }
  dfs((int*)arr, startx, starty, arr[startx][starty]);

  printf("%d", cnt);

  return 0;
}
