#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
long long arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long n, m; std::cin >> n >> m;
  if (n == 1) { std::cout << m; return 0; }
  orep(i, 0, n) {
    if (i==n-1) { arr[i] = m; break; }
    if (m & 1) { arr[i] = (m+1) >> 1; }
    else { arr[i] = m >> 1; }
    m -= arr[i];
    if (m == 0) { std::cout << -1; return 0; }
  }
  for(int i = n-1; i >= 0; --i) {
    std::cout << arr[i] << " ";
  }

  return 0;
}
