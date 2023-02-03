#include <iostream>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int neg[maxN], pos[maxN];
int nCnt, pCnt;

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, k; std::cin >> n >> k;
  int tmp;
  orep(i, 0, n) {
    std::cin >> tmp;
    if (tmp > 0) { pos[pCnt++] = (tmp); }
    else { neg[nCnt++] = (tmp); }
  }
  long long ret = 0;
  std::sort(neg, neg+nCnt, std::greater<int>());
  std::sort(pos, pos+pCnt);
  while(k--) {
    if (pCnt >= 2 && nCnt >= 2) {
      if (pos[pCnt-1] * pos[pCnt-2] >= neg[nCnt-1] * neg[nCnt-2]) {
        ret += pos[pCnt-1] * pos[pCnt-2];
        pCnt -= 2;
      } else {
        ret += neg[nCnt-1] * neg[nCnt-2];
        nCnt -= 2;
      }
    } else if (pCnt >= 2) {
      ret += pos[pCnt-1] * pos[pCnt-2];
      pCnt -= 2;
    } else if (nCnt >= 2) {
      ret += neg[nCnt-1] * neg[nCnt-2];
      nCnt -= 2;
    } else {
      ret += pos[0] * neg[0];
    }
  }
  std::cout << ret;
  return 0;
}
