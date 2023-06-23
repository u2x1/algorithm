#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << std::endl

const int maxN = 2e5+5;
int arr[maxN];

int ask(int i) {
  std::cout << "? " << i; NL;
  int ret; std::cin >> ret;
  return ret;
}

void give(int i) { std::cout << "! " << i; }

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int N; std::cin >> N;
  int l = 1, r = N;
  while(l < r-1) {
    int m = (l + ((r-l)>>1));
    if (ask(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  give(l);

  return 0;
}
