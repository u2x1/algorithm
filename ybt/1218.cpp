#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
int a, b;

void f(const int a, const int b, const int step) {
  if (a / b >= 2 || !b) {
    if (step % 2) { printf("lose\n"); }
    else { printf("win\n"); }
    return;
  }
  f(b, a % b, step+1);
}


int main() {
  while(1) {
    scanf("%d%d", &a, &b);
    if (a == 0 && b == 0) { break; }
    if (a < b) { int tmp = a; a = b; b = tmp; }
    f(a, b, 0);
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
