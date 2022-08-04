#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int main() {
  int d;
  scanf("%d", &d);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  double bike = 50 + d/3.0;  // 除以3.0(带小数点)可以将结果转为浮点数，**不要**只除以3(没有小数点)
  double walk = d / 1.2;
  if(bike < walk) {
    printf("Bike");
  } else if (bike > walk)  {
    printf("Walk");
  } else {
    printf("All");
  }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
