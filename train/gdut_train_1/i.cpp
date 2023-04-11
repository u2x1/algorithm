#include <iostream>
#include <map>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    std::string s; std::cin >> s;
    std::map<char, int> mp;
    for(const char x : s) {
      mp[x]++;
    }
    int mx = 0;
    for(const auto [x,y] : mp) {
      mx = std::max(mx, y);
    }
    std::cout << s.size() - mx; NL;
  }

  return 0;
}
