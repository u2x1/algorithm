#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 3e2+5;
int dp[maxN][maxN];
int n, m;
std::vector<std::vector<int>> son;

int init(const int u) {
  int sum = 1;
  orep(i, 0ul, son[u].size()) {
    const int v = son[u][i];
    int cur = init(v);
    sum += cur;
    for(int j = sum; j>1; --j) {
      orep(k, 0, std::min(cur+1, j)) {
        dp[u][j] = std::max(dp[u][j], dp[u][j-k] + dp[v][k]);
      }
    }
  }
  return sum;
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> n >> m;
  son = std::vector<std::vector<int>>(n+1);
  orep(i, 1, n+1) {
    int a; std::cin >> a >> dp[i][1];
    son[a].push_back(i);
  }
  init(0);
  std::cout << dp[0][m+1];

  return 0;
}

