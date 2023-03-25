#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];
int s, t;

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> s >> t;
  long long ret = 0;
  for(long long a = 0ll; a <= s; ++a) {
    for(long long b = a; a+b <= s; ++b) {
      if (a*b*b > t || a+b+b > s) { continue; }
      int l = b, r = s-(a+b)+1;
      while(l < r-1) {
        const int mid = (l+r) >> 1;
        if ((a*b*mid <= t)) { l = mid; }
        else { r = mid; }
      }
      ret += l-b+1;
    }
  }
  std::cout << ret;

  return 0;
}
