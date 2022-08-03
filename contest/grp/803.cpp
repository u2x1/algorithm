#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cmath>

struct Vec { int x; int y; };

double len(const Vec v) {
  return std::sqrt(v.y*v.y+v.x*v.x);
}

Vec vec(const int *p1, const int *p2) {
  const int a = p2[0]-p1[0], b = p2[1]-p1[1];
  Vec v; v.x = a; v.y = b;
  return v;
}

int inSquare(int *p1, int *p2, int *p3, int *p4) {
  const double l1 = len(vec(p1, p2))
             , l2 = len(vec(p3, p4))
             , l3 = len(vec(p1, p3))
             , l4 = len(vec(p2, p4))
             , l5 = len(vec(p1, p4))
             , l6 = len(vec(p2, p3));
  return (l1 == l2) && (l3 == l4) && (l5 == l6);
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
