#include <iostream>
#include <queue>
#include <map>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];
const int mod = 998244353;

long long ksm(long long x, int e) {
  long long ret = 1;
  while(e) {
    if(e & 1) { ret = ret * x % mod; }
    x = x * x % mod; e >>= 1;
  }
  return ret;
}

long long inv(long long x) { return ksm(x, mod-2); }

long long N;
int inv5 = inv(5);
std::map<long long, int> memo;
long long dp(long long x) {
  if (x > N) { return 0; }
  if (x == N) { return 1; }
  if (memo.count(x)) { return memo[x]; }
  return (memo[x] = inv5 * ((dp(2*x) + dp(3*x) + dp(4*x) + dp(5*x) + dp(6*x)) % mod) % mod);
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> N;
  std::cout << dp(1);

  return 0;
}
