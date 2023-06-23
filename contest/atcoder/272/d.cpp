#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  std::vector<std::pair<int, int>> delta;
  orep(x, 0, 1001) {
    orep(y, 0, 1001) {
      if (x*x+y*y == m) {
        delta.push_back({x, y});
      }
    }
  }
  delta.erase(std::unique(delta.begin(), delta.end()), delta.end());
  std::vector<std::vector<bool>> vis(n, std::vector<bool>(n));
  std::vector<std::vector<int>> ret(n, std::vector<int>(n, -1));
  const auto valid = [&](int x, int y) { return x >= 0 && x < n && y >= 0 && y < n && !vis[x][y]; };
  struct st { int x, y, d; };
  std::queue<st> q;
  q.push({0, 0, 0});
  while(q.size()) {
    const auto [x, y, d] = q.front(); q.pop();
    if (vis[x][y]) { continue; } vis[x][y] = 1;
    ret[x][y] = d;
    for(auto [dx, dy] : delta) {
      if (valid(x-dx, y-dy)) { q.push({x-dx, y-dy, d+1}); }
      if (valid(x+dx, y-dy)) { q.push({x+dx, y-dy, d+1}); }
      if (valid(x-dx, y+dy)) { q.push({x-dx, y+dy, d+1}); }
      if (valid(x+dx, y+dy)) { q.push({x+dx, y+dy, d+1}); }
    }
  }
  orep(i, 0, n) {
    orep(j, 0, n) {
      std::cout << ret[i][j] << " ";
    } NL;
  }

  return 0;
}
