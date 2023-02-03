#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
long long us[maxN], ds[maxN];
long long uds[maxN], dus[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::string b; std::cin >> b;
  orep(i, 0ul, b.size()) {
    us[i+1] = us[i] + (b[i] == 'u');
    ds[i+1] = ds[i] + (b[i] == 'd');
  }

  orep(i, 0ul, b.size()) {
    uds[i+1] = uds[i] + (b[i] == 'd' ? us[i] : 0);
  }
  for(int i = b.size()-1; i >= 0; --i) {
    dus[i] = dus[i+1] + (b[i] == 'd' ? us[b.size()]-us[i] : 0);
  }

  unsigned long long idx, match = 0;
  // (u)du
  orep(i, 0ul, b.size()) {
    if (b[i] != 'u') { continue; }
    const unsigned long m = dus[i];
    if (match < m) { idx = i; match = m; }
    break;
  }
  // u(d)u
  orep(i, 0ul, b.size()) {
    if (b[i] != 'd') { continue; }
    const unsigned long m = us[i] * (us[b.size()]-us[i]);
    if (match < m) { idx = i; match = m; }
  }
  // ud(u)
  for(int i = b.size()-1; i >= 0; --i) {
    if (b[i] != 'u') { continue; }
    const unsigned long m = uds[i];
    if (match < m) { idx = i; match = m; }
    break;
  }

  if (match) { b[idx] = 'x'; }
  std::cout << b;

  return 0;
}
