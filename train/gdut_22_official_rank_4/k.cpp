#include <iostream>
#include <set>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n, tmp; std::cin >> n;
    std::set<int> ret;
    std::set<int> rev;
    orep(i, 0, n) {
      std::cin >> tmp;
      std::set<int> cur { tmp };
      ret.insert(tmp);
      for (auto j : rev) {
        cur.insert(j|tmp);
        ret.insert(j|tmp);
      }
      rev = cur;
    }
    std::cout << ret.size(); NL;
  }

  return 0;
}
