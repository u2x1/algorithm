#include <iostream>
#include <cmath>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 1e6+5;
long long p[maxN]; bool vis[maxN]; long cnt;

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  for(int i = 2; i < maxN; ++i) {
    if (!vis[i]) { p[cnt++] = i; }
    for(int j = 0; j < cnt && i * p[j] < maxN; ++j) {
      vis[i*p[j]] = 1;
      if (i % p[j] == 0) { break; }
    }
  }
  long long N; std::cin >> N;
  int ret = 0;
  for(auto c = std::min(cnt-1, std::upper_bound(p, p+cnt, (int)sqrtl(N)) - p - 1); ~c; --c) {
    for(auto b = std::min(c-1, std::upper_bound(p, p+c, N/(p[c]*p[c])) - p - 1); ~b; --b) {
      ret += std::min(b-1, std::upper_bound(p, p+b, (int)sqrtl(N/(p[c]*p[c]*p[b]))) - p - 1) + 1;
    }
  }
  std::cout << ret;

  return 0;
}

