#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cstring>

int main() {
  double n;
  char dna1[501], dna2[501];
  scanf("%lf%s%s", &n, dna1, dna2);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  int len = strlen(dna1);
  int same = 0;
  for (int i = 0; i < len; ++i) {
    if (dna1[i] == dna2[i]) { ++same; }
  }
  printf(1.0 * same / len > n ? "yes" : "no");


#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
