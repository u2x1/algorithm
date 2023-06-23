#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    std::string s; int _; std::cin >> _ >> s;
    auto p = 0ul;
    if (s[p] != 'm' && s[p] != 'M') { std::cout << "NO"; NL; continue; }
    while (p != s.size() && (s[p] == 'm' || s[p] == 'M')) { ++p; }
    if (p == s.size() || (s[p] != 'e' && s[p] != 'E')) { std::cout << "NO"; NL; continue; } 
    while (p != s.size() && (s[p] == 'e' || s[p] == 'E')) { ++p; }
    if (p == s.size() || (s[p] != 'o' && s[p] != 'O')) { std::cout << "NO"; NL; continue; } 
    while (p != s.size() && (s[p] == 'o' || s[p] == 'O')) { ++p; }
    if (p == s.size() || (s[p] != 'w' && s[p] != 'W')) { std::cout << "NO"; NL; continue; } 
    while (p != s.size() && (s[p] == 'w' || s[p] == 'W')) { ++p; }
    if (p != s.size()) { std::cout << "NO"; NL; continue; }
    std::cout << "YES"; NL;
  }

  return 0;
}
