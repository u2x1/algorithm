#ifdef BENCHMARK    ////
#include <ctime>    ////
#endif              ////

#include <cstdio>

int n, k;
bool used[22];
int arr[22];
void f(const int x) {
  if (x > k) {
    for (int i = 1; i <= k; ++i) { printf("%3d", arr[i]); }
    putchar('\n');
    return;
  }
  for(int i = arr[x-1]; i <= n; ++i) {
    if (!used[i]) { arr[x] = i; used[i] = 1; f(x+1); used[i] = 0;}
  }
}

int main() {
  scanf("%d%d", &n, &k);

#ifdef BENCHMARK                   ////
  clock_t start_clock = clock();   ////
#endif                             ////

  arr[0] = 1;
  f(1);

#ifdef BENCHMARK                                              ////
  printf("\n  run time: %.3f ms\n"                            ////
    , (double)(clock()-start_clock) / CLOCKS_PER_SEC * 1000); ////
#endif                                                        ////

  return 0;
}
