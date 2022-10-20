#include <cstdio>
#include <cstring>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int col[9], row[9];
int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int n, m; scanf("%d%d", &n, &m);
    memset(col, 0, sizeof(col));
    memset(row, 0, sizeof(row));
    orep(i, 0, m) {
      int x, y; scanf("%d%d", &x, &y);
      row[x] = col[y] = 1;
    }
    bool flag = 0;
    crep(i, 1, n) {
      if (!row[i] || !col[i]) { printf("YES"); NL; flag = 1; break;}
    }
    if (!flag) { printf("NO"); NL; }
  }

  return 0;
}
