#include "bits/stdc++.h"

#define all(x)   x.begin(), x.end()
#define NL       std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = ~(1ll << 63);

int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  lnt n, k; std::cin >> n >> k;
  std::vector<lnt> xs(n), ys(n);
  for (int i = 0; i < n; ++i) { std::cin >> xs[i] >> ys[i]; }
  std::sort(all(xs));
  std::sort(all(ys));
  std::vector<lnt> sumx(n+2), sumy(n+2);
  std::vector<lnt> rsumx(n+2), rsumy(n+2);
  for (int i = 1; i <= n; ++i) {
    sumx[i] = sumx[i-1] + xs[i-1];
    sumy[i] = sumy[i-1] + ys[i-1];
  }
  for (int i = n; i >= 1; --i) {
    rsumx[i] = rsumx[i+1] + xs[i-1];
    rsumy[i] = rsumy[i+1] + ys[i-1];
  }
  auto check = [&](int limit) -> bool {
    lnt minx = linf;
    for (int l = 0, r = 0; l < n; ++l) {
      while (r < n && xs[r] - xs[l] <= limit) {
        ++r;
      }
      lnt cost = (xs[l] * (l) - sumx[l]) + (rsumx[r+1] - (xs[l]+limit) * (n-r));
      minx = std::min(cost, minx);
    }
    for (int l = n-1, r = n-1; r > -1; --r) {
      while (l > -1 && xs[r] - xs[l] <= limit) {
        --l;
      }
      lnt cost = ((xs[r]-limit) * (l+1) - sumx[l+1]) + (rsumx[r+2] - (xs[r]) * (n-1-r));
      minx = std::min(cost, minx);
    }
    lnt miny = linf;
    for (int l = 0, r = 0; l < n; ++l) {
      while (r < n && ys[r] - ys[l] <= limit) {
        ++r;
      }
      lnt cost = (ys[l] * (l) - sumy[l]) + (rsumy[r+1] - (ys[l]+limit) * (n-r));
      miny = std::min(cost, miny);
    }
    for (int l = n-1, r = n-1; r > -1; --r) {
      while (l > -1 && ys[r] - ys[l] <= limit) {
        --l;
      }
      lnt cost = ((ys[r]-limit) * (l+1) - sumy[l+1]) + (rsumy[r+2] - (ys[r]) * (n-1-r));
      miny = std::min(cost, miny);
    }
    // std::cout << "limit1 " << limit << ": " << minx << "," << miny; NL;
    return (minx + miny) <= k;
  };
  int l = -1, r = 1e9+1;
  while (l < r - 1) {
    int mid = l + ((r - l) >> 1);
    if (check(mid)) { r = mid; }
    else {
      l = mid;
    }
  }
  std::cout << r;

  return 0;
}
