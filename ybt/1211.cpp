#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

bool f(const int k, const int x) {
  if (k > x) { return false; }
  if (k == x) { return true; }
  return f(2*k+1, x) || f(3*k+1, x);
}

int main() {
  int k, x;
  scanf("%d,%d", &k, &x);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  if (f(k, x)) {
    printf("YES");
  } else {
    printf("NO");
  }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
