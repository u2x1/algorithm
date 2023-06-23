#include <iostream>
#include <cstdio>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << std::endl

void give(const std::string s) { std::cout << s << std::endl; }
int get() {
  int n; std::string s;
  std::cin >> s; std::cin >> s;
  if (s == "GRANTED") { exit(0); }
  scanf(" (%d ms)", &n);
  return n;
}

int getLen() {
  int ret = 1;
  while(1) {
    give(std::string(ret, 'z'));
    int n = get();
    if (n != 5) { return ret; }
    ++ret;
  }
}

std::string cs = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

signed main() {
  int len = getLen();
  int ms = 12;
  std::string s(len, 'z');
  orep(i, 0, len) {
    for(auto &c : cs) {
      s[i] = c; give(s); const int got = get();
      if (got > ms) {
        i = (got-14)/9-1;
        ms = got;
        break;
      }
    }
  }
}
