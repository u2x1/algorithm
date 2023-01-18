#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstring>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define nl          '\n';

unsigned long long dp[13], ten[13];
std::vector<unsigned long long> cal(unsigned long long _x) {
  std::vector<unsigned long long> v(11, 0ull);
  std::string x = std::to_string(_x);
  orep(i, 0ul, x.size()) {
    const int t = x[i] - '0', rest = x.size()-i-1;
    orep(j, 0, 10) { v[j] += t*dp[rest]; }
    orep(j, 0, t) { v[j] += ten[rest]; }
    v[t] += 1 + (i == x.size()-1 ? 0 : std::stoll(x.substr(i+1)));
    v[0] -= ten[rest];
  }
  return v;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(nullptr);

  ten[0] = 1; dp[0] = 0;
  orep(i, 1, 13) {
    ten[i] = ten[i-1] * 10ull;
    dp[i] = ten[i-1] + 10ull*dp[i-1];
  }

  unsigned long long a, b; std::cin >> a >> b;
  // while(b != 0 && a != 0) {
    auto ca = cal(a-1), cb = cal(b);
    orep(i, 0, 10) { std::cout << cb[i] - ca[i] << " "; }
  //  std::cout << nl;
  //  std::cin >> a >> b;
  //}
  return 0;
}
