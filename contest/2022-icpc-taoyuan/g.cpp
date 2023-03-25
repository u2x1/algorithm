#include <iostream>
#include <map>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

std::string s;

bool check(const int x, std::string &ret) {
  std::map<std::string, int> cnt;

  for(auto i = 0ul; i+x <= s.size(); i++) {
    // std::cout << s.substr(i, x)  << " "<<
      ++cnt[s.substr(i, x)]; 
    // NL;
  }

  auto j = 0ul;
  for(auto i = 0ul; i+x <= s.size(); i++) {
    while(j < i+x) { cnt[s.substr(j, x)]--; j++; }
    if (cnt[s.substr(i, x)]) { ret = s.substr(i,x); return 1; }
  }
  return 0;
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    std::cin >> s;
    std::string ret;
    int l = 1, r = s.size();
    while(l < r-1) {
      const int mid = (l+r) >> 1;
      if (check(mid, ret)) { l = mid; }
      else { r = mid; }
    }
    std::cout << ret; NL;
  }

  return 0;
}
