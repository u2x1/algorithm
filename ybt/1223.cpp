#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int f(int x) {
  int zeros;
  for(zeros = 0; ; ++zeros) {
    if ((x & 1) == 0) { x >>= 1; }
    else { break; }
  }
  int ones;
  for(ones = 0; ; ++ones) {
    if ((x & 1) == 1) { x >>= 1; }
    else { break; }
  }
  ++zeros;
  x+=1;
  while(zeros-- > 0) {
    x <<= 1;
  }
  while(--ones > 0) {
    x <<= 1;
    x += 1;
  }
  return x;
}

int main() {
  while(1) {
    int i;
    scanf("%d", &i);
    if(!i) { break; }
    printf("%d\n", f(i));
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////


#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
