#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::string s; std::cin >> s;
  bool neg = s[0] == '-';
  int pos = s[0] == '-';
  bool even = !((s[s.size()-1] - '0') % 2);
  
  int cnt = 0;
  for(; pos < s.size(); ++pos) {
    if (s[pos] == '2') {
      ++cnt;
    }
  }
  double ret = 100.0*cnt/(s.size()-neg) * (neg ? 1.5 : 1) * (even ? 2 : 1);
  printf("%.2f", ret);
  std::cout << "%";

  return 0;
}
