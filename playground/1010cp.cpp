#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

int mp[10][10];

using ull = unsigned long long;
std::map<ull, int> vis;

int n, m;
int ans;

const ull mod = 1e9+7;

ull h() {
  ull ret = 0;
  for(int i = 0; i <= n+1; ++i) {
    for(int j = 0; j <= m+1; ++j) {
      ret *= 2;
      ret += mp[i][j];
    }
  }
  return ret;
}

void dfs() {
  if (vis[h()]) { return; }
  vis[h()] = 1;
  static auto f = [&](int x, int y, int sx, int sy, int tx, int ty) { 
    if (!mp[x][y] || mp[x+tx][y+ty] || !mp[x+sx][y+sy]) { return; }
    mp[x][y] = 0; mp[x+tx][y+ty] = 1; mp[x+sx][y+sy] = 0;
    dfs();
    mp[x][y] = 1; mp[x+tx][y+ty] = 0; mp[x+sx][y+sy] = 1;

  };

  int o = 0;
  orep(x, 0, n+2) {
    orep(y, 0, m+2) {
      o += mp[x][y];
    }
  }
  orep(x, 1, n+1) {
    orep(y, 1, m+1) {
      if (mp[x][y]) {
        f(x, y, 1, 0, -1, 0);
        f(x, y, -1, 0, 1, 0);
        f(x, y, 0, 1, 0, -1);
        f(x, y, 0, -1, 0, 1);
      }
    }
  }

  ans = std::min(ans, o);

}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  orep(a, 1, 7) {
    orep(b, a, 7) {
      n = a, m = b; memset(mp, 0, 100 * sizeof(int));
      orep(i, 1, n+1) { 
        orep(j, 1, m+1) {
          mp[i][j] = 1;
        }
      }
      ans = n*m;
      dfs();
      std::cout << n << " " << m << " = " << ans << std::endl;
    }
  }

  return 0;
}
