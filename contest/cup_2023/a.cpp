#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 0, n) {
    std::string s; std::cin >> s;
    int cur = 0;
    for(auto c : s) {
      if (c == '0') {
        if (cur) { std::cout << (char)(cur+'a'-1); cur = 0; }
      } else {
        cur += (c-'0');
      }
    }
    if (cur) { std::cout << (char)(cur+'a'-1); cur = 0; }
    NL;
  }

  return 0;
}
