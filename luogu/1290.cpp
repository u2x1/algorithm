#include <cstdio>
#include <algorithm>

#define orep(i,a,b)  for(auto i=(a); i!=(b); ++i)
#define NL           putchar(10);

const int maxN = 1e5;
long long xorer;

bool gcd(const int a, const int b, const bool n) {
  if (b == 0) { return !n; }
  if (a/b > 1) { return n; }
  return gcd(b, a%b, !n);
}

int main() {
  int t; scanf("%d", &t);
  while(t-- ) {
    int a, b; scanf("%d%d", &a, &b);
    if (a<b) { std::swap(a,b); }
    printf(gcd(a, b, 1) ? "Stan" : "Ollie");
    printf(" wins\n");
  }
  return 0;
}
