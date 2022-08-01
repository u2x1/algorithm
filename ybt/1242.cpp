#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
int n,k;

bool judge(int *ls, int len) {
//  printf("judging %d\n", len);
  int cnt = 0;
  for(int i = 0; i<n; ++i) {
    cnt += ls[i] / len;
  }
  return cnt >= k;
}

int main() {
  scanf("%d%d", &n, &k);
  int max=0, ls[n];
  double tmp;
  for(int i=0; i<n; ++i) {
    scanf("%lf", &tmp);
    if ((ls[i] = (tmp*100+0.5)) > max) { max = ls[i]; }
  };

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  int l = 0, r = max+1, mid = (l+r) >> 1;
  while(l+1<r) {
    if (judge(ls, mid)) { l=mid; }
    else { r=mid; }
    mid = (l+r) >> 1; 
  }
  printf("%.2f", l/100.0);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
