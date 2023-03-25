#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
long long arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long n, k, s; std::cin >> n >> k >> s;
  orep(i, 0, s) {
    int a, b; std::cin >> a >> b;
    arr[a] += b;
  }
  int ret =0;
  orep(i, 1, n+1) {
    if (arr[i] >= k) { ret++; }
  }
  std::cout << n-ret;

  return 0;
}
