#include <iostream>
#include <cmath>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

long long cal(const long long x, int k) {
  long long cur = 1ll<<k;
  long long ret = 1;
  while(cur != x) {
    ++ret; --k;
    if (cur < x) {
      ret += (1ll<<(k+1))-1;
      cur += (1ll<<k);
    } else {
      cur -= (1ll<<k);
    }
  }
  return ret; 
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int k, q; std::cin >> k >> q;
  while(q--) {
    long long x;
    std::cin >> x;
    if (x == 1ll<<k) { std::cout << 1 << " " << x << " " << x; NL; }
    else { std::cout << cal(x, k) << " " << x << " " << cal(x,k) - (long long)(k - log2(x&(-x))) + ((x&(-x))-1)*2; NL; }
  }

  return 0;
}
