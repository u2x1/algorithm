#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
long long arr[maxN], sum[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, q; std::cin >> n >> q;
  orep(i, 0, n) { std::cin >> arr[i]; }
  std::sort(arr, arr+n);
  orep(i, 1, n+1) {
    sum[i] = sum[i-1] + arr[i-1];
  }
  orep(i, 0, q) {
    int k,x; std::cin >> k >> x;
    if (x < arr[0]) { std::cout << 0; NL; continue; }
    const int idx = std::upper_bound(arr, arr+n, x) - arr;
    std::cout << sum[idx] - sum[std::max(0, idx - k)]; NL;
  }

  return 0;
}
