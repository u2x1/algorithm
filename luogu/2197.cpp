#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 1e5;

int main() {
  int t; scanf("%d", &t);
  while(t--) {
    int n; scanf("%d", &n);
    int xorer = 0;
    orep(i, 0, n) {
      int tmp; scanf("%d", &tmp);
      xorer ^= tmp;
    }
    printf(xorer ? "Yes" : "No"); NL;
  }
  return 0;
}
