#include <iostream>
#include <string>
#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

std::string m1[35];
std::string m2[35];
int H, W;

bool check(int s, int w) {
  for(int i = 0, ii = s; i < H; ++i, ++ii) {
    for(int j = 0, jj = w; j < W; ++j, ++jj) {
      if (m1[ii%H][jj%W] != m2[i][j]) { return false; }
    }
  }
  return 1;
}

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  std::cin >> H >> W;
  orep(i, 0, H) {
    std::cin >> m1[i];
  }
  orep(i, 0, H) {
    std::cin >> m2[i];
  }

  orep(i, 0, H) {
    orep(j, 0, W) {
      if (check(i, j)) { std::cout << "Yes"; exit(0); }
    }
  }
  std::cout << "No";

  return 0;
}
