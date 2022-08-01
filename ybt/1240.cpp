#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int main() {
  int n, m;
  scanf("%d", &n);
  int ls[n];
  for(int i=0; i<n && scanf("%d", &ls[i])==1; ++i);
  scanf("%d", &m);
  int t;
  while(m--) {
    scanf("%d", &t);
    int l=0, r=n-1, mid = (r+l)>>1;
    while(l<r-1) {
      if (ls[mid] > t) { r = mid; }
      else if (ls[mid] < t) { l = mid; }
      else { break; }
      mid = (r+l)>>1;
//      printf("l %d mid %d r %d\n", l,  mid, r);
    }
    if (ls[mid] == t) { printf("%d\n", t); }
    else if (t-ls[l] > ls[r]-t) { printf("%d\n", ls[r]); }
    else { printf("%d\n", ls[l]); }
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
