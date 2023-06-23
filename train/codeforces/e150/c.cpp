#include <iostream>
#include <vector>
#include <map>
#include <string>

#define all(x)      x.begin(), x.end()
#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

#define int long long

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  std::map<char, int> mp;
  mp['A'] = 1;
  mp['B'] = 10;
  mp['C'] = 100;
  mp['D'] = 1000;
  mp['E'] = 10000;
  while(t--) {
    std::string s; std::cin >> s;
    std::vector<int> val(s.size());
    long long raw = 0;
    char mx = 0;
    std::vector<std::vector<int>> sum(s.size(), std::vector<int>(5));
    for(int it = s.size() - 1; it != -1; --it) {
      char x = s[it];
      val[it] = (x < mx ? -mp[x] : mp[x]);
      raw += val[it];
      mx = std::max(mx, x);
    }

    orep(i, 1ul, s.size()) {
      orep(j, 0, 5) { sum[i][j] = sum[i-1][j]; }
      if (val[i-1] > 0) { sum[i][s[i-1]-'A']++; }
    }

    std::vector<std::vector<int>> dp(s.size(), std::vector<int>(5));
    orep(i, 0ul, s.size()) {
      orep(j, 0, 5) {
        orep(k, 0, j) {
          dp[i][j] -= 2*mp[k+'A']*sum[i][k];
        }
      }
    }

    std::map<char, std::vector<int>> pos;
    for(int i = s.size()-1; i != -1; --i) {
      {
        int c = 0;
        for(int j = 4; j > -1; --j) {
          if (c) { dp[i][j] += -mp['A'+j] - val[i]; }
          else { dp[i][j] += mp['A'+j] - val[i]; }
          c += pos['A'+j].size();
        }
      }
      // if (val[i] > 0) { continue; }
      char c = s[i]; int cnt = 0; int p = 0;
      orep(j, c+1, 'E'+1) { cnt += pos[j].size(); if (pos[j].size() == 1) { p = pos[j].back(); } }
      if (cnt == 1) {
        orep(j, 'A', c+1) {
          dp[p][j-'A'] += 2*mp[c];
        }
      }
      pos[c].emplace_back(i);
    }
    long long ret = -(1ll<<60);
    // orep(i, 0, s.size()) { orep(j, 0, 5) { std::cout << sum[i][j] << ","; } std::cout << " "; }  NL;
    // orep(i, 0, s.size()) { orep(j, 0, 5) { std::cout << dp[i][j] << ","; } std::cout << " "; }  NL;
    orep(i, 0ul, s.size()) { orep(j, 0, 5) { ret = std::max(ret, raw+dp[i][j]); } } 
    // std::cout << raw << " "<< ret; NL;
    std::cout << ret; NL;
  }

  return 0;
}
