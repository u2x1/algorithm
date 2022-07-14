// #include <cstdio>
// 
// int main() {
//   double a, b;
//   scanf("%lf%lf", &a, &b);
//   double k = (int)(a / b);
//   double rst = a - k*b;
//   printf("%f", rst);
//   return 0;
// }
#include <iostream>

int main() {
  double a, b;
  std::cin >> a >> b;
  std::cout << a - (int(a/b)*b);
  return 0;
}
