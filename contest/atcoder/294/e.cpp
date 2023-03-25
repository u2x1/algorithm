#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
long long v1[maxN], len1[maxN];
long long v2[maxN], len2[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long l, n1, n2; std::cin >> l >> n1 >> n2;
  orep(i, 0, n1) { std::cin >> v1[i] >> len1[i]; }
  orep(i, 0, n2) { std::cin >> v2[i] >> len2[i]; }

  long long l1 = 0, r1 = 0, l2 = 0, r2 = 0, cur1 = 0, cur2 = 0;
  int pos1 = 0, pos2 = 0;
  long long ret = 0;
  while(r1 < l || r2 < l) {
    if (r2 == l || (r1 < l && r1 <= r2)) {
      l1 = r1 + 1;
      r1 = l1 + len1[pos1]-1;
      cur1 = v1[pos1];
      if (cur2 == cur1) {
        ret += (std::min(r1, r2) - l1 + 1);
      }
      // std::cout << "filling up " << len1[pos1]; NL;
      pos1++;
    } else {
      l2 = r2 + 1;
      r2 = l2 + len2[pos2]-1;
      cur2 = v2[pos2];
      if (cur2 == cur1) {
        ret += (std::min(r1, r2) - l2 + 1);
      }
      // std::cout << "filling dn " << len2[pos2]; NL;
      pos2++;
    }
    // std::cout << ret;  NL;
    // std::cout << r1 << " " << r2;  NL;
  }
  std::cout << ret;

  return 0;
}
