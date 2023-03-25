#include <iostream>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 1e2+5;
int arr[maxN][maxN];
long long dp[20005];
struct st { long long val, cost; } packs[maxN][maxN];
int s, n, m;

void init() {
  orep(i, 1, n+1) {
    std::vector<int> col;
    orep(j, 1, s+1) { col.push_back(arr[j][i]); }
    std::sort(col.begin(), col.end());
    orep(j, 1, s+1) { packs[i][j] = { j*i, col[j-1]*2+1 }; }
  }
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> s >> n >> m;
  orep(i, 1, s+1) {
    orep(j, 1, n+1) {
      std::cin >> arr[i][j];
    }
  }
  init();
  orep(i, 1, n+1) {
    drep(k, m, -1) {
      orep(j, 1, s+1) {
        if (packs[i][j].cost > k) { continue; }
        dp[k] = std::max(dp[k], dp[k-packs[i][j].cost] + packs[i][j].val);
      }
    }
  }

  std::cout << dp[m];

  return 0;
}
