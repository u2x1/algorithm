#include <iostream>
#include <algorithm>
#include <vector>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  orep(i, 0, t) {
    long long n; std::cin >> n;
    long long ncp = n*12;
    std::cout << ncp << ' ' << 4; NL;
    std::cout << ncp/12 << " " << ncp/6 << " " << ncp/4 << " " << ncp/2; NL;
    // long long a = 2, b = 4;
    // long long sum = a+b;
    // std::vector<long long> ret { a, b };
    // while(sum < n || sum % n) {
    //   long long c = a + b;
    //   ret.push_back(c);
    //   sum += c;
    //   a = b; b = c;
    // }
    // std::cout << sum; NL;
    // std::cout << ret[0];
    // orep(i, 1, ret.size()) { std::cout << " " << ret[i]; }
    // NL;
  }

  return 0;
}
