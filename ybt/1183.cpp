#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <algorithm>

struct patient { char id[10]; int age; };

bool operator<(const patient &lhs, const patient &rhs) {
  const int lAg = lhs.age, rAg = rhs.age;
  if (lAg < 60 && rAg < 60) { return 0; }
  else if (lAg >= 60 && rAg < 60) { return 1; }
  else if (lAg < 60 && rAg >= 60) { return 0; }
  else if (lAg >= 60 && rAg >= 60) { return lAg > rAg; }
  return 0;
}

int main() {
  int n;
  scanf("%d", &n);
  patient pats[n];
  for(int i = 0; i<n; ++i) {
    scanf("%s%d", pats[i].id, &pats[i].age);
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  std::stable_sort(pats, pats+n);
  for(int i = 0; i<n; ++i) {
    printf("%s\n", pats[i].id);
  }

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
