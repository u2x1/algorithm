#include <cstdio>

int main() {
  double highest = 9.6 * 6 - 9.4 * 5;
  double lowest = 9.6 * 6 - 9.8 * 5;
  double rst = (9.6 * 6 - highest - lowest) / 4;
  printf("%5.2f", rst);
  return 0;
}

