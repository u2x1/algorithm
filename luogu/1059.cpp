#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i<(b); ++i)
#define NL           putchar(10);

const int maxN = 3e5+5;
const int maxM = 1e3+5;
int dp[maxN][30];

int main() {
  int m, s, t; scanf("%d%d%d", &m, &s, &t);
  int ans = 0, ansSec = 0;
  int startup = 0, startupTime = 0;
  while(m > 10 && t > 0) {
    startup += 60; m-=10; --t; ++startupTime;
  }
  orep(i, 0, t+1) {
    orep(j, 0, 29) {
      dp[i][j] = -1;
    }
  }
  if (t>0) { dp[0][m] = 0; }
  orep(i, 1, t+1) {
    for(int magic = 20; magic >= 0; --magic) {
      if (!~dp[i-1][magic]) { continue; }
      dp[i][magic] = std::max(dp[i][magic], dp[i-1][magic]+17);
      dp[i][magic+4] = std::max(dp[i][magic+4], dp[i-1][magic]);
      if (magic >= 10) {
        dp[i][magic-10] = std::max(dp[i][magic-10], dp[i-1][magic]+60);
        ans = std::max(dp[i][magic-10], ans);
      }
      ans = std::max(dp[i][magic], ans);
      if (ans+startup > s) { ansSec = i; i = t+1; magic=-1; }
    }
  }
  if (ans+startup < s) {
    printf("No"); NL;
    printf("%d", ans+startup);
  } else {
    printf("Yes"); NL;
    printf("%d", ansSec+startupTime);
  }
  return 0;
}
