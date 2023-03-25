#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long ret = 1;
  std::string a, b; std::cin >> a >> b;
  for(auto l = 0ul; l < a.size()-1; ++l) {
    const int p = b.find(a[l]);
    if (p && a[l+1] == b[p-1]) { ret <<= 1; }
  }
  std::cout << ret;

  return 0;
}
