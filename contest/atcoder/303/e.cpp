#include <iostream>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];
std::vector<int> son[maxN];
bool vis[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 1, n) {
    int a, b; std::cin >> a >> b;
    son[a].push_back(b);
    son[b].push_back(a);
  }
  std::vector<int> v;
  orep(i, 1, n+1) {
    if(son[i].size() > 2) {
      v.push_back(i);
    }
  }
  std::vector<int> ret;
  for(auto x : v) {
    ret.push_back(son[x].size());
    n -= son[x].size()+1;
  }
  while(n) {
    ret.push_back(2);
    n -= 3;
  }
  std::sort(ret.begin(), ret.end());
  for(auto x : ret) { std::cout << x << " "; }

  return 0;
}
