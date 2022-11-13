#include <cstdio>
#include <queue>

#define cfor(i,a,b,s)  for(auto i=(a); i!=(b); i+=(s))
#define NL             putchar(10);

const int maxN = 50;
int arr[maxN][maxN], n;
struct Pt { int x, y; };

std::queue<Pt> sxQueue;

void checkValidAndPush(const int x, const int y) {
  if (x < 0 || x == n || y < 0 || y == n) { return; }
  if (arr[x][y] != 2) { return; }
  sxQueue.push({x,y});
}

void search(const int x, const int y) {
  if (arr[x][y] != 2) { return; }
  sxQueue.push(Pt {x, y});
  while(sxQueue.size()) {
    const int xx = sxQueue.front().x, yy = sxQueue.front().y;
    if (arr[xx][yy] == 2) {
      arr[xx][yy] = 0;
      checkValidAndPush(xx+1,yy);
      checkValidAndPush(xx,yy+1);
      checkValidAndPush(xx-1,yy);
      checkValidAndPush(xx,yy-1);
    }
    sxQueue.pop();
  }
}

int main() {
  scanf("%d", &n);
  int tmp;
  cfor(i, 0, n, 1) {
    cfor(j, 0, n, 1) {
      scanf("%d", &tmp);
      if (tmp) { arr[i][j] = 1; }
      else { arr[i][j] = 2; }
    }
  }
  cfor(i, 0, n, 1) {
    search(i, 0);
    search(0, i);
    search(n-1, i);
    search(i, n-1);
  }
  cfor(i, 0, n, 1) {
    cfor(j, 0, n, 1) {
      printf("%d ", arr[i][j]);
    } NL;
  }
  return 0;
}
