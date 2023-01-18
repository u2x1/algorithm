#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    int ret = 0;
    int tmp; while(n--) {
      std::cin >> tmp;
      if (tmp) { ret++; }
    }
    std::cout << ret << NL;
  }

  return 0;
}
