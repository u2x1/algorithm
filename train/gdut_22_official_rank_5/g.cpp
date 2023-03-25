#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];
int mod = 1e9+7;

long long ksm(long long a, int e) {
  int ret = 1;
  while(e) {
    if (e&1) { ret = (ret * a) % mod; }
    a = (a*a) % mod; e>>=1;
  }
  return ret;
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n, k;
    std::cin >> n >> k;
    if (k&1) { std::cout << 0; }
    long long ret = 0;
    //case 1
    if (n&1) {
      ret += (ksm(2, n/2) + ksm(2, n/2+1)) % mod;
    } else {
      ret += ksm(2, n/2)*2%mod;
    }

    //case 2
    int full = n / k; int rest = n%k;
    orep(i, 0, bbh)
  }

  return 0;
}
