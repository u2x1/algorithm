#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <algorithm>

int main() {
  int n;
  scanf("%d", &n);
  int ls[n], m;
  for(int i = 0; i < n && scanf("%d", &ls[i]); ++i);
  scanf("%d", &m);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  std::sort(ls, ls+n);
  for(int i = 0; i<n; ++i) {
    int t = m-ls[i];
    int l=i+1, r=n, mid = (l+r) >> 1;
    int tmp;
    while(l<r) {
      tmp = ls[mid];
      if (tmp == t) { printf("%d %d", ls[i], t); goto end; }
      else if (tmp > t) { r = mid; }
      else { l = mid+1; }
      mid = (l+r) >> 1;
    }
    if (ls[r] == t) { printf("%d %d", ls[i], t); goto end; }
  }
  printf("No");
end:;

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
