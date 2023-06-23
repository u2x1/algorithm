#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n ;std::cin >>n;
  std::string s, a; std::cin >> s; std::cin >> a;
  for(auto &x : s) {
    if (x == '1')  { x = 'l'; }
    if (x == '0')  { x = 'o'; }
  }
  for(auto &x : a) {
    if (x == '1')  { x = 'l'; }
    if (x == '0')  { x = 'o'; }
  }
  std::cout << (s == a ? "Yes" : "No");

  return 0;
}
