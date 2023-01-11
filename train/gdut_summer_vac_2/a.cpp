#include <cstdio>
#include <algorithm>

#define orep(i,l,r) for(int i = (l); i < (r); ++i)
#define NL          putchar(10);

const int maxN = 2e2+5;
int arr[maxN];
int dp[maxN];
const int mm = 1e6+7;

int main() {
  int n, m; scanf("%d%d", &n, &m);
  orep(i, 0, n) { scanf("%d", arr+i+1); }
  dp[0] = 1;
  orep(i, 1, n+1) {
    for (int j = m; j >= 0; --j) {
      for (int k = std::max(0, j-arr[i]); k < j; ++k) {
        dp[j] = (dp[j] + dp[k]) % mm;
      }
    }
  }

  printf("%d", dp[m]);

  return 0;
}
