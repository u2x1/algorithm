#include <iostream>
#include <vector>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

long long N, M, K;
std::string s;
std::vector<long long> xpos;

long long f(long long k) {
  return xpos[k%xpos.size()] + N*(k/xpos.size());
}

long long g(long long l, long long r) {
  if (r >= M*N) { r = M*N-1; }
  return r - l + 1;
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> N >> M >> K;
  std::cin >> s;
  orep(i, 0, N) {
    if (s[i] == 'x') { xpos.emplace_back(i); }
  }
  long long ret = g(0, f(K)-1);
  orep(i, 0ul, xpos.size()) {
    ret = std::max(ret, g(f(i)+1, f(i+K+1)-1));
  }
  std::cout << ret;

  return 0;
}
