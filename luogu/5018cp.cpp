#include <iostream>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 1e6+5;
int arr[maxN];
int l[maxN], r[maxN];

unsigned long ret = 0;

std::pair<std::vector<int>, std::string> dfs(const int u) {
  if (u == -1) { return {std::vector<int>(0), ""} ; }
  // if (!~l[u] && !~r[u]) { ret = std::max(1ul,ret); return std::vector<int> { arr[u] }; }
  const auto aa = dfs(l[u]), bb = dfs(r[u]);
  const auto a = aa.first, b = bb.first;
  if (a.size() == b.size()) {
    bool flag = 1;
    auto i = a.cbegin(); auto j = b.crbegin();
    int exclude = 0;
    for(; i!=a.cend(); ++i, ++j) {
      if (!~(*i)) { ++exclude; }
      if ((*i) != (*j)) { flag = 0; break; }
    }
    if (flag) { ret = std::max(ret, a.size()*2+1-2*exclude); }
  }
  std::vector<int> rr; rr.reserve(a.size()+b.size()+1);
  rr.insert(rr.end(), a.begin(), a.end());
  rr.push_back(arr[u]);
  rr.insert(rr.end(), b.begin(), b.end());
  // std::cout << "for u #" << u << "::::" ; for(auto x : rr) { std::cout << x << " "; } ; NL;
  return rr;
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 1, n+1) { std::cin >> arr[i]; }
  orep(i, 1, n+1) {
    std::cin >> l[i] >> r[i];
  }
  dfs(1);
  std::cout << ret;

  return 0;
}

