#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 3e5+5;
long long arr[maxN];
long long dp1[maxN][2], dp2[maxN][2];

int main() {
  int n; scanf("%d", &n);
  orep(i, 0, n) { scanf("%lld", arr+i); }
  // last selected
  dp1[0][1] = arr[0];
  orep(i, 1, n-1) {
    dp1[i][0] = dp1[i-1][1];
    dp1[i][1] = std::min(dp1[i-1][0], dp1[i-1][1]) + arr[i];
  }
  dp1[n-1][1] = std::min(dp1[n-2][0], dp1[n-2][1]) + arr[n-1];
  // last not selected
  dp2[0][0] = dp2[0][1] = arr[0];
  orep(i, 1, n-1) {
    dp2[i][0] = dp2[i-1][1];
    dp2[i][1] = std::min(dp2[i-1][0], dp2[i-1][1]) + arr[i];
  }
  dp2[n-1][0] = dp2[n-2][1];
  printf("%lld", std::min(dp1[n-1][1], dp2[n-1][0]));
  return 0;
}
