#include <cstdio>
#include <queue>

#define cfor(i,a,b,s)  for(auto i=(a); i!=(b); i+=(s))
#define NL             putchar(10);

const int maxN = 105;
int arr[maxN][maxN];
int n, m, a, b, x, y;
int ret;
struct pt
{ int x, y, dep; };

std::queue<pt> sxq;

void checkAndPush(const int xx, const int yy, const int depth) {
  if (xx < 0 || xx == n || yy < 0 || yy == m || arr[xx][yy]) { return; }
  if (xx == x && yy == y) { ret = depth; return;}
  sxq.push({xx,yy,depth}); arr[xx][yy] = 2;
}

void search() {
  sxq.push({a, b, 0});
  while(sxq.size()) {
    const int xx = sxq.front().x, yy = sxq.front().y, dd = sxq.front().dep;
    sxq.pop();
    checkAndPush(xx-1, yy, dd+1);
    checkAndPush(xx+1, yy, dd+1);
    checkAndPush(xx, yy+1, dd+1);
    checkAndPush(xx, yy-1, dd+1);
    if(ret != 0) { break; }
  }

}

int main() {
  scanf("%d%d%d%d%d%d", &n, &m, &a, &b, &x, &y);
  --a; --b; --x; --y;
  if (a==x && b==y) { printf("0"); return 0; }
  cfor(i, 0, n, 1) {
    cfor(j, 0, m, 1) {
      scanf("%d", &arr[i][j]);
    }
  }
  search();
  printf("%d", ret);
  return 0;
}
