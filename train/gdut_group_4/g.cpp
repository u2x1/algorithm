#include <iostream>
#include <map>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

std::map<std::pair<int, int>, int> mp;
int t;

struct DSU {
  std::vector<int> fa, ret;
  DSU(int n) {
    fa = std::vector<int>(n);
    ret = std::vector<int>(n);
    orep(i, 0, n) { fa[i] = i; ret[i] = 6; }
  }
  int ans(int x) { return ret[find(x)]; }
  int find(int x) { return x == fa[x] ? x : (fa[x] = find(fa[x])); }
  void setfa(int x, int _fa) {
    int fa1 = find(x), fa2 = find(_fa);
    if(fa1 == fa2) { ret[fa1] -= 2; return; }
    ret[fa2] = ret[fa2]+ret[fa1]-2;
    fa[fa1] = fa2;
  }
};

struct Query { int a, b, c; };
signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<Query> qs;
  orep(i, 0, n) {
    int a, b, c; std::cin >> a >> b >> c;
    qs.push_back({a, b, c});
    if (mp.count({b, c}) == 0) { mp[std::make_pair(b,c)] = t++; }
  }
  DSU dsu(t);
  std::vector<char> vis(t);
  auto add = [&](int x, int y, int u) {
    auto v = std::make_pair(x, y);
    if (mp.count(v) && vis[mp[v]]) { dsu.setfa(mp[v], u); }
  };
  for(auto [a, b, c] : qs) {
    if (a == 1) {
      const int u = mp[std::make_pair(b, c)];
      vis[u] = 1;
      add(b+1, c, u); add(b-1, c, u); add(b, c+1, u); add(b-1, c+1, u); add(b+1, c-1, u); add(b, c-1, u);
    } else {
      std::cout << dsu.ans(mp[std::make_pair(b, c)]); NL;
    }
  }

  return 0;
}
