#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cmath>
#include <algorithm>

int len(const int *p1, const int *p2) {
  const int a = p2[0]-p1[0], b = p2[1]-p1[1];
  return a*a+b*b;
}

int inSquare(int *p1, int *p2, int *p3, int *p4) {
  int  l[6] = { len(p1, p2)
              , len(p3, p4)
              , len(p1, p3)
              , len(p2, p4)
              , len(p1, p4)
              , len(p2, p3) };
  std::sort(l, l+6);
  return ((l[0] == l[3]) && (l[4] == l[5])
         && !(l[0] == 0 && l[5] == 0));
}

int main() {
  int p[4][2];
  for(int i = 0; i < 4; ++i) {
    scanf("%d%d", &p[i][0], &p[i][1]);
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  printf("%d", inSquare(p[0], p[1], p[2], p[3]));

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
