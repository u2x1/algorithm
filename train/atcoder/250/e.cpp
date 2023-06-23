#include <iostream>
#include <vector>
#include <map>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::map<int, int> mp1;
  std::vector<int> v1(n), v2(n);
  orep(i, 0, n) {
    int x; std::cin >> x;
    v1[i] = x;
    if (!mp1.count(x)) { mp1[x] = i; }
  }
  std::map<int, int> mp2;
  orep(i, 0, n) {
    int x; std::cin >> x;
    v2[i] = x;
    if (!mp2.count(x)) { mp2[x] = i; }
  }
  std::vector<int> f1(n), f2(n);
  orep(i, 0, n) {
    if (i) { f1[i] = f1[i-1]; }
    int x = mp2.count(v1[i]) ? mp2[v1[i]] : 1<<30;
    f1[i] = std::max(f1[i], x);
  }
  orep(i, 0, n) {
    if (i) { f2[i] = f2[i-1]; }
    int x = mp1.count(v2[i]) ? mp1[v2[i]] : 1<<30;
    f2[i] = std::max(f2[i], x);
  }
  int q; std::cin >> q;
  while(q--) {
    int a, b; std::cin >> a >> b; --a, --b;
    std::cout <<  (f1[a] <= b && f2[b] <= a ? "Yes" : "No"); NL;
  }


  return 0;
}
