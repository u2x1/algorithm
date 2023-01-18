#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

const int maxN = 2e5+5;
int cnt[maxN];
int hasCnt[maxN], itsCnt;

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int t; std::cin >> t;
  while(t--) {
    itsCnt = 0;
    int n; std::cin >> n;
    int tmp;
    orep(i, 0, n) {
      std::cin >> tmp;
      if (!cnt[tmp]) { hasCnt[itsCnt++] = tmp; }
      cnt[tmp]++;
    }
    int out = 0;
    orep(j, 0, itsCnt) {
      if (cnt[hasCnt[j]] == 1) {
        cnt[hasCnt[j]] = 0; out++;
      }
    }
    std::cout << out << NL;
    orep(i, 1, n) {
      if (out != n) {
        orep(j, 0, itsCnt) {
          if (cnt[hasCnt[j]]==2) {
            cnt[hasCnt[j]] = 0; out+=2;
          } else if (cnt[hasCnt[j]] > 2) {
            cnt[hasCnt[j]]--; out++;
          }
        }
      }
      std::cout << out << NL;
    }
  }
  return 0;
}
