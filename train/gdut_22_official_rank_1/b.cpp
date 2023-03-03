#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::string s; std::cin >> s;
  s = '0' + s + '0';
  orep(i, 1ul, s.size()-1) {
    if (s[i] == '1') {
      if (s[i-1] == '1' && s[i+1] == '1') { std::cout << '0'; continue; }
      std::cout << '1'; continue;
    } else {
      if (s[i+1] == '1') { std::cout << '1'; continue; }
      else if (s[i-1] == '1' && s[i+1] != '0') { std::cout << '1'; continue; }
      std::cout << '0';
    }
  }

  return 0;
}
