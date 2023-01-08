#include <cstdio>
#include <cstring>
#include <queue>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 6e3;
char str[maxN][maxN];
bool vis[maxN][maxN];
int cnt;

struct pt { int x,y; };

std::queue<pt> sxq;
void push(const int x, const int y) {
  if (str[x][y] == ' ' && !vis[x][y]) {
    vis[x][y] = 1; sxq.push({x,y});
    ++cnt;
  }
}
void bfs(const int x, const int y) {
  sxq.push({x,y}); vis[x][y] = 1; ++cnt;
  while (sxq.size()) {
    const int xx = sxq.front().x, yy = sxq.front().y;
    sxq.pop();
    push(xx+1,yy); push(xx,yy+1);
    push(xx-1,yy); push(xx,yy-1);
  }
}

int main() {
  int n, m; scanf("%d%d ", &n, &m);
  orep(i, 0, n) { fgets((char*)(str+i), maxN, stdin); }
  int idx=-1, idy=-1;
  int white=0, black=0;
  orep(i, 0, n) {
    orep(j, 0, m) {
      if (str[i][j] == ' ') {
        ++white;
        if (idx == -1) { idx= i; idy = j; } 
      }
      else {
        ++black;
      }
    }
  }
  if (white == 0) {
    printf("0"); return 0;
  } else {
    bfs(idx, idy);
    printf("%d", white/cnt);
  }
  return 0;
}
