#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>
#include <algorithm>
struct Event { int start; int end; };
bool operator <(const Event &a, const Event &b) {
  if (a.end == b.end) { return a.start < b.start; }
  return a.end < b.end;
}

int main() {
  int n;
  scanf("%d", &n);
  Event es[n];
  for(int i = 0; i < n; ++i) {
    scanf("%d%d", &es[i].start, &es[i].end);
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  std::sort(es, es+n);
  int cnt = 0;
  for(int i = 0, t = -1; i < n; ++i) {
    const int s = es[i].start;
    const int e = es[i].end;
    if (s < t) { continue; }
    t = e;
    ++cnt;
  }
  printf("%d", cnt);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
