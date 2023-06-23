#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];
std::vector<int> son[maxN];
int in[maxN], out[maxN];
int dep[maxN];

std::vector<std::pair<int, int>> vs[maxN];

int _t;

void dfs(int x) {
  in[x] = _t++;
  for(auto u : son[x]) {
    dep[u] = dep[x] + 1;
    dfs(u);
    vs[dep[u]].emplace_back(in[u], u);
  }
  out[x] = _t++;
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int N; std::cin >> N;
  orep(i, 2, N+1) { int p; std::cin >> p; son[p].emplace_back(i); }
  orep(i, 1, N+1) { std::sort(vs[i].begin(), vs[i].end()); }
  int Q; std::cin >> Q;
  vs[0].emplace_back(0, 1); dfs(1);
  orep(i, 0, Q) {
    int U, D; std::cin >> U >> D;
    // for(auto [x, y] : vs[D]) { std::cout << x << "," << y << " "; }
    auto l = std::lower_bound(vs[D].begin(), vs[D].end(), std::make_pair(in[U], 0));
    auto r = std::lower_bound(vs[D].begin(), vs[D].end(), std::make_pair(out[U], 0));
    // std::cout << *l << " - " << *r;
    std::cout << r - l; NL;
  }

  return 0;
}
