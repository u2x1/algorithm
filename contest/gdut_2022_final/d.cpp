#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 1e5;

int main() {
  int n, v, a;
  scanf("%d%d%d", &n, &v, &a);
  printf((n < 2 || a == 1) ? "100" : "0");
  return 0;
}
