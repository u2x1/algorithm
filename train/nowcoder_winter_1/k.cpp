#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  if (n < 3) { std::cout << 0; return 0; }
  if (n == m) { std::cout << m-2; return 0; }
  while(m && n-3 >= m-1) {
    n-=3; m-=1;
  }
  std::cout << (m ? m-1 : 0);

  return 0;
}
