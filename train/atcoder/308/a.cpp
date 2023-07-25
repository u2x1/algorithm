#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, m; std::cin >> n >> m;
  std::vector<std::string> eat;
  std::string s;
  orep(i, 0, n){  std::cin >> s; eat.push_back(s); }
  std::vector<std::string> pr;
  std::vector<int> p;
  std::map<std::string, int> mp;
  orep(i, 0, m) { std::cin >> s; pr.push_back(s); }
  int tmp;
  orep(i, 0, m+1) { std::cin >> tmp; p.emplace_back(tmp); }
  orep(i, 1, m+1) {
    mp[pr[i-1]] = p[i];
  }
  int ret = 0;
  for(auto x : eat) {
    if (mp.count(x) == 0) { ret += p[0]; }
    else { ret += mp[x]; }
  }
  std::cout << ret;


  return 0;
}
