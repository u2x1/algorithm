#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, a, b, c; std::cin >> n >> a >> b >> c;
  auto l = 0ul, r = 0ul;
  std::string s;
  std::cin >> s;
  int aa = 0, bb = 0, cc = 0;
  long long ret = 0;
  for(; l < s.size(); ++l) {
    while((aa < a || bb < b || cc < c) && r < s.size()) {
      aa += (s[r] == 'R');
      bb += (s[r] == 'M');
      cc += (s[r] == 'B');
      ++r;
    }
    if (aa >= a && bb >= b && cc >= c) {
      ret += s.size()-r+1;
    }
    aa -= (s[l] == 'R');
    bb -= (s[l] == 'M');
    cc -= (s[l] == 'B');
  }
  std::cout << ret;

  return 0;
}
