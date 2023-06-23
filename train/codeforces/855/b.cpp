#include <iostream>
#include <cctype>
#include <map>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n, k; std::cin >> n >> k;
    std::string s; std::cin >> s;
    std::map<char, int> mp;
    for(auto x : s) {
      mp[x]++;
    }
    int ret = 0;
    int offset = 'A'-'a';
    for(char c = 'a'; c <= 'z'; ++c) {
      int d = std::min(mp[c], mp[c+offset]);
      ret += d;
      int rest = std::max(mp[c], mp[c+offset]) - d;
      if (rest / 2 && k) {
        int add = std::min(rest/2, k);
        k -= add;
        ret += add;
      }
    }
    std::cout << ret; NL;
  }

  return 0;
}
