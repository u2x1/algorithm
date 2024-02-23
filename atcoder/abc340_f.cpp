#include "bits/stdc++.h"

#define all(x)   x.begin(), x.end()
#define NL       std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

std::pair<lnt, lnt> exgcd(lnt a, lnt b) {
  if (b == 0) { return {1, 0}; }
  auto [y, x] = exgcd(b, a % b);
  y -= a / b * x;
  return {x, y};
}

int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  lnt a, b; std::cin >> a >> b;
  lnt g = std::__gcd(a, b);
  if (std::abs(g) >= 3) { std::cout << -1; return 0; }
  auto [x, y] = exgcd(b, -a);
  x = x * 2 / g;
  y = y * 2 / g;
  std::cout << x << " " << y;

  return 0;
}
