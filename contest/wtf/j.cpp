#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

std::vector<int> per;

bool cmp(const int x, const int y) {
  std::cout << "1 " << x << " " << y << std::endl;
  std::string s; std::cin >> s;
  return s == "YES";
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 1, n+1) { per.push_back(i); }
  std::stable_sort(per.begin(), per.end(), cmp);

  std::cout << "0";
  for(auto x : per) { std::cout << " " << x; }

  return 0;
}
