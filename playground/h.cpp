#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

bool check(long long x) {
  if (x == 1) { return 0; }
  bool flag = 1;
  for(int i = 2; i * i < x; ++i) {
    if (x % i == 0) {
      flag = 0; break;
    }
  }
  return flag;
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);

  int n; std::cin >> n;
  std::vector<int> v(n);
  long long sum = 0;
  for(auto &x : v) { std::cin >> x; sum += x; }

  if (n * 2 > sum) { std::cout << "No"; return 0; }
  else if (n == 1) {
    std::cout << (check(sum) ? "Yes" : "No"); return 0;
  } else if (n == 2) {
    if (sum & 1) {
      std::cout << (check(sum - 2) ? "Yes" : "No"); return 0;
    } else {
      std::cout << "Yes"; return 0;
    }
  }else {
    if (sum & 1) {
      std::cout << (sum > 2*n + 1 && check(sum - 2) ? "Yes" : "No"); return 0 ;
    } else {
      std::cout << "Yes"; return 0;
    }
  }

  return 0;
}
