#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, k; std::cin >> n >> k;
  std::vector<int> v(n);
  for(auto &x : v) { std::cin >> x; }
  int mx = 0;
  long long ret = 0;
  for(int i = v.size()-1; ~i; --i) {
    mx = std::max(mx, v[i]);
    if (v.size()-i <= k) { ret -= v[i]; }
    else { ret += mx - v[i]; }
  }
  std::cout << ret;

  return 0;
}
