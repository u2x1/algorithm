#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);
#define PTD(v)       printf(#v ": %d\t", v); fflush(stdout);
#define PTC(v)       printf(#v ": %c\t", v); fflush(stdout);
#define REDIR        freopen("data.in", "r", stdin);

int main() {
  int t; scanf("%d", &t);
  const double pi = 3.1415926535;
  while(t--) {
    int a, b, r, h;
    scanf("%d%d%d%d", &a, &b, &r, &h);
    double diff = std::abs(a-b); diff = std::min(diff, 360-diff);
    diff /= 360;
    const double c = diff * pi * 2 * r;
    const double rst = c*c + h*h;
    printf("%.2f", rst); NL;
  }

  return 0;
}
