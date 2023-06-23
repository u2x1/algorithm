#include <iostream>
#include <queue>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

const int mod = 998244353;

long long ksm(long long x, long long e) {
  long long ret = 1;
  while(e) {
    if (e & 1) { ret = ret*x%mod; }
    x = x*x%mod; e >>= 1;
  }
  return ret;
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int q; std::cin >> q;
  long long ret = 1; int len = 1;
  std::queue<int> v; v.push(1);
  while(q--) {
    int e; std::cin >> e;
    if (e == 1) { 
      int a; std::cin >> a;
      v.push(a); ++len;
      ret = (ret*10%mod + a) % mod;
    } else if (e == 2) {
      long long t = v.front(); v.pop();
      ret = (ret - t*ksm(10, len-1)%mod+mod)%mod;
      --len;
    } else if (e == 3) {
      std::cout << ret; NL;
    }
  }

  return 0;
}
