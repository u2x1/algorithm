#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cmath>

double arctan(double x) {
  double sum = x;
  bool nega = 1;
  double curr = x;
  for (int i = 3; ((curr=curr*x*x)/i) >= 1e-6; i+=2) {
    if (nega) { sum -= curr/i;}
    else      { sum += curr/i; }
    nega = !nega;
  }
  return sum;
}

int main() {

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  printf("%.10lf", 6*arctan(1/sqrt(3)));

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
