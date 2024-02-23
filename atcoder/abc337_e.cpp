#include "bits/stdc++.h"

#define all(x)   x.begin(), x.end()
#define NL       std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int n; std::cin >> n;
  int p = std::__lg(n-1) + 1;
  std::vector<std::vector<int>> serve(p);
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < p; ++j) {
      if ((i >> j) & 1) {
        serve[j].emplace_back(i+1);
      }
    }
  }
  std::cout << p; NL;
  for (int i = 0; i < p; ++i) {
    std::cout << serve[i].size() << " ";
    for (auto x : serve[i]) { std::cout << x << " "; } NL;
  }
  std::cout.flush();
  std::string s; std::cin >> s;
  std::reverse(all(s));
  int ret = 0;
  for (int i = 0; i < p; ++i) {
    ret = ret * 2 + (s[i] == '1');
  }
  std::cout << ret + 1;

  return 0;
}
