#include <cstdio>

#ifdef BENCHMARK
#include <ctime>
#endif

int arr[20][20];

int main() {
  int n;
  scanf("%d", &n);

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

  arr[1][0] = 1;
  arr[1][1] = 1;
  printf("1\n1 1\n");
  int cache;
  for (int i = 2; i < n; ++i) {
    printf("1");
    arr[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      cache = arr[i-1][j-1] + arr[i-1][j];
      arr[i][j] = cache;
      printf(" %d", cache);
    }
    printf("\n");
  }

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
