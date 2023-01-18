#include <iostream>
#include <iomanip>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  std::cout << std::setprecision(10);
  int n, m; std::cin >> n >> m; int oriM = m;
  double ret = 0;
  orep(i, 1, n+1) {
    if (i == n && m > 1) { ret += (oriM-n+1.0)/oriM; break; }
    if (m <= 0) { break; }
    ret += 1.0/i;
    --m;
  }
  std::cout << ret;

  return 0;
}
