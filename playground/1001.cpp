#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const long long inf = 1e16;

int exgcd(int a, int b, int &x, int &y) {
  if (!b) {
    x = 1; y = 0;
    return a;
  }
  int d = exgcd(b, a % b, x, y);
  int t = x;
  x = y;
  y = t - (a / b) * y;
  return d;
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int _; std::cin >> _;
  while(_--) {
    int N, q; std::cin >> N >> q;
    std::vector<std::vector<int>> son(N+1);
    orep(i, 1, N) {
      int a, b; std::cin >> a >> b;
      son[a].emplace_back(b);
      son[b].emplace_back(a);
    }
    auto solve = [&](int sa, int ta, int sb, int tb){
      std::vector<int> pathA, pathB;
      auto initPath = [&](auto &v, auto s, auto t) {
        std::function<bool(int, int)> dfs = [&](int u, int fa) {
          if (u == t) { v.emplace_back(u); return true; }
          bool flag = 0;
          for(auto x : son[u]) {
            if (x == fa) { continue; }
            flag |= dfs(x, u);
          }
          if (flag) { v.emplace_back(u); }
          return flag;
        };
        dfs(s, 0);
        {
          std::vector<int> tmp = v;
          tmp.pop_back();
          std::reverse(all(v));
          v.insert(v.end(), tmp.begin()+1, tmp.end());
        }
      };
      initPath(pathA, sa, ta); initPath(pathB, sb, tb); 
      std::vector<std::array<int, 2>> tiA(N+1, {-1, -1}), tiB(N+1, {-1, -1});
      auto initTime = [](auto &ti, auto path) {
        orep(i, 0, path.size()) {
          if (ti[path[i]][0] != -1) { ti[path[i]][1] = i; }
          else { ti[path[i]] = { i, i }; }
          // std::cout << ti[path[i]][0] << " " << ti[path[i]][1]; NL;
        }
      };
      initTime(tiA, pathA); initTime(tiB, pathB);
      long long n = pathA.size(), m = pathB.size();
      std::pair<long long, int> ret = { inf, -1 };
      orep(u, 1, N+1) {
        orep(i1, 0, 2) {
          orep(i2, 0, 2) {
            long long a = tiA[u][i1], b = tiB[u][i2];
            if (a == -1 || b == -1) { continue; }
            if (n == m && a == b) {
              ret = std::min(ret, {a, u});
            } else {
              int x, y; exgcd(n, m, x, y); int g = std::__gcd(n, m);
              x *=  (b-a) / g;
              int dx = m / g;
              x = ((x % dx + dx) % dx);
              ret = std::min(ret, {x*n+a, u});
            }
          }
        }
      }
      return ret;
    };
    while(q--) {
      int sa, ta, sb, tb; std::cin >> sa >> ta >> sb >> tb;
      auto ret = solve(sa, ta, sb, tb);
      // std::cout << "ret: " << ret.second; NL;
      std::cout << ret.second; NL;
    }
  }

  return 0;
}
