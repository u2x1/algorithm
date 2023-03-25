#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    std::string s; std::cin >> s;
    if (s[0] >= 'A' && s[0] <= 'Z') { std::cout << "NO"; NL; continue; }
    int cnt  = 1;
    orep(i, 1ul, s.size()) {
      if (s[i] >= 'A' && s[i] <= 'Z') { cnt++; }
      if (cnt > 7) { std::cout << "NO"; NL; goto fend; }
    }
    std::cout << "YES"; NL;
fend:;
  }

  return 0;
}
