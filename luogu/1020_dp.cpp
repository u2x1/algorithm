#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 1e5;
int arr[maxN], dp[maxN] = {1};
int ans1, ans2;

int main() {
  int tmp, n = 0;
  while(~scanf("%d", &tmp)) {
    arr[n++] = tmp;
  }
  orep(i, 1, n) {
    dp[i] = 1;
    orep(j, 0, i) {
      if(arr[i] <= arr[j]) {
        dp[i] = std::max(dp[i], dp[j] + 1);
        ans1 = std::max(ans1, dp[i]);
      }
    }
  }
  printf("%d", ans1); NL;
  orep(i, 1, n) {
    dp[i] = 1;
    orep(j, 0, i) {
      if(arr[i] > arr[j]) {
        dp[i] = std::max(dp[i], dp[j] + 1);
        ans2 = std::max(ans2, dp[i]);
      }
    }
  }
  printf("%d", ans2);
  return 0;
}
