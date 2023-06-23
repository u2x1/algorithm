#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 1e3+5;
int arr[maxN];
std::vector<int> e[maxN];

int fa[maxN];
int find(const int x) { return x==fa[x] ? x : (fa[x] = find(fa[x])); }

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  int m; std::cin >> m;
  orep(i, 1, n+1) { fa[i] = i; }
  int cnt = n;
  std::string s; int a, b;
  orep(i, 0, m) {
    std::cin >> s >> a >> b; if (s == "E") { e[a].emplace_back(b); e[b].emplace_back(a); }
    else {
      if (find(a) == find(b)) { continue; }
      fa[fa[a]] = fa[b]; --cnt;
    }
  }
  orep(i, 1, n+1) {
    for(auto x : e[i]) {
      for(auto y : e[i]) {
        if (x == y) { continue; }
        if (find(x) == find(y)) { continue; }
        fa[fa[x]] = fa[y]; --cnt;
      }
    }
  }
  std::cout << cnt;

  return 0; }
