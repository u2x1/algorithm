#include <iostream>
#include <string>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int ret[maxN];
std::string mp[maxN];
int H, W;

bool valid(int x, int y) { return ~x && x < H && ~y && y < W; }

int sz = 0;
bool check(int a, int b, int n = 1) {
  if (  !valid(a+n ,b+n)
      ||!valid(a+n ,b-n)
      ||!valid(a-n ,b+n)
      ||!valid(a-n ,b-n)) { return 1; }
  if (mp[a][b] != '#') { return 0; }
  if (   mp[a+n][b+n] == '#'
      && mp[a+n][b-n] == '#'
      && mp[a-n][b+n] == '#'
      && mp[a-n][b-n] == '#') {
    sz = std::max(sz, n);
    return check(a, b, n+1);
  }
  return 1;
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> H >> W;
  orep(i, 0, H) { std::cin >> mp[i]; }
  orep(i, 0, H) { orep(j, 0, W) { sz = 0; if (check(i, j)) { ret[sz]++; } } }
  orep(i, 1, std::min(H, W)+1) { std::cout << ret[i] << " "; }


  return 0;
}
