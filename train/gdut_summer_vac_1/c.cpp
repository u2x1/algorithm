#include <cstdio>
#include <cstring>
#include <queue>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          putchar(10);

const int maxN = 500;
int arr[maxN][maxN];
int n,m;

struct st { int x; int y;};

std::queue<st> q;

void checkPush(const int x, const int y, const int step) {
  if (x < 0 || y < 0 || x >= n || y >= m) { return; }
  if (~arr[x][y]) { return; }
  q.push({x,y});
  arr[x][y] = step;
}

void paint(const int x, const int y) {
  checkPush(x, y, 0);
  while(q.size()) {
    const int xx = q.front().x, yy = q.front().y; q.pop();
    const int step = arr[xx][yy];
    checkPush(xx+1, yy+2, step+1);    checkPush(xx+2, yy+1, step+1);    
    checkPush(xx+1, yy-2, step+1);    checkPush(xx+2, yy-1, step+1);
    checkPush(xx-1, yy+2, step+1);    checkPush(xx-2, yy+1, step+1);
    checkPush(xx-1, yy-2, step+1);    checkPush(xx-2, yy-1, step+1);
  }
}

int main() {
  int x, y; scanf("%d%d%d%d", &n, &m, &x, &y);
  --x; --y;

  memset(arr, -1, sizeof(arr));

  paint(x, y);
  orep(i, 0, n) {
    orep(j, 0, m) {
      printf("%d\t", arr[i][j]);
    } NL;
  }

  return 0;
}
