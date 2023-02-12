#include <iostream>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e4+5;
int arr[maxN]; bool vis[maxN];
std::vector<std::vector<int>> son;
long long dp[maxN];

long long ret;
void init(int x) {
  vis[x] = 1;
  dp[x] = arr[x];
  orep(i, 0ul, son[x].size()) {
    if(vis[son[x][i]]) { continue; }
    init(son[x][i]);
    dp[x] += dp[son[x][i]] > 0 ? dp[son[x][i]] : 0;
  }
  ret = std::max(ret, dp[x]);
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  son = std::vector<std::vector<int>>(n+1);
  std::cin >> arr[1];
  int mx = arr[1];
  orep(i, 2, n+1) { std::cin >> arr[i]; mx = std::max(mx, arr[i]); }
  if (mx <= 0) { std::cout << mx; return 0; }
  orep(i, 1, n) {
    int a, b; std::cin >> a >> b; 
    son[a].push_back(b);
    son[b].push_back(a);
  }
  init(1);
  std::cout << ret;

  return 0;
}
