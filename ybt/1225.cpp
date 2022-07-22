#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <algorithm>

struct Rock { int n; int v; double sg; };
bool operator<(const Rock &a, const Rock &b){ 
  return a.sg > b.sg;
}

int main() {
  int k;
  scanf("%d", &k);
  int w, s;
  Rock rs[101];
  while (k--) {
    scanf("%d%d", &w, &s);
    for(int i = 0; i < s; ++i) {
      scanf("%d%d", &rs[i].n, &rs[i].v);
      rs[i].sg = 1.0 * rs[i].v / rs[i].n;
    }
    std::sort(rs, rs+s);
    double rst = 0;
    for(int i = 0; i < s; ++i) {
      if (rs[i].n >= w) {
        rst += w * rs[i].sg;
        break;
      } else {
        w -= rs[i].n;
        rst += rs[i].v;
      }
    }
    printf("%.2f\n", rst);
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
