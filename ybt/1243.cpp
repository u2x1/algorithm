#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int n, m;

bool judge(const int *ls, const int x) {
//  printf("judging %d ... ", x);
  int sum = 0; int cnt=1;
  for(int i = 0; i < n; ++i) {
    if ((sum+=ls[i]) > x) { ++cnt; sum = ls[i]; }
  }
//  if (sum > x) { cnt+=2; }
//  else { ++cnt; }
//  printf("%d\n", cnt);
  return cnt <= m;
}

int main() {
  scanf("%d%d", &n, &m);
  int ls[n];
  int l = 0, r=0;
  for(int i = 0; i<n && scanf("%d", &ls[i]) == 1; ++i) {
    if (ls[i] > l) { l = ls[i]; }
    r+=ls[i];
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  int mid = (l+r) >> 1;
  while(l<r) {
    if (judge(ls, mid)) { r = mid; }
    else { l = mid+1; }
    mid = (l+r) >> 1;
  }
  printf("%d", r);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
