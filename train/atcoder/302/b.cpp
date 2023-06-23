#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
std::string arr[maxN];
int H, W;
std::string s = "snuke";

void out(int x, int y, int dx, int dy, int d = 0) {
  std::cout << x+1 << " " << y+1; NL;
  if (d == 4) { exit(0); }
  out(x+dx, y+dy, dx, dy, d+1);
}

bool dfs(int x, int y, int dx, int dy, int d = 0) {
  if (x < 0 || x >= H || y < 0 || y >= W) { return 0; }
  if (arr[x][y] != s[d]) { return 0; }
  if (d == 4) { out(x-4*dx, y-4*dy, dx, dy); }
  return dfs(x+dx, y+dy, dx, dy, d+1);
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> H >> W;
  orep(i, 0, H) { std::cin >> arr[i]; }
  orep(i, 0, H) orep(j, 0, W) {
    dfs(i, j, 1, 0);
    dfs(i, j, -1, 0);
    dfs(i, j, 0, 1);
    dfs(i, j, 0, -1);
    dfs(i, j, 1, 1);
    dfs(i, j, 1, -1);
    dfs(i, j, -1, -1);
    dfs(i, j, -1, 1);
  }


  return 0;
}
