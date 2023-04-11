#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n; std::cin >> n;
  orep(i, 0, n) { std::cin >> arr[i]; }
  std::sort(arr, arr+n, std::greater<int>());
  {
    long long r = 1ll<<arr[0];
    orep (i, 1, n) {
      r = (1ll<<arr[i]) + (1ll<<arr[i]) * ceil(1.0*r/(1ll<<arr[i]));
    }
    std::cout << r;
  }
  std::cout << " ";
  {
    std::reverse(arr, arr+n);
    std::vector<int> v(n);
    for(int i = 0, a = 0; i < n; ++a, i+=2) { v[i] = arr[a]; }
    for(int a = n-1, i = 1; i < n; i+=2, a--) { v[i] = arr[a]; }

    long long r = 1ll<<v[0];
    orep (i, 1, n) {
      r = (1ll<<v[i]) + (1ll<<v[i]) * ceil(1.0*r/(1ll<<v[i]));
    }
    std::cout << r;
  //  NL; orep(i, 0, n) { std::cout << v[i] << " "; } NL;
  }
  // long long mx = 0, mi = 1ll<<60;
  // do {
  //   long long r = 1ll<<arr[0];
  //   orep (i, 1, n) {
  //     r = (1ll<<arr[i]) + (1ll<<arr[i]) * ceil(1.0*r/(1ll<<arr[i]));
  //   }
  //   if (mx <= r) {
  //     // NL; orep(i, 0, n) { std::cout << arr[i] << " "; } std::cout << r; NL;
  //   }
  //   mx = std::max(mx, r);
  //   mi = std::min(mi, r);
  // }
  // while(std::next_permutation(arr, arr+n));
  // std::cout << '\n' << mi << " " << mx;
  return 0;
}
