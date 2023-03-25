#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int c[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n, m; std::cin >> n >> m;
    std::vector<std::priority_queue<int, std::vector<int>, std::greater<int>>> ww(27);
    std::string s, cc, p;
    std::cin >> s >> cc >> p;
    orep(i, 0, n) {
      ww[s[i]-'a'].push(cc[i]-'0');
    }
    long long ret = 0;
    orep(i, 0, m) {
      if (ww[p[i]-'a'].empty()) { std::cout << -1; goto fend; }
      ret += ww[p[i]-'a'].top(); ww[p[i]-'a'].pop();
    }
    std::cout << ret;
fend: NL;
  }

  return 0;
}
