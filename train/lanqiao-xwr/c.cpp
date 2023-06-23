#include <iostream>
#include <functional>
#include <vector>
#include <cctype>
#include <map>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

#define int long long

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::string s, _;
  while(std::cin >> _) { s += _; }
  std::map<char, int> mp;
  mp['+'] = 1;
  mp['-'] = 2;
  mp['*'] = 3;
  mp['/'] = 4;
  std::map<char, std::function<int(int, int)>> ff;
  ff[mp['*']] = [](int x, int y) { return x * y; };
  ff[mp['/']] = [](int x, int y) { return x / y; };
  ff[mp['-']] = [](int x, int y) { return x - y; };
  ff[mp['+']] = [](int x, int y) { return x + y; };

  std::vector<int> v;
  int n = s.size();
  orep(i, 0, n) {
    if (!isdigit(s[i])) { v.emplace_back(mp[s[i]]); continue; }
    int x = 0;
    for(; isdigit(s[i]); ++i) {
      x = x*10 + s[i]-'0';
    } --i;
    if (v.size() && v.back() >= 3) {
      int op = v.back(); v.pop_back();
      int y = v.back(); v.pop_back();
      v.emplace_back(ff[op](y, x));
    } else {
      v.emplace_back(x);
    }
  }
  int ret = v.front();
  orep(i, 1, v.size()) {
    int op = v[i];
    int y = v[++i];
    ret = ff[op](ret, y);
  }
  std::cout << ret;

  return 0;
}
