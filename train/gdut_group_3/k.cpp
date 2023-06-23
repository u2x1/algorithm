#include <iostream>
#include <string>
#include <map>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];
struct st { int vals[3]{0, 0, 0}; };
std::map<std::string, st> mp;

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::map<std::string, int> mpkey {{"left", 0}, {"right", 1}, {"any", 2}};
  int n; std::cin >> n; int sum = 0;
  orep(i, 0, n) {
    std::string a, b; int c; std::cin >> a >> b >> c;
    mp[a].vals[mpkey[b]] = c;
    sum += c;
  }
  int cnt = 0;
  for(auto &[_, x] : mp) {
    cnt += std::max(std::min(1, x.vals[2]), std::max(x.vals[0], x.vals[1]));
  }
  if (cnt == sum) { std::cout << "impossible"; }
  else { std::cout << cnt+1; }

  return 0;
}
