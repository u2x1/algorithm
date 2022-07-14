#include <cstdio>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {
  int n;
  scanf("%d", &n);
  unsigned int arr[n];
  for (int i = 0; i < n && scanf("%u", &arr[i]) == 1; ++i);

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

  bool flag = 1;
  while (flag) {
    flag = 0;
    for (int i = 1; i < n; ++i) {
      if (arr[i-1] < arr[i]) {
        flag = 1;
        int buffer; buffer = arr[i-1]; arr[i-1] = arr[i]; arr[i] = buffer;
      }
    }
  }
  for(int i = 0; i < n && printf("%u\n", arr[i]); ++i);

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
