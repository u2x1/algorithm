#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int a, b;
int cnt;
void f(const int left, const int last, const int plate) {
  if (left == 0) { ++cnt; return; }
  if (left < 0 || plate == b) { return; }
  for(int i = last; i <= left; ++i) {
    f(left-i, i, plate+1);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for(int i = 0; i<n; ++i) {
    scanf("%d%d", &a, &b);
    f(a, 1, 0);
    printf("%d\n", cnt);
    cnt = 0;
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
