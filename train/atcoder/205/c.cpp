#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long a, b, c; std::cin >> a >> b >> c;
  if (a == b || c == 0) { std::cout << "="; return 0; }
  c &= 1;
  if (!c) { a = a*a; b = b*b; }
  if (a == b) { std::cout << "="; }
  else { std::cout << (a < b ? "<" : ">"); }

  return 0;
}
