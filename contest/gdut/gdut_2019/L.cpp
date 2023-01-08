#include <cstdio>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int main() {
  int n, l, m; scanf("%d%d%d", &n, &l, &m);
  double rst = 0;
  crep(i, 1, n) {
    rst += 0.5 / i;
  }
  printf("%.4f", rst*l);

  return 0;
}
