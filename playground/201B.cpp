#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  std::vector<std::vector<int>> mp(n, std::vector<int>(m));
  orep(i, 0, n) {
    orep(j, 0, m) {
      std::cin >> mp[i][j];
    }
  }
  // if (n == 1  && m == 1) { std::cout << mp[0][0]*8; NL; std::cout << "0 0"; exit(0); }
  std::vector<long long> ls(n), cs(m);
  orep(i, 0, n) {
    ls[i] = std::accumulate(all(mp[i]), 0ll);
  }
  orep(j, 0, m) {
    orep(i, 0, n) {
      cs[j] += mp[i][j];
    }
  }

  std::vector<long long> ver(n), hor(m);
  orep(x, 0, n) {
    long long ret = 0;
    long long init = 2 -x*4;
    orep(i, 0, n) {
      ret += ls[i]*(init*init);
      init += 4;
    }
    ver[x] = ret;
  }

  orep(y, 0, m) {
    long long ret = 0;
    long long init = 2 -y*4;
    orep(i, 0, m) {
      ret += cs[i]*(init*init);
      init += 4;
    }
    hor[y] = ret;
  }

  auto cal = [&](int x, int y) {
    long long ret = 0;
    ret = ver[x] + hor[y];
    // std::cout << ver(x) << " " << hor(y); NL;
    return ret;
  };

  long long ret = 1e18;
  int x, y;
  orep(i, 0, n) {
    orep(j, 0, m) {
      if (ret > cal(i, j)) {
        x = i; y = j;
        ret = cal(i, j);
      }
    }
  }
  std::cout << ret; NL;
  std::cout << x << " " << y;

  return 0;
}
