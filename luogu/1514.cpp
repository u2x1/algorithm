#include <cstdio>
#include <cstring>
#include <queue>
#include <climits>
#include <algorithm>

#define cfor(i,a,b,s)  for(auto i=(a); i!=(b); i+=(s))
#define NL             putchar(10);

const int maxN = 510;

int m, n;
int arr[maxN][maxN]; bool vis[maxN][maxN];

struct Pt {int x,y;};
struct Rg {int l=INT_MAX,r=-1;} rgs[maxN];
bool operator<(const Rg a, const Rg b) {
  if (a.l == b.l) { return a.r < b.r; }
  return a.l < b.l;
}
int sxq[300000][2];
int head, tail;

void checkNpush(const int val, const int x, const int y) {
  if (x < 0 || x == m || y < 0 || y == n || vis[x][y]) { return; }
  if (val >= arr[x][y]) { return; }
  sxq[tail][0] = x; sxq[tail][1] = y; vis[x][y] = 1;
  tail++;
}

bool reach[maxN];

void search(const int y) {
  memset(vis, 0, sizeof(vis));
  head = 0; tail = 1;
  sxq[0][0] = m-1; sxq[0][1] = y; vis[m-1][y] = 1;
  while(head < tail) {
    const int xx = sxq[head][0], yy = sxq[head][1];
    ++head;
    if (!xx) {
      rgs[yy].l = std::min(rgs[yy].l, y);
      rgs[yy].r = std::max(rgs[yy].r, y);
      reach[y] = 1;
    }
    checkNpush(arr[xx][yy], xx+1, yy);
    checkNpush(arr[xx][yy], xx-1, yy);
    checkNpush(arr[xx][yy], xx, yy+1);
    checkNpush(arr[xx][yy], xx, yy-1);
  }
}

int main() {
  scanf("%d%d", &m, &n);
  cfor(i, 0, m, 1) {
    cfor(j, 0, n, 1) {
      scanf("%d", &(arr[i][j]));
    }
  }
  cfor(i, 0, n, 1) { search(i); }
  int failCnt=0; cfor(i, 0, n, 1) { failCnt+=!reach[i]; }
  if (failCnt) { printf("%d\n%d", 0, failCnt); return 0; }
  std::sort(rgs, rgs+n); int lastr = 0, maxR=-1;;
  int realAns = 0, left = 0, i = 0;
  while (left < n) {
    int maxr = -1;
    for(; i < n && rgs[i].l <= left; ++i) {
      maxr = std::max(maxr, rgs[i].r);
    }
    left = maxr + 1;
    ++realAns;
  }
  printf("1\n%d", realAns);
  return 0;
}
