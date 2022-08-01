#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <algorithm>

struct Rl { int a; int b; };
bool operator<(const Rl& a, const Rl& b) {
  return a.a<b.a;
}

int main() {
  int n;
  scanf("%d", &n);
  Rl arr[n];
  for(int i = 0; i<n && ~scanf("%d%d", &arr[i].a, &arr[i].b); ++i);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  std::sort(arr, arr+n);
  int dp[n], max=0;
  for(int i=0; i<n; ++i) {
    dp[i] = 1;
    for(int j=0; j<i; ++j) {
      if (arr[j].b <= arr[i].b) {
        dp[i] = std::max(dp[i], dp[j]+1);
      }
      max = std::max(dp[i], max);
    }
  }
  printf("%d", max);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
