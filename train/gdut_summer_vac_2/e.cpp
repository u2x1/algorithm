#include <iostream>
#include <map>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

#define M 998244353

const int maxN = 1e3+5;
int arr[maxN];
std::map<int, long long> dp[maxN];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n; std::cin >> n;
  long long ret = 0;
  orep(i, 0, n) {
    int tmp; std::cin >> tmp; arr[i] = tmp;
    ret += 1;
    orep(j, 0, i) {
      const int df = tmp - arr[j];
      dp[i][df] = (dp[i][df] + std::max(1ll, dp[j][df]+1)) % M;
      ret = (std::max(1ll, dp[j][df]+1) + ret) % M;
    }
  }
  std::cout << ret % M;

  return 0;
}
