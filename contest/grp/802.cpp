#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>


bool f(const int raw, const int left, const int x) {
  if (!left && !x) { return true; }
  if (!x) { return false; }
  if (raw%x) { return false; }
  return f(raw, left/10, left%10);
}

void fun(int left, int right) {
  if (left < 1) { left = 1; }
  ++right;
  while (left != right) {
    if (f(left, left/10, left%10)) { printf("%d ", left); }
    ++left;
  }
}

int main() {
  int l, r;
  scanf("%d%d", &l, &r);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  fun(l, r);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
