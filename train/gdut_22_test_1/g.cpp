#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
long long arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  int cnt = 0;
  orep(i, 1, m) {
    if (std::__gcd(i, m) == 1) { arr[cnt++] = i; }
  }
  orep(i, 0, n) {
    long long tmp; std::cin >> tmp;
    --tmp;
    std::cout << arr[tmp%cnt] + (tmp/cnt)*m << " ";
  }

  return 0;
}
