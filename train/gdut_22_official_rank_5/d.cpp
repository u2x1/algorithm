#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define drep(i,l,r) for(auto i = (l); i > (r); --i)
#define NL          std::cout << '\n'

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  long long n, a, b, s; std::cin >> n >> a >> b >> s;
  s -= a+b;
  if (b*(n-2) >= s && a*(n-2) <= s)  { std::cout << "YES"; }
  else { std::cout << "NO"; }

  return 0;
}
