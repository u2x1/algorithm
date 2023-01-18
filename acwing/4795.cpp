#include <iostream>
#include <set>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  long long n, m; std::cin >> n >> m;
  std::set<long long> rs, cs;
  orep(i, 0, m) {
    int r, c; std::cin >> r >> c;
    rs.insert(r);
    cs.insert(c);
    long long taken = rs.size()*(n-cs.size()) + cs.size()*(n-rs.size()) + rs.size() * cs.size();
    std::cout << n*n - taken << " ";
  }
  return 0;
}
