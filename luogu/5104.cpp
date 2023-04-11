#include <iostream>
#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];
const int mod = 1e9+7;

long long ksm(long long x, long long e) {
  long long ret = 1;
  while(e) {
    if (e&1) { ret = (ret*x) % mod; }
    e >>= 1; x = (x*x) % mod;
  }
  return ret;
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long w, n, k; std::cin >> w >> n >> k;
  std::cout << w * ksm(ksm(2, k), mod-2) % mod;


  return 0;
}
