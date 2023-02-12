#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::string str; std::cin >> str;
  // (ascii(0)=48) % 4 == 0 ===> ascii(4) % 4 == 0
  if (str.size() > 1) { std::cout << ((str[str.size()-2] * 10 + str[str.size()-1]) % 4 ? 0 : 4); }
  else { std::cout << (str[str.size()-1] % 4 ? 0 : 4); }

  return 0;
}
