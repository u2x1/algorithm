#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

struct Node { long long a, b; };

long long sum[maxN];

signed main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long n, k; std::cin >> n >> k;
  std::vector<std::pair<long long, long long>> st;
  orep(i, 0, n) {
    long long a, b; std::cin >> a >> b;
    st.emplace_back(a, b);
  }
  std::sort(st.begin(), st.end());
  int _i = 0;
  for(auto [x, y] : st) {
    sum[_i+1] = sum[_i] + y;
    _i++;
    // std::cout << sum[_i] << " ";
  }
  const auto idx = [&](long long x) { return std::upper_bound(st.begin(), st.end(), std::make_pair(x, 1ll<<62)) - st.begin(); };
  long long l = -1, r = 0;
  while(k) {
    l = r;
    r = l + k;
    k = sum[idx(r)] - sum[idx(l)];
  }
  std::cout << r;

  return 0;
}
