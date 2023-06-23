#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

int cal(bool up, int m, int cur, int fin) {
  if (cur == fin) { return 0; }
  if (cur < fin) {
    if (up) {
      return fin - cur;
    } else {
      return cur-1+fin-1;
    }
  } else {
    if (up) {
      return m-cur+m-fin;
    } else {
      return cur - fin;
    }
  }
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  std::vector<std::array<int, 4>> v(n);
  int o = 0;
  for(auto &[idx, x, y, z] : v) { idx = o++; std::cin >> x >> y >> z; }
  std::sort(all(v), [&](auto a, auto b) { return a[3] < b[3]; });
  int idx = 0;
  int curf = 0; bool up = 1;
  std::vector<int> ret(n);
  for(int t = 0; t < 1e8+5; ++t) {
    if (up) {
      if (++curf == m) { up = 0;}
    } else {
      if (--curf == 1) { up = 1;}
    }
    // std::cout << "t: "  << t << " , " << curf; NL;
    if (idx == n || v[idx][3] != t) { continue; }
    while(idx < n && v[idx][3] == t) {
      auto [id, s, f, _] = v[idx];
      if (s == f) { ret[id] = _; ++idx; continue; }
      ret[id] = _+cal(up, m, curf, s);
      // std::cout << "cal "<< ret[id]; NL;
      bool cu = up;
      if (up && curf > s || !up && curf < s) {
        cu = !up; 
      }
      ret[id] += cal(cu, m, s, f);
      // std::cout << "ret " << id << " IS " << ret[id]; NL;
      ++idx;
    }
  }
  for(auto x : ret) { std::cout << x; NL; }


  return 0;
}
