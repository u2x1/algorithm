#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >>  t;
  while(t--) {
    int n; std::cin >> n;
    std::vector<int> v(n);
    std::map<int, int> mp;
    for(auto &x : v) { std::cin >> x; mp[x]++; }
    int sum = 0;
    int x = 0;
    bool no = 0;
    orep(i, 0, n+1) {
      if (mp[i] == 0 && sum < i) { no = 1; }
      if (no) { std::cout << "-1 "; continue; }
      std::cout << sum - (i+1) + mp[i] << " ";
      sum += mp[i];
    } NL;
  }

  return 0;
}
