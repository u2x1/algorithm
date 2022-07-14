#include <cstdio>
#include <cmath>

int main() {
//   for (int i = 1100; i < 10000; i+=1100) {
//     for (int j = 0; j < 100; j+=11) {
//       int n = i+j, root = sqrt(n);
//       if (root * root == i+j) { printf("%d", n); }
//     }
//   }
  for (int i = 32; i < 100; ++i) {
    int n = i * i;
    int hi = n / 100, lo = n % 100;
    if (hi/10==hi%10 && lo/10==lo%10) { printf("%d\n", n); }
  }
  return 0;
}
