#include <cstdio>
#include <climits>

int main() {
  int count = 0, sum = 0, min = INT_MAX, max = INT_MIN;
  int cache;
  while (scanf("%d", &cache) != EOF) {
    ++count;
    sum += cache;
    if (min > cache) { min = cache; }
    if (max < cache) { max = cache; }
  }
  printf("%d %d %.3f", min, max, 1.0*sum/count);
  return 0;
}
