#include <iostream>

#define orep(i,l,r) for(auto i = (l); i < (r); ++i)
#define NL          std::cout << '\n';

const int maxN = 2e5+5;
long long a[maxN], b[maxN], c[maxN];

int main() {
  std::ios::sync_with_stdio(0); std::cin.tie(0);
  int n, p; std::cin >> n >> p;
  orep(i, 0, n) { std::cin >> c[i]; }
  const int half = n / 2;
  orep(i, 0, half) {
    if (c[i] < c[n-i-1]) { c[i] += p; }
    if ((c[i] - c[n-i-1]) & 1ll && !(p & 1)) { std::cout << "No"; return 0; }
    if ((c[i] - c[n-i-1]) & 1ll) { c[i] += p; }
    b[i] = (c[i]-c[n-i-1]) / 2;
    b[n-i-1] = -b[i];
  }
  if (n & 1) { b[n/2] = 0; a[n/2] = c[n/2]; }
  orep(i, 0, n) { a[i] = (c[i] - b[i] + p) % p; }

  std::cout << "Yes"; NL;
  orep(i, 0, n) { std::cout << a[i] << " "; } NL;
  orep(i, 0, n) { std::cout << b[i] << " "; } NL;

  return 0;
}
