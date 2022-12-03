#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 1e5;
int arr[maxN];
int dp[maxN];

int main() {
  int n; scanf("%d", &n);
  orep(i, 0, n) { scanf("%d", arr+i); }
  int ans = 1;
  orep(i, 0, n) {
    dp[i] = 1;
    orep(j, 0, i) {
      if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
        dp[i] = dp[j]+1;
        ans = std::max(ans, dp[i]);
      }
    }
  }
  orep(i, 0, n) {
    orep(j, 0, i) {
      if (arr[j] > arr[i] && dp[i] < dp[j] + 1) {
        dp[i] = dp[j] + 1;
        ans = std::max(ans, dp[i]);
      }
    }
  }
  printf("%d", n - ans);
  return 0;
}
