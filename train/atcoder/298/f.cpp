#include <iostream>
#include <map>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int N; std::cin >> N;
  std::map<int, long long> row, col;
  orep(i, 0, N) {
    int R, C, X; std::cin >> R >> C >> X;
    row[R] += X; col[C] += X;
  }
  long long m1 = 0, m2 = 0;
  for(auto [_, x] : row) { m1 = std::max(m1, x); std::cout << "r " << _ << " " << x; NL; }
  for(auto [_, x] : col) { m2 = std::max(m2, x); std::cout << "c " << _ << " " << x; NL; }
  
  std::cout << m1 + m2;

  return 0;
}
