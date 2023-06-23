#include <iostream>
#include <vector>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e3+5;
int fa[maxN];
int find(int x) { return x == fa[x] ? x : (fa[x] = find(fa[x])); }

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  int m; std::cin >> m;
  orep(i, 1, 2*n+1) { fa[i] = i; }
  std::string s; int x, y;
  orep(i, 0, m) {
    std::cin >> s >> x >> y;
    if (s == "E") {
      fa[find(n+y)] = find(x);
      fa[find(n+x)] = find(y);
    } else {
      fa[find(x)] = find(y);
    }
  }
  int cnt = 0;
  orep(i, 1, n+1) {
    cnt += find(i) == i;
  }
  std::cout << cnt;

  return 0;
}
