#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

#define M 998244353

const int maxN = 4e5+5;
long long sum[maxN];
int ls[maxN], rs[maxN];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
  int n, m; std::cin >> n >> m;
  orep(i, 0, m) {
    int l, r; std::cin >> l >> r;
    ls[i] = l; rs[i] = r;
    sum[l]++; sum[r+1]--;
  }

  orep(i, 1, n+1) { sum[i] += sum[i-1]; }
  orep(i, 1, n+1) { sum[i] += sum[i-1]; }

  long long ret = 0;
  orep(i, 0, m) {
    if (ls[i] >= n) { continue; }
    const int ll = ls[i], rr = std::min(rs[i], n-1);
    int max = n-ll, min = n-rr;
    int minus = std::min(rr, max) - std::max(ll, min) + 1;
    long long add = sum[max] - sum[min-1];
    if (minus > 0) { add -= minus; }
    ret = (ret + add) % M;
  }
  std::cout << ret;

  return 0;
}
