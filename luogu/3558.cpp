#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 1e6+5;
int arr[maxN];
int dp[3];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  dp[0] = dp[1] = dp[2] = 1e8;
  std::cin >> arr[0];
  dp[arr[0]+1] = 0;
  orep(i, 1, n) {
    std::cin >> arr[i];
    if (arr[i] == 0) {
      if (arr[i-1] != 0) {
        dp[1] = std::min(dp[0], dp[1]);
      }
      dp[0]++; dp[2]++;
    } else if (arr[i] == 1) {
      dp[2] = std::min(dp[0],std::min(dp[1], dp[2]));

      dp[1]=dp[0]+1; dp[0]+=2;

    } else if (arr[i] == -1) {
      if (dp[0]>=1e8 && dp[2]>=1e8) { std::cout << "BRAK"; return 0; }
      dp[1]=1e8;
      dp[2]+=2;
    }
  }
  std::cout << std::min(dp[0], std::min(dp[1], dp[2]));
  return 0;
}
