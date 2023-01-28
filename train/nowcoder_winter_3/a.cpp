#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n; std::cin >> n;
  long long ret = 0;
  int tmp;
  while (n--) {
    std::cin >> tmp;
    if (tmp <= 0) {
      ret += tmp;
    } else {
      while(tmp && !(tmp&1)) {
        tmp >>= 1;
      }
      ret += tmp;
    }
  }
  std::cout << ret;

  return 0;
}
