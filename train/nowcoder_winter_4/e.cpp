#include <iostream>
#include <cmath>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, t, a; std::cin >> n >> t >> a;
  long long ret = -1;
  orep(i, 0, n) {
    int h, v; std::cin >> h >> v;
    if (h <= a) { ++ret; continue; }
    if ((v*t) >= a) { std::cout << "-1"; return 0; }
    const int att = a - (v*t);
    ret += ceil(1.0*(h-a)/att) + 1;
  }
  std::cout << 1+ret*t;

  return 0;
}
