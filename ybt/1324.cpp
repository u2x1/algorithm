#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <algorithm>
struct A { int start; int end; };
bool operator<(const A &a, const A &b) {
  return a.end < b.end;
}

int main() {
  int n;
  scanf("%d", &n);
  A as[n];
  for(int i = 0; i < n; ++i) {
    scanf("%d%d", &as[i].start, &as[i].end);
  }
  std::sort(as, as+n);
  int cnt = 0; int last = -1;
  for(int i = 0; i<n; ++i) {
    if (as[i].start <= last) { continue; }
    if (as[i].end > last) { last = as[i].end; ++cnt; }
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  printf("%d", cnt);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
