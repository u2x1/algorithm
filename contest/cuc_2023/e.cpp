#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 3+5;
int a[maxN][maxN];

int dfs(const int x, const int y, const int depth) {
  bool flag = 1;
  orep(i, 0, 3) {
    orep(j, 0, 3) {
      if (a[i][j] || !flag) { flag = 0; break; }
    }
  }
  if (flag) { return depth; }
  if (depth > 7) { return 100; }
  const int bk = a[x][y];
  const int bk1 = a[std::min(x+1, 2)][y], bk2 = a[std::max(x-1, 0)][y];
  const int bk3 = a[x][std::min(y+1, 2)], bk4 = a[x][std::max(y-1, 0)];
  a[x][y] = !bk;
  a[std::min(x+1, 2)][y] = !bk1;
  a[std::max(x-1, 0)][y] = !bk2;
  a[x][std::min(y+1, 2)] = !bk3;
  a[x][std::max(y-1, 0)] = !bk4;
  int ret = 100;
  orep(i, 0, 3) {
    orep(j, 0, 3) {
      if (i == x && j == y) { continue; }
      ret = std::min(ret, dfs(i, j, depth+1));
    }
  }
  a[x][y] = bk;
  a[std::min(x+1, 2)][y] = bk1;
  a[std::max(x-1, 0)][y] = bk2;
  a[x][std::min(y+1, 2)] = bk3;
  a[x][std::max(y-1, 0)] = bk4;
  return ret;
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  orep(i, 0, 3) {
    orep(j, 0, 3) {
      std::cin >> a[i][j];
    }
  }
  int ret = 100;
  orep(i, 0, 3) {
    orep(j, 0, 3) {
      ret = std::min(ret, dfs(i, j, 0));
    }
  }
  std::cout << ret;

  return 0;
}
