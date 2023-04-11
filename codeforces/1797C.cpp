#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

int ask(const int a, const int b) {
  int ret;
  std::cout << "? " << a << " " << b << std::endl;
  std::cin >> ret;
  return ret;
}

void give(const int a, const int b) { std::cout << "! " << a << " " << b << std::endl; }

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t=0; std::cin >> t;
  while(t--) {
    int n, m; std::cin >> n >> m;
    int a = ask(1,1), b, c;
    if (a >= n) {
      b = ask(1, 1+a); give(1+b, 1+a);
    } else if (a >= m) {
      b = ask(1+a, 1); give(1+a, 1+b);
    } else {
      b = ask(1, 1+a); c = ask(1+a, 1);
      if (b < a) { give(b+1, a+1); }
      else if (c <= a) { give(a+1, c+1); }
    }
  }

  return 0;
}
