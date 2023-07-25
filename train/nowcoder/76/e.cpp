#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    std::vector<int> sum(s.size()+1);
    orep(i, 1ul, s.size()+1) { sum[i] = sum[i-1] + (s[i-1] == ')'); }
    std::vector<int> lt, rt;
    orep(i, 0ul, s.size()) {
      if (s[i] == '(') { lt.emplace_back(i+1); }
      else { rt.emplace_back(i+1); }
    }
    if (rt.size() != lt.size()) { std::cout << -1; NL; continue; }
    long long ret = 0;
    orep(i, 0ul, lt.size()) {
      if (rt[i] > lt[i]) { continue; }
      ret -= sum[lt[i]]-sum[rt[i]];
      // std::cout << ret << " ";
      ret += lt[i] - rt[i];
      // std::cout << ret; NL;
    }
    std::cout << ret; NL;
  }

  return 0;
}
