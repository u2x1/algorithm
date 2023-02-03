#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long x, y, k, n; std::cin >> x >> y >> k >> n;
  long long rawN = n;
  long long T; std::cin >> T;
  long long acc = 0;
  while(n) {
    acc += n;
    T -= n * x;
    if (T <= 0) { std::cout << rawN - n + 1; return 0; }
    if (acc >= k) { x += acc/k*y; acc %= k; }
    --n;
  }

  std::cout << -1;

  return 0;
}
