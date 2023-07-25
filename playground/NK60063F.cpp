#include <bits/stdc++.h>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

long long mod = 1e9+7;

long long ksm(long long x, long long e) {
  long long ret = 1;
  while(e) {
    if (e&1) { ret = ret*x % mod; }
    e >>= 1; x = (x * x) % mod;
  }
  return ret;
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  std::string s;
  std::vector<std::array<int, 3>> v(3);
  orep(i, 0, 3) {
    std::cin >> s;
    orep(j, 0, 3) {
      int x;
      if (s[j] == 'w') { x = 0; }
      if (s[j] == 'i') { x = 1; }
      if (s[j] == 'n') { x = 2; }
      v[i][x]++;
    }
  }
  long long inv9 = ksm(9, mod-2);
  std::function<long long(int)> dfs = [&](int n){
    orep(i, 0, 3) {
      if (v[i][0] == v[i][1] && v[i][1] == v[i][2]) { return 1ll * (i == 0); }
    }
    if (n == 0) { return 0ll; }
    long long ret = 0;
    orep(i, 0, 3) {
      if (v[0][i] <= 1) { continue; }
      orep(j, 0, 3) {
        if (v[1][j] < 1) { continue; }
        orep(k, 0, 3) {
          if (v[2][k] < 1) { continue; }
          long long prob = v[1][j] * v[2][k] * inv9 % mod;
          v[0][i]--; v[1][i]++;
          v[1][j]--; v[2][j]++;
          v[2][k]--; v[0][k]++;
          ret += prob * dfs(n-1) % mod;
          ret %= mod;
          v[0][i]++; v[1][i]--;
          v[1][j]++; v[2][j]--;
          v[2][k]++; v[0][k]--;
        }
      }
    }
    return ret;
  };
  std::cout << dfs(n);

  return 0;
}
