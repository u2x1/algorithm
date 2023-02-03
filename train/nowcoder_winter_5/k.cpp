#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long n; std::cin >> n;
  int cnt = 0;
  while(n > 2) {
    ++cnt; n = (n>>1) + 1;
  }
  std::cout << cnt;

  return 0;
}
