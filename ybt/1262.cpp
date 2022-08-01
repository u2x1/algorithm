#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
#include <algorithm>

struct Tank {
  int mine;
  int arrN = 0;
  int arr[201];
};

int main() {
  int n;
  scanf("%d", &n);
  Tank ts[n+1];
  int dp[n+1] = {0};
  for(int i=1; i<=n && ~scanf("%d", &ts[i].mine); ++i);
  int a, b;
  while(~scanf("%d %d", &a, &b)) {
    if (!a && !b) { break; }
    ts[b].arr[ts[b].arrN] = a;
    ++ts[b].arrN;
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  dp[1] = ts[1].mine;
  int sl[n+1] = {0};
  int max = 0, maxSl;
  for(int i = 2; i <= n; ++i) {
    int nn = ts[i].arrN;
    for(int j = 0; j < nn; ++j) {
      if (dp[i] < dp[ts[i].arr[j]]) {
        dp[i] = std::max(dp[i], dp[ts[i].arr[j]]);
        sl[i] = ts[i].arr[j];
      }
    }
    dp[i] += ts[i].mine;
    if (max < dp[i]) { max = dp[i]; maxSl = i; }
  }
  const int maxSl_cp = maxSl;
  int out[201] { maxSl }, pos = 1;
  while(sl[maxSl]) {
    maxSl = out[pos++] = sl[maxSl];
  }
  printf("%d", out[--pos]);
  for(--pos; pos!=-1; --pos) { printf("-%d", out[pos]); }
//  putchar(10);
//  for(int i=1; i<=n; ++i) { printf("%d-", sl[i]); }
  printf("\n%d", dp[maxSl_cp]);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
