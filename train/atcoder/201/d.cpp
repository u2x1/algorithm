#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e3+5;
std::string mp[maxN];
int dp[maxN][maxN];

int inf = 0x3f3f3f3f;

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int H, W; std::cin >> H >> W;
  orep(i, 0, H) { std::cin >> mp[i]; }
  const auto val = [&](int x, int y) { return (mp[x][y] == '+' ? 1 : -1); };
  for(int i = H-1; ~i; --i) {
    for(int j = W-1; ~j; --j) {
      if (i == H-1 && j == W-1) { continue; }
      dp[i][j] = -inf;
      if(i != H) { dp[i][j] = std::max(dp[i][j], +val(i+1, j)-dp[i+1][j]); }
      if(j != W) { dp[i][j] = std::max(dp[i][j], +val(i, j+1)-dp[i][j+1]); }
    }
  }
  if (dp[0][0] > 0) { std::cout << "Takahashi"; }
  if (dp[0][0] < 0) { std::cout << "Aoki"; }
  if (dp[0][0] == 0) { std::cout << "Draw"; }


  return 0;
}
