#include <cstdio>

#define orep(i,l,r) for(int i = (l); i < (r); ++i)
#define NL          putchar(10);

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int n; scanf("%d", &n);
    if (n == 3) { printf("NO\n"); continue; }
    if (!(n & 1)) {
      printf("YES\n");
      orep(i, 0, n) {
        printf("%d ", i & 1 ? 1 : -1);
      } NL;
    } else {
      printf("YES\n");
      const int x = (n / 2)-1;
      printf("%d", -x);
      orep(i, 0, x+1) {
        printf(" %d %d", x+1, -x);
      } NL;
    }
  }

  return 0;
}
