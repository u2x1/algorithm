#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

struct node { int a, b, idx; };

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<std::vector<node>> v(n+1);
  int xx, yy;
  std::vector<std::array<int, 2>> prs(n+1);
  orep(i, 0, n) {
    int a, b; std::cin >> a >> b;
    if (i == 0) { xx = b; b = 0; }
    if (i == 1) { yy = b; b = 0; }
    v[a].push_back({a, b, i});
    v[b].push_back({a, b, i});
  }
  for(auto y : v) {
    for(auto [a, b, c] : y) {
      std::cout << a << "," << b << "," << c <<  " ";
    } NL;
  }
  prs[n] = { xx, yy };
  int zr1 = 0, zr2 = 1;
  int cnt = 0;
  std::vector<std::pair<int, int>> out;
  orep(_, 1, n) {
    auto [x, y] = prs[zr1]; // y == 0
    int xx, yy, zz;
    for(auto [a, b, c] : v[x]) {
      if (b) { xx = a; yy = b; zz = c; }
    }
    std::cout << x << " " << y; NL;
    std::cout << xx << " " << yy << " " << zz; NL;
    std::cout << zr1 << " " << zr2; NL;
    if (x == yy) {
      prs[zz][1] = 0;
      prs[zr1] = { x, x };
      zr1 = zz;
      out.emplace_back(zz, zr1);
    } else if (x == xx){
      prs[zr2] = { yy, prs[zr2][0] };
      out.emplace_back(zz, zr2);
      prs[zr1] = { x, x };
      out.emplace_back();
      zr1 = zz, zr2 = zz;
      prs[zz] = { 0, 0 };
    }
  }

  std::cout << out.size(); NL;
  for(auto [x, y] : out) { std::cout << x << " " << y; NL; }

  return 0;
}
