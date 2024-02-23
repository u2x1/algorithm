#include "bits/stdc++.h"

#define all(x)   x.begin(), x.end()
#define NL       std::cout << '\n'

using lnt = long long;

const int inf = 0x3f3f3f3f;
const lnt linf = 1ll << 62;

const lnt mo = 23333333333333333;

int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  int n; std::cin >> n;
  std::vector<__int128> v(n);
  for (int i = 0; i < n; ++i) {
    std::string s; std::cin >> s;
    __int128 a = 0;
    for (int j = 0; j < std::ssize(s); ++j) {
      int c = s[j] - '0';
      a = a * 10 % mo + c;
    }
    v[i] = a;
  }
  std::map<__int128, lnt> cnt;
  for (auto x : v) { cnt[x]++; }
  lnt ret = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ret += cnt[v[i] * v[j] % mo];
    }
  }
  std::cout << ret;

  return 0;
}
