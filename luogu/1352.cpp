#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 6e3+5;
long long dp[maxN][2];
bool vis[maxN];
int arr[maxN];
std::vector<std::vector<int>> son;

void init(int x) {
  dp[x][1] = arr[x];
  orep(i, 0ul, son[x].size()) {
    const int s = son[x][i];
    init(s);
    dp[x][0] += std::max(dp[s][1], dp[s][0]);
    dp[x][1] += dp[s][0];
  }
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  son = std::vector<std::vector<int>>(n+1);
  orep(i, 1, n+1) {
    std::cin >> arr[i];
  }
  orep(i, 1, n) {
    int a, b; std::cin >> a >> b;
    vis[a] = 1;
    son[b].push_back(a);
  }
  int boss;
  orep(i, 1, n+1) { if (!vis[i]) { boss = i; } }
  init(boss);
  std::cout << std::max(dp[boss][0], dp[boss][1]);

  return 0;
}
