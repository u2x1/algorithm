#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>
int _gcd(const int large, const int small) {
  if (small == 0) { return large; }
  return _gcd(small, large%small);
}
int gcd(const int a, const int b) {
  if (a < b) { return _gcd(b, a); }
  return _gcd(a, b);
}

int lcm(int a, int b) {
  return a*b/(gcd(a,b));
}

int main() {
  int n;
  scanf("%d", &n);
  int a, b;
  int c, d;
  scanf("%d/%d", &a, &b);
  for(int i = 1; i < n; ++i) {
    scanf("%d/%d", &c, &d);
    int _lcm = lcm(b,d);
    a *=     _lcm / b;
    a += c * _lcm / d;
    b = _lcm;
    int _gcd = gcd(a, b);
    a /= _gcd; b /= _gcd;
  }

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  printf("%d", a);
  if (b != 1) {printf("/%d", b);}

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
