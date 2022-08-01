#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>


double a, b, c, d;
double val(double x) {
  return a*x*x*x+b*x*x+c*x+d;
}

int main() {
  scanf("%lf%lf%lf%lf", &a, &b, &c, &d);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  double rst[3]; int pos = 0;
  for(int i = -101; i < 100; ++i) {
    const int x1 = i, x2 = x1+1;
    const double y1 = val(x1), y2 = val(x2);
//    printf("i: %d, pos: %d\n", i, pos);
    if ((y1 > 0 && y2 < 0) ||
        (y1 < 0 && y2 > 0)) {
      for(double df = x1; df < x2; df+=0.001) {
        const double xx1 = df, xx2 = df+0.001;
        const double yy1 = val(xx1), yy2 = val(xx2);
          if ((yy1 > 0 && yy2 < 0) ||
              (yy1 < 0 && yy2 > 0)) {
            rst[pos++] = xx1; break;
          } else if (!yy1) { rst[pos++] = xx1; break; } 
          if (pos == 3) { break; }
      }
    } else if (!y1) { rst[pos++] = x1; } 
    if (pos == 3) { break; }
  }
  printf("%.2f %.2f %.2f", rst[0], rst[1], rst[2]);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
