#include <iostream>
#include <climits>
#include <cstring>
#include <queue>
#include <string>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

int H, W, T;
std::string MP[301];

std::vector<std::pair<int, int>> cds;
std::pair<int, int> start, goal;

std::vector<std::vector<int>> d[20];
void bfs(int i, int sx, int sy) {
  std::queue<std::pair<int, int>> q;
  q.emplace(sx, sy);
  d[i] = std::vector<std::vector<int>>(H, std::vector<int>(W, 0x3f3f3f3f));
  d[i][sx][sy] = 0;
  auto push = [&](int x, int y, int dist) {
    if (~x && x < H && ~y && y < W && (MP[x][y] != '#') && dist < d[i][x][y]) {
      d[i][x][y] = dist;
      q.emplace(x, y);
    }
  };
  while(!q.empty()) {
    auto [x, y] = q.front(); q.pop();
    // if (MP[x][y] == 'G') { continue; }
    int dist = d[i][x][y] + 1;
    push(x+1, y, dist); push(x, y+1, dist);
    push(x-1, y, dist); push(x, y-1, dist);
  }
}

int dp[1<<20][20];
signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> H >> W >> T;
  orep(i, 0, H) { std::cin >> MP[i]; }
  orep(i, 0, H) {
    orep(j, 0, W) {
      if (MP[i][j] == 'S') { start = { i, j }; }
      if (MP[i][j] == 'G') { goal = { i, j }; }
      if (MP[i][j] == 'o') { cds.emplace_back(i, j); }
    }
  }

  bfs(18, start.first, start.second);
  if (d[18][goal.first][goal.second] > T) { std::cout << -1; exit(0); }

  memset(dp, 0x3f, sizeof(dp));
  orep(i, 0ul, cds.size()) {
    auto &[x, y] = cds[i];
    bfs(i, x, y);
    dp[1<<i][i] = d[i][start.first][start.second];
  }

  for(int s = 1; s < (1<<(cds.size())); ++s) {
    orep(last, 0ul, cds.size()) {
      if (!(s & (1<<last))) { continue; }
      orep(nx, 0ul, cds.size()) {
        // if (last == nx) { continue; }
        if ((s & (1<<nx))) { continue; }
        dp[s | (1 << nx)][nx] = std::min(dp[s | (1 << nx)][nx], dp[s][last] + d[last][cds[nx].first][cds[nx].second]);
      }
    }
  }

  int ret = 0;
  for(int s = 1; s < (1<<(cds.size())); ++s) {
    orep(last, 0ul, cds.size()) {
      if (!(s & (1<<last))) { continue; }
      if (dp[s][last] + d[last][goal.first][goal.second] > T) { continue; }
      ret = std::max(ret, __builtin_popcount(s));
    }
  }
  std::cout << ret;

  return 0;
}
