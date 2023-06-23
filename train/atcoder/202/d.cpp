#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 60+5;
long long comb[maxN][maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);

  orep(i, 0, 61) {
    comb[i][0] = 1;
    orep(j, 1, 61) {
      if (!i) { continue; }
      comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
    }
  }

  long long a, b, k; std::cin >> a >> b >> k;
  while(k > 1) {
    for(long long i = a+b-1; ~i; --i) {
      long long aslot = a+b-1-i-(b-1);
      if (aslot < 0) { continue; }
      long long c = comb[a+b-1-i][aslot];
//      std::cerr << a+b-1-i << " " << aslot << std::endl;
//      std::cout << i << " "<< aslot << " " << c; NL;
      if (k > c) { k -= c; continue; }
      else {
        std::cout << std::string(a-aslot, 'a') << 'b';
        a -= a-aslot; b -= 1;
        break;
      }
      // break;
      // std::cout << k << "0000"; NL;
    }
  }
  std::cout << std::string(a, 'a') << std::string(b, 'b');

  return 0;
}
