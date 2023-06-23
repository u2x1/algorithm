#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, k; std::cin >> n >> k;
  long long ret = 0;
  orep(i, 1, n+1) {
    orep(j, 1, k+1) {
      ret += i*100+j;
    }
  }
  std::cout << ret;

  return 0;
}
