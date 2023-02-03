#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
int arr[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int t; std::cin >> t;
  while(t--) {
    long long a, b, c; std::cin >> a >> b >> c;
    long long sum = a+b+c;
    if (sum % 2) { std::cout << "No"; NL; continue; }
    sum >>= 1;
    long long aa = sum - a, bb = sum - b, cc = sum - c;
    if (aa < bb) { std::swap(aa, bb); }
    if (aa < cc) { std::swap(aa, cc); }
    if (bb + cc <= aa) { std::cout << "No"; NL; continue; }
    std::cout << "Yes"; NL;
    std::cout << sum - a << " ";
    std::cout << sum - b << " ";
    std::cout << sum - c;
    NL;
  }
  return 0;
}
