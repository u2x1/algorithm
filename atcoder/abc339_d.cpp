#include "bits/stdc++.h"

#define all(x)   x.begin(), x.end()
#define NL       std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<std::string> mp(n);
  for (auto &x : mp) { std::cin >> x; }
  std::queue<std::array<int, 5>> q;
  std::pair<int, int> p1 = {-1, -1}, p2 = p1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (mp[i][j] == 'P') {
        if (p1.first == -1) {
          p1 = {i, j};
        } else {
          p2 = {i, j};
        }
      }
    }
  }
  q.push({p1.first, p1.second, p2.first, p2.second, 0});
  int ret = -1;
  std::vector vis(n, std::vector(n, std::vector(n, std::vector<int>(n))));
  vis[p1.first][p1.second][p2.first][p2.second] = 1;
  auto chk = [&](int x, int y) {
    if (x == n || x == -1 || y == n || y == -1 || mp[x][y] == '#') { return false; }
    return true;
  };
  while (!q.empty()) {
    auto [x1, y1, x2, y2, dep] = q.front();
    q.pop();
    if (x1 == x2 && y1 == y2) {
      ret = dep;
      break;
    }
    static std::array<int, 4> dx = {0, 0, -1, 1}, dy = {-1, 1, 0, 0};
    for (int i = 0; i < 4; ++i) {
      std::pair<int, int> np1 = chk(x1+dx[i], y1+dy[i]) ? std::pair{x1+dx[i], y1+dy[i]} : std::pair{x1, y1};
      std::pair<int, int> np2 = chk(x2+dx[i], y2+dy[i]) ? std::pair{x2+dx[i], y2+dy[i]} : std::pair{x2, y2};
      auto [nx1, ny1] = np1;
      auto [nx2, ny2] = np2;
      if (vis[nx1][ny1][nx2][ny2]) { continue; }
      vis[nx1][ny1][nx2][ny2] = 1;
      q.push({nx1, ny1, nx2, ny2, dep+1});
    }
  }
  std::cout << ret;

  return 0;
}
