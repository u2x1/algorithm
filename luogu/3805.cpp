#include <iostream>
#include <algorithm>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e7+5;
int arr[maxN];
int d[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::string raw; std::cin >> raw;
  std::string s = "#";
  for(const auto x : raw) { s += x; s += '#'; }

  for(int i = 0, l = 0, r = -1; i < s.size(); ++i) {
    int k = (i > r) ? 1 : (std::min(r-i+1, d[l+r-i]));
    while(i-k >= 0 && i+k < s.size() && s[i-k] == s[i+k]) { ++k; }
    d[i] = k--;
    if (i+k > r) { l = i-k; r = i+k; }
  }

  std::cout << -1+*std::max_element(d, d+s.size());

  return 0;
}
