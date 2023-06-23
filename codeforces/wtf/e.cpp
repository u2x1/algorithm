#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

void solve() {
  int n; std::cin >> n;
  std::string s; std::cin >> s;
  if (n & 1) { std::cout << -1; NL; return; }
  std::map<char, int> mp; mp.clear();
  int ret = 0;
  for(const auto &c : s) {
    mp[c]++;
    if (mp[c] > n/2) { std::cout << -1; NL; return; }
  }
  mp.clear();
  for(auto i = 0, j = n-1; i < j; ++i, --j) {
    if (s[i] == s[j]) { mp[s[i]]++; }
  }
  std::vector<int> v(0);
  int sum = 0;
  for(const auto &[_, x] : mp) { v.push_back(x); sum += x; }
  if (!v.size()) { std::cout << 0; NL; return; }
  std::sort(v.rbegin(), v.rend());
  if (v[0] > sum-v[0]) { ret = v[0]; }
  else { ret = sum/2+(sum&1); }
  std::cout << ret; NL;
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
