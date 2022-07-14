#include <cstdio>
#include <ctime>

#define SIZE 200000

int prime[10000];
bool not_prime[SIZE];

void mark(int i) {
  for (int j = i; j < SIZE; j+=i) { not_prime[j] = 1; }
}

int main() {
  int n, count = 1;
  scanf("%d", &n);
#ifdef BENCHMARK
  std::clock_t start = clock();
#endif
  prime[0] = 2;
  mark(2);
  for (int i = 3; n >= count - 1; i += 2) {
    if(!not_prime[i]) {
      prime[count++] = i;
      mark(i);
    }
  }
  printf("%d", prime[n-1]);
#ifdef BENCHMARK
  printf("\n  runtime: %f ms\n", (double)(clock()-start) / CLOCKS_PER_SEC * 1000);
#endif
  prime[0] = 2;
  return 0;
}
