#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <algorithm>

float female[40], male[40];
int main() {
  int n;
  scanf("%d", &n);
  int femalePos = 0, malePos = 0;
  char gender[7];
  for(int i = 0; i < n; ++i) {
    scanf("%s", gender);
    if(gender[0] == 'm') { scanf("%f", &male[malePos++]); }
    else { scanf("%f", &female[femalePos++]); }
  }
  

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  std::sort(male, male+malePos);
  std::sort(female, female+femalePos, [](double a, double b) { return a > b; });
  for(int i = 0; i<malePos; ++i) {
    printf("%.2f ", male[i]);
  }
  for(int i = 0; i< femalePos; ++i) {
    printf("%.2f ", female[i]);
  }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
