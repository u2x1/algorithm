#include <cstdio>
#include <cstring>

#ifdef BENCHMARK
#include <ctime>
#endif

int main() {
  int n, m;
  scanf("%d%d", &n, &m);

#ifdef BENCHMARK
  std::clock_t start = clock();
#endif

  bool out[n]; memset(out, 0, sizeof(out));
  int curr = 0, idx = 0, left = n;
  while (left != 0) {
    if (idx == n) { idx = 0; }
    if (out[idx]) { ++idx; continue; }
    if (++curr == m) {
      out[idx] = 1;
      printf("%d ", idx + 1);
      --left;
      curr = 0;
    }
    ++idx;
  }

#ifdef BENCHMARK
  printf("\n  runtime: %.3f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif

  return 0;
}
