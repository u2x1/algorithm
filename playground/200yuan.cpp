#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e6+5;
int arr[maxN];
const int mod = 1e9+7;

int twos[maxN] = { 1 };

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<bool> v(n);
  orep(i, 1, n) { twos[i] = (twos[i-1]<<1) % mod; }
  char c;
  orep(i, 0, n) { std::cin >> c; v[i] = c-'0'; }
  long long lhs = 0, rhs = 0;
  for(int i = n-2; i > -1; --i) { rhs = ((rhs<<1) + v[i])%mod; }

  long long ret = 0;
  orep(i, 0, n) {
    const int sz = n-i-1;
    long long cnt = 0;
    if (lhs) { cnt += lhs * twos[sz]*twos[sz] % mod; }
    if (v[i] == 1) { cnt += (rhs+1)*twos[sz] % mod; }
    cnt %= mod;
    ret += cnt;
    std::cout << twos[sz] << " " << cnt << " ";
    for(int i = 3; i > -1; --i) {
      std::cout << ((lhs>>i) & 1);
    } std::cout << " ";
    for(int i = 3; i > -1; --i) {
      std::cout << ((rhs>>i) & 1);
    } NL;
    lhs = ((lhs<<1) + v[i]) % mod;
    if (v[i+1]) { rhs = (rhs - (twos[sz-1]) + mod) % mod; }
  }
  std::cout << ret;

  return 0;
}
