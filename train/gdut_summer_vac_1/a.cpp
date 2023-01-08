#include <cstdio>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          putchar(10);

const int maxN = 25;
bool arr[maxN][maxN];

int cnt;
int x, y;
void dfs(const int i, const int j) {
  if (i < 0 || i >= x || j < 0 || j >= y) { return; }
  if (!arr[i][j]) { return; }
  ++cnt; arr[i][j] = 0;
  dfs(i+1,j); dfs(i,j+1);
  dfs(i-1,j); dfs(i,j-1);
}

int main() {
  while(1) {
    scanf("%d%d ", &y, &x);
    if (!x && !y) { return 0; }
    int sx, sy;
    orep(i, 0, x) {
      orep(j, 0, y) {
        const char c = getchar();
        if (c == '@') { arr[i][j] = 1; sx = i; sy = j; continue; }
        arr[i][j] = (c == '.') ? 1 : 0 ;
      } getchar();
    }
    cnt = 0; dfs(sx, sy);
    printf("%d", cnt); NL;
  }
}
