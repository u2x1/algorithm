#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i< (b); ++i)
#define crep(i,a,b)  for(auto i=(a); i<=(b); ++i)
#define NL           putchar(10);

int main() {
  int n, m; scanf("%d%d", &n, &m); ++n;
  int a[m]; orep(i, 0, m) { scanf("%d", a+i); }
  std::sort(a, a+m);

  long long rst = 0;
  int last = a[0];
  orep(i, 1, m) {
    if (a[i] <= last) {
      ++last;
      if (last > n) { printf("-1"); return 0; }
      rst += last-a[i];
    } else {
      if (last > n) { printf("-1"); return 0; }
      last = a[i];
    }
  }

  printf("%lld", rst);
  return 0;
}
