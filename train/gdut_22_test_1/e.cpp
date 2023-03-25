#include <iostream>
#include <climits>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, q; std::cin >> n >> q;
  orep(i, 0, n) { std::cin >> arr[i]; }
  orep(i, 0, q) {
    long long len = INT_MAX;
    long long k; std::cin >> k;
    int l = 0, r = 0;
    int retl, retr;
    long long sum = 0;
    for(; l < n; ) {
      while(sum < k && r < n) {
        sum += arr[r++]; 
        // std::cout << "sum " << sum << " on " << l << " " << r; NL;
      }
      if (sum == k) {
        // std::cout << "on " << l << " " << r; NL;
        if (r-l < len) {
          retl = l; retr = r-1;
          len = r-l;
        }
      }
      // std::cout << "sum " << sum << " on " << l << " " << r; NL;
      sum -= arr[l++];
    }
    std::cout << retl << " " << retr; NL;
  }


  return 0;
}
