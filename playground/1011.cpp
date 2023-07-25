#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

#define int long long

std::vector<int> v;
std::vector<__int128> fac(100);

bool f(int k) {
  int hi = -1;
  orep(i, 0, k) { hi = std::max(hi, v[i]); }
  orep(i, k, v.size()-1) {
    if(v[i] > hi) { return v[i] == v.size(); }
  }
  return v.back() == v.size();
}

int method1(int n) {
  v = std::vector(n, 0ll);
  std::iota(all(v), 1ll);
  int x = 0;
  std::vector<int> ret(n);
  do {
    orep(i, 0, n) {
      ret[i] += f(i);
    }
  } while(std::next_permutation(all(v)));
  std::cout << "ret(n=" << n << "): "<< max_element(all(ret)) - ret.begin(); NL;
  for(auto x : ret) { std::cout << x << " " ; } NL;
  return max_element(all(ret)) - ret.begin();
}

long long method2(int n) {
  std::vector<int> ret(n);
  ret[0] = fac[n-1];
  orep(k, 1, n) {
    orep(i, k, n) {
      // std::cerr << i-1 << " " << n-k << " " << i-k << '\n';
      // std::cerr << (fac[i-k] * (n-i)) << '\n';
      // std::cerr << (k * fac[i-1] * fac[n-k]) << '\n';
      // std::cerr << (k * fac[i-1] * fac[n-k]) / (fac[i-k] * (n-i)) << '\n';
      // std::cerr << ret[k] << '\n';
      ret[k] += (k * fac[i-1] * fac[n-k]) / (fac[i-k] * (n-i));
    }
  }
  for(auto x : ret) { std::cout << x << " "; } NL;
  std::cout << "ret(n=" << n << "): "<< max_element(all(ret)) - ret.begin() ; NL;
  return max_element(all(ret)) - ret.begin();
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  fac[0] = 1;
  orep(i, 1, fac.size()) { fac[i] = i * fac[i-1]; }
  // method1(4);
  // method2(4);
  orep(n, 1, 100) {
    method2(n);
  }

  return 0;
}
