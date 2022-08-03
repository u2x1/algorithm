#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <cmath>

struct Vec { int x; int y; };

// int dot(Vec v1, Vec v2) {
//   return (v1.x*v2.x)+(v2.y*v2.y);
// }
//
// bool vertical(const Vec v1, const Vec v2) {
//   return !dot(v1, v2);
// }

double len(const Vec v) {
  return std::sqrt(v.y*v.y+v.x*v.x);
}

Vec vec(const int *p1, const int *p2) {
  const int a = p2[0]-p1[0], b = p2[1]-p1[1];
  Vec v; v.x = a; v.y = b;
  return v;
}


int inSquare(int *p1, int *p2, int *p3, int *p4) {
  const double sqrt2 = std::sqrt(2);
  const int *p[4] = { p1, p2, p3, p4 };

  Vec v[3];
  for(int i = 0; i < 4; ++i) {
    int pos = 0;
    for(int j = 0; j < 4; ++j) {
      if (i == j) { continue; }
      v[pos++] = vec(*(p+i), *(p+j));
    }

    double fst = len(v[0]);
    for(int i = 1; i < 3; ++i) {
      const double it = len(v[i]);
      if (std::abs(it-fst) < 0.0001
       || std::abs(it-fst*sqrt2) < 0.0001
       || std::abs(it*sqrt2-fst) < 0.0001 ) { continue; }
      return 0;
    }
  }
  return 1;
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
