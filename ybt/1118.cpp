#include <cstdio>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {
  int n;
  scanf("%d", &n);
  int arr[4*n];
  for (int i = 0; i < n 
          && scanf("%d%d%d%d", &arr[i*4],& arr[i*4+1], &arr[i*4+2], &arr[i*4+3]);
          ++i);
  int tx, ty;
  scanf("%d%d", &tx, &ty);

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

  int topmost = -2;
  for (int i = n-1; i != -1; --i) {
    if (  tx - arr[i*4]   >= 0
       && ty - arr[i*4+1] >= 0
       && tx - arr[i*4]   <= arr[i*4+2]
       && ty - arr[i*4+1] <= arr[i*4+3]) {
      topmost = i;
      break;
    }
  }
  printf("%d", topmost + 1);

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
