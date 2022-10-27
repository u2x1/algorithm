#include <cstdio>
#include <cmath>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int main() {
  int x1, y1, x2, y2, k, m;
  scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &k, &m);
  int dist = std::sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));

  printf("%d", dist >= k ? 0 : dist*m);

  return 0;
}
