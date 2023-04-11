#include <iostream>
#include <map>
#include <algorithm>
#include <set>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'
#define int long long

const int maxN = 1e6+5;
int arr[maxN];
int notprime[maxN];
std::vector<int> factor[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  for (int i = 2; i < maxN; ++i) {
    if (!notprime[i]) {
      factor[i].push_back(i);
      for(int j = i+i; j < maxN; j+=i) {
        notprime[j] = 1;
        factor[j].push_back(i);
      }
    }
  }

  int t; std::cin >> t;
  while(t--) {
    int n; std::cin >> n;
    std::map<int, std::vector<int>> mp;
    orep(i, 1, n+1) {
      std::cin >> arr[i];
      for(const int x : factor[arr[i]]) { mp[x].push_back(i); }
    }
    long long ret = 0;
    for(auto &[x, v] : mp) {
      v.push_back(n+1);
      ret += (n+1)*n/2;
      int last = 0;
      // std::cout << "for x " << x << ":::";
      for(const auto pos : v) {
        // std::cout << pos << " ";
        const int len = pos-last-1;
        if (len) { ret -= (len+1)*len/2; }
        last = pos;
      }
    }
    std::cout << ret; NL;
  }

  return 0;
}
