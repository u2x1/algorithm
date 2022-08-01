#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <algorithm>
struct Rg {int l; int r;};
bool operator<(Rg a, Rg b) { return a.l < b.l; }

int main() {
  int n;
  scanf("%d", &n);
  if (!n) { printf("no"); return 0; }
  Rg rs[n];
  for(int i = 0; i < n; ++i) {
    scanf("%d%d", &rs[i].l, &rs[i].r);
    // if (a < l && b >= l-1) {
    //   l = a;
    // } else if (b > r && a <= r+1) {
    //   r = b;
    // } else if (a>=l && b<=r) {
    // } else {
    //   printf("no");
    //   return 0;
    // }
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  std::sort(rs, rs+n);
  int a=rs[0].l, b=rs[0].r;
  for(int i = 1; i < n; ++i) {
    if (rs[i].l > b+1) { printf("no"); return 0; }
    b = rs[i].r > b ? rs[i].r : b;
  }
  printf("%d %d", a, b);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
