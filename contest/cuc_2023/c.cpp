#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int cnt[6];
int cpcnt[6];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    orep(i, 0, 5) { cnt[i] = 0; }
    int n; std::cin >> n;
    std::string s;
    orep(i, 0, n) {
      std::cin >> s;
      const char c = s[0];
      if (c == 'W') { cnt[0]++; }
      else if (c == 'U') { cnt[1]++; }
      else if (c == 'B') { cnt[2]++; }
      else if (c == 'G') { cnt[3]++; }
      else if (c == 'R') { cnt[4]++; }
    }
    bool flag = 1;
    int m; std::cin >> m;
      int cp = n; 
      orep(i, 0, 5) { cpcnt[i] = cnt[i]; }
    orep(i, 0, m) {
      std::cin >> s; int o = 0;
      orep(i, 0ul, s.size()) {
        const char c = s[i];
        if (c == 'W')      { cpcnt[0]--; cp--; }
        else if (c == 'U') { cpcnt[1]--; cp--; }
        else if (c == 'B') { cpcnt[2]--; cp--; }
        else if (c == 'G') { cpcnt[3]--; cp--; }
        else if (c == 'R') { cpcnt[4]--; cp--; }
        else if (c == 'O') { o++; }
      }
      cp -= o;
      orep(i, 0, 5) { if (cpcnt[i] < 0) { flag = 0; } }
      if (cp < 0) { flag = 0; }
    }
    std::cout << (flag ? "YES" : "NO"); NL;
  }

  return 0;
}
