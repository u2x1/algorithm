#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::string s; std::cin >> s;
  std::sort(s.begin(), s.end());
  std::string s2 = s;
  std::reverse(s.begin(), s.end());
  int i1 = 0;
  for(int i = s.size()-1; i > -1; --i) {
    i1 = i1*10+s[i];
  }

  int i2 = 0;
  for(int i = s.size()-1; i > -1; --i) {
    i2 = i2*10+s2[i];
  }

  std::cout << i2 - i1;

  return 0;
}
