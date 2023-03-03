#include <iostream>
#include <cstring>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 1e4+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::string s; std::cin >> s;
  int g=0, p=0, l=0, t=0;
  orep(i, 0ul, s.size()) {
    switch(s[i]) {
      case 'g':
      case 'G':
        ++g; break;
      case 'p':
      case 'P':
        ++p; break;
      case 'l':
      case 'L':
        ++l; break;
      case 't':
      case 'T':
        ++t; break;
    }
  }
  while(g || p || l || t) {
    if (g) { std::cout << 'G'; --g; }
    if (p) { std::cout << 'P'; --p; }
    if (l) { std::cout << 'L'; --l; }
    if (t) { std::cout << 'T'; --t; }
  }

  return 0;
}
