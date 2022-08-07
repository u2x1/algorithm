#include <cstdio>
#include <cstring>
#include <algorithm>
#define LEN 10000000

int arr[LEN], len=1;
long long dp[LEN][2];
int main() {
  char c=getchar();
  while(c != EOF) {
    if (c == '1') {
      ++arr[len];
      c = getchar();
    } else {
      while((c=getchar()) != EOF && c != '1');
      ++len;
    }
  }

  for(int i=1; i<=len; ++i) { arr[i] *= arr[i]; }

  for(int i = len-1; i >= 1; --i) {
    dp[i][0] = std::max(arr[i] - dp[i+1][1], dp[i+1][0]);
    dp[i][1] = std::min(arr[i] - dp[i+1][0], dp[i+1][1]);
    printf("dp[%d][0]: %lld  dp[%d][1]: %lld\n", i, dp[i][0], i, dp[i][1]);
  }

  printf("%lld", dp[1][0]);

  return 0;
}
