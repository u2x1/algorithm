#include <iostream>
#include <string>

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::string s; std::cin >> s;
  int ret = 0;
  s = "0" + s;
  for(int i = s.size()-1; ~i; ) {
    char c = s[i];
    int cnt = 0;
    while(~i && s[i] == c) { --i; ++cnt; }
    if (c == '1') {
      if (cnt > 1) { s[i] = '1'; } 
      ++ret;
    }
  }
  std::cout << ret;

  return 0;
}
