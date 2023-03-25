#include <iostream>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 4e4+5;
const int maxM = 65;
struct st { int cost, val; };
st arr[maxM];

std::vector<int> son[maxM];
int dp[maxM][maxN*maxM];
int n, m;
int ret;

void init(const int u = 0, const int fa = 64, const int t = n) {
  if (t <= 0) { return; }
  orep(i, 0, t-arr[u].cost+1) {
    dp[u][i] = dp[fa][i] + arr[u].val;
  }
  for (const int v : son[u]) {
    init(v, u, t-arr[u].cost);
    orep(i, arr[v].cost, t+1) {
      dp[u][i] = std::max(dp[u][i], dp[v][i-arr[v].cost]);
    }
  }
}


int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> n >> m;
  int tmp;
  orep(i, 1, m+1) {
    std::cin >> arr[i].cost >> tmp;
    arr[i].val = arr[i].cost * tmp;
    int fa; std::cin >> fa;
    son[fa].push_back(i);
  }
  init();
  orep(i, 0, n+1) { ret = std::max(ret, dp[0][i]); }
  std::cout << ret;

  return 0;
}
