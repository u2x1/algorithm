#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e3+5;
const int mod = 998244353;
long long sum[maxN];
long long ret[maxN];

long long inv(long long x) {
  int a = mod-2; long long r = 1;
  while(a) {
    if (a&1) { r = r * x % mod; }
    a >>= 1; x = (x*x) % mod;
  }
  return r;
}

int n, m, k;
long long c;
void mark(const int i) {
  const long long add = (ret[i]*c)% mod;
  // std::cout << "add is " << add; NL;
  if (i+m <= n) {
    sum[i+1] = (sum[i+1] + add) % mod;
    sum[i+m+1] = (sum[i+m+1] - add + mod) % mod;
    // std::cout << "set " << i << " and " << (i+m) << " to " << add; NL;
  } else {
    sum[i+1] = (sum[i+1] + add) % mod;
    sum[n-(m-(n-i))] = (sum[n-(m-(n-i))] + add) % mod;
    if (n-(m-(n-i)) < n) sum[n] = (sum[n] - add + mod) % mod;
    // std::cout << "on " << i << " "  << "set " << i << " and " << n-(m-(n-i)); NL;
  }
}

void accu() {
  orep(i, 1, n+1) {
    sum[i] = (sum[i-1]+sum[i])%mod;
  }
  orep(i, 0, n+1) {
    ret[i] = sum[i];
    sum[i] = 0;
    // std::cout << ret[i] << " "; 
  } 
}


signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> n >> m >> k;
  c = inv(m);
  ret[0] = 1;
  long long rst = 0;
  orep(i, 0, k) {
    orep(j, 0, n) { mark(j); }
    accu();
    rst = (rst+ret[n]) % mod;
  }
  std::cout << rst;
  
  return 0;
}
