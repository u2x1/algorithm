#include <iostream>
#include <cstring>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 20+5;
std::string s[maxN];
const int mod = 1e6+3;
int n, k;

int com[maxN][maxN];

long long spe(const long long ss) {
  std::string cs = "";
  orep(i, 0, n) {
    if ((ss>>i)&1) {
      if (cs == "") { cs = s[i]; }
      else {
        orep(j, 0, cs.size()) {
          if (s[i][j] == '?') { continue; }
          if (s[i][j] != '?' && cs[j] == '?') { cs[j] = s[i][j]; }
          if (cs[j] != s[i][j]) { return 0; }
        }
      }
    }
  }
  long long ret = 1;
  orep(i, 0, cs.size()) {
    if (cs[i] == '?') { ret = (ret*26) % mod; }
  }
  // std::cout << "spe";
  // orep(i, 0, 3) { std::cout << ((ss>>i)&1); }
  // std::cout << ": " << ret; NL;
  return ret;
}


long long cnt[17];
void init() {
  memset(cnt, 0, sizeof cnt);
  orep(bs, 0ll, (1ll<<n)) {
    const int c = __builtin_popcount(bs);
    if (c < k) { continue; }
    cnt[c] += spe(bs);
    cnt[c] %= mod;
  }
}

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  orep(i, 0, maxN) {
    com[i][0] = 1;
    orep(j, 1, i+1) {
      com[i][j] = com[i-1][j-1] + com[i-1][j];
      com[i][j] %= mod;
    }
  }
  while(t--) {
    std::cin >> n >> k;
    orep(i, 0, n) { std::cin >> s[i]; }
    init();
    long long ret = 0;
    // orep(c, 1, 16)std::cout << cnt[c] << " "; NL;
    for(int i = n; i >= k; --i) {
      for(int j = n; j > i; --j) {
        cnt[i] -= cnt[j] * com[j][i];
        // std::cout << "com " << j << " " << i << ": " << com[j][i]; NL;
        cnt[i] %= mod;
      }
    }
    ret = cnt[k];
    if (ret < 0) { ret += mod; }
    std::cout << ret; NL;
    // orep(c, 1, 16)std::cout << cnt[c] << " "; NL;
  }

  return 0;
}
