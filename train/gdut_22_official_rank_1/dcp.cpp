#include <iostream>
#include <cstring>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long n; std::cin >> n;
  long long ret = 0;
  orep(ii, 1, n+1) {
    int i = ii;
    if (!(i%10 > 0 && i%10 < 4)) { continue; }
    i/=10;
    while(i) {
      if (i%10 > 3) { goto fend; }
      i/=10;
    }
    ret++;
fend:;
     // std::cout << ii << ": " << ret; NL;
  }

  std::cout << ret;
  return 0;
}
