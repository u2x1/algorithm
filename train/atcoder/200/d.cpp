#include <iostream>
#include <vector>
#include <set>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 200+5;
std::set<int> ret[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<bool> dp(201, 0), newdp = dp;
  orep(i, 1, n+1) {
    int x;
    std::cin >> x; x %= 200;
    if (dp[x]) {
      std::cout << "Yes"; NL;
      std::cout << "1 " << i; NL;
      std::cout << ret[x].size() << " ";
      for(auto a : ret[x]) { std::cout << a << " "; }
      exit(0);
    } else if (dp[0]) {
      std::cout << "Yes"; NL;
      std::cout << "1 " << i; NL;
      std::cout << ret[0].size()+1 << " ";
      for(auto a : ret[0]) { std::cout << a << " "; } std::cout << i;
      exit(0);
    }
    orep(j, 0, 200) {
      if (dp[j]) {
        if (dp[(j+x) % 200]) {
          std::cout << "Yes"; NL;
          std::cout << ret[j].size()+1 << " ";
          for(auto a : ret[j]) { std::cout << a << " "; } std::cout << i; NL;
          std::cout << ret[(j+x)%200].size() << " ";
          for(auto a : ret[(j+x)%200]) { std::cout << a << " "; }
          exit(0);
        } else {
          newdp[(j+x)%200] = 1;
          ret[(j+x)%200] = ret[j];
          ret[(j+x)%200].insert(i);
        }
      }
    }
    newdp[x%200] = 1; ret[x%200].insert(i);
    dp = newdp;
  }
  std::cout << "No";

  return 0;
}
