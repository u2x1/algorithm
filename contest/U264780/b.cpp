#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 1e5 + 5;
int a[maxN], b[maxN];

int main() {
  int n, q; scanf("%d", &n);
  orep(i, 1, n+1) {
    int tmp;
    scanf("%d", &tmp); 
    a[i] = a[i-1] + (tmp == 1);
    b[i] = b[i-1] + (tmp == 2);
  }
  scanf("%d", &q);
  while(q--) {
    int l, r; scanf("%d%d", &l, &r);
    const int aa = a[r] - a[l-1];
    const int bb = b[r] - b[l-1];
    printf(aa == bb ? "Draw" : (aa > bb) ? "Argentina" : "Saudi Arabia");
    NL;
  }
  const int aa = a[n] - a[0];
  const int bb = b[n] - b[0];
  printf(aa == bb ? "Draw" : (aa > bb) ? "Argentina" : "Saudi Arabia");
  return 0;
}
