#include <iostream>
#include <algorithm>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    int n, k; std::cin >> n >> k;
    long long sum = 0;
    orep(i, 0, n) { std::cin >> arr[i]; sum+=arr[i]; }
    int l = 0;
    std::sort(arr, arr+n);
    while(k) {
      if (l == n) {
        if (k & 1) { sum -= 2*arr[n-1]; }
        break;
      }
      if (arr[l] < 0) { arr[l] = -arr[l]; sum += 2*arr[l]; ++l; }
      else if (arr[l] == 0) { break; }
      else if (arr[l] > 0) {
        if (k&1) {
          if (l > 0) { sum -= 2*std::min(arr[l-1], arr[l]); }
          else { sum -= 2*arr[l]; }
        }
        break;
      }
      k--;
    }
    std::cout << sum; NL;
  }
  return 0;
}
