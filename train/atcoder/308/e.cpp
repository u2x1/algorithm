#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<int> v(n);
  for(auto &x : v) { std::cin >> x; }
  std::string s; std::cin >> s;
  std::vector ms(n, std::vector<long long>(3, 0ll));
  std::vector xs(n, std::vector<long long>(3, 0ll));
  orep(i, 1, n) {
    char c = s[i-1];
    ms[i] = ms[i-1];
    if (c == 'M') { ms[i][v[i-1]]++; }
  }
  for(int i = n-2; i > -1; --i) {
    char c = s[i+1];
    xs[i] = xs[i+1];
    if (c == 'X') { xs[i][v[i+1]]++; }
  }
  long long ret = 0;
  orep(i, 0, n) {
    if (s[i] != 'E') { continue; }
    orep(a, 0, 3) {
      orep(b, 0, 3) {
        long long x = 0;
        std::set<int> vv { a, b, v[i] };
        for(auto y : vv) { if (y != x) { break; } ++x; }
        ret += x * ms[i][a] * xs[i][b];
      }
    }
  }
  std::cout << ret;

  return 0;
}
