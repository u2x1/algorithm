#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];
bool rated[maxN];
const int mod = 998244353;

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long a = 233333333;
  int x = 1;
  long long val = a;
  while(1) {
    if (val == 972066295) {
      std::cout << x;
      exit(0);
    }
    val = val*a%mod;
    ++x;
  }

  return 0;
}
