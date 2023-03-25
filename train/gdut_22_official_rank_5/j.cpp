#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];
long long sum[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long n, m; std::cin >> n >> m;
  
  orep(i, 0, n) {
    std::cin >> arr[i];
    sum[i+1] = sum[i]+arr[i];
  }

  orep(i, 0, n) {
    long long out = sum[n]+m-arr[i];
    if (i != 0) { out = std::max(out, sum[i]); }
    if (i != n-1) { out = std::max(out, sum[n]-sum[i+1]); }
    std::cout << out << " ";
    // std::cout << sum[i] << " " << sum[n] - ()
    // out = std::max(out, sum[i]);
  }

  return 0;
}
