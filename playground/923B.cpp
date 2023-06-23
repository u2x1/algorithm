#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<int> v(n), t(n);
  for(auto &x : v) { std::cin >> x; }
  for(auto &x : t) { std::cin >> x; }
  long long sum = 0;
  long long level = 0;
  std::multiset<int> st;
  orep(i, 0, n) {
    st.insert(v[i]+level);
    sum += v[i]+level;
  }

  return 0;
}
