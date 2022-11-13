#include <cstdio>
#include <queue>

#define cfor(i,a,b,s)  for(auto i=(a); i!=(b); i+=(s))
#define NL             putchar(10);

const int maxN = 305;

int m;
bool willRuin[maxN][maxN], vis[maxN][maxN];
int ruinAt[maxN][maxN];

struct Pos{int x, y, t;};
std::queue<Pos> sxq;

bool check(const int x, const int y) {
  if (x < 0 || y < 0) { return 0; }
  return 1;
}

void checkAndPush(const int x, const int y, const int t) {
  if (!check(x,y) || (willRuin[x][y] && ruinAt[x][y] <= t)) { return; }
  sxq.push({x,y,t});
}
void checkAndRuin(const int x, const int y, const int t) {
  if (!check(x,y)) { return; }
  if (willRuin[x][y] && ruinAt[x][y] < t) { return; }
  ruinAt[x][y] = t; willRuin[x][y] = 1;
}

int finalAns = -1;

void search() {
  sxq.push({0,0,0});
  while(sxq.size()) {
    const int xx = sxq.front().x, yy = sxq.front().y, tt = sxq.front().t;
    sxq.pop();
    if (vis[xx][yy]) { continue; }
    vis[xx][yy] = 1;
    if (!willRuin[xx][yy]) { finalAns = tt; return; }
    checkAndPush(xx+1, yy, tt+1);
    checkAndPush(xx, yy-1, tt+1);
    checkAndPush(xx, yy+1, tt+1);
    checkAndPush(xx-1, yy, tt+1);
  }
}


int main() {
  scanf("%d", &m);
  if(!m) { printf("0"); return 0; }
  int x, y, t;
  cfor(i, 0, m, 1) {
    scanf("%d%d%d", &x, &y, &t);
    checkAndRuin(x,y,t);
    checkAndRuin(x+1,y,t);
    checkAndRuin(x-1,y,t);
    checkAndRuin(x,y+1,t);
    checkAndRuin(x,y-1,t);
  }
  if (ruinAt[0][0] == 0) { printf("-1"); return 0; }
  if (!willRuin[0][0]) { printf("0"); return 0; }
  search();
  printf("%d", finalAns);
  return 0;
}
