#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int r[maxN];
int c[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int N, T; std::cin >> N >> T;
  int win = -1;
  bool app = 0;
  orep(i, 1, N+1) {
    std::cin >> c[i];
    if (c[i] == T) { app = 1; }
  }
  orep(i, 1, N+1) {
    std::cin >> r[i];
  }
  if (app) {
    int hi = 0;
    orep(i, 1, N+1) {
      if (c[i] == T && hi < r[i]) {
        win = i; hi = r[i];
      }
    }
  } else {
    int hi = r[1]; win = 1;
    orep(i, 2, N+1) { 
      if (c[i] == c[1] && hi < r[i]) {
        win = i; hi = r[i];
      }
    }
  }
  std::cout << win;


  return 0;
}
