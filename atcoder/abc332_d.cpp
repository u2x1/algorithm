#include "bits/stdc++.h"

#define all(x)   x.begin(), x.end()
#define NL       std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  std::vector mp1(n, std::vector<int>(m));
  std::vector mp2(n, std::vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> mp1[i][j]; 
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> mp2[i][j]; 
    }
  }
  std::set<lnt> vis;
  std::queue<std::array<int, 11>> q;
  
  auto hash = [&](auto x) {
    lnt ret = 0;
    for (int i = 0; i < n+m; ++i) {
      ret = ret * 10 + x[i];
    }
    return ret;
  };
  {
    std::array<int, 11> x;
    for (int i = 0; i < n+m; ++i) {
      if (i < n) { x[i] = i; }
      else { x[i] = i - n; }
    }
    q.push(x);
    vis.insert(hash(x));
  }
  int ret = inf;
  while (!q.empty()) {
    auto t = q.front(); q.pop();
    int flag = 1;
    for (int i = 0; i < n; ++i) { 
      for (int j = 0; j < m; ++j) {
        flag &= (mp1[t[i]][t[j+n]] == mp2[i][j]);
      }
    }
    // for (auto x : t) { std::cout << x << " "; } NL;
    if (flag == 1) {
      // for (auto x : t) { std::cout << x << " "; } NL;
      ret = t[10]; break;
    }
    for (int i = 0; i < n+m-1; ++i) {
      if (i == n-1) { continue; }
      auto x = t;
      x[10] ++;
      std::swap(x[i], x[i+1]);
      lnt h = hash(x);
      if (vis.contains(h)) { continue; }
      vis.insert(h);
      q.push(x);
    }
  }
  std::cout << (ret == inf ? -1 : ret);


  return 0;
}
