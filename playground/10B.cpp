#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'
#define int long long

int cal(int l, int r) {
  if (l >= 0) {
    return (l+r)*(r-l+1)/2;
  } else if (r > 0) {
    return cal(0, -l) + cal(0, r);
  } else {
    return cal(-r, -l);
  }
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, k; std::cin >> n >> k;
  int cx = (k+1)/2, cy = (k+1)/2;
  std::vector<std::vector<int>> mp(k+1, std::vector<int>(k+1));
  ;
  orep(_, 0, n) {
    int x; std::cin >> x;
    int cost = 1ll<<60; int a, b, c;
    orep(i, 1, k+1) {
      std::vector<int> sum(k+1);
      orep(j, 1, k+1){ sum[j] = sum[j-1] + mp[i][j]; }
      for(int j = 1; j+x-1 <= k; ++j) {
        if (sum[j+x-1]-sum[j-1]) { continue; }
        int curcost = labs(cx-i)*x+cal(j-cy, j+x-1-cy);
        if (cost > curcost) { cost = curcost; a = i; b = j; c = j+x-1; }
      }
    }
    if (cost != 1ll<<60) {
      orep(i, b, c+1) { mp[a][i] = 1; }
      std::cout << a << " " << b << " " << c; NL;
    } else {
      std::cout << -1; NL;
    }
  }

  return 0;
}
