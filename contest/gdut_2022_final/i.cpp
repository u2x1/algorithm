#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 1e6;
long long dp[maxN][2];

int main() {
  int n; scanf("%d", &n);
  const long long infL = 1ll << 62;
  long long line0Mx[2] = {-infL,-infL}, line1Mx[2] = {-infL,-infL};
  orep(i, 1, n+1) { scanf("%lld", &dp[i][0]); }
  orep(i, 1, n+1) { scanf("%lld", &dp[i][1]); }

  orep(i, 1, n+1) {
    dp[i][0] += std::max(dp[i-1][1], line0Mx[i%2]);
    dp[i][1] += std::max(dp[i-1][0], line1Mx[i%2]);
    line0Mx[i%2] = std::max(line0Mx[i%2], dp[i][0]);
    line1Mx[i%2] = std::max(line1Mx[i%2], dp[i][1]);
  }
  printf("%lld", std::max(dp[n][0], dp[n][1]));
  return 0;
}
