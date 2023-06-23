#include <iostream>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

int ask(int x) { std::cout << "+ " << x << std::endl; int ret; std::cin >> ret; return ret; }
void give(int x) { std::cout << "! " << x; exit(0); }

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::vector<int> t(1e6);
  int init; std::cin >> init;
  orep(i, 1, 1001) {
    int x = ask(1);
    if (x == init) { give(i); }
    t[x] = i;
  }
  orep(i, 1, 1001) {
    int x = ask(1000);
    if (x == init || t[x]) { give((i+1)*1000-t[x]); }
    t[x] = (i+1)*1000-t[x];
  }

  return 0;
}
