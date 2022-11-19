#include <cstdio>
#include <queue>

#define cfor(i,a,b,s)  for(auto i=(a); i!=(b); i+=(s))
#define NL             putchar(10);

const int maxN = 410;

int step[maxN][maxN];
int n, m, x, y;
struct Pt{ int x, y, t; };

bool vis[maxN][maxN];

std::queue<Pt> sxq;

void checkAndPush(const int x, const int y, const int t) {
  if (x < 0 || y < 0 || x >= n || y >= m || vis[x][y]) { return; }
  sxq.push({x,y,t});
  vis[x][y] = 1;
}

void search() {
  sxq.push({x,y,0}); vis[x][y] = 1;
  while(sxq.size()) {
    const int xx = sxq.front().x, yy = sxq.front().y, tt = sxq.front().t;
    sxq.pop();
    step[xx][yy] = tt;
    checkAndPush(xx+2,yy+1,tt+1);
    checkAndPush(xx+2,yy-1,tt+1);
    checkAndPush(xx-2,yy+1,tt+1);
    checkAndPush(xx-2,yy-1,tt+1);
    checkAndPush(xx+1,yy+2,tt+1);
    checkAndPush(xx+1,yy-2,tt+1);
    checkAndPush(xx-1,yy+2,tt+1);
    checkAndPush(xx-1,yy-2,tt+1);
  }
}

int main() {
  scanf("%d%d%d%d", &n, &m, &x, &y);
  --x; --y;
  cfor(i, 0, n, 1) {
    cfor(j, 0, m, 1) {
      step[i][j] = -1;
    } NL;
  }
  search();
  cfor(i, 0, n, 1) {
    cfor(j, 0, m, 1) {
      printf("%d ", step[i][j]);
    } NL;
  }
  return 0;
}
